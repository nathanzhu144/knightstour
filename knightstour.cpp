#include "knightstour.h"

//  Board setup functions  //


//Requires: Nothing.
//Modifies: board
//Effects:  Sets all indices of board to -1
void initialize_board(int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    for (int r = 0; r < MAX_NUM_ROWS; ++r)
    {
        for (int c = 0; c < MAX_NUM_COLS; ++c)
        {
            board[r][c] = -1;
        }
    }
}

// Misc helper functions//

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    return (row >= 0 && row < board_row_size && col >= 0 && col < board_col_size && board[row][col] == -1);
}

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Returns the degree of a node indicated by row, col.  Degree is defined as number of possible
//          moves that a chess piece can make.
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

//Board solver functions//

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Returns a vector of pairs<int, std::pair<int, int > > of possible
//          moves in form of (degree, coordinate).
//
//          first = degree after a move
//          second = move position in std::pair(int row, int col)
//
//Note:     This uses the Warnsdorf's heurstic.  It chooses the next open position
//          with the fewest number of moves from that position.

std::vector<std::pair<int, std::pair<int, int>>> possible_moves(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    std::vector<std::pair<int, std::pair<int, int>>> optimal_moves;

    //Iterates through all 8 possible moves, finding node with least vertices
    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board) &&
            find_degree_of_node(row + row_change[i], col + col_change[i], board) > 0)
        {
            optimal_moves.push_back(std::make_pair(find_degree_of_node(row + row_change[i], col + col_change[i], board),
                                                   std::make_pair(row + row_change[i], col + col_change[i])));
        }
    }

    std::sort(optimal_moves.begin(), optimal_moves.end());

    return optimal_moves;
}

//Requires: All squares to be moved on except for one.
//Modifies: Nothing.
//Effects:  Finds last move in the form std::pair(int row, int col).  Since possible_moves returns
//          an empty vector on the last move before completing a board, as the last move will be to a
//          position of degree 0.
//
//          Returns -1, -1 if cannot find a solution.  i.e. knight cannot move to any spaces.
//

std::pair<int, int> last_move(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{

    //Iterates through all 8 possible moves of the knight looking for an empty square
    for (int i = 0; i < NUM_MOVES; ++i)
    {
        if (is_move_good(row + row_change[i], col + col_change[i], board))
        {
            //returns coordinates of last square
            return std::make_pair(row + row_change[i], col + col_change[i]);
        }
    }

    //No squares can be moved to.
    return std::make_pair(-1, -1);
}

//Backtracking functions//

void kt(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    board[row][col] = 0;

    std::cout << "row " << board_row_size;
    std::cout << "col " << board_col_size;

    if (kt_utility(row, col, 0, board))
    {
        print_board(board);
    }
    else
    {
        std::cout << "There is no solution.";
    }
}

bool kt_utility(int row, int col, int num_moves_made_already, int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    //Finished filling whole board except one.

    if (num_moves_made_already >= board_row_size * board_col_size - 2)
    {
        std::pair<int, int> last = last_move(row, col, board);

        //no move from current square can get to last open square
        if (last.first == -1 && last.second == -1)
        {
            return false;
        }
        //there exists a move to last open square
        else
        {
            board[last.first][last.second] = num_moves_made_already + 1;
            return true;
        }
    }

    //Not finished filling whole board except one.

    //Makes an array of possible next moves ordered according to Warnsdorff's
    std::vector<std::pair<int, int>> possible_next_moves;

    for (const std::pair<int, std::pair<int, int>> &i : possible_moves(row, col, board))
    {
        possible_next_moves.push_back(i.second);
    }

    //Attempts to make all knight moves in an order sorted by an increasing degree.
    for (auto i = possible_next_moves.begin(); i != possible_next_moves.end(); ++i)
    {
        board[i->first][i->second] = num_moves_made_already + 1;

        //If move later results in a successful knights tour
        if (kt_utility(i->first, i->second, num_moves_made_already + 1, board))
        {
            return true;
        }
        //If move later does not result in a successful knights tour
        else
        {
            board[i->first][i->second] = -1;
        }
    }

    //none of possible moves from this square result in a knights tour
    return false;
}



//Menu functions//

//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board.
void print_board(const int board[MAX_NUM_ROWS][MAX_NUM_COLS])
{
    for (int r = 0; r < board_row_size; ++r)
    {
        for (int c = 0; c < board_col_size; ++c)
        {
            printf(" %4d ", board[r][c]);
        }
        std::cout << std::endl;
    }
}

//Requires: Nothing.
//Modifies: Nothing
//
//Effects:  Prints board in to file.  Overwrites file if it exists already.  If append flag is true
//          append to the file.  Otherwise, write over original file.
//

void print_board_to_file(std::string file_name_in, bool append, const int board[MAX_NUM_ROWS][MAX_NUM_COLS]){
    FILE *f;
    if(append){
        f = fopen(file_name_in.c_str(), "a"); 
    }else{
        f = fopen(file_name_in.c_str(), "w+");
    }

    fprintf(f, "\n");
    fprintf(f, "board size %i x %i\n", board_row_size, board_col_size);
    fprintf(f, "starting from row %i col %i\n", starting_row, starting_col);
    fprintf(f, "\n");

    for (int r = 0; r < board_row_size; ++r)
    {
        for (int c = 0; c < board_col_size; ++c)
        {
            fprintf(f, " %4d ", board[r][c]);
        }
        fprintf(f, "\n");
    }

    fprintf(f, "\n");
    fprintf(f, "\n");
    fprintf(f, "\n");
    fprintf(f, "\n");

    fclose(f);
    
}


std::pair<int, int> board_choice()
{
    std::cout << "How many rows would you like the board to have?" << std::endl;
    std::cout << ">> ";
    std::cin >> board_row_size;
    std::cout << "How many columns would you like the board to have?" << std::endl;
    std::cout << ">> ";
    std::cin >> board_col_size;
    std::cout << "What would you like the starting square to be?" << std::endl;
    std::cout << "Ex. If you want starting square to be in row 2, col 3, put \" 2 3 \"" << std::endl;
    std::cout << "Make sure it is in bounds!"  << std::endl;
    std::cout << ">> ";

    std::cin >> starting_row >> starting_col;

    return std::make_pair(starting_row, starting_col);
}