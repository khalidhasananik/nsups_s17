#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void E();

signed main()
{
    fast_io;

    std_io;

    E();
}

void E()
{
    int n;

    cin >> n;

    list<int> tim;

    multimap<int, string> mp;

    for (int i = 0; i < n; i++)
    {
        int h, m, s;

        cin >> h >> m >> s;

        int time = h * (60 * 60) + m * 60 + s;

        string sh = to_string(h);

        string sm = to_string(m);

        string ss = to_string(s);

        string str = sh;

        str += ' ' + sm + ' ' + ss;

        tim.push_back(time);

        mp[time] = str;
    }

    // tim.sort();

    // while (!tim.empty())
    // {
    //     cout << mp[tim.front()] << endl;

    //     tim.pop_front();
    // }

    for (auto it : mp)

        cout << it.second << endl;
}

void D()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)

        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)

        if (v[i] % 2)

            cout << v[i] << " ";

    for (int i = n - 1; i >= 0; i--)

        if (v[i] % 2 == 0)

            cout << v[i] << " ";
}

void C()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        if (n * n < k)

            cout << "NO" << endl;

        else if (n & 1)

            if (k % 4 == 0 or (k - 1) % 4 == 0) // 1 5 9 13 17

                cout << "YES" << endl;

            else

                cout << "NO" << endl;

        else
        {
            if (k % 4 == 0) // 4 8 12 16

                cout << "YES" << endl;

            else

                cout << "NO" << endl;
        }
    }
}

set<int> divs;

void find_div(int n)
{
    for (int i = 1; i * i <= n; i++)

        if (n % i == 0)

            divs.insert(i), divs.insert(n / i);
}

void B()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int a, b;

        cin >> a >> b;

        find_div(__gcd(a, b));

        cout << divs.size() << endl;

        divs.clear();
    }
}

void A()
{
    int a, b, c;

    cin >> a >> b >> c;

    int ttl = 0;

    ttl += (a * 2);

    if (c >= 2 and b) // if c !>= 2, b are useless
    {
        ttl += (2 * b) + 3;

        c -= 2;
    }

    ttl += (c / 2) * 3;

    cout << ttl << endl;
}
