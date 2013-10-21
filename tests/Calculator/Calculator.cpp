/*
 * Calculator.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#include <IShellAction.h>

#include "Calculator.h"

Calculator::Calculator() : cmd_add(this), cmd_subtract(this)
{

}

Calculator::~Calculator()
{
}

std::vector<IShellAction*> Calculator::getCmdList()
{
	return {&cmd_add, &cmd_subtract};
}
