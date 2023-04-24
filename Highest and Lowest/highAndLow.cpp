#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string highAndLow(const std::string& numbers)
{
    std::stringstream ss(numbers);
    std::vector<int> arr;
  
    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }
    int h = arr[0];
    int l = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if(h < arr[i])
        {
            h = arr[i];
        }
        else if(l > arr[i])
        {
            l = arr[i];
        }
    }  
    std::string result = std::to_string(h) + " " + std::to_string(l);
    return result;
}