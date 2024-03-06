#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void F();

signed main()
{
    fast_io;

    // std_io;

    F();
}

void F()
{
    int w, h;

    cin >> w >> h;

    string arr[w][h];

    bool arr2[w][h] = {false};

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == "#")

                arr2[i][j] = true;
        }
    }

    bool flag = false;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (arr[i][j] == "#")
            {
                if (arr2[i][j - 1] == true or arr2[i][j + 1] == true or arr2[i - 1][j] == true or arr2[i + 1][j] == true)
                {
                    flag = true;
                }

                else

                    flag = false;
            }
        }
    }

    if (flag)

        cout << "Yes" << endl;

    else

        cout << "NO" << endl;
}

void D()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        vector<int> candy(n), orange(n);

        int mincandy = INT_MAX, minorange = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            cin >> candy[i];

            mincandy = min(mincandy, candy[i]);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> orange[i];

            minorange = min(minorange, orange[i]);
        }

        int total = 0, a = 0, b = 0;

        for (int i = 0; i < n; i++)
        {
            a = candy[i] - mincandy;

            b = orange[i] - minorange;

            total += max(a, b);
        }

        // for(int i = 0; i < n; i++)
        // {
        //     total += orange[i] - minorange;
        // }

        cout << total << endl;
    }
}

void C()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)

            cin >> arr[i];

        sort(arr.begin(), arr.end());

        // for(int i = 0; i < n; i++)

        //     cout << arr[i] << " ";

        // cout << endl;

        bool flag = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] > 1)
            {
                flag = false;

                break;
            }
        }

        if (flag)

            cout << "YES" << endl;

        else

            cout << "NO" << endl;
    }
}

void E()
{
    int a, b;

    cin >> a >> b;

    if (b < a)

        cout << a - 1 << endl;

    else if (b >= a)

        cout << a << endl;
}

void B()
{
    int a, b, x;

    cin >> a >> b >> x;

    if ((x >= a) and x <= (a + b))

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

void A()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x;

        cin >> x;

        if (x == 1 or x == 2)

            cout << 0 << endl;

        else if (x % 2 == 1)

            cout << (x / 2) << endl;

        else

            cout << (x / 2) - 1 << endl;
    }
}
