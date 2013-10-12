#include <Shell.h>
#include <IShell.h>

#include <iostream>

class DemoShell : public IShell
{
protected:
	class doTest : public ShellAction
	{
	public:
		virtual ~doTest() { }
		virtual int run(std::vector<std::string> &args)
		{
			std::cout << "Just a test" << std::endl;
			return 0;
		}
	};
	class doOther : public ShellAction
	{
	public:
		virtual ~doOther() { }
		virtual int run(std::vector<std::string> &args)
		{
			std::cout << "Another function" << std::endl;
			return 0;
		}
	};

	doTest cmd_test;
	doOther cmd_other;

public:
	virtual std::vector<shellCmd> getCmdList()
	{
		std::vector<shellCmd> cmd_list;
		shellCmd cmd;
		cmd.command = "test";
		cmd.shortCmd = "t";
		cmd.call = &cmd_test;
		cmd.help = "Just a test\n";
		cmd_list.push_back(cmd);

		cmd.command = "other";
		cmd.shortCmd = "o";
		cmd.call = &cmd_other;
		cmd.help = "Another function\n";
		cmd_list.push_back(cmd);
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

