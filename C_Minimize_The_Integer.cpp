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
    string s;
    cin>>s;
    int n=s.length();

    vector<int>even;
    vector<int>odd;

    for(int i=0;i<n;i++)
    {
        int x=(s[i]-'0');
        if(x%2)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }
    string z="";
    int i=0;
    int j=0;
    int n1=(int)(odd.size());
    int n2=(int)(even.size());
    // sort(all(odd));
    // sort(all(even));
    while(i<n1 && j<n2)
    {
        if(odd[i]<even[j]){
            z+=to_string(odd[i]);
            i++;
        }
        else
        {
            z+=to_string(even[j]);
            j++;
        }
    }
    while(i<n1)
    {
        z+=to_string(odd[i]);
        i++;
    }
    while(j<n2)
    {
        z+=to_string(even[j]);
        j++;
    }
    cout<<z<<endl;
}