#include <iostream>
using namespace std;

void draw_triangle(int h) {
    int spaces {h};
    int symbols {1};

    cout << "---------------------------------" << "\n";
    cout << "triangle" << "\n";
    cout << "---------------------------------" << "\n";

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        for (int k = 0; k < symbols; k++) {
            cout << "*";
        }

        cout << "\n";
        symbols += 2;
        spaces -= 1;
    }
}

void draw_square(int side) {
    cout << "---------------------------------" << "\n";
    cout << "square" << "\n";
    cout << "---------------------------------" << "\n";

    for (int i = 0; i < side; i++) {
        cout << " ";
        for (int j = 0; j < side; j++) {
            cout << "*";
            cout << " ";
        }
        cout << "\n";
    }
}

void draw_rectangle(int height, int width) {
    cout << "---------------------------------" << "\n";
    cout << "rectangle" << "\n";
    cout << "---------------------------------" << "\n";

    for (int i = 0; i < height; i++) {
        cout << " ";
        for (int j = 0; j < width; j++) {
            cout << "*";
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    int height {0};
    int height2 {0};

    cout << "Enter vertical height: ";
    cin >> height;
    cout << "Enter horizontal size (for rectangle): ";
    cin >> height2;

    system("cls");

    draw_triangle(height);
    draw_square(height);
    draw_rectangle(height, height2);

    system("pause");
    return 0;
}
