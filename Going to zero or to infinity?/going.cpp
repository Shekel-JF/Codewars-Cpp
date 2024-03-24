class Suite
{
public:
    static double going(int n)
    {
        if(n == 1)
        {
            return 1;
        }

        return 1.0 + going(n - 1) / n;
    }
};
