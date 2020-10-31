#ifndef TEST_TASK_TOOLS_INC_COMMAND_LINE_PARSER_H
#define TEST_TASK_TOOLS_INC_COMMAND_LINE_PARSER_H

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <list>

enum class Command
{
    Unknown,
    Load,
    Store,
    Blur,
    Resize,
    Help,
    Quit
};

struct ExecutionCommand
{
    Command command;
    std::list<std::string> parameters;
};

// TODO: maybe use boost.program_options when necessary
class CommandLineParser
{
  public:
    ExecutionCommand ParseCommand(std::string& command_line);

  private:
    std::list<std::string> GetTokens(std::string& command_line);
    Command GetCommand(std::string& command_string);
};

#endif // TEST_TASK_TOOLS_INC_COMMAND_LINE_PARSER_H