/*
 * Subtract.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#include <string>
#include <sstream>

#include <IShellAction.h>

#include "../Calculator.h"
#include "Subtract.h"

Subtract::Subtract(Calculator * outer) : IShellAction(outer)
{

}

Subtract::~Subtract()
{
}

int Subtract::run()
{
	int a = 0, b = 0;
	std::stringstream ssa;
	ssa << getArg("a");
	ssa >> a;
	std::stringstream ssb;
	ssb << getArg("b");
	ssb >> b;

	std::cout << (a - b) << std::endl;
	return 0;
}

std::string Subtract::getHelp()
{
	return "Performs a-b";
}

IShellAction::argList Subtract::getArgList()
{
	return {{"a", true}, {"b", true}};
}

std::string Subtract::getCmdName()
{
	return "subtract";
}

std::string Subtract::getShortCmd()
{
	return "-";
}
