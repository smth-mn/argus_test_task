#include "image_processor.h"

void ImageProcessor::Load(std::list<std::string> parameters)
{
    if (parameters.size() != 2)
    {
        std::cout << "Wrong parameters number\n";
        return;
    }

    auto name = parameters.front();
    parameters.pop_front();
    auto input_path = parameters.front();
    parameters.pop_front();

    cv::Mat img = cv::imread(input_path, cv::IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << input_path << "\n";
        return;
    }
    std::cout << "Remembered name \"" << name << "\"\n";
    names_to_images[name] = img;
}

void ImageProcessor::Store(std::list<std::string> parameters)
{
    if (parameters.size() != 2)
    {
        std::cout << "Wrong parameters number\n";
        return;
    }

    auto name = parameters.front();
    parameters.pop_front();
    auto output_path = parameters.front();
    parameters.pop_front();

    if (names_to_images.find(name) == names_to_images.end())
    {
        std::cout << "No such image: " << name << "\n";
        return;
    }

    cv::imwrite(output_path, names_to_images[name]);
}

void ImageProcessor::Blur(std::list<std::string> parameters)
{
    if (parameters.size() != 3)
    {
        std::cout << "Wrong parameters number\n";
        return;
    }

    auto name = parameters.front();
    parameters.pop_front();
    auto destination_name = parameters.front();
    parameters.pop_front();
    auto window_size_string = parameters.front();
    parameters.pop_front();
    auto window_size = 0;

    try
    {
        window_size = stoi(window_size_string);
    }
    catch(const std::invalid_argument& ia)
    {
        std::cout << "Window size parameter must be a valid integer number, but not: " << window_size_string << "\n";
        return;
    }

    if (names_to_images.find(name) == names_to_images.end())
    {
        std::cout << "No such image: " << name << "\n";
        return;
    }
    auto source = names_to_images[name];
    auto destination = source.clone();
    cv::blur(source, destination, cv::Size(window_size,window_size), cv::Point(-1,-1));
    names_to_images[destination_name] = destination;
}

void ImageProcessor::Resize(std::list<std::string> parameters)
{
    if (parameters.size() != 4)
    {
        std::cout << "Wrong parameters number\n";
        return;
    }

    auto name = parameters.front();
    parameters.pop_front();
    auto destination_name = parameters.front();
    parameters.pop_front();
    auto new_width_string = parameters.front();
    parameters.pop_front();
    auto new_height_string = parameters.front();
    parameters.pop_front();
    auto new_width = 0;
    auto new_height = 0;

    try
    {
        new_width = stoi(new_width_string);
        new_height = stoi(new_height_string);
    }
    catch(const std::invalid_argument& ia)
    {
        std::cout << "Dimension parameters must be valid integer numbers, but not: " 
                  << new_width_string << " and " << new_height_string << "\n";
        return;
    }

    auto source = names_to_images[name];
    auto destination = source.clone();
    cv::resize(source, destination, cv::Size(new_width, new_height));
    names_to_images[destination_name] = destination;
}

