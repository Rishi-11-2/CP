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
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;

    if(k==0)
    {
        if(n>=2)
        cout<<-1<<endl;
        else 
        {
            cout<<"A"<<endl;
            cout<<"B"<<endl;
        }
        return;
    }

    if(n==k)
    {
        for(int j=1;j<=2;j++)
        {
            int l=0;
            for(int i=0;i<n;i++)
            {
                if(l==0)
                {
                    cout<<"A";
                }
                else if(l==1)
                {
                    cout<<"B";
                }
                else
                {
                    cout<<"C";
                }
                l=(l+1)%3;
            }
            cout<<endl;
        }
        return;
    }

    int x1=-1;

    int y1=-1;

    int count=n/2;
    for(int i=1;i<=count;i++)
    {
        int x=i;
        x+=(n-2*i);

        if(x==k)
        {
            x1=i;
            y1=n-2*i;
            break;
        }
    }

    if(x1!=-1 && y1!=-1)
    {
        int flag=0;
        string s1="";
        string s2="";
        for(int i=1;i<=x1;i++)
        {
            
            s1.push_back('A');
            s1.push_back('B');
            s2.push_back('B');
            s2.push_back('C');
        }
        flag=0;
        for(int i=1;i<=y1;i++)
        {
            if(flag==0)
            {
                s1.push_back('A');
                s2.push_back('A');

            }
            else if(flag==1)
            {
                s1.push_back('B');
                s2.push_back('B');
            }
            else
            {
                s1.push_back('C');
                s2.push_back('C');
            }
            flag=(flag+1)%3;
        }

        cout<<s1<<endl;
        cout<<s2<<endl;
        return;
    }

    if(n%2 && (k==(n/2)))
    {
        int flag=0;
        string s1="";
        string s2="";
        s1.push_back('C');
        s2.push_back('B');
        for(int i=1;i<=(n/2);i++)
        {
            
            s1.push_back('A');
            s1.push_back('B');
            s2.push_back('A');
            s2.push_back('C');
        }

        cout<<s1<<endl;
        cout<<s2<<endl;
        return;
    }
    cout<<-1<<endl;



}