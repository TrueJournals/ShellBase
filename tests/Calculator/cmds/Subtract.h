/*
 * Subtract.h
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#ifndef SUBTRACT_H_
#define SUBTRACT_H_

#include <string>

#include <IShellAction.h>

class Calculator;

class Subtract: public IShellAction
{
public:
	Subtract(Calculator * outer);
	virtual ~Subtract();

	virtual int run();
	virtual std::string getHelp();
	virtual argList getArgList();
	virtual std::string getCmdName();
	virtual std::string getShortCmd();
};

#endif /* SUBTRACT_H_ */
