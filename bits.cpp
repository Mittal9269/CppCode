#include <bits/stdc++.h>
using namespace std;
 
int power(long long int x, long long int y, long long int p)
{
    long long int res = 1; // Initialize result
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int numberOfDigits(long long  x)
{
    int i = 0;
    while (x) 
        x /= 10;
        i++;
    }
    return i;
}
void printLastKDigits(long long a, long long  b, long long  k)
{
    long long  temp = 1;
    for (long long i = 1; i <= k; i++)
        temp *= 10;
    temp = power(a, b, temp);
    for (long long i = 0; i < k - numberOfDigits(temp); i++)
        cout << 0;
    if (temp)
        cout << temp;
}
 
int main(){
    long long a, b ,k;  cin>>a>>b>>k;
    double x, y;
     x = b * log10(a);
       y = floor(pow(10, x - floor(x) +k  - 1));
       printf("%d ", (int)y);
       printLastKDigits(a , b, k) ;
       
    
}