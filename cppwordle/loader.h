#pragma once
#include <vector>
class Loader
{
	std::vector<std::string> word_list;

public:
	std::string GetWord();
private:
	void LoadWords();
	int RandomizeIndex(const int& min, const int& max);
};