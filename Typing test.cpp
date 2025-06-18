#include <iostream>
#include <string>
#include <ctime>
#include <thread>
using namespace std;

int main() {
    string original, typed;
    char choice;

    cout << "Typing Speed Test\n";

    do {
        cout << "\nEnter a sentence you'd like to practice:\n";
        getline(cin, original);

        while (true) {
            cout << "\nGet ready to type the sentence again:\n";
            cout << "\"" << original << "\"\n";

            cout << "\nStarting in:\n";
            for (int i = 3; i > 0; i--) {
                cout << i << "...\n";
                this_thread::sleep_for(chrono::seconds(1));
            }

            cout << "Start typing now:\n";

            clock_t start = clock();
            getline(cin, typed);
            clock_t end = clock();

            double timeTaken = double(end - start) / CLOCKS_PER_SEC;

            int wordCount = 1;
            for (int i = 0; i < typed.length(); i++) {
                if (typed[i] == ' ')
                    wordCount++;
            }

            int correctChars = 0;
            int length = min(original.length(), typed.length());
            for (int i = 0; i < length; i++) {
                if (original[i] == typed[i])
                    correctChars++;
            }

            float accuracy = (correctChars * 100.0) / original.length();
            float wpm = (wordCount / timeTaken) * 60;

            cout << "\n--- Result ---\n";
            cout << "Time Taken     : " << timeTaken << " seconds\n";
            cout << "Words Typed    : " << wordCount << "\n";
            cout << "Typing Speed   : " << wpm << " WPM\n";
            cout << "Accuracy       : " << accuracy << "%\n";

            if (wpm >= 40)
                cout << "Feedback       : Excellent speed!\n";
            else if (wpm >= 25)
                cout << "Feedback       : Good effort!\n";
            else
                cout << "Feedback       : Keep practicing!\n";

            cout << "\nDo you want to:\n";
            cout << "1. Try the same sentence again\n";
            cout << "2. Enter a new sentence\n";
            cout << "3. Exit\n";
            cout << "Enter your choice (1/2/3): ";
            int userChoice;
            cin >> userChoice;
            cin.ignore();

            if (userChoice == 1) {
                continue;
            } else if (userChoice == 2) {
                break;
            } else {
                cout << "\nThanks for using the Typing Speed Test!\n";
                return 0;
            }
        }

    } while (true);
}
