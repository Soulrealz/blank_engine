# blank_engine

## PROJECT STARTUP REQUIREMENTS

### 1. Download Premake

Go to this site and click on Windows under Pre-Built Binaries
> https://premake.github.io/download 

Once you download the zip open it and get premake5.exe and save it in bin folder(create it if it doesn't exist) in the project root directory.

### 2. Install CMake (necessary for some Conan packages)

Get the win 64 installer from here
>https://cmake.org/download/

Click add to path and next on everything else

### 3. Install and configure Conan (requires python)

Install with
> pip install conan

Configure conan profile
> conan profile detect

Now open the directory in which your profile was saved. 
> C:\Users\your_user\.conan2\profiles\default

Edit cppstd from 14 to 20
> compiler.cppstd=14

Restart your gitbash or whatever shell you are using so that it can detect CMake for the next step

### 4. Download Packages and Build Project

Automatically:

    py build_project.py

Manually:

    conan install conanfile.py --build missing --output-folder=./dependencies --settings=build_type=Debug
    
    conan install conanfile.py --build missing --output-folder=./dependencies --settings=build_type=Release

If the above command is throwing the following error in gitbash run it again but in CMD
    
    ERROR: fmt/10.0.0: Error in build() method, line 94

Then to build the project run
    
    ./bin/premake5.exe vs2019

### 5. Cppcheck

Download ver 2.12.1 (zip)
> https://github.com/danmar/cppcheck/releases

Extract in a folder of your choosing (not in this project) enter the root directory and execute

    mkdir build
    cd build
    cmake ..
    cmake --build .

Add cppcheck to path in system environment variables

    path_to_folder\cppcheck-2.12.1\cppcheck-2.12.1\build\bin\Debug

To use cppcheck run

    py analyze.py path/to/folder OR py analyze.py path/to/cppFile

If no path is provided the default location is "." or the root project directory.