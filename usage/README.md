Chapter 1. usage
====

Level: Medium Easy

Time: this may take 10 - 20 minutes

Contents
----
* how to symbolize argc, angv
* how to set find/avoid

Exercise
----
Download [usage](./usage). 
Analyze the binary and answer the following questions.
Flag format is `angr{***}`.

(1) After fuction `usage()` called, what happens? (< 1 min)

(2) When `usage()` is called? (< 1 min)

(3) How many arguments the binary expects? (< 1 min)

(4) What should `argv[1]` be? (< 1 min)

(5) When usage of `./usage` is collect, what happens? (< 1 min)

(6) Write solver script using angr. If you trying this excercise in own environment, run `echo angr{dummy} > flag` in your shell beforehand. (5 - 15 min)

Hints
----
### (1) - (5)
JUST DO THE REVERSING!!

### (6)
#### Hint 1
solver template is available: [solver-template.py](solver-template.py)

#### Hint 2
see [angr documentation](https://github.com/angr/angr-doc/blob/master/CHEATSHEET.md#constraint-solver-claripy)

```python
argv1 = angr.claripy.BVS("argv1", flag_size * 8)
initial_state = b.factory.full_init_state(args=["./antidebug", argv1], add_options=simuvex.o.unicorn, remove_options={simuvex.o.LAZY_SOLVES})
```