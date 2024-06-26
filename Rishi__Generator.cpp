// A C++ Program to generate test cases for
// a weighted directed graph
#include <bits/stdc++.h>
using namespace std;

using namespace chrono;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long getRandomNumber(long long l,long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}


int main()
{
    long long t=1;

    cout<<t<<endl;

    long long n=getRandomNumber(1,(long long)1e5);
    long long k=getRandomNumber(1,(long long)1e9);

    cout<<n<<" "<<k<<endl;
    long long arr[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=getRandomNumber(1,(long long)1e9);
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}
