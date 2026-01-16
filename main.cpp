#include <iostream>
#include <random>
#include <ctime>

const int ROW = 3;
const int COL = 3;

void enemy_move(std::string arr[ROW][COL], int used[9], int step) {
    int r;
    int c;
    int choice;

    while (true) {
        r = rand() % 3;
        c = rand() % 3;
        
        if (arr[r][c] != "x" && arr[r][c] != "o") {
            arr[r][c] = "o";
            if ((r == 0) && (c == 0)) {
                choice = 0;
            }
            if ((r == 0) && (c == 1)) {
                choice = 1;
            }
            if ((r == 0) && (c == 2)) {
                choice = 2;
            }
            if ((r == 1) && (c == 0)) {
                choice = 3;
            }
            if ((r == 1) && (c == 1)) {
                choice = 4;
            }
            if ((r == 1) && (c == 2)) {
                choice = 5;
            }
            if ((r == 2) && (c == 0)) {
                choice = 6;
            }
            if ((r == 2) && (c == 1)) {
                choice = 7;
            }
            if ((r == 2) && (c == 2)) {
                choice = 8;
            }
            used[step] = choice;
            break;
        }
    }
}

void print_arr(std::string arr[ROW][COL]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

int choice_(int choice, int arr[9]) {
    bool good = 0;
    std::cout << "Enter your move (0-8): ";
    while(!good) {
        std::cin >> choice;

        if (choice < 0 || choice > 8) {
            std::cout << "Invalid choice! Enter 0-8: ";
            continue;
        }

        good = 1;
        
        for (int i = 0; i < 9; i++) {
            if (choice == arr[i]) {
                std::cout << "Cell is occupied!" << std::endl;
                std::cout << "Try again: ";
                good = 0;
                break;
            }
        }
    }
    
    return choice;
}

bool check_win(std::string arr[ROW][COL], int used[9]) {
    if (used[8] != -1) {
        std::cout << "Draw" << std::endl;
        return 1;
    }

    if (arr[0][0] == "x" && arr[0][1] == "x" && arr[0][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[1][0] == "x" && arr[1][1] == "x" && arr[1][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[2][0] == "x" && arr[2][1] == "x" && arr[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[0][0] == "x" && arr[1][0] == "x" && arr[2][0] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[0][1] == "x" && arr[1][1] == "x" && arr[2][1] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[0][2] == "x" && arr[1][2] == "x" && arr[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[0][0] == "x" && arr[1][1] == "x" && arr[2][2] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    } else if (arr[0][2] == "x" && arr[1][1] == "x" && arr[2][0] == "x") {
        std::cout << "X won" << std::endl;
        return 1;
    }

    if (arr[0][0] == "o" && arr[0][1] == "o" && arr[0][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[1][0] == "o" && arr[1][1] == "o" && arr[1][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[2][0] == "o" && arr[2][1] == "o" && arr[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[0][0] == "o" && arr[1][0] == "o" && arr[2][0] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[0][1] == "o" && arr[1][1] == "o" && arr[2][1] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[0][2] == "o" && arr[1][2] == "o" && arr[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[0][0] == "o" && arr[1][1] == "o" && arr[2][2] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    } else if (arr[0][2] == "o" && arr[1][1] == "o" && arr[2][0] == "o") {
        std::cout << "O won" << std::endl;
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    short int choice;
    bool winner = 0;
    int step = 0;

    std::string arr[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = ".";
        }
    }

    int used_nums[9];

    for (int i = 0; i < 9; i++) {
        used_nums[i] = -1;
    }

    while (!winner) {
        print_arr(arr);
        choice = choice_(choice, used_nums);

        used_nums[step] = choice;
        step++;

        switch(choice) {
            case(0):
                arr[0][0] = "x";
                break;
            case(1):
                arr[0][1] = "x";
                break;
            case(2):
                arr[0][2] = "x";
                break;
            case(3):
                arr[1][0] = "x";
                break;
            case(4):
                arr[1][1] = "x";
                break;
            case(5):
                arr[1][2] = "x";
                break;
            case(6):
                arr[2][0] = "x";
                break;
            case(7):
                arr[2][1] = "x";
                break;
            case(8):
                arr[2][2] = "x";
                break;
            default:
                std::cout << "Wrong choice!" << std::endl;
        }

        if (check_win(arr, used_nums)) {
            winner = 1;
            print_arr(arr);
            break;
        }

        enemy_move(arr, used_nums, step);
        step++;

        if (check_win(arr, used_nums)) {
            winner = 1;
            print_arr(arr);
        }
    }
    system("pause");
    return 0;
}