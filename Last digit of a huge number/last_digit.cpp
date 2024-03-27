#include <list>
#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;


int last_digit(list<int> array)
{
    int arr[3] = {1, 1, 1};
	for (int i = 0; i < 3 && !array.empty(); i++)
    {
		arr[i] = array.front();
	    array.pop_front();
	}

	int count = 0;
	while (!array.empty() && array.front() == 0)
    {
	    count++;
	    array.pop_front();
	}
    if (count % 2 == 1)
    {
        arr[2] = 1;
    }
	arr[0] %= 10;
	if(arr[1] == 0 && arr[2] != 0)
    {
        return 1;
    }
	if(arr[2] == 0)
    {
        return arr[0];
    }
  
	int exp = (arr[1] - 1) % 4 + 1;

	if(exp == 1 || exp == 4)
    {
        return int(pow(arr[0], exp)) % 10;
    }
	if(exp == 2)
    {
		if(arr[2] == 1)
        {
            return int(pow(arr[0], 2)) % 10;
        }
		else
        {
            return int(pow(arr[0], 4)) % 10;
        }
	}
	if(exp == 3)
    {
		if(arr[2] % 2 == 1)
        {
            return int(pow(arr[0], 3)) % 10;
        }      
		    else
        {
            return int(pow(arr[0], 1)) % 10;
        }
	}
	return -1;
}