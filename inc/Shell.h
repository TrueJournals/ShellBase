/**
 * A base class for writing a wide variety of shell-like programs.
 * Still under heavy planning and development.
 */
#ifndef SHELL_H_
#define SHELL_H_

#include <string>
#include <IShell.h>

class Shell
{
public:
    Shell(IShell & shell, std::string prompt);
    ~Shell();
    void setPrompt(std::string prompt);
    std::string getPrompt();
    void run();
    void setExitWords(std::vector<std::string> &words);
    
private:
    IShell & _shell;
    std::string _prompt;
    std::vector<std::string> _exitWords;

    int showHelp(std::vector<std::string> &args);
    int listAllCommands();
    int commandHelp(std::string &cmd);
};

#endif
