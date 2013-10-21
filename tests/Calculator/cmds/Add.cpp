/*
 * Add.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#include <sstream>
#include <string>

#include <IShellAction.h>

#include "../Calculator.h"
#include "Add.h"

Add::Add(Calculator * outer) : IShellAction(outer)
{

}

Add::~Add()
{
}

int Add::run()
{
	int a = 0, b = 0;
	// Workaround because cygwin on Windows doesn't have stoi :(
	std::stringstream ssa;
	ssa << getArg("a");
	ssa >> a;

	std::stringstream ssb;
	ssb << getArg("b");
	ssb >> b;

	std::cout << (a + b) << std::endl;
	return 0;
}

std::string Add::getHelp()
{
	return "Adds a, b and returns the result.";
}

IShellAction::argList Add::getArgList()
{
	return {{"a", true}, {"b", true}};
}

std::string Add::getCmdName()
{
	return "add";
}

std::string Add::getShortCmd()
{
	return "+";
}
