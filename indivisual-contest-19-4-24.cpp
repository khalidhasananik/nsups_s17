#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void I();

signed main()
{
    fast_io;

    // std_io;

    I();
}

void I()
{
    int n;

    cin >> n;

    string arr[n];

    for (int i = 0; i < n / 2; i++)
    {
        string s;

        int x;

        cin >> x >> s;

        arr[x] += "- ";

        // cout << arr[x] << endl;
    }

    for (int i = n / 2; i < n; i++)
    {
        string s;

        int x;

        cin >> x >> s;

        arr[x] += s + " ";

        // cout << arr[x] << endl;
    }

    for (int i = 0; i < n; i++)

        cout << arr[i];

    // int q = n;

    // multimap<int, string> mp;

    // while (q--)
    // {
    //     int x;

    //     string s;

    //     cin >> x >> s;

    //     mp.insert({x, s});
    // }

    // for (auto x : mp)

    //     cout << x.first << " " << x.second << endl;
}

void A()
{
    int a, b;

    cin >> a >> b;

    int num = __gcd(a, b);

    int ans = 1;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            ans++;

            while (num % i == 0)

                num /= i;
        }
    }

    if (num > 1)

        ans++;

    cout << ans << endl;
}

void J()
{
    int q;

    cin >> q;

    string s = "";

    while (q--)
    {
        int o;

        char x, y;

        cin >> o;

        if (o == 1)
        {
            cin >> x;

            s += x;
        }

        else if (o == 2)
        {
            if (!s.empty())

                s.pop_back();
        }

        else
        {
            cin >> x >> y;

            replace(s.begin(), s.end(), x, y);
        }
    }

    if (!s.empty())

        cout << s << endl;

    else

        cout << "The final string is empty" << endl;
}

void G()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        cout << "Case " << i << ":";

        int p, l, num = 0;

        cin >> p >> l;

        num = p - l;

        set<int> divs;

        for (int i = 1; i * i <= num; i++)

            if (num % i == 0)
            {
                if (i > l) // q % i has to be greater than l

                    divs.insert(i);

                if (num / i > l)

                    divs.insert(num / i);
            }

        if (divs.size() == 0)

            cout << " impossible";

        else

            for (auto x : divs)

                cout << " " << x;

        cout << endl;
    }
}

void F()
{
    int q;

    cin >> q;

    stack<string> st;

    string s = "";

    st.push(s);

    while (q--)
    {
        int t;

        cin >> t;

        if (t == 1)
        {
            string w;

            cin >> w;

            s += w, st.push(s);
        }

        else if (t == 2)
        {
            int k;

            cin >> k;

            s.erase(s.size() - k, k), st.push(s);
        }

        else if (t == 3)
        {
            int k;

            cin >> k;

            cout << s[k - 1] << endl;
        }

        else

            st.pop(), s = st.top();
    }
}