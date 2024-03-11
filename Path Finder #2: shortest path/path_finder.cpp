#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

int path_finder(string maze)
{
    vector<vector<int>> m;
    vector<int> curr;
    maze+="\n";
    
    for(unsigned long i = 0; i < maze.size(); i++)
    {
        if(maze[i] == '\n')
        {
            m.push_back(curr);
            curr.clear();
        }
        else
        {
            if(maze[i] == '.')
            {
                curr.push_back(INT_MAX);
            }
            else if(maze[i] == 'W')
            {
                curr.push_back(-1);
            }
        }
    }
  
    queue<pair<unsigned long, unsigned long>> queue;
    queue.push({0, 0});
    m[0][0] = 0;
    while(!queue.empty())
    {
        pair<unsigned long, unsigned long> curr = queue.front();
        queue.pop();
        unsigned long x = curr.first;
        unsigned long y = curr.second;

        if(x >= 1 && m[x - 1][y] > m[x][y] + 1)
        {
            m[x - 1][y] = m[x][y] + 1;
            queue.push({x - 1, y});
        }
        if(x + 1 < m.size() && m[x + 1][y] > m[x][y] + 1)
        {
            m[x + 1][y] = m[x][y] + 1;
            queue.push({x + 1, y});
        }
        if(y >= 1 && m[x][y - 1] > m[x][y] + 1)
        {
            m[x][y - 1] = m[x][y] + 1;
            queue.push({x, y - 1});
        }
        if(y + 1 < m[0].size() && m[x][y + 1] > m[x][y] + 1)
        {
            m[x][y + 1] = m[x][y] + 1;
            queue.push({x, y + 1});
        }
    }

    if(m[m.size() - 1][m[0].size() - 1] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return m[m.size() - 1][m[0].size() - 1];
    }
}