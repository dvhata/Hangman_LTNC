#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>

using namespace std;


string getHangPicture(int badGuessCount)
{
    string picture[] = { "",
"   ------------\n"
"   |           \n"
"   |           \n"
"   |           \n" 
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |          |\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",

    };
    return picture[badGuessCount];
}

void clearScreen()
{
#ifdef _WIN32
        system("cls");
#elif __linux__
        system("clear");
#endif // _WIN32

}

void renderGame(string guessedWord, int badGuessCount, string badGuess = "")
{
    clearScreen();
    cout << "Current guess = " << guessedWord << endl;
    cout << "You have made bad " << badGuessCount << " guess(es)"
        << (badGuess.empty() ? "" : ": ") << badGuess << endl
        << getHangPicture(badGuessCount) << endl;
}

const vector<string> HANGED = {
"   ------------\n"
"   |         /\n"
"   |        O\n"
"   |       /|\\\n"
"   |       / \\\n"
"   |         \n"
"   |         \n"
"   |         \n"
"   |         \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |           \\\n"
"   |            O\n"
"   |           /|\\\n"
"   |           / \\\n"
"   |             \n"
"   |             \n"
"   |             \n"
"   |             \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        "
};

const vector<string> DANCE = {
"       \n "
"   0   \n "
"  *|*  \n "
"  | |  \n"
"       \n",
"   0*  \n"
"  *|   \n"
"  | |  \n",
"       \n "
"  *0  \n"
"   |*  \n"
"  | |  \n",
"       \n "
"  *0*  \n"
"   |   \n"
"  | |  \n"
};

void printGameOverInfo(string guessedWord, string word, int badGuessCount)
{
    renderGame(guessedWord, badGuessCount);
    if (guessedWord != word) {
        int n = 0;
        int temp = 20 ;
        while (temp > 0) {
            clearScreen();
            cout << "Game Over!!! You are hanged" << endl
                << "The correct word is " << word << endl;
            cout << HANGED[n];
            n = (n + 1) % HANGED.size();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            temp = temp - 1;        }

    }
    else {
        int n = 0;
        int temp = 20;
        while (temp > 0) {
            clearScreen();
            cout << "Congrats!!! You are free" << endl
                 << "The correct word is " << word << endl;
            cout << DANCE[n];
            n = (n + 1) % DANCE.size();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            temp = temp - 1;
        }
    }
}

/*
const vector<string> plane1 = {
"                    ____._____\n",
"                   _______|_______\n",
"                  |               \\\n",
"                  |                \\\n",
"      ____________|                 \\\n",
" ____|       KHONG CO CHU NAO!!!!    |\n",
" |___________________________________|  \n",
};
const vector<string> plane2 = {

" |___________________________________|  \n",
};


string plane_string(int dem, int n)
{
    string s(1, ' ');
    s[0] = dem + '0';
    return "  ___|  There are " + s + " letters in word  |\n";
}

void planeRight(int dem)
{
    int a = 1;
    for (int n = 0; n < 40; ++n) {
        clearScreen();
        string s_count = plane_string(dem, n);
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < a; ++j) cout << " ";
            cout << plane1[i];
        }
        for (int j = 0; j < a; ++j) cout << " ";
        cout << s_count;
        for (int j = 0; j < a; ++j) cout << " ";
        cout << plane2[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        a += 2;
    }
}
void planeWrong()
{
    int a = 1;
    for (int n = 0; n < 40; ++n) {
        clearScreen();
        string s_count = plane_string(0, n);
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < a; ++j) cout << " ";
            cout << plane1[i];
        }
        for (int j = 0; j < a; ++j) cout << " ";
        cout << s_count;
        for (int j = 0; j < a; ++j) cout << " ";
        cout << plane2[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        a += 2;
    }
}

*/
