#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (isPrime((i * 10) + j))
                v.pb((i * 10) + j);
        }
    }
    int z = 0;
    int flag = 1;
    int a1 = 2;
    if (n == 1)
    {
        int x = s[0] - '0';
        if (!isPrime(x))
        {
            z = x;
            a1 = 1;
            cout << z << el;
            cout << a1 << el;
            return;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (i != j)
            {
                int a = s[i] - '0';
                int b = s[j] - '0';
                int x = (a * 10) + b;

                auto it = find(v.begin(), v.end(), ((a * 10) + b));
                if (it == v.end())
                {
                    z = ((a * 10) + b);
                    if (!isPrime(z / 10))
                    {
                        z = z / 10;
                        a1--;
                        cout << a1 << el;
                        cout << z << el;
                        return;
                    }
                    else if (!isPrime(z % 10))
                    {
                        z = z % 10;
                        a1--;
                        cout << a1 << el;
                        cout << z << el;
                        return;
                    }
                }
            }
        }
    }
}