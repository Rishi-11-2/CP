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
        solve();
}
void solve()
{
    int h,w,n;
    cin>>h>>w>>n;
    char grid[h+1][w+1];
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        grid[i][j]='.';
    }
    map<string,string>clockwise;
    map<string,string>counterclockwise;

    clockwise["up"]="right";
    clockwise["right"]="down";
    clockwise["down"]="left";
    clockwise["left"]="up";

    counterclockwise["up"]="left";
    counterclockwise["left"]="down";
    counterclockwise["down"]="right";
    counterclockwise["right"]="up";

    map<string,pair<int,int>>mp;

    mp["right"]={0,1};
    mp["left"]={0,-1};
    mp["up"]={-1,0};
    mp["down"]={1,0};

    queue<pair<int,int>>q;

    q.push({1,1});
    // debug(clockwise["right"]);
    string dir="up";
    while(n>0)
    {
        auto it=q.front();
        q.pop();
        int x=it.first;
        int y=it.second;
        if(grid[x][y]=='.')
        {

            grid[x][y]='#';
            dir=clockwise[dir];
        }
        else
        {
            grid[x][y]='.';
            dir=counterclockwise[dir];
        }
        // debug(x,y,dir);
        n--;
        x=(x+mp[dir].first);
        y=(y+mp[dir].second);
        if(x<1)
        x=h;
        if(y<1)
        y=w;
        if(x>h)
        x=1;
        if(y>w)
        y=1;
        q.push({x,y});
    }

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        cout<<grid[i][j];

        cout<<endl;
    }

}