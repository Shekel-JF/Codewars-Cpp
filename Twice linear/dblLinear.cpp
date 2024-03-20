#include <queue>
using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n)
    {
        queue<int> que_y;
        queue<int> que_z;
        que_z.push(1);
        que_y.push(1);
         
        int next_y = 3;
        int next_z = 4;
           
        int size = 0;
        while(size < n)
        {
            if(size == n - 1)
            {
                return min(next_y, next_z);
            }
           
            if(next_z > next_y)
            {
                que_y.pop();
                que_y.push(next_y);
                que_z.push(next_y);
              
                next_y = 2 * que_y.front() + 1;
            }
            else if(next_z < next_y)
            {
                que_z.pop();
                que_y.push(next_z);
                que_z.push(next_z);
              
                next_z = 3 * que_z.front() + 1;
            }
            else
            {
                que_z.pop();
                que_y.pop();
                que_y.push(next_y);
                que_z.push(next_y);
              
                next_y = 2 * que_y.front() + 1;
                next_z = 3 * que_z.front() + 1;           
            }
            size++;
        }
      
        return 1;
    }
};