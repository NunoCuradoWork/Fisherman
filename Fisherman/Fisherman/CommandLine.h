#pragma once
#include <string>
#include <vector>
#include <sstream>

class CommandLine
{
private:

	std::string command;
	std::vector<std::string> listOfCommands;

public:

	CommandLine() {};
	~CommandLine() {};

	std::string getCommand() { return command; }
	std::vector<std::string>& getListofCommands(){ return listOfCommands; }

};