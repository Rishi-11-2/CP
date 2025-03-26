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
void solve(int );
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t = 1;
    cin >> t;
    int c=0;
    while (t--)
    {
        c++;
        solve(c);
    }
}
/*2 3 1
  3 1 2
  2 1 3
*/
long long countAndMerge(vector<long long>& arr, long long l, long long m, long long r) {
  
    // Counts in two subarrays
    long long n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<long long> left(n1), right(n2);
    for (long long i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (long long j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    long long res = 0;
    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
          // elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
long long countInv(vector<long long> arr, long long l, long long r){
    long long res = 0;
    if (l < r) {
        long long m = (r + l) / 2;

        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
          // the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}
void solve(int t)
{
    long long n;
    cin>>n;

    vector<long long>arr(n);

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long count=countInv(arr,0,n-1);
    long long res=count;
    long long left=0;
    long long right=0;
    for(long long l=0;l<n;l++)
    {
        long long c=count;
        vector<long long>v;
        for(auto it:arr)
        v.push_back(it);
        for(long long r=l+1;r<n;r++)
        {
            // debug(v[r-1],v[r]);
            if(v[r-1]>v[r])
            {
                // debug("h");
                c--;
            }
            else if(v[r-1]<v[r])
            {
                c++;
            }
            swap(v[r-1],v[r]);
            // debug(l,c);
            if(c<res)
            {
                res=c;
                left=l;
                right=r;
            }
        }
    }

    cout<<left+1<<" "<<right+1<<endl;
    

}