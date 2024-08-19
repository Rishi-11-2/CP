
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
    
    int n=getRandomNumber(1,(int)(1e4));
    int d=(int)(1e4);
    int m= getRandomNumber(1,d/n);
    int k=getRandomNumber(1,min(n,m));
    cout<<n<<" "<<m<<" "<<k<<endl;

    int w=getRandomNumber(1,n*m);
    cout<<w<<endl;
    int arr[w];
    for(int i=0;i<w;i++)
    {
        arr[i]=getRandomNumber(1,(int)(1e9));
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }
