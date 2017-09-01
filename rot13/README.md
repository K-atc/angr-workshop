Chapter 2. rot13
====

Level: Easy

Time: this may take 15 minutes

Contents
----
* how to symbolize stdin

Exercise
----
Download [rot13](./rot13). 
Analyze the binary and answer the following questions.
Flag format is `angr{***}`.

(1) What kind of inputs the binary expects? (1 min)

(2) How user input is transformed? (3 min)

(3) When `congratz!` will be printed? (1 min)

(4) Write solver script using angr. (10 min)

Hints
----
### (1) - (3)
JUST DO THE REVERSING!!

### (4)
#### Hint 1
solver template is available: [solver-template.py](./solver-template.py)

#### Hint 2
see [angr documentation](https://github.com/angr/angr-doc/blob/master/CHEATSHEET.md#exploring-and-analysing-pathgroups)

```python
path_group.explore(find=lambda p: "correct" in p.state.posix.dumps(1))
initial_state = b.factory.full_init_state(args=["./antidebug", argv1], add_options=simuvex.o.unicorn, remove_options={simuvex.o.LAZY_SOLVES})
```

Or [ntddk's blog](https://ntddk.github.io/2016/08/27/angr-afl-driller/) may help you