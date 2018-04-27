// #include "knightstour.h"
// #include <iostream>

// //Note
// //
// //

// void test_next_move()
// {

//     //Board 1
//     // 
//     //  General test.
//     //    - one open square

//     int b1[8][8] =
//         {
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, -1, 15, -1, 15, 15},
//             {15, 15, 99, 15, 15, 15, -1, 15},
//             {15, 15, 15, 15, -1, 15, 15, 15},
//             {15, 15, -1, 15, 15, 15, -1, 15},
//             {15, 15, 15, -1, 15, -1, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15}};

//     std::vector<std::pair<int, std::pair<int, int> > > moves_row2_col2_1 = possible_moves(2, 2, b1);

//     std::cout << "For move possible moves from (2,2) we have: " << std::endl;
//     std::cout << "----------------------------------------------" << std::endl;

//     for (std::vector<std::pair<int, std::pair<int, int> > >::iterator i = moves_row2_col2_1.begin(); i != moves_row2_col2_1.end(); ++i)
//     {
//         std::cout << "Square (" << i->second.first << ", " << i->second.second << ") with degree " << i->first << std::endl;
//     }

//     std::cout << std::endl;


//     //Board 2
//     // 
//     //  General test.
//     //     - two open squares

//     int b2[8][8] =
//         {
//             {15, 15, -1, 15, 15, 15, -1, 15},
//             {-1, 15, 15, 15, -1, 15, 15, 15},
//             {15, 15, 99, 15, 15, 15, 15, 15},
//             {15, -1, 15, 15, -1, 15, 15, 15},
//             {15, 15, -1, 15, 15, 15, -1, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15}};

//     std::vector<std::pair<int, std::pair<int, int> > > moves_row2_col2_2 = possible_moves(2, 2, b2);

//     std::cout << "For move possible moves from (2,2) we have: " << std::endl;
//     std::cout << "----------------------------------------------" << std::endl;

//     for (std::vector<std::pair<int, std::pair<int, int> > >::iterator i = moves_row2_col2_2.begin(); i != moves_row2_col2_2.end(); ++i)
//     {
//         std::cout << "Square (" << i->second.first << ", " << i->second.second << ") with degree " << i->first << std::endl;
//     }

//     std::cout << std::endl;

//     //Board 3
//     // 
//     //  General test.
//     //     - multiple open squares

//     int b3[8][8] =
//         {
//             {15, 15, -1, 15, 15, 15, -1, 15},
//             {-1, 15, 15, 15, -1, 15, 15, 15},
//             {15, 15, 99, 15, 15, 15, 15, 15},
//             {-1, -1, 15, 15, -1, 15, 15, 15},
//             {15, 15, -1, 15, 15, 15, -1, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15}};

//     std::vector<std::pair<int, std::pair<int, int> > > moves_row2_col2_3 = possible_moves(2, 2, b3);

//     std::cout << "For move possible moves from (2,2) we have: " << std::endl;
//     std::cout << "----------------------------------------------" << std::endl;

//     for (std::vector<std::pair<int, std::pair<int, int> > >::iterator i = moves_row2_col2_3.begin(); i != moves_row2_col2_3.end(); ++i)
//     {
//         std::cout << "Square (" << i->second.first << ", " << i->second.second << ") with degree " << i->first << std::endl;
//     }

//     std::cout << std::endl;


//     //Board 4
//     // 
//     //  General test.
//     //     - 0 open squares

//     int b4[8][8] =
//         {
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 99, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15},
//             {15, 15, 15, 15, 15, 15, 15, 15}};

//     std::vector<std::pair<int, std::pair<int, int> > > moves_row2_col2_4 = possible_moves(2, 2, b4);

//     std::cout << "For move possible moves from (2,2) we have: " << std::endl;
//     std::cout << "----------------------------------------------" << std::endl;

//     for (std::vector<std::pair<int, std::pair<int, int> > >::iterator i = moves_row2_col2_4.begin(); i != moves_row2_col2_4.end(); ++i)
//     {
//         std::cout << "Square (" << i->second.first << ", " << i->second.second << ") with degree " << i->first << std::endl;
//     }

//     std::cout << std::endl;


//     //Board 5
//     // 
//     //  General test.
//     //     - 8 open squares

//     int b5[8][8] =
//         {
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, 99, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1},
//             {-1, -1, -1, -1, -1, -1, -1, -1}};

//     std::vector<std::pair<int, std::pair<int, int> > > moves_row2_col2_5 = possible_moves(2, 2, b5);

//     std::cout << "For move possible moves from (2,2) we have: " << std::endl;
//     std::cout << "----------------------------------------------" << std::endl;

//     for (std::vector<std::pair<int, std::pair<int, int> > >::iterator i = moves_row2_col2_5.begin(); i != moves_row2_col2_5.end(); ++i)
//     {
//         std::cout << "Square (" << i->second.first << ", " << i->second.second << ") with degree " << i->first << std::endl;
//     }

//     std::cout << std::endl;

//     print_board(b5);
// }

// int main()
// {


//     test_next_move();
//     //int board[NUM_ROWS][NUM_COLS];
//     //initialize_board(board);
// }