#include <cstdint>

using namespace std;
template <class F>
auto calc(int64_t n, F f) ->int64_t
{
    int64_t res = 0;
  
    for (int64_t i = 1; i <= n;)
    {
        int64_t value = n / i;
        int64_t next_i = n / value + 1;
        res += f(value) * (next_i - i);
        i = next_i;
    }
    return res;
}