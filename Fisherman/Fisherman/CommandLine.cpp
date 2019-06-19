#include "CommandLine.h"
#include <iostream>
#include <sstream>



void CommandLine::receiveLineCommands()
{
	std::string input;
	listOfCommands.clear();
	
	while (input.compare("prox") != 0)
	{
		CommandArguments auxData;
		std::getline(std::cin, input);
		std::stringstream ss(input);

		bool auxCounter = true;

		while (std::getline(ss, input, ' '))
		{
			if (auxCounter)
			{
				auxData.command = input.substr(0);
				auxCounter = false;
			}
			else
				auxData.arguments.push_back(input);
		
		}
		listOfCommands.push_back(auxData);
	}
}