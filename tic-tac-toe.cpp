#include <iostream>
#include <random>
#include <ctime>

const int ROW = 3;
const int COL = 3;

void bot_move(std::string field[ROW][COL], int used_cells[9], int game_step) {
    int random_row, random_col, interpreted_choice;

    while (true) {
        random_row = rand() % 3;
        random_col = rand() % 3;
        
        if (field[random_row][random_col] != "x" && field[random_row][random_col] != "o") {
            field[random_row][random_col] = "o";
            if ((random_row == 0) && (random_col == 0)) {
                interpreted_choice = 0;
            }
            if ((random_row == 0) && (random_col == 1)) {
                interpreted_choice = 1;
            }
            if ((random_row == 0) && (random_col == 2)) {
                interpreted_choice = 2;
            }
            if ((random_row == 1) && (random_col == 0)) {
                interpreted_choice = 3;
            }
            if ((random_row == 1) && (random_col == 1)) {
                interpreted_choice = 4;
            }
            if ((random_row == 1) && (random_col == 2)) {
                interpreted_choice = 5;
            }
            if ((random_row == 2) && (random_col == 0)) {
                interpreted_choice = 6;
            }
            if ((random_row == 2) && (random_col == 1)) {
                interpreted_choice = 7;
            }
            if ((random_row == 2) && (random_col == 2)) {
                interpreted_choice = 8;
            }
            used_cells[game_step] = interpreted_choice;
            break;
        }
    }
}

void print_array(std::string field[ROW][COL]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

int choice_handler(int user_choice, int used_cells[9]) {
    bool is_a_good_choice = 0;

    std::cout << "Enter your move (0-8): ";

    while(!is_a_good_choice) {
        std::cin >> user_choice;

        if (user_choice < 0 || user_choice > 8) {
            std::cout << "Invalid choice! Enter 0-8: ";
            continue;
        }

        is_a_good_choice = 1;
        
        for (int i = 0; i < 9; i++) {
            if (user_choice == used_cells[i]) {
                std::cout << "Cell is occupied!" << std::endl;
                std::cout << "Try again: ";
                is_a_good_choice = 0;
                break;
            }
        }
    }
    
    return user_choice;
}

bool check_end(std::string field[ROW][COL], int used_cells[9]) {
    if (used_cells[8] != -1) {
        std::cout << "Draw" << std::endl;
        return 1;
    }

    if (field[0][0] == "x" && field[0][1] == "x" && field[0][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[1][0] == "x" && field[1][1] == "x" && field[1][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[2][0] == "x" && field[2][1] == "x" && field[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[0][0] == "x" && field[1][0] == "x" && field[2][0] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[0][1] == "x" && field[1][1] == "x" && field[2][1] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[0][2] == "x" && field[1][2] == "x" && field[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[0][0] == "x" && field[1][1] == "x" && field[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (field[0][2] == "x" && field[1][1] == "x" && field[2][0] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    }

    if (field[0][0] == "o" && field[0][1] == "o" && field[0][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[1][0] == "o" && field[1][1] == "o" && field[1][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[2][0] == "o" && field[2][1] == "o" && field[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[0][0] == "o" && field[1][0] == "o" && field[2][0] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[0][1] == "o" && field[1][1] == "o" && field[2][1] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[0][2] == "o" && field[1][2] == "o" && field[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[0][0] == "o" && field[1][1] == "o" && field[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (field[0][2] == "o" && field[1][1] == "o" && field[2][0] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    }

    return 0;
}

int main() {
    short int choice = -1;
    int game_step = 0;

    srand(time(NULL));

    std::string field[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            field[i][j] = ".";
        }
    }

    int used_cells[9];

    for (int i = 0; i < 9; i++) {
        used_cells[i] = -1;
    }

    while (true) {
        print_array(field);
        choice = choice_handler(choice, used_cells);

        used_cells[game_step] = choice;
        game_step++;

        switch(choice) {
            case(0):
                field[0][0] = "x";
                break;
            case(1):
                field[0][1] = "x";
                break;
            case(2):
                field[0][2] = "x";
                break;
            case(3):
                field[1][0] = "x";
                break;
            case(4):
                field[1][1] = "x";
                break;
            case(5):
                field[1][2] = "x";
                break;
            case(6):
                field[2][0] = "x";
                break;
            case(7):
                field[2][1] = "x";
                break;
            case(8):
                field[2][2] = "x";
                break;
            default:
                std::cout << "Wrong choice!" << std::endl;
        }

        if (check_end(field, used_cells)) {
            print_array(field);
            break;
        }

        bot_move(field, used_cells, game_step);
        game_step++;

        if (check_end(field, used_cells)) {
            print_array(field);
            break;
        }
    }

    return 0;
}
