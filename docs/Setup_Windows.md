# Installing C on Windows

## Problems

C in special and C++ are still problematic on Windows.

Git BASH https://gitforwindows.org/ and MYSYS2 are not related.

The ms-vscode.cpptools is under heavy development.

In VSCode a developer spends a lot of time to work on the toolchain.
Debugging often crashes.

## VSCode Extensions

ms-vscode.cpptools - C/C++ IntelliSense, debugging, and code browsing.

`.vscode/extensions.json`

```json
  "recommendations": [
    "ms-vscode.cpptools",
    "ms-vscode.makefile-tools",
    "spmeesseman.vscode-taskexplorer"

  ],
```

## MSYS2

https://www.msys2.org/

https://github.com/msys2/msys2-installer/releases/download/2022-01-18/msys2-x86_64-20220118.exe

`pacman -S --needed base-devel mingw-w64-x86_64-toolchain`

Enter a selection (default=all): 3

3) mingw-w64-x86_64-gcc


### VSCode Terminal Settings

settings.json

```json
    "terminal.integrated.profiles.windows": {
        "MSYS2": {
            "path": "C:\\msys64\\msys2_shell.cmd",
            "args": [
                "-defterm",
                "-mingw64",
                "-no-start",
                "-here"
            ]
        }
    },
    "terminal.integrated.defaultProfile.windows": "MSYS2"
```

## MinGW

Set Path for MinGW, usually ends with `bin`.

## A C-Course on Windows

https://www.udemy.com/course/c-programming-in-windows/learn/lecture/17288232?start=0#overview
