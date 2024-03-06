class Chain
{  
    public:
        int val;
        Chain(int n)
        {
            val = n;
        }
        Chain operator() (int n) const
        {
            return Chain(val + n);
        }
        int operator+ (int n) const
        {
            return n + val;
        }
        int operator- (int n) const
        {
            return n - val;
        }
};

bool operator==(int n, const Chain& c)
{
    return n == c.val;
}

auto add(int n)
{
    return Chain(n);
}