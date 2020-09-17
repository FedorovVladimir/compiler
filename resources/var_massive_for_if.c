//
//  var_massive_for_if.c
//  
//
//  Created by Maxim Butin on 17.09.2020.
//

#include <stdio.h>

using namespace std;
int main ()
{
   int i, j, temp, pass = 0;
   int a[10] = {10, 2, 0, 14, 43, 25, 18, 1, 5, 45};
   for(i = 0; i < 10; i++)
   {
      cout <<a[i] << " ";
   }
   
   cout << endl;
   for(i = 0; i < 10; i++)
   {
       for(j = i + 1; j < 10; j++)
       {
           if(a[j] < a[i])
           {
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
            }
        }
        
        pass++;
    }
    
    for(i = 0; i < 10; i++)
    {
        cout <<a[i] << " ";
    }
    
    return 0;
}
