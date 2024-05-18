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
        solve();
    
}
// 5 1 4 2 3
int make_query(int l,int r)
{
    cout<<"?"<<" "<<l<<" "<<r<<endl;

    int codeforcesOutput;
    cin>>codeforcesOutput;

    return codeforcesOutput;
}
void solve()
{

    int n;
    cin>>n;

    int smaxIndex=make_query(1,n);


    int res=-1;
    if(n==2)
    {
        int idx=-1;
        if(smaxIndex==1)
        {
            idx=2;
        }
        else
        {
            idx=1;
        }
        cout<<"!"<<" "<<idx<<endl;
        return;
    }
    /* we fix the secondMaxIndex. Now we check whether the maximum is the left of the 
    second max index or to the right of second max index
    Accordingly we apply binary search to find the answer*/


    // if the maximum is to the right of secondMax
    if(smaxIndex==1 || make_query(1,smaxIndex)!=smaxIndex)
    {
        int low=smaxIndex+1;
        int high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int idx=make_query(smaxIndex,mid);
            if(idx!=smaxIndex)
            {
                low=mid+1;
            }
            //5 6 2 3 1
            else
            {
                res=mid;
                high=mid-1;
            }
        }
    }
    // if the maximum is to the left of second maximum
    else
    {
        int low=1;
        int high=smaxIndex-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            int idx=make_query(mid,smaxIndex);

            if(idx!=smaxIndex)
            {
                high=mid-1;
            }
            else
            {
                res=mid;
                low=mid+1;
            }
        }
    }

    cout<<"!"<<" "<<res<<endl;
    
}