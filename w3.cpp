#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void Y();

signed main()
{
    fast_io;

    // std_io;

    Y();
}

void Y()
{
    int tc, x;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        multiset<int> s;

        while (n--)

            cin >> x, s.insert(x);

        for (int i = 0; i < k; i++)
        {
            auto it = s.begin();

            x = *it;

            s.erase(it);

            s.insert(x * -1);
        }

        int sum = 0;

        for (auto &x : s)

            sum += x;

        cout << sum << endl;
    }
}

void X()
{
    int n;

    cin >> n;

    const int N = 200000;

    vector<int> a(N), b(N), p(N);

    for (int i = 0; i < n; i++)

        cin >> p[i];

    for (int i = 0; i < n; i++)

        cin >> a[i];

    for (int i = 0; i < n; i++)

        cin >> b[i];

    set<int> s[4];

    for (int i = 0; i < n; i++)
    {
        s[a[i]].insert(p[i]);

        s[b[i]].insert(p[i]);
    }

    int m;

    cin >> m;

    while (m--)
    {
        int x;

        cin >> x;

        if (s[x].size() == 0)

            cout << -1 << " ";

        else
        {
            int ans = *s[x].begin();

            cout << ans << " ";

            for (int i = 1; i <= 3; i++)

                s[i].erase(ans);
        }
    }
}

void W()
{
    int n;

    cin >> n;

    vector<int> a(n);

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        mp[a[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < 32; j++)
        {
            int x = (1 << j) - a[i]; // 1 << j = 2^j

            if (mp.count(x) and (mp[x] > 1 or (mp[x] == 1 and x != a[i])))
                // if x exists that means we can find a pair a[i] and x and x is our a[j]
                flag = true;
        }

        if (!flag)

            ans++;
    }

    cout << ans << endl;
}

void V()
{
    int n, k;

    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        v.push_back(x);
    }

    cin >> k;

    for (int i = 0; i <= n - k; i++)
    {
        int boro = INT_MIN;

        for (int j = i; j < (i + k); j++)

            boro = max(boro, v[j]);

        cout << boro << " ";
    }

    cout << endl;
}

void U()
{
    int l, q, c, x;

    cin >> l >> q;

    set<int> s;

    s.insert(0);

    s.insert(l);

    while (q--)
    {
        cin >> c >> x;

        if (c == 1)

            s.insert(x);

        else
        {
            auto it = s.find(x);

            if (it != s.end())
                // if exists we minus the previous point from the current point
                cout << x - *prev(s.lower_bound(x)) << endl;

            else
                // if not exists we minus the previous point from the upper point
                cout << *s.upper_bound(x) - *prev(s.lower_bound(x)) << endl;
        }
    }
}

void T()
{
    int tc;

    cin >> tc;

    multiset<int> s;

    while (tc--)
    {
        int n, w, x, h = 1;

        cin >> n >> w;

        while (n--)

            cin >> x, s.insert(x);

        int temp = w;

        while (!s.empty())
        {
            auto it = s.upper_bound(temp);
            // upper_bound returns the first element greater than temp

            if (it != s.begin())
            {
                it--;

                temp -= *it;

                s.erase(it);
            }

            else

                temp = w, h++;
        }

        cout << h << endl;
    }
}

void S()
{
    int n, m;

    int sum = 0;

    cin >> n;

    vector<int> vec(n, 0);

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        sum += x;

        vec[i] = sum;
    }

    cin >> m;

    while (m--)
    {
        int x;

        cin >> x;

        auto upper = lower_bound(vec.begin(), vec.end(), x);

        cout << upper - vec.begin() + 1 << endl;
    }
}

void R()
{
    int n, m, x;

    vector<int> s, vec;

    cin >> n >> m;

    while (n--)

        cin >> x, s.push_back(x);

    while (m--)

        cin >> x, vec.push_back(x);

    sort(s.begin(), s.end());

    for (int i = 0; i < vec.size(); i++)

        cout << upper_bound(s.begin(), s.end(), vec[i]) - s.begin() << " ";

    cout << endl;
}

void Q()
{
    int n, k;

    cin >> n >> k;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)

        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    int sum = 0, cnt = 1, mul = 1;

    for (int i = 0; i < n; i++)
    {
        sum += v[i] * mul;

        cnt == k ? mul++, cnt = 1 : cnt++;
    }

    cout << sum << endl;
}

