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
    long long n;
    cin>>n;
    long long arr[n];
    set<long long>s;
    map<long long,long long>mp2;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp2[arr[i]]++;
        s.insert(arr[i]);
    }
    vector<long long>b(all(s));
    long long m=(long long)(b.size());
    long long suffix=0;
    map<long long,long long>mp;
    for(long long i=m-1;i>=0;i--)
    {
        mp[b[i]]=suffix;
        suffix+=(b[i]*mp2[b[i]]);
    }
    for(long long i=0;i<n;i++)
    {
        cout<<mp[arr[i]]<<" ";
    }
    cout<<endl;
}