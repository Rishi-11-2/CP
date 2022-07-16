#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        long long p = 1;
        long long m = 1;
        long long maxE = 1;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                p = p * arr[i];
                maxE = max(maxE, m);
                m = 1;
            }
            if (arr[i] > 0)
            {
                m *= arr[i];
                p *= arr[i];
            }
            if (arr[i] == 0)
            {
                maxE = max(maxE, m);
                maxE = max(maxE, p);
                m = 1;
                p = 1;
            }
        }
        maxE = max(maxE, p);
        maxE = max(maxE, m);
        cout << maxE << el;
    }
}