void P()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int n, r;

        cin >> n >> r;

        set<int> spy, civilian;

        bool flag = false;

        while (r--)
        {
            int x, y;

            cin >> x >> y;

            spy.insert(x);

            civilian.insert(y);
        }

        for (auto &it : civilian)

            if (spy.find(it) != spy.end())
            {
                flag = true;

                break;
            }

        cout << "Scenario #" << i << ": ";

        flag ? cout << "spied" << endl : cout << "spying" << endl;
    }
}

void N()
{
    int m, n;

    cin >> m >> n;

    map<string, int> mp;

    cin.ignore();

    while (m--)
    {
        string s;

        int n;

        cin >> s >> n;

        mp[s] += n;
    }

    while (n--)
    {
        string s;

        int sum = 0;

        while (getline(cin, s) and s != ".")
        {
            stringstream iss(s);

            string word;

            while (iss >> word)

                sum += mp[word];
        }

        cout << sum << endl;
    }
}

void M()
{
    map<char, char> mp;

    mp['A'] = '2';
    mp['B'] = '2';
    mp['C'] = '2';
    mp['D'] = '3';
    mp['E'] = '3';
    mp['F'] = '3';
    mp['G'] = '4';
    mp['H'] = '4';
    mp['I'] = '4';
    mp['J'] = '5';
    mp['K'] = '5';
    mp['L'] = '5';
    mp['M'] = '6';
    mp['N'] = '6';
    mp['O'] = '6';
    mp['P'] = '7';
    mp['R'] = '7';
    mp['S'] = '7';
    mp['T'] = '8';
    mp['U'] = '8';
    mp['V'] = '8';
    mp['W'] = '9';
    mp['X'] = '9';
    mp['Y'] = '9';
    mp['1'] = '1';
    mp['2'] = '2';
    mp['3'] = '3';
    mp['4'] = '4';
    mp['5'] = '5';
    mp['6'] = '6';
    mp['7'] = '7';
    mp['8'] = '8';
    mp['9'] = '9';
    mp['0'] = '0';

    int tc, n;

    char c;

    cin >> tc;

    while (tc--)
    {
        map<string, int> mp2;

        cin >> n;

        cin.ignore();

        while (n--)
        {
            string s, t = "";

            int cnt = 0;

            cin >> s;

            for (char c : s)

                if (c != '-')
                {
                    cnt++;

                    t += mp[c];

                    if (cnt == 3)

                        t += '-';
                }

            mp2[t]++;
        }

        bool flag = false;

        for (auto [a, b] : mp2)

            if (b > 1)
            {
                flag = true;

                cout << a << " " << b << endl;
            }

        if (!flag)

            cout << "No duplicates." << endl;

        if (tc)

            cout << endl;
    }
}

void L()
{
    int n;

    cin >> n;

    map<string, int> mp;

    while (n--)
    {
        string s;

        cin >> s;

        mp[s]++;

        if (mp[s] == 1)

            cout << "OK" << endl;

        else
        {
            s += to_string(mp[s] - 1);

            cout << s << endl;

            mp[s]++;
        }
    }
}

void K()
{
    int tc, n, d, ca = 1;

    cin >> tc;

    while (tc--)
    {
        cin >> n >> d;

        set<int> s;

        int arr[n];

        int ans = INT_MIN, cnt = 0;

        for (int i = 0; i < n; i++)

            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            s.insert(arr[i]);

            ++cnt;

            ans = max(ans, (*prev(s.end()) - *s.begin()));
            //(*prev(s.end()) - *s.begin()) = max element - min element

            if (cnt == d)

                s.erase(arr[i - d + 1]), cnt--;
        }

        printf("Case %lld: %lld\n", ca++, ans);
    }
}

void J()
{
    int n;

    cin >> n;

    map<string, int> mp;

    while (n--)
    {
        string s;

        cin >> s;

        mp[s]++;

        if (mp[s] == 1)

            cout << "NO" << endl;

        else

            cout << "YES" << endl;
    }
}

void I()
{
    int n, x;

    cin >> n;

    map<int, int> mp;

    while (n--)

        cin >> x, mp[x]++;

    int boro = INT_MIN;

    for (auto [a, b] : mp)

        boro = max(boro, b);

    cout << boro << endl;
}

