#pragma once
#include <map>
#include <string>

class Checker
{
	std::map<char, int> duplicateMap;
public:
	bool CheckWord(const std::string& input, const std::string& target);
private:
	void AddToDuplicateMap(std::string toAdd);
};

