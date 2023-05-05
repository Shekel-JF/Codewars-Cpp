class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        unsigned int i = 0;
        while(i < arr.size()-1 && arr.size() > 0)
        {
            
            if ((arr[i] == "NORTH" && arr[i+1] == "SOUTH")
                || (arr[i] == "SOUTH" && arr[i+1] == "NORTH")
                || (arr[i] == "EAST" && arr[i+1] == "WEST")
                || (arr[i] == "WEST" && arr[i+1] == "EAST"))
            {
                arr.erase(arr.begin() + i, arr.begin() + i + 2);
                if(i > 0)
                {
                    i--;
                }
            }
            else
            {
                i++;
            }
        }
        return arr;
    }
};
