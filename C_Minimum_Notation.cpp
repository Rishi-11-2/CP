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
void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    deque<int>q;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        // int x=s[i]-'0';
        while(!q.empty() && s[i]<s[q.back()])
        {
            // debug(i);
            // debug(s[q.back()]-'0');
            pq.push(s[q.back()]-'0');
            q.pop_back();
        }
        q.push_back(i);
    }
    string res="";
    while(!q.empty() && !pq.empty())
    {
        int x=s[q.front()]-'0';
        int y=pq.top();
        y=min(y+1,9);
        if(x<y)
        {
            res+=to_string(x);
            q.pop_front();
        }
        else
        {
            res+=to_string(y);
            pq.pop();
        }
    }
    while(!pq.empty())
    {
        int y=pq.top();
        y=min(y+1,9);
        res+=to_string(y);
        pq.pop();
    }
    while(!q.empty())
    {
        int x=s[q.front()]-'0';
        res+=to_string(x);
        q.pop_front();
    }
    cout<<res<<endl;
}