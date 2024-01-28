#include <iostream>
using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else 
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();
    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1) {
        PrintMessage("|", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }
    if (guessCount >= 2) {
        PrintMessage("|", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }
    if (guessCount >= 3) {
        PrintMessage("O", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }
    if (guessCount == 4) {
        PrintMessage("/", false, false);
    }
    if (guessCount == 5) {
        PrintMessage("/|", false, false);
    }
    if (guessCount >= 6) {
        PrintMessage("/|\\", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }
    if (guessCount >= 7) {
        PrintMessage("|", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }
    if (guessCount == 8) {
        PrintMessage("/", false, false);
    }
    if (guessCount >= 9) {
        PrintMessage("/ \\", false, false);
    }
    else {
        PrintMessage(" ", false, false);
    }

    PrintMessage("+----------+", false, false);
    PrintMessage("|          |", false, true);
    
}

void PrintLetters(string input) 
{
    PrintMessage("AVAILABLE LETTERS", false, false);
    string s1;
    for (char i = 'A'; i <= 'M'; i++)
    {
        if (input.find(i) == string::npos) {
            s1 += i;
            s1 += " ";
        }   
        else {
            s1 += "  ";
        }
    }
    PrintMessage(s1, false, false);
    string s2;
    for (char i = 'N'; i <= 'Z'; i++)
    {
        if (input.find(i) == string::npos) {
            s2 += i;
            s2 += " ";
        }
        else {
            s2 += "  ";
        }
    }
    PrintMessage(s2, false, false);
}

bool PrintWordAndCheckWin(string word, string guessed) 
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            s += "? ";
            won = false;
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false, true);
    return won;
}