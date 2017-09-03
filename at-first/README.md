Chapter 0. At First
====

What is Symbolic Execution?
-----
TODO

Make up enviroment for angr
-----
Follow following steps:

1. Install [angr](https://github.com/angr/angr/)
    * If you have installed angr a long time before, upgrade them with `sudo -H pip2 install angr --upgrade`.
2. Run attached file `install-check.py` to check if you have installed angr correctly

attached files: [install-check.py](./install-check.py)

Analysis Flow
-----
Overall steps:

1. Prepare Python script file (*NOTE: Do NOT name it `angr.py`. `import angr` imports `angr.py` self and not imports true angr module*)
1. `import angr`
1. set up angr instance and load binary like `p = angr.Project('BIN', load_options={'auto_load_libs': False})`
    * You can give command line arguments in this line (see Chapter 1)
1. Set up path explorer
1. Run explorer. angr starts path exploring to get models (solusions) that satisfies given (path) constraints
1. Concrete (Finalize) symbolic values

### When you know the address(es) should (not) be reached
Then `find` and `avoid` are useful. 

`find` is the path exploring goal.
If angr found that there's a satisfiable constrains which reaches to the address specified by `find`, path exploring finishes.

`avoid` is a dead end of path exploring.
If angr reaches to the address specified by `avoid`, angr gives up its path and continue exploring another path.

`find` and `avoid` can be array of address. Note that they are __OR condition__.
Too may find/avoid address causes undesied results.

#### Sample script (from at-first/install-check.py)

```python
#!/bin/python2
import angr

p = angr.Project('r100', load_options={'auto_load_libs': False})
ex = p.surveyors.Explorer(find=(0x400844, ), avoid=(0x400855,))
ex.run()
found = ex.found
if len(found): # I recommend error hadling like this
    print(found[0].state.posix.dumps(0).strip('\0\n')) # => Code_Talkers
else:
    print("[!] no solusions!")
```

- - -
Did you have read up on this chapter? OK, it's angr time!! Let's go on [Chapter 1](../usage)!!