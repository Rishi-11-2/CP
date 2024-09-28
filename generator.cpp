
#include <bits/stdc++.h>
using namespace std;

using namespace chrono;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long double getRandomNumberD(long double l,long double r){
    return uniform_real_distribution<long double>(l,r)(rng);
}

long long  getRandomNumber(long long  l,long long  r){
    return uniform_int_distribution<long long >(l,r)(rng);
}


int main()
{
    
    long long n=getRandomNumber(1,(int)(1e5));
    cout<<n<<endl;

    long long arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=getRandomNumber(1,(long long)(1e9));
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }
