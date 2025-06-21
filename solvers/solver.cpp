// Alex Oliver 2025

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

// thanks to https://stackoverflow.com/questions/14762456/getclipboarddatacf-text
string getClipboardText() {
    if (!OpenClipboard(nullptr)) { return 0; }
    
    HANDLE hData = GetClipboardData(CF_UNICODETEXT);
    if (hData == nullptr) {
        CloseClipboard();
        return 0;
    }

    wchar_t* pszText = static_cast<wchar_t*>(GlobalLock(hData));
    if (pszText == nullptr) {
        CloseClipboard();
        return "";
    }

    wstring wtext(pszText);
    GlobalUnlock(hData);
    CloseClipboard();

    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wtext.c_str(), -1, nullptr, 0, nullptr, nullptr);
    string text(bufferSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, wtext.c_str(), -1, &text[0], bufferSize, nullptr, nullptr);

    if (!text.empty() && text.back() == '\0') {
        text.pop_back();
    }

    return text;
}

vector<string> parseStringToArray(const string& clipboardText) {
    stringstream ss(clipboardText);
    vector<string> returnWords;
    string line;

    while (getline(ss, line)) {
        if (!line.empty() || line != "\n") {
            returnWords.push_back(line);
        }
    }

    return returnWords;
}

// thanks to https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
template<typename T, typename P>
T remove_if(T beg, T end, P pred) {
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

int indexOf(const string& str, const vector<string>& array, int length) {
    for (size_t k = 0; k < length; k ++) {
        string strNoSpaces = str;
        strNoSpaces.erase(remove_if(strNoSpaces.begin(), strNoSpaces.end(), ::isspace), strNoSpaces.end());
        string arrayKNoSpaces = array[k];
        arrayKNoSpaces.erase(remove_if(arrayKNoSpaces.begin(), arrayKNoSpaces.end(), ::isspace), arrayKNoSpaces.end());
        if (strNoSpaces == arrayKNoSpaces) {
            return static_cast<int>(k);
        }
    }

    return -1;
}

void start() {
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x41, 0, 0, 0);
    keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x43, 0, 0, 0);
    keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

int main() {
    // use this for debugging
    SetConsoleOutputCP(CP_UTF8);

    string output;
    ifstream lines("path/to/dictionary.txt");
    string line;
    while (getline(lines, line)) {
        output += line+"\n";
    }

    pair<int, int> positions[12] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}};

    vector<string> resource = parseStringToArray(output);

    start();

    Sleep(100);

    vector<string> tempGameOptions = parseStringToArray(getClipboardText());

    string gameOptions[12];
    for (int i = 7; i < 19; i ++) {
        gameOptions[i-7] = tempGameOptions[i];
    }
    
    
    for (int i = 0; i < 12; i ++) {
        cout << "GAME: " << gameOptions[i] << endl;
    }
    
    /*
    for (int i = 0; i < resource.size(); i ++) {
        cout << resource[i] << endl;
    }
    */

    vector<pair<int, int>> instructions;
    for (int i = 0; i < 12; i++) {
        int j = indexOf(gameOptions[i], resource, resource.size());
        int translationIndex;

        if (j%2 == 0) {
            translationIndex = j+1;
        } else {
            translationIndex = j-1;
        }

        int a = i;
        int b = indexOf(resource[translationIndex], vector<string>(gameOptions, gameOptions+12), 12);

        if (b == -1) continue;

        bool exists = false;
        for (const auto& p : instructions) {
            if ((p.first == a && p.second == b) || (p.first == b && p.second == a)) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            instructions.push_back(make_pair(a, b));
        }
    }

    for (size_t i = 0; i < 6; i ++) {
        cout << "match: " << instructions[i].first << " and " << instructions[i].second << endl;
    }

    
    int x, y;
    for (size_t i = 0; i < 6; i ++) {
        x = positions[instructions[i].first].first;
        y = positions[instructions[i].first].second;

        SetCursorPos(390+(x*370), 310+(y*280));
        mouse_event(0x0002, 0, 0, 0, 0);
        Sleep(150);
	    mouse_event(0x0004, 0, 0, 0, 0);

        x = positions[instructions[i].second].first;
        y = positions[instructions[i].second].second;

        SetCursorPos(390+(x*370), 310+(y*280));
        mouse_event(0x0002, 0, 0, 0, 0);
        Sleep(150);
	    mouse_event(0x0004, 0, 0, 0, 0);
    }
}
