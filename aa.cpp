#include<bits/stdc++.h>
using namespace std;

int sum(int x,int y){
    cout<<"Sum"<<endl;
    return (x+y);
}
int sub(int x,int y)
{
    cout<<"Sub"<<endl;
    return (x-y);
}
int main()
{
    int (*fp1)(int,int)=sum;
    int (*fp2)(int,int)=sub;
    int (*fp3)(int,int);
    int x;
    cin>>x;
    if(x%2==0)
    fp3=sum;
    else
    fp3=sub;
    int y=(*fp1)(9,10);
    cout<<y<<endl;
}