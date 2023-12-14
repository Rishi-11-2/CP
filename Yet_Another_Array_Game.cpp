#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
void solve();
long long s;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    long long t;
    cin >> t>>s;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    multiset<long long>st;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        st.insert(arr[i]);
    }

    long long sum=0;
    long long p=0;
    while(!st.empty())
    {
        if(p==0)
        {
            if((long long)st.size()==2)
            {
                sum+=*st.rbegin();
                auto it=st.end();
                it--;
                st.erase(it);
            }
            else
            {
                sum+=*st.begin();
               st.erase(st.begin());
            }
            p=1;
        }
        else if(p==1)
        {
            auto it=st.end();
            it--;
            st.erase(it);
            p=0;
        }
    }
    if(s==1)
    {
        cout<<max(sum,*max_element(arr,arr+n))<<endl;

    }
    else if(s==0)
    {
        cout<<sum<<endl;
    }
}