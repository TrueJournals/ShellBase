#include <Shell.h>
#include <IShell.h>
#include <IShellAction.h>

#include <iostream>
#include <string>
#include <sstream>

class DemoShell : public IShell
{
protected:
	class doTest : public IShellAction
	{
	private:
		DemoShell *shell;
	protected:
		const argList args = { {"test", true} };
		const std::string cmdName = "doTest";
		const std::string shortCmd = "dt";
	public:
		doTest(DemoShell *outer) : IShellAction(outer), shell(outer) { }
		virtual ~doTest() { }
		virtual int run()
		{
			std::cout << "Just a test" << std::endl;
			std::cout << "Number: " << shell->number << std::endl;
			return 0;
		}
		virtual std::string getHelp()
		{
			return "Just a test function";
		}
		virtual argList getArgList() { return args; }
		virtual std::string getCmdName() { return cmdName; }
		virtual std::string getShortCmd() { return shortCmd; }
	};
	class doOther : public IShellAction
	{
	private:
		DemoShell *shell;
	protected:
		const argList args = { {"one", true}, {"two", true} };
		const std::string cmdName = "doOther";
		const std::string shortCmd = "do";
	public:
		doOther(DemoShell *outer) : IShellAction(outer), shell(outer) { }
		virtual ~doOther() { }
		virtual int run()
		{
			std::stringstream ss;
			ss << this->getArg("one");
			ss >> shell->number;

			std::cout << "Another function" << std::endl;
			return 0;
		}
		virtual std::string getHelp()
		{
			return "Test function number 2";
		}
		virtual argList getArgList() { return args; }
		virtual std::string getCmdName() { return cmdName; }
		virtual std::string getShortCmd() { return shortCmd; }
	};

	doTest cmd_test;
	doOther cmd_other;

public:
	DemoShell() : cmd_test(this), cmd_other(this), number(5) { }
	virtual std::vector<IShellAction*> getCmdList()
	{
		std::vector<IShellAction*> cmd_list;
		cmd_list.push_back(&cmd_test);
		cmd_list.push_back(&cmd_other);
		return cmd_list;
	}
	virtual ~DemoShell() { }
	int number;
};

int main(int argc, char *argv[])
{
    DemoShell demoShell;
    Shell shell(demoShell, "demo");

    shell.run();
    
    return 0;
}

