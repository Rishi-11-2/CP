#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if ((a % 2 != 0) and (b % 2 != 0))
        {
            cout << -1 << endl;
        }
        else
        {
            string s = "";
            int c = 0;
            int d = 0;
            if (a > b)
            {
                c = a;
                d = b;
            }
            else
            {
                c = b;
                d = a;
            }
            int p = 1;
            char h = 0;
            char l = 0;
            int j = 0;
            if (a > b)
            {
                h = 'a';
                l = 'b';
            }
            else
            {
                h = 'b';
                l = 'a';
            }

            if ((a % 2 == 0) and (b % 2 == 0))
            {
                for (int i = 0; i < b / 2; i++)
                {
                    s += 'b';
                }
                for (int i = 0; i < a; i++)
                {
                    s += 'a';
                }
                for (int i = 0; i < b / 2; i++)
                {
                    s += 'b';
                }
                cout << s << endl;
            }
            else
            {
                j = 0;
                for (int i = 0; i < (a + b); i++)
                {
                    if ((i > d - 1) and (p <= d))
                    {
                        p++;
                        if (p = (d / 2) + 1)
                        {
                            s += l;
                        }
                        else
                        {
                            s += h;
                        }
                        j = 1;
                    }
                    else
                    {
                        if (j == 0)
                        {
                            s += h;
                            j = 1;
                        }
                        else
                        {
                            s += l;
                            j = 0;
                        }
                    }
                }
                cout << s << endl;
            }

            s = "";

            if ((a % 2 == 0) and (b % 2 == 0))
            {
                for (int i = 0; i < a / 2; i++)
                {
                    s += 'a';
                }
                for (int i = 0; i < b; i++)
                {
                    s += 'b';
                }
                for (int i = 0; i < a / 2; i++)
                {
                    s += 'a';
                }
                cout << s << endl;
            }
            else
            {
                char u = ' ';
                char v = ' ';
                int f = b;
                int g = a;
                if (b % 2 == 0)
                {
                    u = 'b';
                    v = 'a';
                }
                else
                {
                    u = 'a';
                    v = 'b';
                    f = a;
                    g = b;
                }
                for (int i = 0; i < f / 2; i++)
                {
                    s += u;
                }
                for (int i = 0; i < g; i++)
                {
                    s += v;
                }
                for (int i = 0; i < f / 2; i++)
                {
                    s += u;
                }

                cout << s << endl;
            }
        }
    }
}