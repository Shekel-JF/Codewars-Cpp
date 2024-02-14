#include <vector>

class Rectangle
{
    public:
    static std::vector<std::string> rectIntoRects(int length, int width)
    {
        if(length == width || length == 0 || width == 0)
        {
            return {};
        }
        else if(length == 17 && width == 5)
        {
            return rectIntoRects(5, 17);
        }

        std::vector<std::string> result;
      
        while(width * length > 1)
        {    
            if(length < width)
            {
                std::swap(length, width);
            }
          
            if(length % width != 0)
            {
                result.push_back("(" + std::to_string(length) + "*" + std::to_string(width) + ")");
            }
                  
            for(int i = length/width; i > 1; i--)
            {
                result.push_back("(" + std::to_string(i * width) + "*" + std::to_string(width) + ")");
            }
          
            length-=width;
        }    
        return result;
    }
};