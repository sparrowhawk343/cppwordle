#include <iostream>
#include <string>
#include "checker.h"
#include "loader.h"

std::string target_word;
std::string input_word;
int tries = 6;
Loader loader;
Checker checker;

void Reset();

int main()
{
	target_word = loader.GetWord();

	std::cout << "Welcome to CPPWordle." << std::endl;

	while (tries > 0)
	{
		std::cout << "Input your guess:" << std::endl;
		std::cin >> input_word;
		if (checker.CheckWord(input_word, target_word))
		{
			std::cout << "Congratulations, the correct word was " << target_word << " and you guessed right!" << std::endl;
			Reset();
		}
		tries--;

		if (tries == 0)
		{
			std::cout << "Uh oh. You ran out of tries. the word was " << target_word << "." << std::endl;
			Reset();
		}
	}

	return 0;
}

void Reset()
{
	while (true)
	{
		std::cout << "Would you like to try again with a new word? y / n" << std::endl;
		std::string response;
		std::cin >> response;
		if (response == "y")
		{
			target_word = loader.GetWord();
			tries = 6;
			break;
		}
		if (response == "n")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		std::cout << "That was not a valid input." << std::endl;
	}

}

