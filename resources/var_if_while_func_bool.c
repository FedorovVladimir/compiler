//
//  var_if_while_func_bool.c
//  
//
//  Created by Maxim Butin on 17.09.2020.
//

#include <stdio.h>

bool perfectNumber(int n)
{
    int i = 1, sum = 0;
    while(i < n){
        if (n % i == 0)
        {
            sum = sum + i;
        }
        i++;
    }
    
    if(sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    if (perfectNumber(6))
    {
        cout<<"Perfect Number";
    }
    else
    {
        cout << "NOT Perfect Number";
    }
    return 0;
}

