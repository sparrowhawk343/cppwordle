#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include "loader.h"


std::vector<std::string> word_list;


std::string Loader::GetWord()
{
	if (word_list.empty())
	{
		LoadWords();
	}
	return word_list[RandomizeIndex(0, word_list.size() - 1)];
}

void Loader::LoadWords()
{
	std::ifstream inputFile("words.txt");

	if (!inputFile)
	{
		std::cerr << "Text source file could not be found." << std::endl;
		return;
	}

	// add words to vector

	while (inputFile)
	{
		std::string stringInput;
		std::getline(inputFile, stringInput);
		word_list.push_back(stringInput);
	}
}

int Loader::RandomizeIndex(const int& min, const int& max)
{
	static thread_local std::mt19937 generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}