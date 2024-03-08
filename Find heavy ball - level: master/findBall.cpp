unsigned int findBall(Scales scales)
{   
    int w = 0;
    switch(scales.getWeight({0, 1, 2}, {5, 6, 7}))
    {
        case 0:
            switch(scales.getWeight({3}, {4}))
            {
                case -1:
                    return 3;
                case 1:
                    return 4;
            }
        
        case -1:
            w = scales.getWeight({0}, {2});
            return 1 + w;

        case 1:
            w = scales.getWeight({5}, {7});
            return 6 + w;
    }
}