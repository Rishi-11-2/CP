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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    vector<long long>x;
    map<long long,long long>mp;
    set<long long>s;
    for(long long i=1;i<=n;i++)
    {
        long long y;
        cin>>y;
        mp[y]=i;
        s.insert(y);
        x.push_back(y);
    }
    vector<long long>p;
    p.push_back(-(int)(1e10));
    for(long long i=1;i<=n;i++)
    {
        long long y;
        cin>>y;
        p.push_back(y);
    }

    vector<long long>prefix(n+1,0);
    for(long long i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+p[i];
    }

    long long q;
    cin>>q;
    for(long long i=1;i<=q;i++)
    {
        long long a,b;
        cin>>a>>b;

        if(b<(*s.begin()) || a>(*s.rbegin()) )
        {
            cout<<0<<endl;
            continue;
        }
        if((*s.begin())>= a  && (*s.rbegin())<=b)
        {
            cout<<prefix[n]<<endl;
            continue;
        }
        if(a==b)
        {
            // auto it=
            // cou
            if(s.find(a)!=s.end())
            {
                cout<<p[mp[a]]<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
            continue;
        }
        auto it1=s.lower_bound(a);
        long long map_a=mp[*it1];

        auto it2=s.upper_bound(b);
        // cout<<*it2<<endl;
        it2--;
        long long map_b=mp[*it2];
        // debug(map_b,map_a);
        cout<<prefix[map_b]-prefix[map_a-1]<<endl;

    }
}