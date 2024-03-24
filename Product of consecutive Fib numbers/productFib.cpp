#include <vector>
typedef unsigned long long ull;

using namespace std;
class ProdFib
{
public:
  static vector<ull> productFib(ull prod)
  {
      ull a = 1;
      ull b = 1;
    
      while(a * b < prod)
      {
          ull tmp = a;
          a = b + a;
          b = tmp;
      }
    
      vector<ull> result;
      result.push_back(b);
      result.push_back(a);
      if(a * b == prod)
      {  
          result.push_back(true);
      }
      else
      {
          result.push_back(false);
      }
      return result;
  }
};