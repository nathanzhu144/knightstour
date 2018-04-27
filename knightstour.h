#include <iostream>
#include <string>       //for std::string
#include <utility>      //for std::pair
#include <algorithm>    //for std::sort
#include <vector>       //for std::vector
#include <map>          //for std::map
#include <fstream>      //for std::ofstream
#include <stdio.h>      // for printf

//Number of rows and cols of board
const int MAX_NUM_ROWS = 210;
const int MAX_NUM_COLS = 210;
const int NUM_MOVES = 8;
static int board_row_size;
static int board_col_size;
static int starting_row;
static int starting_col;

static int row_change[NUM_MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
static int col_change[NUM_MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};


//Board setup functions//


//Requires: Nothing.
//Modifies: board
//Effects:  Sets all indices of board to -1
void initialize_board(int board[MAX_NUM_ROWS][MAX_NUM_COLS]);


//Misc helper functions//

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Checks if a location is off the board or already has been used before.
//          Returns false if either is true.
bool is_move_good(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Finds the degree of a node.  Degree is defined as number of possible
//          moves that a chess piece can make.
int find_degree_of_node(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);

//Requires: Nothing.
//Modifies: Nothing.
//Effects:  If move is good, makes a move on that square, marking it with the number
//          of moves done.
void make_move(int row, int col, int num, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);


//Requires: Nothing.
//Modifies: Nothing.
//Effects:  Returns a vector of pairs<int, std::pair<int, int > > of possible 
//          moves in form of (degree, coordinate).
//          Does not include moves to a node with 0 degrees.  
//
//          first = degree after a move
//          second = move position in std::pair(int row, int col)
//
//Note:     This uses the Warnsdorff's heurstic.  It chooses the next open position
//          with the fewest number of moves from that position.

std::vector<std::pair<int, std::pair<int, int> > > possible_moves(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);



//Requires: All squares to be moved on except for one.
//Modifies: Nothing.
//Effects:  Finds last move in the form std::pair(int row, int col).  Since possible_moves returns 
//          an empty vector on the last move before completing a board, as the last move will be to a 
//          position of degree 0.
//
//          Returns -1, -1 if cannot find a solution.  i.e. knight cannot move to any spaces.
//

std::pair<int, int> last_move(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);


//Menu functions//


//Requires: Nothing.
//Modifies: Nothing
//Effects:  Prints board in standard output to terminal.
void print_board(const int board[MAX_NUM_ROWS][MAX_NUM_COLS]);



//Requires: Nothing.
//Modifies: Nothing
//
//Effects:  Prints board in to file.  Overwrites file if it exists already.  If append flag is true
//          append to the file.  Otherwise, write over original file.
//
void print_board_to_file(std::string file_name_in, bool append, const int board[MAX_NUM_ROWS][MAX_NUM_COLS]);


//Requires: valid numerical input
//          input for starting position has to be in bounds
//Modifies: 
//          static int board_row_size;
//          static int board_col_size;
//          static int starting_row;
//          static int starting_col;
//Effects:  Returns a pair (int row, int col) representing starting position of first move.

std::pair<int, int> board_choice();

void kt(int row, int col, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);

bool kt_utility(int row, int col, int num_moves_made_already, int board[MAX_NUM_ROWS][MAX_NUM_COLS]);


