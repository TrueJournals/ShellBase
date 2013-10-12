/*
 * IShell.h
 */

#ifndef ISHELL_H_
#define ISHELL_H_
#include <vector>
#include <string>

class IShell
{
protected:
	class ShellAction
	{
	public:
		virtual ~ShellAction() { }
		virtual int run(std::vector<std::string> &args) = 0;
	};

	typedef struct
	{
		std::string command;
		std::string shortCmd;
		ShellAction* call;
		std::string help;
	} shellCmd;

public:
	virtual std::vector<shellCmd> getCmdList() = 0;
	virtual ~IShell() { }
};



#endif /* ISHELL_H_ */
