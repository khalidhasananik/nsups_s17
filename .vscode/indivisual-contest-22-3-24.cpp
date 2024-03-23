#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void A();

signed main()
{
    fast_io;

    // std_io;

    A();
}

void A()
{
    int a, b, c;

    cin >> a >> b >> c;

    int ttl = 0;

    ttl += (a * 2);

    if (c >= 2)
        ttl += (((2 * b) - 1) + 4), c -= 2;
    else if (c == 1)
        ttl += (((2 * b) - 1) + 2), c -= 1;

    if (c > 0)
    {
        if (c % 2 == 0)
        {
            int x = c / 2;

            ttl += (x * 3);
        }

        else
        {
            if (c == 1)
                ttl += 1;

            else
            {
                int x = c / 2;

                ttl += (x * 3) + 1;
            }
        }
    }

    cout << ttl << endl;
}