void H()
{
    map<string, string> mp;

    int n, m;

    string s, t, u;

    cin >> n >> m;

    while (n--)
    {
        cin >> s >> t;

        t += ';';

        mp[t] = s;
    }

    while (m--)
    {
        cin >> s >> t;

        cout << s << " " << t << " #" << mp[t] << endl;
    }
}

void G()
{
    int n, x, cnt = 0;

    cin >> n;

    map<int, int> mp;

    while (n--)

        cin >> x, mp[x]++;

    for (auto it : mp)

        if (it.second < it.first)

            cnt += it.second;

        else

            cnt += it.second - it.first;

    cout << cnt << endl;
}

void F()
{
    int tc, n, m, x;

    map<int, int> mp;

    cin >> tc;

    while (tc--)
    {
        cin >> n >> m;

        map<int, int> mp;

        int cnt = 0;

        while (n--)

            cin >> x, mp[x]++;

        while (m--)

            cin >> x, mp[x]--;

        for (auto x : mp)

            if (x.second != 0)

                cnt += abs(x.second);

        cout << cnt << endl;
    }
}

void E()
{
    int n, q;

    cin >> n >> q;

    int t = n / 2;

    cin.ignore();

    multimap<string, pair<string, string>> mp;

    while (t--)
    {
        string s;

        getline(cin, s);

        s.erase(0, 1);

        s.erase(s.size() - 1, 1);

        for (int i = 0; i < s.size(); i++)

            if (!isalnum(s[i]) and s[i] != ' ')

                s[i] = ' ';

        stringstream ss(s);

        string tag, key, value;

        ss >> tag;

        while (ss >> key >> value)
        {
            mp.insert({tag, {key, value}});
        }
    }

    n /= 2;

    while (n--)
    {
        string s;

        getline(cin, s);
    }

    while (q--)
    {
        string s;

        getline(cin, s);

        string tag, key;

        for (int i = 0; i < s.size(); i++)

            if (s[i] == '~')
            {
                tag = s.substr(i - 4, 4);

                key = s.substr(i + 1, s.size() - i - 1);
            }

        auto it = mp.equal_range(tag);

        bool found = false;

        for (auto i = it.first; i != it.second; i++)

            if (i->second.first == key)
            {
                cout << i->second.second << endl;

                found = true;
            }

        if (!found)

            cout << "Not Found!" << endl;
    }
}

void D()
{
    string s;

    multimap<string, string> mp;

    while (cin >> s and s != "XXXXXX")
    {
        string t = s;

        sort(t.begin(), t.end());

        mp.insert({t, s});
    }

    while (cin >> s and s != "XXXXXX")
    {
        string t = s;

        sort(t.begin(), t.end());

        auto it = mp.equal_range(t); // lower_bound and upper_bound

        multiset<string> st;

        if (it.first == it.second)

            cout << "NOT A VALID WORD" << endl;

        else
        {
            for (auto i = it.first; i != it.second; i++)

                st.insert(i->second);

            for (auto &i : st)

                cout << i << endl;
        }

        cout << "******" << endl;
    }
}

void C()
{
    int x;

    unordered_map<int, int> mp;

    vector<int> v;

    while (cin >> x)
    {
        if (mp[x] == 0)

            v.push_back(x);

        mp[x]++;
    }

    int n = v.size();

    // for (int i = 0; i < n; i++)

    //     cout << v[i] << " " << mp[v[i]] << endl;

    for (auto &i : v)

        cout << i << " " << mp[i] << endl;
}

void B()
{
    int tc, q, num;

    string s;

    map<string, int> mp;

    cin >> tc;

    while (tc--)
    {
        cin >> q >> s;

        if (q == 1)
        {
            cin >> num;

            mp[s] += num;
        }

        else if (q == 2)

            mp.erase(s);

        else

            cout << mp[s] << endl;
    }
}

void A()
{
    int tc, q, num;

    set<int> st;

    cin >> tc;

    while (tc--)
    {
        cin >> q >> num;

        if (q == 1)

            st.insert(num);

        else if (q == 2)

            st.erase(num);

        else
        {
            if (st.find(num) != st.end())

                cout << "Yes" << endl;

            else

                cout << "No" << endl;
        }
    }
}