#ifndef DATA_H_
#define DATA_H_

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "CommonInfo.h"

// namespace handle input data of used
namespace data
{
    // swap
    template<typename T>
    void swap(T& a, T& b)
    {
        T temp{a};
        a = b;
        b = temp;
    }

    // compare string by alphabet a -> z
    bool compareAlphabet(const std::string& s1, const std::string& s2);

    // pause console
    void pauseConsole();
    // clear console ubuntu
    void clearConsole();
    // download data from file to vector
    std::vector<CommonInfo> downloadData(const std::string& file_name);
    // max level setting
    constexpr int k_max_level{5};
    // min level setting
    constexpr int k_min_level{1};
    // igrone characters from the input 
    void igrone();
    // enter and check a number integer
    int enterInteger();
    // enter and check a number integer between min to max
    int enterInteger(int min, int max);
    // check email format abc@xyz.def
    bool isInvalidEmail(const std::string& email);
    // enter anh check person key have 8 number
    bool isInvalidPersonKey(const std::string& person_key);
};
#endif // DATA_H_