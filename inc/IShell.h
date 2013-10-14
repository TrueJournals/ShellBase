/*
 * IShell.h
 */

#ifndef ISHELL_H_
#define ISHELL_H_
#include <vector>
#include <string>
#include <algorithm>

class IShell
{
protected:
	class ShellAction
	{
	public:
		typedef std::vector<std::pair<std::string, bool> > argList;
		virtual ~ShellAction() { }
		virtual int run(std::vector<std::string> &args) = 0;
		virtual std::string getHelp() = 0;
		virtual argList getArgList() = 0;
		virtual std::string getCmdName() = 0;
		virtual std::string getShortCmd() = 0;
		// TODO: Could this be done with count_if instead? My initial tests didn't work
		virtual unsigned int numReqArgs() {
			argList args = this->getArgList();
			unsigned int count = 0;
			for(auto a : args)
			{
				if(a.second) ++count;
			}
			return count;
		}
	};

public:
	virtual std::vector<ShellAction*> getCmdList() = 0;
	virtual ~IShell() { }
};



#endif /* ISHELL_H_ */
