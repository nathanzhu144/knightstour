# Knight's Tour

This is a command-line interface program designed to find open Knight's tours on <br>
various-sized chessboards.  A <a href="https://en.wikipedia.org/wiki/Knight%27s_tour ">Knight's Tour</a> is a special example of a Hamiltonian circuit. It is defined as the   

<img src="photos/example_knights_tour.png" alt="Knight's Tour"> </img>




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

This often finds the solution quickly, but in the case that there is not a k

<img src="photos/cli_knights_tour_1.png" alt="Knight's Tour"> 

<img src="photos/file_writing_example.png" alt="file writing example">
<imt src="photos/no_solution.png" alt="no solution">
