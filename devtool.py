import os
import sys
import subprocess

if __name__ == "__main__":
    # call build tool premake
    subprocess.run(("./bin/premake5.exe", "vs2019"))