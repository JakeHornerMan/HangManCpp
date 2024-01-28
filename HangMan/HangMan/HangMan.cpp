#include <iostream>
#include <time.h>
#include "DrawFunctions.h"
using namespace std;

int main()
{
    srand(time(0));
    string guesses = "";
    string word;
    word = LoadRandomWord("words.txt");

    int errors = 0;
    bool win = false;

    do
    {
        system("cls");
        PrintMessage(word);
        PrintMessage("HANG MAN");
        DrawHangman(errors);
        PrintLetters(guesses);
        PrintMessage("GUESS THE WORD");
        win = PrintWordAndCheckWin(word, guesses);

        if (win)
            break;

        char x;
        cout << ">"; 
        cin >> x;
        x = (char)toupper(x);
        if (guesses.find(x) == string::npos)
        {
            guesses += x;
        }
        errors = TriesLeft(word, guesses);

    } while (errors < 10);

    if (win)
    {
        PrintMessage("YOU WON!");
    }
    else
    {
        PrintMessage("YOU LOST!");
    }

    /*PrintMessage("HANG MAN");
    DrawHangman(errors);
    PrintLetters(guesses);
    PrintMessage("GUESS THE WORD");
    PrintWordAndCheckWin(word, guesses);*/
}


/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
>
*/
