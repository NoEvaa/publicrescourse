import sys
try:
    if sys.ps1: INTERPRETER = True
except AttributeError:
    INTERPRETER = bool(sys.flags.interactive)
    
if INTERPRETER:
    print('python交互式解释器执行')
else:
    print('python解释器执行')
