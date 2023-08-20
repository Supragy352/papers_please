# Papers Please
![image](https://github.com/Supragy352/papers_please/assets/55745696/aefcba62-5bbe-4e99-a870-271fb9ffb069)
The papers please demo made with [Raylib](https://github.com/raysan5/raylib/tree/master)

## Getting it to work was a big deal.

1. Learned how to use `make` fully, variables and all.
2. CMake is less cryptic now.
3. How to enable/work with Raylib both on:
    - On Windows:
        - You clone the git repo and then you can wither build the raylib from source using CMake and Make, OR you can installa nd then go to                      the examples directory.
        - You see where you want to work. VSC is something I am not used to. So I used Sublime obviously, I just ran CMAKE with the $(CMAKE_EXPORT_COMPILE_COMMANDS) key turned on. That generates the json database (compile_commands.json) along with the `makefiles` which helps with the completions of the Clangd Server.
        - Once that was working we can build any project using a striped down version of the Makefile for exmples keeping only the Windows stuff.
    - On Linux:
       -  You clone the git repo and then build from source coz who are you kidding, and but but but, you need the `base-devel` package on Arch/Arch-  based or `build-essentials` for Ubuntu. Then run CMAKE to build and generate the Makefiles and run `make` and voila!, `raylib` is built. Install with `make install`.
       -  Now sublime works like a charm coz you can export the database with `bear` and start working.

## Actual stuff on how it works

Well for one this is a followed tutorial by Andrew Hamel Codes on YT. 
