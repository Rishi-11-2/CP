#include <bits/stdc++.h>
using namespace std;
char mov(char a)
{
    if (a == 'z')
        return 'a';
    return a++;
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, q;
        cin >> n >> q;
        char a[n], b[n];
        cin >> a;
        cin >> b;
        for (int i = 0; i < q; i++)
        {
            int y = 0;
            int q1, q2;
            cin >> q1 >> q2;
            q1-=1;
            q2-=1;
            for (int j = q1; j <= q2; j++)
            {
                if (a[j] != b[j] )
                {
                    if( (mov(a[j+1]) != b[j+1]) && (a[j+1] != (mov(b[j+1])) ))
                    y = 1;
                }
            }
            if (y == 1)
                cout << "NO"<<endl;
            else
                cout << "YES"<<endl;
        }
    }
}