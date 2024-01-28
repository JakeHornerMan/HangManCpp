#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DrawFunctions.h"

string LoadRandomWord(string path) 
{
	int lineCount = 0;
	string word;
	vector<string> v;
	ifstream reader(path);
	if (reader.is_open())
	{
		while (std::getline(reader, word))
		{
			v.push_back(word);
		}

		int randomLine = rand() % v.size();
		word = v.at(randomLine);
		reader.close();
	}
	return word;
}

int TriesLeft(string word, string guessed) 
{
	int errors = 0;
	for (int i = 0; i < guessed.length(); i++)
	{
		if (word.find(guessed[i]) == string::npos)
		{
			errors++;
		}
	}
	return errors;
}