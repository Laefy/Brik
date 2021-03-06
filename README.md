# Compiler

In order to build the project, you will need a compiler that supports C++17 and its libraries.\
If you use GCC, make sure you use at least the version 9.1.

### Notes for Windows

If you are on Windows and do not have Visual Studio >= 17 (not VSCode) installed, you will have to install MSYS2 to get an up-to-date version of GCC.

Follow the instructions on this page : https://www.msys2.org/.

Edit the "Path" environment variable (the user or system one):
1. Add "C:\msys64\mingw64\bin" to it (if you installed MSYS2 elsewhere, then update the path accordingly).
2. If you had a previous MinGW version installed (usually located in C:\mingw"), remove its bin folder from the Path.

Open VSCode.\
Run the command `Preferences: Open User Settings`.\
Search for the setting `CMake: Mingw Search Dirs` and add `"C:\msys64\mingw64` to it (without the bin folder).\
Restart VSCode, run the command `CMake: Scan For Kits`, then `CMake: Edit User-Local CMake Kits`.\
Add the following code inside the JSON of the MSYS2 compilers:
```json
"preferredGenerator": {
  "name": "MinGW Makefiles"
},
"environmentVariables": {
  "CMT_MINGW_PATH": "C:\\msys64\\mingw64\\bin"
}
```

---

# Installation of dependencies

This project depends on the [SFML library](https://www.sfml-dev.org/index.php). 

### Windows

You can download the source code from [Github](https://github.com/SFML/SFML/releases/tag/2.5.1).

Extract the content of the zip archive.\
Open the root folder inside VSCode (the root folder is the one containing `src`, `include`, `CMakeLists.txt`, etc).\
Open the command panel (Ctrl+Shift+P) and run `CMake: Configure` command.\
Once the configuration is completed, run `CMake: Edit CMake Cache (UI)`.\
Search for CMAKE_INSTALL_PREFIX and set it to an empty folder of your choice (it will become the installation directory of the library).\
Click on the Save button and close the CMake Cache Editor.\
Run the command `CMake: Build Target` and select the target called "install".

Check that the library files were correctly generated inside the folder you specified as CMAKE_INSTALL_PREFIX.\
If that's not the case, contact me ASAP.

Finally, open the Windows environnement variables editor.\
Create or edit the variable CMAKE_PREFIX_PATH.\
Add the installation folder of the SFML library to it.

### Linux

Use your favorite package manager to install the SFML library.

For instance with apt-get on Ubuntu:\
`sudo apt-get install libsfml-dev`

---

# Building the project

Open the root folder of Brik inside VSCode.\
Open the command panel (Ctrl+Shift+P) and run `CMake: Configure` command.\
Use F7 or run `CMake: Build` to compile the project.

---

# Launching the game

Press F5 or run `Debug: Start Debugging`.\
Select `C++ (GDB/LLDB)` or `C++ (Windows)` depending on your environnement.\
Then select `Default Configuration`.\
If you are not prompt for these choices, make sure there is no `launch.json` file inside the `.vscode` folder and repeat the previous steps.

A brand new `launch.json` file should have been generated inside the `.vscode` folder.\
Replace the `program` entry by the following: `"program": "${command:cmake.launchTargetPath}"`.\
Make sure the `cwd` entry is set to the following: `"cwd": "${workspaceFolder}"`.\
Save the `launch.json` file.

From now on, pressing F5 or running `Debug: Start Debugging` should allow you to start the game.
