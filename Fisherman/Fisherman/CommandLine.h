#pragma once
#include <string>
#include <vector>


struct CommandArguments
{
	std::string command;
	std::vector <std::string> arguments;
};


class CommandLine
{
private:

	std::string command;
	std::vector<CommandArguments> listOfCommands;

public:

	CommandLine() {};
	~CommandLine() {};

	std::string getCommand() { return command; }
	std::vector<CommandArguments>& getListofCommands(){ return listOfCommands; }


	void receiveLineCommands();
};

