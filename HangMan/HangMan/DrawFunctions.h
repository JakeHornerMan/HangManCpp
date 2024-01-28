#pragma once
#include <iostream>
using namespace std;
void PrintMessage(string message, bool printTop = true, bool printBottom = true);
void DrawHangman(int guessCount = 0);
void PrintLetters(string input);
bool PrintWordAndCheckWin(string word, string guessed);
string LoadRandomWord(string path);
int TriesLeft(string word, string guessed);