/**
 * A base class for writing a wide variety of shell-like programs.
 * Still under heavy planning and development.
 */
 
 #include <string>

class ShellBase
{

protected:
    ShellBase();
    ~ShellBase();
    void setPrompt(std::string prompt);
    std::string getPrompt();
    
private:
    std::string prompt;
};
