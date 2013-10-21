/*
 * IShellAction.h
 *
 *  Created on: Oct 20, 2013
 *      Author: Bobby
 */

#ifndef ISHELLACTION_H_
#define ISHELLACTION_H_

#include <algorithm>
#include <vector>
#include <string>
#include <utility>

#include <iostream>

class IShell;

// TODO: Can we pass some sort of state into each ShellAction? How
//       can various ShellActions interact with each other?
class IShellAction
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

	IShellAction(IShell* shell) : outer(shell) { }	// By passing in the outer class, we can hold a state
	virtual ~IShellAction() { }

	/**
	 * run() is the main processing function for this command.  It can call other functions,
	 * interact with outer, print to stdout or stderr, read from stdin, etc.  Basically, run
	 * will have complete execution control of the application.
	 *
	 * Run can retrieve arguments directly from this->args if you wish, but it's recommended
	 * to use the helper functions getArg.  With getArg, you can either pass an index or an
	 * argument's name (as defined in the argList given by getArgList())
	 */
	virtual int run() = 0;
	virtual std::string getHelp() = 0;
	virtual argList getArgList() = 0;
	virtual std::string getCmdName() = 0;
	virtual std::string getShortCmd() = 0;

	// TODO: Could this be done with count_if instead? My initial tests didn't work
	virtual unsigned int numReqArgs() {
		argList args = this->getArgList();
		return std::count_if(args.begin(), args.end(),
				[](std::pair<std::string, bool> a) { return a.second; });
	}

	virtual void setArgs(std::vector<std::string> &args) {
		this->shell_args = args;
	}

	/**
	 * getArg() helper functions
	 * These functions will help run() to retrieve arguments from the list.  Note that
	 * the list of arguments is 0-indexed, and that the 0th argument is the name of the
	 * command being run.  Due to the way the shell works, this may be either the short
	 * command OR the long command.
	 */
	virtual std::string getArg(std::vector<std::string>::size_type n) {
		return shell_args[n];
	}

	virtual std::string getArg(std::string arg_name) {
		argList arg_list = getArgList();
		argList::size_type arg_index;
		for(arg_index = 0; arg_index < getArgList().size(); ++arg_index) {
			if(arg_list[arg_index].first == arg_name)
				break;
		}
		/**
		 * Because getArgList does not contain the "command name" argument, we must
		 * increment the arg index by one here.  This accounts for the offset that
		 * makes up the command name, and makes up for the index difference between
		 * getArgList and the actual shell_args vector
		 */
		++arg_index;
		if(arg_index >= this->shell_args.size()) throw 1;	// TODO: Exception class

		return this->shell_args[arg_index];
	}

protected:
	std::vector<std::string> shell_args;
	IShell* outer;
};

#endif /* ISHELLACTION_H_ */
