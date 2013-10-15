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
	// TODO: Can we pass some sort of state into each ShellAction? How
	//       can various ShellActions interact with each other?
	class ShellAction
	{
	public:
		/*
		 * An argList is a list of argument names, with a flag of whether or not
		 *  that argument is required.  The Shell will enforce the argument
		 *  requirement for you, but only by count.  You must, therefore,
		 *  place all required arguments at the beginning of the vector.  You can
		 *  then have as many optional arguments as you wish.
		 * Please note that arguments are not passed to run() in a named manner.
		 *  That is, the only correspondence between argList and the vector passed
		 *  to run() is index number.  Additionally, index 0 passed to run() will
		 *  always be the name of the command that's being run (either short name,
		 *  or full name).
		 */
		typedef std::vector<std::pair<std::string, bool> > argList;
		ShellAction(IShell* shell) { }	// By passing in the outer class, we can hold a state
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
