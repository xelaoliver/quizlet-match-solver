# Alex Oliver 2025

import pyperclip
import pyautogui

with open("path/to/dictionary.txt", encoding="utf-8") as file:
    reference = [line.rstrip() for line in file]

positions = [[0, 0], [1, 0], [2, 0], [3, 0], [0, 1], [1, 1], [2, 1], [3, 1], [0, 2], [1, 2], [2, 2], [3, 2]]
instructions = []
pyautogui.PAUSE = .085

pyautogui.click()
pyautogui.hotkey("ctrlleft", "a")
pyautogui.hotkey("ctrlleft", "c")

s = pyperclip.paste()
game = s.split("\r\n")
game = game[7:len(game)-1]

for i in range(12):
    j = reference.index(game[i])

    if j%2 == 0:
        end = j+1
    else:
        end = j-1
    
    append = not any(game.index(reference[end]) in jtem for jtem in instructions)

    if append:
        instructions.append([game.index(game[i]), game.index(reference[end])])

pyautogui.moveTo(390, 310, duration = 0)
for i in range(len(instructions)):
    a = positions[instructions[i][0]]
    pyautogui.moveTo(390+(a[0]*370), 310+(a[1]*280), duration = 0)
    pyautogui.click()

    a = positions[instructions[i][1]]
    pyautogui.moveTo(390+(a[0]*370), 310+(a[1]*280), duration = 0)
    pyautogui.click()
