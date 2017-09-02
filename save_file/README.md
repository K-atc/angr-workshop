Chapter 4. save_file
====

Level: Medium Medium

Time: this may take 20 - 25 minutes

Contents
----
* how to symbolize file 
* how to generate exploit code using angr

Exercise
----
Download [save_file](./save_file). 
Analyze the binary and answer the following questions.
Flag format is `angr{***}`.

(1) What is the name of save file? (1 min)

(2) How is the save file format? (3 min)

(3) There's a vulnerability. What is it? (3 - 8 min)

(4) Print flag with exploitation. (3 min)

(5) Generate exploitation code using angr. (10 min)

Hints
----
### (1)
JUST DO IT!!

### (2)
There's a struct. Reverse it!

### (3)
This is a common vulnerability.

### (4)
JUST DO THE REVERSING!!

### (5)
see:

* https://github.com/angr/angr-doc/blob/master/docs/states.md#working-with-the-filesystem
* https://github.com/angr/angr-doc/blob/master/examples/asisctffinals2015_license/solve.py#L12