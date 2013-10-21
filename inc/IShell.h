/*
 * IShell.h
 */

#ifndef ISHELL_H_
#define ISHELL_H_

#include <vector>

class IShellAction;

class IShell
{
public:
	virtual std::vector<IShellAction*> getCmdList() = 0;
	virtual ~IShell() { }
};



#endif /* ISHELL_H_ */
