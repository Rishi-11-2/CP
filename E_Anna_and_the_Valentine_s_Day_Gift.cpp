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
bool cmp(const string &a,const string &b)
{
    int n=a.length();
    int x=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]=='0')
        x++;
        else
        break;
    }
    n=b.length();
    int y=0;
    for(int i=n-1;i>=0;i--)
    {
        if(b[i]=='0')
        y++;
        else
        break;
    }
    if(x==y)
    return a<b;
    return x>y;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    vector<string>v;
    int res=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        v.push_back(to_string(arr[i]));
        res+=v[i].length();
    }
    sort(all(v),cmp);
    int c=0;
    for(auto it:v)
    {
        if(c%2==0)
        {
            int count=0;
            int m=it.length();
            for(int i=m-1;i>=0;i--)
            {
                if(it[i]=='0')
                count++;
                else
                break;
            }
            res-=count;
        }
        c++;
    }
    if(res>m)
    {
        cout<<"Sasha"<<endl;
    }
    else
    {
        cout<<"Anna"<<endl;
    }
    // cout<<res<<endl;

}