
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
    

    long long n=getRandomNumber(1,(long long)1e5);

    long double low=-1e12;
    long double high=1e12;

    cout<<n<<endl;

    for(int i=1;i<=n;i++)
    {
        long double x=getRandomNumberD(low,high);
        long double y = getRandomNumberD(low,high);

        cout<<x<<" "<<y<<endl;
    }
}
