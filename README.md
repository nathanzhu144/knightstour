# Knight's Tour
Created by <b>Nathan Zhu </b>

## Introduction

This is a command-line interface program designed to find open Knight's tours on various-sized chessboards.  A <a href="https://en.wikipedia.org/wiki/Knight%27s_tour ">Knight's Tour</a> is a special example of a Hamiltonian path. It is defined as the problem of finding a sequence of moves of a knight on a chessboard so that the knight can visit every square of the chessboard only once.  If the knight ends on a square that is one knight's move from the starting square, then it is a closed circuit.  Otherwise, it is defined as an open circuit.  While the math proofs below are about closed circuits, this program endeavors to just find a circuit, and most of the time it returns an open circuit.

While normal chessboards are 8 by 8, the knight's tour is generalizable to rectangular boards of all sizes; it is even applied
to non-rectangular boards.  However, this program only handles rectangular boards of 210 x 210 or smaller.


<img src="photos/example_knights_tour.png" alt="Knight's Tour"> </img>

## Setting Up

The setting up is surprisingly simple.  

```$  curl -OL https://github.com/nathanzhu144/knightstour/knight_setup.sh
```$  bash knight_setup.sh
```
## Time Complexity Analysis

This program is a modified brute-force algorithm.  The brute-force algorithm uses 

A naive implementation of this program doing a depth-first search without any heuristics will struggle with runtime issues,
since the complexity of this program is exponential, with a runtime of O(k<sup>N</sup>), where N is the total number of
squares in the chessboard itself and k is the average branching factor of the board.  Since the size of k represents the average branching factor of the board, it has to be a constant value between 0 and 8, as at most a knight at a given position can have 8 possible moves, and the least number of possible moves a knight can have at a given position is no possible moves. It is sufficient to say that given the expoential nature of the problem, a brute force solution will not finish running in a reasonable amount of time for boards bigger than 10 by 10 boards.



```C++
int find_degree_of_node(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    int num_degrees = 0;

    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board))
        {
            ++num_degrees;
        }
    }

    return num_degrees;
}
```

However, as this program uses stack frames for backtracking, it crashes on large enough inputs.  




## Functionality

This often finds the solution quickly, but in the case that there is not a k

<img src="photos/cli_knights_tour_1.png" alt="Knight's Tour"> 

<img src="photos/file_writing_example.png" alt="file writing example">
<img src="photos/no_solution.png" alt="no solution">
