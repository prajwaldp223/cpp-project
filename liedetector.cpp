#include <iostream>
#include <fstream>
#include <cstdlib> // Add this line for rand()
#include <ctime>   // Add this line for time()

using namespace std;

int main() {
    char playAgain;

    do {
        string txt;
        ifstream fil("file1.txt");
        ifstream file("file2.txt");

        int truth_lines = 0;
        int lies_lines = 0;

        while (getline(fil, txt)) {
            truth_lines++;
        }
        while (getline(file, txt)) {
            lies_lines++;
        }

        srand(time(0));
        int truthIndex1 = rand() % truth_lines;
        int truthIndex2 = rand() % truth_lines;
        int lieIndex = rand() % lies_lines;

        ifstream t("file1.txt");
        ifstream li("file2.txt");

        string truth1;
        string truth2;
        string lie;

        for (int i = 0; i <= max(truthIndex1, truthIndex2); i++) {
            string txt;
            getline(t, txt);

            if (i == truthIndex1) {
                truth1 = txt;
            } else if (i == truthIndex2) {
                truth2 = txt;
            }
        }

        for (int i = 0; i <= lieIndex; i++) {
            getline(li, lie);
        }

        int bullet = 1;
        int lieChecker;

        for (int i = 0; i <= max(truthIndex1, max(truthIndex2, lieIndex)); i++) {
            if (i == truthIndex1) {
                cout << bullet << " * " << truth1 << endl;
                bullet++;
            } else if (i == truthIndex2) {
                cout << bullet << " * " << truth2 << endl;
                bullet++;
            } else if (i == lieIndex) {
                lieChecker = bullet;
                cout << bullet << " * " << lie << endl;
                bullet++;
            }
        }

        cout << "enter your answer >> ";
        int ans;
        cin >> ans;

        if (ans == lieChecker) {
            cout << "you got the right answer!!\n";
        } else {
            cout << "better luck next time \n the correct answer is >>";
            cout << lie << endl;
        }

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing. Exiting the game." << endl;
    return 0;
}
