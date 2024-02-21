#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void J();

signed main()
{
    fast_io;

    std_io;

    J();
}

void J()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)

            cin >> arr[i];

        int choto = INT_MAX, boro = INT_MIN;

        int cnt;

        bool flag = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] > 2)
            {
                flag = false;

                break;
            }
        }

        if (flag)
        {
            cout << n << " " << n << endl;
        }

        else

            for (int i = 0; i < n - 1; i++)
            {
                cnt = 1;

                if (arr[i + 1] - arr[i] <= 2)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        if (arr[j + 1] - arr[j] <= 2)
                        {
                            cnt++;
                        }

                        else

                            break;
                    }
                }

                if (arr[i] - arr[i - 1] <= 2)
                {
                    for (int j = i; j >= 0; j--)
                    {
                        if (arr[j] - arr[j - 1] < +2)

                            cnt++;

                        else

                            break;
                    }
                }

                boro = max(boro, cnt);

                choto = min(choto, cnt);
            }

        cout << choto << " " << boro << endl;
    }
}

// void J()
// {
//     int tc;

//     cin >> tc;

//     while (tc--)
//     {
//         int n;

//         cin >> n;

//         int arr[n];

//         for (int i = 0; i < n; i++)

//             cin >> arr[i];

//         int choto = INT_MAX, boro = INT_MIN;

//         int cnt;

//         bool flag = true;

//         for (int i = 0; i < n - 1; i++)
//         {
//             if (arr[i + 1] - arr[i] > 2)
//             {
//                 flag = false;

//                 break;
//             }
//         }

//         if (flag)
//         {
//             cout << n << " " << n << endl;
//         }

//         else
//         {
//             for (int i = 0; i < n - 1; i++)
//             {
//                 cnt = 1;

//                 for (int j = i + 1; j < n; j++)
//                 {
//                     if (arr[j] - arr[i] <= 2)

//                         cnt++;

//                     else

//                         break;
//                 }

//                 for (int k = i - 1; k >= 0; k--)
//                 {
//                     if (arr[i] - arr[k] <= 2)

//                         cnt++;

//                     else

//                         break;
//                 }

//                 boro = max(boro, cnt);

//                 choto = min(choto, cnt);
//             }

//             cout << choto << " " << boro << endl;
//         }
//     }
// }

void E()
{
    string s = "314159265358979323846264338327";

    int tc;

    cin >> tc;

    while (tc--)
    {
        int ans = 0;

        string t;

        cin >> t;

        if (s[0] == t[0])
        {
            for (int i = 0; i < t.size(); i++)
            {
                if (s[i] == t[i])

                    ans++;

                else

                    break;
            }

            cout << ans << endl;
        }

        else

            cout << 0 << endl;
    }
}

void K()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, p;

        cin >> n >> p;

        bool flag = false;

        int choto = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int x;

            cin >> x;

            if (x / p >= 1)
            {
                flag = true;

                choto = min(choto, x % p);
            }
        }

        if (flag)

            cout << choto << endl;

        else

            cout << -1 << endl;
    }
}

void I()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        map<int, int> mp;

        int n;

        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            int x;

            cin >> x;

            arr[i] = x;

            mp[x]++;
        }

        int boro = INT_MIN;

        for (int i = 0; i < n; i++)

            boro = max(boro, mp[arr[i]]);

        cout << n - boro << endl;
    }
}

void H()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        string t = "";

        for (int i = 0; i < 8; i++)
        {
            string s;

            cin >> s;

            for (int i = 0; i < s.size(); i++)

                if (isalpha(s[i]))

                    t += s[i];
        }

        cout << t << endl;
    }
}

void G()
{

    int tc;

    cin >> tc;

    while (tc--)
    {
        int h1, h2, m1, m2, s1, s2, p1 = 0, p2 = 0;

        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

        p1 += (h1 * 3600 + m1 * 60 + s1);

        p2 += (h2 * 3600 + m2 * 60 + s2);

        if (p1 < p2)

            cout << "Player1" << endl;

        else if (p1 > p2)

            cout << "Player2" << endl;

        else

            cout << "Tie" << endl;
    }
}

bool is_vowel(char c)
{
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

void F()
{
    string s, t = "";

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (!is_vowel(s[i]))

            t += s[i];
    }

    cout << t << endl;
}

void D()
{
    int n;

    cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++)

        sum += i;

    cout << sum << endl;
}

void C()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x;

        cin >> x;

        if (x == 6)

            cout << "YES" << endl;

        else

            cout << "NO" << endl;
    }
}

void B()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)

        cout << n;

    cout << endl;
}

void A()
{
    int n;

    cin >> n;

    cout << n << endl;
}
