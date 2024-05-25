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
    int n;
    cin>>n;

    string s;
    cin>>s;

    map<char,vector<int>>mp;

    for(int i=0;i<n;i++)
    {
        mp[s[i]].push_back(i);
    }

    map<int,char>mp1;
    map<char,int>mp2;
    for(auto &it:mp)
    {
        auto v=it.second;
        int sz=(int)(v.size());
        int x=sz%2;
        int y=sz-x;
        int j=0;
        for(int i=1;i<=y/2;i++)
        {
            // debug(v[i]);
            mp1[v[j]]='H';
            j++;
        }

        for(int i=(y/2)+1;i<=y;i++)
        {
            // debug(v[i]);
            mp1[v[j]]='R';
            j++;
        }
        // debug(x,y,it.first);
        if(x>0 )
        {
            // debug(v[j]);
            if(it.first=='N' || it.first=='S')
            mp1[v[j]]='R';
            else
            mp1[v[j]]='H';
        }

        // debug(it.first,x);
        mp2[it.first]=x;
        
    }
    if(mp2.find('E')==mp2.end())
    mp2['E']=0;
    
    if(mp2.find('W')==mp2.end())
    mp2['W']=0;

    if(mp2.find('N')==mp2.end())
    mp2['N']=0;

    if(mp2.find('S')==mp2.end())
    mp2['S']=0;
    

    if(mp2['N']==mp2['S'] && mp2['W']==mp2['E'])
    {
        int count1=0;
        int count2=0;
       for(int i=0;i<n;i++)
       {
          if(mp1[i]=='H')
          count1++;
          else if(mp1[i]=='R')
          count2++;
       }
       if(count1==0 || count2==0)
       {
        cout<<"NO"<<endl;
        return;
       }

       for(int i=0;i<n;i++)
       cout<<mp1[i];
       cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
}