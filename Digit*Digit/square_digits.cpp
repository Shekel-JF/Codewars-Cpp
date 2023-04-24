int square_digits(int num)
{
    int result = 0;
    int a = 1;
    while(num > 0)
    {
        int b = num % 10;
        result += a * b * b;
        if(b <= 3)
        {
            a*=10;
        }
        else
        {
            a*=100;
        }
        num/=10;
    }  
    return result;
}