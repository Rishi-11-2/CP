#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

    vector<char>digit;
    vector<char>letter;
    int flag=0;
    for(char c:s)
    {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) 
        {
            letter.push_back(c);
            flag=1;
        }
        else if (c >= 48 && c <= 57) 
        {
            if(flag)
            {
                cout<<"NO"<<endl;
                return;
            }
            digit.push_back(c);
        }
    }

    auto v1=digit;

    sort(all(v1));

    auto v2=letter;

    sort(all(v2));

    if(v1!=digit || v2!=letter)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;


}