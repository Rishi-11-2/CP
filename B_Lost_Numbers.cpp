#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long getRandomNumber(long long l, long long r) {return uniform_int_distribution<long long>(l, r)(rng);}
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
    int t;
    
        solve();
    
}
int make_query(int l,int r)
{
    cout<<"?"<<" "<<l+1<<" "<<r+1<<endl;
    int codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
int isP(int n)
{
     if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
void solve()
{
    int count=1;
    vector<int>v={4, 8, 15, 16, 23,42};
    int a[6];
    memset(a,0,sizeof(a));
    vector<int>mul;
    for(int i=0;i<4;i++)
    {
        int x=make_query(i,i+1);
        mul.push_back(x);
    }
    double x=((mul[0]*1.0)/(mul[1]*1.0));
    if(mul[1]==2*mul[0]|| mul[0]==2*mul[1])
    {
        x=((mul[1]*1.0)/(mul[2]*1.0));
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<6;k++)
            {
                if(j==k)
                continue;
                
                double z=((v[j]*1.0)/(v[k]*1.0));
                // debug(x,z);
                if(z==x)
                {

                    a[1]=v[j];
                    a[3]=v[k];
                    break;
                }
            }
        }
        a[0]=(mul[0]/a[1]);
        a[2]=(mul[2]/a[3]);
        a[4]=(mul[3]/a[3]);
    }
    else
    {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<6;k++)
            {
                if(j==k)
                continue;
                
                double z=((v[j]*1.0)/(v[k]*1.0));
                // debug(x,z);
                if(z==x)
                {

                    a[0]=v[j];
                    a[2]=v[k];
                    break;
                }
            }
        }
        a[1]=(mul[0]/a[0]);
        a[3]=(mul[2]/a[2]);
        a[4]=(mul[3]/a[3]);
    }
    set<int>s(all(v));
    for(int i=0;i<5;i++)
    {
        s.erase(a[i]);
    }
    a[5]=*s.begin();
    cout<<"!"<<" ";
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}