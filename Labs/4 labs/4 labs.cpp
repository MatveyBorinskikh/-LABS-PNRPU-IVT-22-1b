              #include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
  int n;
  int a[100], b[100], c[100];
  int j = 0;
  for(int i = 0; i < 10; i++)
    {
        a[i] = rand()%100-50;
    }

    for(int i = 0; i < 10; i++)
    {
        std::cout << a[i] << " ";
    }
  std::cout << std::endl;


  for (int i; i < 10; i++)
    {
      if(i%3!=0 or i==0)
      {
        b[j] = a[i];
        j++;
        n = j;
      }
    }
 
 
  for(j = 0; j < n; j++)
    {
        std::cout << b[j] << " ";
    }
  std::cout << std::endl;


  for (j = 0; j < n; j++)
  {
      if (a[j]<0)
      {
      cout << b[j] << " " << b[j]+1 << " ";
      }
      else 
      {
         cout << b[j] << " ";
      }
  }
}