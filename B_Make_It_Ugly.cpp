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
    int n;
    cin>>n;

    int arr[n];

    set<int>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }

    if((int)(s.size())==1)
    {
        cout<<-1<<endl;
        return;
    }

    int i=1;
    int count=INT_MAX;
    int c=1;
    while(i<n-1)
    {
        int j=i-1;
        int k=i+1;
        if(arr[i]==arr[j])
        c++;
        int flag=0;
        int count1=0;
        // debug(i,c);
        while(k<n && arr[k]==arr[j] && arr[i]!=arr[k])
        {
            // debug(i,k);

            k++;
            count1++;
            flag=1;
        }
        if(flag)
        {
            // debug(c,count1);
            count=min(count,min(c,count1));
            c=count1;
        }
        i=k;
    }
    cout<<count<<endl;
    
}