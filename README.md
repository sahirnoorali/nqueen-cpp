# Solving N-Queen Problem

This code solves the N Queen puzzle which is an extension of 8 Queen Puzzle. (https://en.wikipedia.org/wiki/Eight_queens_puzzle)

## Solution
The code searches in a recursive manner to find a state where all queens can be placed in the chess board without anyone beating the other. Since it's a recursive algorithm, it also has a backtracking feature to undo the wrong attempts of finding a solution. 

## Output
The code ultimately outputs the solution (chess board configuration) on the console. An example is given below:
```
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0
```
where 1 denotes a Queen and 0 denotes an empty space.
## Note 
'n' is defined in the very top of the code as a directive. And this is not the best/efficient way out there to solve N-Queen problem.
