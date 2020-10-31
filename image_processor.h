#ifndef TEST_TASK_TOOLS_INC_IMAGE_PROCESSOR_H
#define TEST_TASK_TOOLS_INC_IMAGE_PROCESSOR_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <map>
#include <list>
#include <iostream>

class ImageProcessor
{
  public:
    void Load(std::list<std::string> parameters);
    void Store(std::list<std::string> parameters);
    void Blur(std::list<std::string> parameters);
    void Resize(std::list<std::string> parameters);
  private:
    std::map<std::string, cv::Mat> names_to_images{};
};

#endif // TEST_TASK_TOOLS_INC_IMAGE_PROCESSOR_H