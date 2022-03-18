#include "checker.h"
#include "textColor.h"
#include <iostream>
#include <map>
#include <sstream>

std::map<char, int> duplicateMap;

bool Checker::CheckWord(const std::string& input, const std::string& target)
{
	const char* target_string = target.c_str();
	const char* input_string = input.c_str();
	std::stringstream output_string;
	int correct_chars = 0;

	AddToDuplicateMap(target);

	for (int i = 0; i < 5; i++)
	{
		if (input_string[i] == target_string[i] || std::toupper(input_string[i]) == target_string[i])
		{
			duplicateMap[input_string[i]]--;
			correct_chars++;
		}
	}

	// loop to 5 because all words in Wordle have a length of 5 (plus null terminator)
	for (int i = 0; i < 5; i++)
	{
		if (input_string[i] == target_string[i] || std::toupper(input_string[i]) == target_string[i])
		{
			// char is flagged as green (is contained in target string, in correct spot)
			output_string << BACKGROUND(BackgroundColor::Green, input_string[i]);
		}
		else if (duplicateMap[input_string[i]] != 0)
		{
			// char is flagged as yellow (is contained in target string, but in a different spot)
			duplicateMap[input_string[i]]--;
			output_string << BACKGROUND(BackgroundColor::Yellow, input_string[i]);
		}
		else
		{
			// char is flagged as grey (is not contained in target string)
			output_string << BACKGROUND(BackgroundColor::BrightBlack, input_string[i]);
		}
	}
	std::cout << output_string.str() << std::endl;
	std::cout << std::endl;
	if (correct_chars == 5)
	{
		return true;
	}
	return false;
}


void Checker::AddToDuplicateMap(std::string toAdd)
{

	for (char letter : toAdd)
	{
		if (duplicateMap.find(letter) != duplicateMap.end())
		{
			duplicateMap[letter]++;
		}
		else
		{
			duplicateMap.insert({ letter, 1 });
		}
	}
}
