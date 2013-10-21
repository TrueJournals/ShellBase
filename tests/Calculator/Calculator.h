/*
 * Calculator.h
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <IShell.h>

#include "cmds/Add.h"
#include "cmds/Subtract.h"

class IShellAction;

class Calculator: public IShell
{
public:
	Calculator();
	virtual ~Calculator();

	virtual std::vector<IShellAction*> getCmdList();

private:
	Add cmd_add;
	Subtract cmd_subtract;
};

#endif /* CALCULATOR_H_ */
