import os
import sys
import subprocess

def RunConan(build_type):
    subprocess.run((
        'conan', 'install', '.', 
        '--build', 'missing', 
        '--output-folder=./dependencies', 
        f'--settings=build_type={build_type}'
    ))
  

if __name__ == "__main__":
    RunConan("Debug")
    RunConan("Release")
    #RunConan("Dist")
    # call build tool premake
    subprocess.run(("./bin/premake5.exe", "vs2019"))