/*
 * Add.h
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#ifndef ADD_H_
#define ADD_H_

#include <string>

#include <IShellAction.h>

class Calculator;

class Add: public IShellAction
{
public:
	Add(Calculator * outer);
	virtual ~Add();

	virtual int run();
	virtual std::string getHelp();
	virtual argList getArgList();
	virtual std::string getCmdName();
	virtual std::string getShortCmd();
};

#endif /* ADD_H_ */
