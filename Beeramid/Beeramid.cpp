int beeramid(int bonus, double price)
{
    int cansAmount = bonus/price;
    int currLevel = 0;
  
    while(cansAmount > 0)
    {
        currLevel++;
        cansAmount -= (currLevel+1)*(currLevel+1);
    }
    return currLevel;
}