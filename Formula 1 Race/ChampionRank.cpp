#include <string>

using namespace std;

int ChampionRank(int champion, const string &events )
{
    vector<int> positions;
    for(int i = 1; i <= 20; i++)
    {
        positions.push_back(i);
    }
    istringstream eventStream(events);
  
    int pilot = 0;
    string event = "";
  
    while(eventStream >> pilot)
    {
        auto iter = find(positions.begin(), positions.end(), pilot);
        eventStream >> event;
        if(event == "O")
        {
            iter_swap(iter, iter - 1);
        }
        else
        {
            if(pilot == champion)
            {
                return -1;
            }
            else
            {
                positions.erase(iter);
            }       
        }
    }
    return find(positions.begin(), positions.end(), champion) - positions.begin() + 1;
};
