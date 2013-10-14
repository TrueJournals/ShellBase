#include <Shell.h>
#include <IShell.h>

#include <iostream>

class DemoShell : public IShell
{
protected:
	class doTest : public ShellAction
	{
	protected:
		const argList args = { {"test", true} };
		const std::string cmdName = "doTest";
		const std::string shortCmd = "dt";
	public:
		virtual ~doTest() { }
		virtual int run(std::vector<std::string> &args)
		{
			std::cout << "Just a test" << std::endl;
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
	class doOther : public ShellAction
	{
	protected:
		const argList args = { {"one", true}, {"two", false} };
		const std::string cmdName = "doOther";
		const std::string shortCmd = "do";
	public:
		virtual ~doOther() { }
		virtual int run(std::vector<std::string> &args)
		{
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
	virtual std::vector<ShellAction*> getCmdList()
	{
		std::vector<ShellAction*> cmd_list;
		cmd_list.push_back(&cmd_test);
		cmd_list.push_back(&cmd_other);
		return cmd_list;
	}
	virtual ~DemoShell() { }
};

int main(int argc, char *argv[])
{
    DemoShell demoShell;
    Shell shell(demoShell, "demo");

    shell.run();
    
    return 0;
}

