#include "command_line_parser.h"

ExecutionCommand CommandLineParser::ParseCommand(std::string& command_line)
{
    ExecutionCommand result{};
    auto tokens = GetTokens(command_line);
    result.command = GetCommand(tokens.front());
    tokens.pop_front();
    result.parameters = tokens;
    // while (!tokens.empty())
    // {
    //     std::cout << "\"" <<tokens.front() << "\"\n";
    //     tokens.pop_front();
    // }
    return result;
}

std::list<std::string> CommandLineParser::GetTokens(std::string& command_line)
{
    std::list<std::string> tokens;
    std::stringstream token_stream(command_line);
    std::string intermediate;

    while(std::getline(token_stream, intermediate, ' '))
    {
        if (!intermediate.empty())
        {
            tokens.emplace_back(intermediate);
        }
    }
    return tokens;
}

Command CommandLineParser::GetCommand(std::string& command_string)
{
    if (command_string == "load" || command_string == "ld")
    {
        return Command::Load;
    }
    else if (command_string == "store" || command_string == "s")
    {
        return Command::Store;
    }
    else if (command_string == "blur")
    {
        return Command::Blur;
    }
    else if (command_string == "resize")
    {
        return Command::Resize;
    }
    else if (command_string == "help" || command_string == "h")
    {
        return Command::Help;
    }
    else if (command_string == "exit" || command_string == "quit" || command_string == "q")
    {
        return Command::Quit;
    }
    return Command::Unknown;
}
