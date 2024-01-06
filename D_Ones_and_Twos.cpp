#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int s=0;
    int count_one=0;
    int count_two=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        count_one++;
        
        if(a[i]==2)
        count_two++;
        
        s+=a[i];
    }

    for(int i=1;i<=q;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int req_s;
            cin>>req_s;
            if(req_s>s)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                int diff=s-req_s;
                if(diff==0)
                {
                    cout<<"YES"<<endl;
                    continue;
                }
                if(diff%2 && count_one)
                {
                    cout<<"YES"<<endl;
                }
                else if(diff%2==0 && count_two)
                {
                    cout<<"YES"<<endl;
                }
                else
                cout<<"NO"<<endl;
            }

        }
        else if(op==2)
        {
            int j,v;
            cin>>j>>v;
            if(a[j-1]==1)
            {
                count_one--;
                count_two++;
            }
            if(a[j-1]==2)
            {
                count_two--;
                count_one++;
            }
            s-=a[j-1];
            a[j-1]=v;
            s+=a[j-1];

        }
    }
}