/* matrix - 0s and 1s */
/*
 0 0 0 1 1 2 
 0 0 1 1 1 3 
 0 0 0 0 1 1 
 0 1 1 1 1 4 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
   cin>>s;
   int n=s.length();

   int hash=0;
   for(int i=0;i<n;i++)
   {
      hash+=(i+1)+(s[i]-'a'+1);
   }
   cout<<hash<<endl;
}