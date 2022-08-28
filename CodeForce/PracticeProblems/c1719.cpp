#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
#define INF INT_MAX
void solve();
int findDifff(string s,int l,int h)
{
    int a1=0;
    int b1=0;
    for(int i=l;i<=h;i++)
    {
        if(s[i]=='a')
        a1++;
        if(s[i]=='b')
        b1++;
    }
    return(abs(a1-b1));
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[n];
    int b[n];
    
    int low=0;
    int high=n-1;
    int d=findDifff(s,low,high);
    while(low<high and d!=0)
    {
        int d1=findDifff(s,low+1,high);
        int d2=findDifff(s,low,high-1);
        if(d1<d2)
        {
            low++;
            d=d1;
        }
        else
        {
            high--;
            d=d2;
        }}
        if(low>=high)
        {
            low=-1;
            high=-1;
            cout<<low<<" "<<high<<el;
            return;
        }
        low++;
        high++;
        cout<<low<<" "<<high<<el;
        
    }