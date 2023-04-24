class Printer
{
    public:
        static std::string printerError(const std::string &s)
        {
            int bad = 0;
            int total = s.length();
            for (int i = 0; i < total; i++)
            {
                if(s[i] < 'a' || s[i] > 'm')
                {
                    bad++;
                }
            }
            std::string result = std::to_string(bad) + "/" + std::to_string(total);
            return result;
    }
};