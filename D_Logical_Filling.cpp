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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    string res;
    for(int i=0;i<n;i++)
    {
        res.push_back('1');
    }
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            res[i]='.';
        }
        else if(s[i]=='o')
        {
            count1++;
            res[i]='o';
        }
        else
        {
            int flag=0;
            if((i>0) && (s[i-1]=='o'))
            flag=1;

            if((i<(n-1)) && (s[i+1]=='o'))
            flag=1;

            if(flag)
            res[i]='.';
            else
            count2++;
        }
    }
    // debug(count1,count2);
    int flag=0;
    if(count1==k)
    {
        flag=2;
    }
    else if((count2+count1)==k)
    {
        flag=1;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?' && res[i]=='1')
        {
            if(flag==1)
            res[i]='o';
            else if(flag==2)
            res[i]='.';
            else
            res[i]='?';
        }
    }

    int i=0;
    int j=0;
    int c=0;
    while(i<n)
    {
        int j=i;
        int count=0;
        while(j<n && res[j]=='?')
        {
            count++;
            j++;
        }
        c+=(count+1)/2;
        i=j+1;
        // debug(count);
    }

    if(c==(k-count1))
    {
        i=0;
        while(i<n)
        {
            int j=i;
            int count=0;
            while(j<n && res[j]=='?')
            {
                count++;
                j++;
            }
            if(count%2)
            {
                int k=i;
                int flag=0;
                while(k<j)
                {
                    if(flag==0)
                    res[k]='o';
                    else
                    res[k]='.';
                    flag=1-flag;
    
                    k++;
                }
            }
            i=j+1;
            // debug(count);
        }
    }
    cout<<res<<endl;
}