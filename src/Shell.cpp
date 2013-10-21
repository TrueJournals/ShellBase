/**
 * ShellBase implementation
 */
 
#include <algorithm>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

extern "C" {
#include <readline/readline.h>
#include <stdlib.h>
}

#include <Shell.h>
#include <IShell.h>
#include <IShellAction.h>
 
Shell::Shell(IShell &shell, std::string prompt) : _shell(shell), _prompt(prompt),
		_exitWords({"exit", "quit"})
{

}

Shell::~Shell()
{

}

void Shell::run()
{
	int result = 0;
	while(result >= 0)
	{
		char * line = readline((_prompt + "> ").c_str());
		if(line == NULL)
		{
			std::cout << std::endl;
			break;
		}

		std::stringstream cmd_stream;
		cmd_stream.str(std::string(line));
		free(line);

		std::string cmd_part;
		std::vector<std::string> cmd_parts;
		// TODO: Arguments with quotes
		while(cmd_stream >> cmd_part)
		{
			cmd_parts.push_back(cmd_part);
		}

		if(cmd_parts.size() < 1) continue;

		// TODO: Handling of special commands, like "help"
		if(std::find(_exitWords.begin(), _exitWords.end(), cmd_parts.at(0)) != _exitWords.end())
			break;
		if(cmd_parts.at(0) == "help")
		{
			if(showHelp(cmd_parts) < 0)
			{
				std::cout << "No help found for '" << cmd_parts.at(0) << "'" << std::endl;
			}
			continue;
		}

		// TODO: History
		bool foundCmd = false;
		for(auto cmd : _shell.getCmdList())
		{
			if(cmd->getCmdName() == cmd_parts.at(0) ||
					cmd_parts.at(0) == cmd->getShortCmd())
			{
				foundCmd = true;
				if(cmd_parts.size() < cmd->numReqArgs()+1)
				{
					std::cout << "ERROR: Not enough arguments for " << cmd->getCmdName() << std::endl;
					break;
				}
				result = cmd->run(cmd_parts);
				break;
			}
		}

		if(!foundCmd)
			std::cout << "ERROR: Command '" << cmd_parts.at(0) << "' not found." << std::endl;
	}
}

int Shell::showHelp(std::vector<std::string> &args)
{
	if(args.size() == 1)
		return listAllCommands();
	else
		return commandHelp(args.at(1));
}

int Shell::listAllCommands()
{
	int count = 0;
	for(auto cmd : _shell.getCmdList())
	{
		std::cout << std::setw(20) << cmd->getCmdName();
		if(++count > 5) std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

int Shell::commandHelp(std::string &cmd)
{
	for(auto c : _shell.getCmdList())
	{
		if(c->getCmdName() == cmd || c->getShortCmd() == cmd)
		{
			if(c->getShortCmd().empty() == false)
				std::cout << "(" << c->getShortCmd() << ") ";
			std::cout << c->getCmdName() << " ";
			for(auto a : c->getArgList())
			{
				if(a.second == false) std::cout << "[";
				std::cout << a.first;
				if(a.second == false) std::cout << "]";
				std::cout << " ";
			}
			std::cout << std::endl;
			std::cout << c->getHelp() << std::endl;
			return 0;
		}
	}

	return -1;
}
