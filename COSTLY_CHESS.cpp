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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve(long long ,long long,long long,long long);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long a,b,c,d;
    while(cin>>a)
    {
        cin>>b>>c>>d;
        solve(a,b,c,d);

    }
}
void solve(long long a,long long b,long long c,long long d)
{

    vector<long long>res;

        vector<vector<long long>>dis(10,vector<long long>(10,(long long)(1e9)));

        set<pair<long long,pair<long long,long long>>>st;

        st.insert({0,{a,b}});
        // debug(a,b,c,d);
        dis[a][b]=0;
        while(!st.empty())
        {
            auto it=*st.begin();
            st.erase(st.begin());
            long long d=it.first;
            long long i=it.second.first;
            long long j=it.second.second;
            long long a[]={2,2,-2,-2,1,1,-1,-1};
            long long b[]={1,-1,1,-1,2,-2,2,-2};

            for(long long k=0;k<8;k++)
            {
                long long x=a[k]+i;
                long long y=b[k]+j;
                if(x>=0 && y>=0 && x<8 && y<8)
                {
                    // debug(i,j,x,y);
                    long long cost=i*x+j*y;
                    if(dis[x][y]>(dis[i][j]+cost))
                    {
                        st.erase({dis[x][y],{x,y}});
                        dis[x][y]=dis[i][j]+cost;
                        st.insert({dis[i][j],{x,y}});
                    }

                }
            }
        }
        res.push_back(dis[c][d]);

    for(auto it:res)
    cout<<it<<endl;
}