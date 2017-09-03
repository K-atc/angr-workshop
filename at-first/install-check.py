#!/bin/python2
# orig: https://github.com/angr/angr-doc/blob/master/examples/defcamp_r100/solve.py
# original script no longer works!
import angr

p = angr.Project('r100', load_options={'auto_load_libs': False})
ex = p.surveyors.Explorer(find=(0x400844, ), avoid=(0x400855,))
ex.run()
found = ex.found
if len(found):
    # NOTE: Path Object is obsoleted
    # see https://github.com/angr/angr-doc/blob/master/docs/paths.md
    print(found[0].state.posix.dumps(0).strip('\0\n')) # => Code_Talkers
else:
    print("[!] no solusions!")