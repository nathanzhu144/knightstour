#include "knightstour.h"
#include <fstream>

void print_menu()
{
    std::cout << "Welcome to the Knight's Path simulation." << std::endl;
    std::cout << "  1. Simulate a path in terminal." << std::endl;
    std::cout << "  2. Simulate a path and write it to a file. " << std::endl;
    std::cout << "  3. Quit the simulation." << std::endl;
    std::cout << ">> ";
}

int get_input()
{
    int temp = 0;
    std::cin >> temp;
    return temp;
}

int main()
{
    int menu_choice = 0;

    int board[MAX_NUM_ROWS][MAX_NUM_COLS];
    initialize_board(board);

    while (menu_choice != 3)
    {
        print_menu();

        menu_choice = get_input();

        if (menu_choice == 1)
        {
            std::pair<int, int> first_move;
            first_move = board_choice();
            initialize_board(board);
            board[first_move.first][first_move.second] = 0;

            if (kt_utility(first_move.first, first_move.second, 0, board))
            {
                std::cout << std::endl;
                print_board(board);
                std::cout << std::endl;
            }
            else
            {
                std::cout << "There is no solution." << std::endl;
                std::cout << std::endl;
            }
        }
        if (menu_choice == 2)
        {
            std::string file_name;
            std::string append_choice;
            bool append = true;

            std::pair<int, int> first_move;
            first_move = board_choice();
            initialize_board(board);
            board[first_move.first][first_move.second] = 0;

            std::cout << "What would you like the filename to be?" << std::endl;
            std::cout << ">> ";
            std::cin >> file_name;
            std::cout << "Would you like to append to the file or overwrite it?" << std::endl;
            std::cout << "Press 'o' to overwrite or anything else to append to it." << std::endl;
            std::cout << ">> ";
            std::cin >> append_choice;

            //overwrite file
            if (append_choice == "O" || append_choice == "o")
            {
                if (kt_utility(first_move.first, first_move.second, 0, board))
                {
                    std::cout << std::endl;
                    std::cout << "Successfully wrote to " << file_name << std::endl;
                    std::cout << std::endl;
                    print_board_to_file(file_name, false, board);
                }
                else
                {
                    std::cout << "There is no solution." << std::endl;
                    std::cout << std::endl;
                }
            }
            //append to file
            else
            {
                if (kt_utility(first_move.first, first_move.second, 0, board))
                {
                    std::cout << std::endl;
                    std::cout << "Successfully wrote to " << file_name << std::endl;
                    std::cout << std::endl;
                    print_board_to_file(file_name, true, board);
                }
                else
                {
                    std::cout << "There is no solution." << std::endl;
                    std::cout << std::endl;
                }
            }
        }

        if (menu_choice == 3)
        {
            break;
        }

        initialize_board(board);
    }

    return 0;
}