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
    vector<int>isPrime(100,1);
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
        solve();
}
struct Interactor{
    int hiddenNumber;
    int queriesTillNow;
    int limitQueries;
    bool printInteraction;
    string answer;
    Interactor(){
        isPrime[0]=isPrime[1]=0;
        for(int i=2;(i*i)<=100;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;(j)<=100;j+=i)
                {
                    isPrime[j]=0;
                }
            }
        }
        hiddenNumber = getRandomNumber(1, 100);
        string answer="composite";
        if(isPrime[hiddenNumber])
         answer="prime";
        queriesTillNow = 0;
        limitQueries = 20;
        printInteraction = false;
    }
    void checkTotalQueries(){
        if(queriesTillNow >= limitQueries){
            cout << "Made more than limit queries for " << hiddenNumber << endl;
        }
        assert(queriesTillNow < limitQueries);        
    }
    string make_query(int x){
        checkTotalQueries();
        queriesTillNow++;
        if(hiddenNumber%x==0)
            return "yes";
        return "no";
    }
    void isValidOutput(string x){
        if(x != answer){
            cout<<answer\<<endl;
            cout << "Failed for " << hiddenNumber<<endl; 
        }else{
            cout << "Passed for " << hiddenNumber << endl;
        }
    }
};

string make_query(int x)
{
    cout<<x<<endl;
    string codeforcesOutput;
    cin>>codeforcesOutput;
    return codeforcesOutput;
}
void solve()
{
     Interactor interactor=Interactor();   
    vector<int>v;
    for(int i=2;i<100;i++)
    {
        if(isPrime[i])
        {
            v.push_back(i);
            if(i==53)
            break;
        }
    }
    // debug(v.size());
    int count=0;
    int num=-1;
    int flag=0;
    int x=-1;
    for(auto it:v)
    {
        string s=interactor.make_query(it);
        if(s=="yes")
        {
            if(flag==0)
            {
                x=it;
                flag=1;
            }
            count++;
            num=it;
        }
        if(count>=2)
        break;
    }
    if(count>=2)
    {
        interactor.isValidOutput("composite");

        // cout<<"composite"<<endl;
        return ;
    }
    if(count==0)
    {
        interactor.isValidOutput("prime");

        // cout<<"prime"<<endl;
        return;
    }
    num=num*x;
    int c=1;
    while(count<2 && c<=2)
    {
        string s=make_query(num);
        if(s=="yes")
        count++;
        num=num*x;
    }
    if(count==2)
    {
        // cout<<"composite"<<endl;
        interactor.isValidOutput("composite");
    }
    else
    {
        // cout<<"prime"<<endl;
        interactor.isValidOutput("prime");
    }
}