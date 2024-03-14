#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

void F();

signed main()
{
    fast_io;

    // std_io;

    F();
}

void F()
{
    int arr[6][6];

    int sum = 0, sum1 = INT_MIN;

    for (int i = 0; i < 6; i++)

        for (int j = 0; j < 6; j++)

            cin >> arr[i][j];

    for (int i = 0; i <= 3; i++)

        for (int j = 1; j <= 4; j++)
        {

            sum = (arr[i][j - 1] + arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j - 1] + arr[i + 2][j] + arr[i + 2][j + 1]);

            sum1 = max(sum1, sum);
        }

    cout << sum1 << endl;
}

void E()
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

        cout << total << endl;
    }
}

void D()
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

        bool flag = true;

        for (int i = 0; i < n - 1; i++)

            if (arr[i + 1] - arr[i] > 1)
            {
                flag = false;

                break;
            }

        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
}

void C()
{
    int n, x;

    cin >> n >> x;

    int choto = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int y;

        cin >> y;

        choto = min(choto, y);

        x -= y;
    }

    cout << n + (x / choto) << endl;
}

void B()
{
    string s;

    cin >> s;

    int sum = 700;

    for (int i = 0; i < s.size(); i++)

        if (s[i] == 'o')

            sum += 100;

    cout << sum << endl;
}

void A()
{
    int a, b;

    cin >> a >> b;

    cout << (a * b) - ((a + b) - 1) << endl;
}