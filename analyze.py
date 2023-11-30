import subprocess
import sys

def RunStaticAnalysis(location):
    subprocess.run((
        'cppcheck', '--cppcheck-build-dir=analysis_cache', '--std=c++20', 
        f'{location}'
    ))
  

if __name__ == "__main__":
    if len(sys.argv) != 2:
        location = "."
    else: location = sys.argv[1]
    RunStaticAnalysis(location)