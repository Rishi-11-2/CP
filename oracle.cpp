#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

   int i=0;
   int j=n-1;
   set<pair<int,int>>s;
   while(i<j)
   {
      if(arr[i]!=arr[j])
      s.insert({max(arr[i],arr[j]),min(arr[i],arr[j])});
      i++;
      j--;
   }
   cout<<(int)s.size()<<endl;
}
