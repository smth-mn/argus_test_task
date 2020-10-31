#ifndef TEST_TASK_APP_INC_APPLICATION_H
#define TEST_TASK_APP_INC_APPLICATION_H

#include <command_line_parser.h>
#include <image_processor.h>
#include <iostream>
#include <string>

class Application
{
  public:
    void Run()
    {
        finished = false;
        while (!finished)
        {
            std::string command_line;
            std::getline(std::cin, command_line);
            auto execution_command = command_line_parser.ParseCommand(command_line);
            switch(execution_command.command)
            {
                case Command::Unknown:
                    std::cout << "Unknown command\n";
                    ShowHelp();
                    break;
                case Command::Load:
                    image_processor.Load(execution_command.parameters);
                    break;
                case Command::Store:
                    image_processor.Store(execution_command.parameters);
                    break;
                case Command::Blur:
                    image_processor.Blur(execution_command.parameters);
                    break;
                case Command::Resize:
                    image_processor.Resize(execution_command.parameters);
                    break;
                case Command::Help:
                    ShowHelp();
                    break;
                case Command::Quit:
                    finished = true;
                    break;
                default:
                    std::cout << "Something unpredicted happend\n";
                    finished = true;
                    break;
            }
        }
    }
  private:
    void ShowHelp()
    {
        // TODO: move text to resource file
        std::cout << "Это консольное приложение, осуществляющее обработку изображения\n";
        std::cout << "Поддерживаемые команды:\n";
        std::cout << "    load, ld: <name> - имя изображения, по имени оно доступно в других командах <filename> - имя файла для загрузки\n";
        std::cout << "    store, s: <name> - имя изображения <filename> - имя файла для сохранениея\n";
        std::cout << "    blur: <from_name> - имя изображения  <to_name> - имя изображения <size> - размер сглаживаемой области\n";
        std::cout << "    resize: <from_name> - имя изображения <to_name> - имя изображения <new_width> <new_height>\n";
        std::cout << "    help, h: Выводит справку о поддерживаемых командах\n";
        std::cout << "    exit, quit, q: выход\n";
    }

    CommandLineParser command_line_parser{};
    ImageProcessor image_processor{};
    bool finished;
};

#endif // TEST_TASK_APP_INC_APPLICATION_H
