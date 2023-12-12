#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int b[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>b[i][j];
    }
    vector<int>row,col;
    for(int i=0;i<n;i++)
    {
        row.push_back(i);
    }
    for(int j=0;j<m;j++)
        col.push_back(j);

    do
    {
        do{
            int flag=1;

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(a[row[i]][col[j]]!=b[i][j])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)
            {
                int cc=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(row[i]>row[j])
                        cc++;
                    }
                }
                for(int i=0;i<m;i++)
                {
                    for(int j=i+1;j<m;j++)
                    {
                        if(col[i]>col[j])
                        cc++;
                    }
                }
                cout<<cc<<endl;
                return;
            }
        }while(next_permutation(all(col)));
    }while(next_permutation(all(row)));

    cout<<-1<<endl;
}