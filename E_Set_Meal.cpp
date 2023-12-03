#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
        solve();
}
void solve()
{
    long long n,m,l;
    cin>>n>>m>>l;
    long long a[n];
    for(long long i=0;i<n;i++)
    cin>>a[i];
    long long b[m]; 
    for(long long i=0;i<m;i++)
    cin>>b[i];
    

    set<pair<long long,long long>>s;
    for(long long i=1;i<=l;i++)
    {
        long long c,d;
        cin>>c>>d;
        // cout<<"Hi"<<endl;
        s.insert({c,d});
    }
    vector<pair<long long,long long>>x;
    vector<pair<long long,long long>>y;
    for(long long i=0;i<n;i++)
    {
        x.push_back({a[i],i});
    }
    for(long long i=0;i<m;i++)
    {
        y.push_back({b[i],i});
    }
    sort(all(x));
    reverse(all(x));
    sort(all(y));
    reverse(all(y));
    priority_queue< pair<long long,pair<long long,long long>> >pq;
    set<pair<long long,long long>>vis;
    vis.insert({0,0});
    pq.push({x[0].first+y[0].first,{0,0}});
    long long res=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        long long i=it.second.first;
        long long j=it.second.second;
        // cout<<i<<" "<<j<<endl;
        long long ii=x[i].second;
        long long jj=y[j].second;
        // cout<<ii<<" "<<jj<<endl;
        if(s.find({ii+1,jj+1})==s.end())
        {
            res=it.first;
            break;
        }
        if(i+1<n)
        {
            if(vis.find({i+1,j})==vis.end())
            {
                vis.insert({i+1,j});
                pq.push({x[i+1].first+y[j].first,{i+1,j}});
            }
        }
        if(j+1<m)
        {
            if(vis.find({i,j+1})==vis.end())
            {
                vis.insert({i,j+1});
                pq.push({x[i].first+y[j+1].first,{i,j+1}});
            }
        }
    }

    cout<<res<<endl;
}