import subprocess

def RunStaticAnalysis(location):
    subprocess.run((
        'cppcheck', '--cppcheck-build-dir=analysis_cache', '--std=c++20', 
        f'{location}'
    ))
  

if __name__ == "__main__":
    RunStaticAnalysis(".")