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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1)
    {
        cout << s << endl;
        return;
    }
    string left = "";
    string right = "";
    int i = 0;
    int j = n - 1;
    while (i < j && s[i] == s[j])
    {
        left += s[i];
        right = s[j] + right;
        i++;
        j--;
    }
    int flag = 0;
    int k = -1;
    if (i == j)
    {
        k = i;
        flag = 1;
    }
    string front = "";
    string back = "";
    int f = i + 1;
    int flag1 = 0;
    if (f == j)
    {
        flag1 = 1;
    }
    else if (f > j)
        flag1 = 2;
    while (f <= j && s[i] != s[f])
    {
        f++;
    }
    if (flag1 == 0)
    {
        string lfront = "";
        int ff = i;
        string lback = "";
        while (i < f && s[i] == s[f])
        {
            lfront += s[i];
            lback = s[f] + lback;
            i++;
            f--;
        }
        if (i < f)
        {
            front = s[ff];
        }
        else
        {
            if (i == f)
                front = lfront + s[i] + lback;
            else if (i > f)
                front = lfront + lback;
        }
    }
    else if (flag1 == 1)
    {
        front = s[i];
    }
    int b = j - 1;
    int flag2 = 0;
    if (b == i)
    {
        flag2 = 1;
    }
    else if (b < i)
    {
        flag2 = 2;
    }
    if (flag2 == 0)
    {
        int bb = j;
        while (b >= i && s[j] != s[b])
        {
            b--;
        }
        string rfront = "";
        string rback = "";
        while (b < j && s[b] == s[j])
        {
            rfront += s[b];
            rback = s[j] + rback;
            b++;
            j--;
        }
        if (b < j)
            back = s[bb];
        else
        {
            if (b == j)
                back = rfront + s[j] + rback;
            else if (b > j)
                back = rfront + rback;
        }
    }
    else if (flag2 == 1)
    {
        back = s[j];
    }
    string res = "";
    if (flag == 0)
    {
        if (front.length() > back.length())
            res = left + front + right;
        else
            res = left + back + right;
    }
    else if (flag == 1)
    {
        res = left + s[k] + right;
    }
    cout << res << endl;
}