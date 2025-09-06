# Alex Oliver 2025

import pyperclip
import pyautogui

with open("path/to/dictionary.txt", encoding="utf-8") as file:
    reference = [line.rstrip() for line in file]

positions = [[390, 310], [760, 310], [1130, 310], [1500, 310], [390, 590], [760, 590], [1130, 590], [1500, 590], [390, 870], [760, 870], [1130, 870], [1500, 870]]
instructions = []
pyautogui.PAUSE = .085

pyautogui.click()
pyautogui.hotkey("ctrlleft", "a")
pyautogui.hotkey("ctrlleft", "c")

s = pyperclip.paste()
game = s.split("\r\n")
game = game[7:len(game)-1]
reference = [line.strip()[:100]+"…" if len(line) > 100 else line.strip() for line in reference]

print(game)

for i in range(12):
    j = reference.index(game[i])

    if j%2 == 0:
        end = j+1
    else:
        end = j-1

    x = game.index(game[i])

    if not x in instructions:
        instructions.extend([x, game.index(reference[end])])

for i in range(12):
    a = positions[instructions[i]]
    pyautogui.moveTo(a[0], a[1], duration = 0)
    pyautogui.click()
