#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>
#include <string>
#include <conio.h>


#include "draw.h"
#include "utility.h"

using namespace std;

void openWelcome() {
    cout << "Welcome to     H    A    N    G    M    A    N  "<< endl;
    Sleep(1000);
    cout << "Hope you enjoy it!!! " << endl;
    Sleep(1000);
    cout << endl;
    cout << "Now let's start!" << endl;
    cout << "You have 2 levels:" << endl;
    cout << "--> Easy: Your guess word has < 5 characters " << endl;
    cout << "--> Diffcult: Your guess word >= 5 characters " << endl;
}

char chooseLevel() {
    cout << "Please choose the LEVEL you want (e/d):  ";
    char level;
    cin >> level;
    return level;
}

char readAGuess()
{
    char guess;
    cout << "Say ? if you want a hint " << endl;
    cout << "Please enter your next guess: ";
    cin >> guess;
    return guess;
}
 

void update(string& guessedWord, const string& word, char guess)
{
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guess)
            guessedWord[i] = guess;
    }
}

string suggest(const string &word, string &guessedWord) {
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (guessedWord[i] == '-') {
            guessedWord[i] = word[i];
            goto end;
        }       
    }
    end:;
    return guessedWord;
}

int showTopic() {
    cout << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Here are the topics we have, let's choose one you like: " << endl;
    cout << "Topic 1: FAMILY" << endl
         << "Topic 2: FRUIT" << endl
         << "Topic 3: VEGETABLE" << endl
         << "Topic 4: FOOD" << endl
         << "Topic 5: SUBJECT" << endl
         << "Topic 6: VEHICLE" << endl
         << "Topic 7: COLOR" << endl
         << "Topic 8: FILM" << endl;
    cout << "Your topic you choose is: Topic " ;
    int n;
    cin >> n;
    return n;
}

string chooseTopic (int n) {
    if (n == 1) return "Vocab - Family.txt";
    if (n == 2) return "Vocab - Fruit.txt";
    if (n == 3) return "Vocab - Vegetable.txt";
    if (n == 4) return "Vocab - Food.txt";
    if (n == 5) return "Vocab - Subject.txt";
    if (n == 6) return "Vocab - Vehicle.txt";
    if (n == 7) return "Vocab - Color.txt";
    if (n == 8) return "Vocab - Film.txt";
}


int main(int argc, char* argv[])
{
    int countWin = 0, countLost = 0;
    openWelcome();
    Sleep(3000);
    srand(time(0));
    while (true) {
        int n = showTopic();
        string fileName = argc > 1 ? argv[1] : chooseTopic(n);
        string word = chooseWord(fileName);
        int lengthWord = word.length();
        char level = chooseLevel();
        if (level == 'e') {
            while (lengthWord > 5) {
                word = chooseWord(fileName);
                lengthWord = word.length();
            }
        }
        if (level == 'd') {
            while (lengthWord <= 5) {
                word = chooseWord(fileName);
                lengthWord = word.length();
            }
        }
        if (word.empty()) {
            cout << "No word available in " << fileName << endl;
            return 0;
        }
        string guessedWord = string(word.length(), '-');
        int badGuessCount = 0;
        const int MAX_BAD_GUESS = 7;
        string badGuess;
        int length = lengthWord / 2;
        do {

            renderGame(guessedWord, badGuessCount, badGuess);
            char guess = readAGuess();

            if (guess == '?') {
                if (length > 0) {
                    cout << suggest(word, guessedWord);
                    cout << "There are " << length - 1 << " hint(s) left";
                    Sleep(1000);
                }
                if (length <= 0) {
                    cout << "There is no hint left. Fighting!!!" << endl;
                    Sleep(1000);
                }
                length--;
            } else {
                if (contains(word, guess)) {
                    update(guessedWord, word, guess);
                }
                else {
                    badGuessCount++;
                    badGuess = badGuess + guess + " , ";
                }
            }
        end:;
        } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word);

        if (guessedWord == word) {
            countWin++;
        }
        else {
            countLost++;
        }

        printGameOverInfo(guessedWord, word, badGuessCount);
        cout << endl;
        cout << "Do you want more (Y/N) ? ";
        string answer;
        cin.ignore(1);
        getline(cin, answer);
        if (answer != "Y" && answer != "y") {
            cout << endl;
            cout << "W I N: " << countWin << endl;
            cout << "L O S E: " << countLost << endl;
            cout << endl;

            cout << "-----------------------------------------" << endl;

            cout << "Good bye and thank you for playing me!" << endl;

            cout << "-----------------------------------------";
            Sleep(500);
            break;
        }      
    }

    return 0;
} 

/*
else {
            cout << "Do you want to change the topic: (Y/N) ";
            char rep;
            cin >> rep;
            if (rep == 'Y' || rep == 'y') {
                int n = showTopic();
                srand(time(0));
                string fileName = argc > 1 ? argv[1] : chooseTopic(n);
            }
        }
*/


/*
void statistic(int countWin, int countLost, string guessedWord, string word) {
    (guessedWord == word) ? countWin++ : countLost++;
    cout << "W I N: " << countWin << endl;
    cout << "L O S E: " << countLost << endl;
}

*/