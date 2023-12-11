#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
        solve();
}
void solve()
{
    long long k,g,m;
    cin>>k>>g>>m;
    long long glass=0;
    long long mug=0;
    while(k>0)
    {
        if(glass==g)
        {
            glass=0;
        }
        else if(mug==0)
        {
            mug=m;
        }
        else
        {
            long long x=g-glass;
            glass+=min(x,mug);
            mug=mug-min(x,mug);
        }
        // cout<<glass<<" "<<mug<<endl;
        k--;
    }
    cout<<glass<<" "<<mug<<endl;
}