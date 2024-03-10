#include <vector>

using namespace std;

vector<vector<long long>> det_minor(vector<vector<long long>> &m, int index)
{
    vector<vector<long long>> minor = m;
    minor.erase(minor.begin() + index);
    for(vector<long long> &x : minor)
    {
        x.erase(x.begin());
    }
    return minor;
}

long long determinant(vector<vector<long long>> m)
{
    int size = m.size();
    if(size == 1)
    {
        return m[0][0];
    }

    int sum = 0;
    int n = 1;
    for(int i = 0; i < size; i++)
    {
        sum+= n * m[i][0] * determinant(det_minor(m, i));
        n = -n;
    }
    return sum;
}





