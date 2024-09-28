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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;

    string s;
    cin>>s;
    vector<long long>even(26,0);
    vector<long long>odd(26,0);

    for(long long i=0;i<n;i++)
    {
        if(i%2==0)
        {
            even[s[i]-'a']++;
        }
        else
        {
            odd[s[i]-'a']++;
        }
    }
    if(n%2==0)
    {
        long long count1=*max_element(even.begin(),even.end());
        long long count2=*max_element(odd.begin(),odd.end());

        cout<<(n-(count1+count2))<<endl;
        return;
    }
    vector<long long>left_even(26,0);
    vector<long long>left_odd(26,0);
    vector<long long>right_even(26,0);
    vector<long long>right_odd(26,0);
    right_even=even;
    right_odd=odd;
    long long res=INT_MAX;
    for(long long i=0;i<n;i++)
    {
        if(i%2)
        {
            right_odd[s[i]-'a']--;
        }
        else
        {
            right_even[s[i]-'a']--;
        }

        vector<long long>temp_even(26,0);
        vector<long long>temp_odd(26,0);
        for(long long i=0;i<26;i++)
        {
            temp_odd[i]=left_odd[i]+right_even[i];
            temp_even[i]=left_even[i]+right_odd[i];
        }

        long long count1=*max_element(temp_even.begin(),temp_even.end());
        long long count2=*max_element(temp_odd.begin(),temp_odd.end());

        res=min(res,n-(count1+count2));

        if(i%2)
        {
            left_odd[s[i]-'a']++;
        }
        else
        {
            left_even[s[i]-'a']++;
        }
    }

    cout<<res<<endl;
}