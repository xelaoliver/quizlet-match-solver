# Quizlet Match solver

Solve Quizlet Match games without any effort and reach the top of the leaderboards.

![Alt Text](https://github.com/xelaoliver/quizlet-match-solver/blob/main/quizlet.gif)

# Usage

Download either the C++ or Python file. Copy the *Terms in this set* from your chosen set in Quizlet and then, create a **dictionary.txt** file in the same directory. Do not delete any whitespace as both programs automatically account for them.

Position your mouse cursor on the *Start Game* button and run the program (this can be done in VS Code by pressing <kbd>ctrl</kbd> + <kbd>alt</kbd> + <kbd>n</kbd>).

# Information

On my daily daily driver, I can complete a match in 2.2 seconds using the C++ version and 2.9 seconds using the Python version. I doubt that I'll be able to program a faster way to solve these because I had to add delay between mouse clicks to let Quizlet correctly register them. Both versions of this solver work by encoding text into UTF-8 for parsing, so this can solve matches in different languages.

## Beware

- The C++ version will not care if your text file input is not found.
- These programs only work on Windows

# License

Copyright 2025 Alex Oliver

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
