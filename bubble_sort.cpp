#include <iostream>

using namespace std;

void ascending_order(int nums[10]) {
    int temp {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void descending_order(int nums[10]) {
    int temp {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (nums[j] < nums[j + 1]) {
                temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void only_even(int nums[10], int result[10], int &count) {
    count = 0;
    for (int i = 0; i < 10; i++) {
        if (nums[i] % 2 == 0) {
            result[count] = nums[i];
            count++;
        }
    }
}

void only_odd(int nums[10], int result[10], int &count) {
    count = 0;
    for (int i = 0; i < 10; i++) {
        if (nums[i] % 2 != 0) {
            result[count] = nums[i];
            count++;
        }
    }
}

int main() {
    srand(time(NULL));
    int numbers[10];
    int result[10];
    int count;
    int num_length {sizeof(numbers) / sizeof(numbers[0])};
    int choice {};

    for (int i = 0; i < num_length; i++) {
        numbers[i] = rand() % 10;
    }

    cout << "random numbers: " << endl;

    for (int i = 0; i < num_length; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    cout << "Display as: " << endl;
    cout << "1. Ascending order (low -> high)" << endl;
    cout << "2. Descending order (high -> low)" << endl;
    cout << "3. Show even numbers" << endl;
    cout << "4. Show odd numbers" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            ascending_order(numbers);

            for (int i = 0; i < num_length; i++) {
                cout << numbers[i] << " ";
            } 
            
            break;
        case 2:
            descending_order(numbers);

            for (int i = 0; i < num_length; i++) {
                cout << numbers[i] << " ";
            }

            break;
        case 3:
            only_even(numbers, result, count);

            for (int i = 0; i < count; i++) {
                cout << result[i] << " ";
            }

            break;
        case 4:
            only_odd(numbers, result, count);

            for (int i = 0; i < count; i++) {
                cout << result[i] << " ";
            }

            break;
        case 0:
            break;
        default:
            cout << "Error." << endl;
            break;
    }

    cout << endl;
    system("pause");

    return 0;
}

