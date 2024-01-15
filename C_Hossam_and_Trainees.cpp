
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
// typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
vector<int>v;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    int m=33500;
    vector<bool>isPrime(m+1,1);
    for(int i=2;i<=m;i++)
    {
        if(isPrime[i])
        {
            v.push_back(i);

            for(int j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    // v.clear();
    // for(int i=2;i<=m;i++)
    // {
    //     if(isPrime[i])
    //     {
    //     }
    // }
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
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        // cout<<arr[i]<<endl;
        // mp[arr[i]]++;

    }
    // cout<<(v.size())<<endl;  
         for(int j=0;j<n;j++)
        {
            for(auto i:v)
            {
                if(arr[j]<i)
                break;
                if(arr[j]%i)
                continue;
                if((arr[j]%i)==0)
                {
                    mp[i]++;
                    if(mp[i]>=2)
                    {
                        cout<<"YES"<<'\n';
                        return;
                    }

                }
                while(arr[j]%i==0)
                {
                    arr[j]=arr[j]/i;
                }
            }

            if(arr[j]!=1)
            mp[arr[j]]++;

             if(mp[arr[j]]>=2)
            {
              cout<<"YES"<<'\n';
              return;
            }

    }
    cout<<"NO"<<'\n';
}