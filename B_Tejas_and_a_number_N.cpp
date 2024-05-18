#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }

    return a.first>b.first;
}
void solve()
{
    int n;
    cin>>n;

    string s=to_string(n);
    int m=s.length();
    vector<pair<int,int>>v;
    map<int,int>mp;
    for(int i=0;i<m;i++)
    {
        int digit=(s[i]-'0');
        mp[digit]=i;
        v.push_back({digit,i});
    }
    sort(all(v),cmp);

    int i=0;
    int j=0;
    while(j<m && i<m)
    {
        int d1=s[i]-'0';
        int d2=s[v[j].second]-'0';

        if(d1==d2)
        {
            i++;
            j++;
        }
        else
        {
            swap(s[i],s[mp[v[j].first]]);
            break;
        }
    }
    cout<<s<<endl;
}