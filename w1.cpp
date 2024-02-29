#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void V();

signed main()
{
    fast_io;

    // std_io;

    V();
}

void V()
{
    // Binary Deque

    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, s;

        cin >> n >> s;

        int arr[n], sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            sum += arr[i];
        }

        if (sum < s)
        {
            cout << -1 << endl;

            continue;
        }

        vector<int> next_one(n + 1, n);

        int index = n;

        for (int i = n - 1; i >= 0; i--)
        {
            next_one[i] = index;

            if (arr[i] == 1)

                index = i;
        }

        int ans = INT_MAX, current_sum = 0, left = 0;

        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            dq.push_back(arr[i]);

            current_sum += arr[i];

            while (current_sum > s)
            {
                current_sum -= dq.front();

                dq.pop_front();

                left++;
            }

            if (current_sum == s)

                ans = min(ans, left + (n - next_one[i]));
        }

        cout << ans << endl;
    }
}

void Z()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int l, m, ans = 0;

        cin >> l >> m;

        l *= 100;

        queue<int> left, right;

        for (int i = 0; i < m; i++)
        {
            int x;

            string s;

            cin >> x >> s;

            if (s == "left")

                left.push(x);

            else

                right.push(x);
        }

        for (int i = 0; !(left.empty() and right.empty()); i++)
        {
            int sum = 0;

            if (i % 2 == 0)

                while (!left.empty() and sum + left.front() <= l)
                {
                    sum += left.front();

                    left.pop();
                }

            else

                while (!right.empty() and sum + right.front() <= l)
                {
                    sum += right.front();

                    right.pop();
                }

            ans++;
        }

        cout << ans << endl;
    }
}

bool ispalindrome(string s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; i++)

        if (s[i] != s[n - i - 1])

            return false;

    return true;
}

void Y()
{
    string s;

    while (cin >> s)
    {
        int n = s.size();

        set<string> st;

        for (int i = 1; i <= n; i++)

            for (int j = 0; j < n; j++)
            {
                string sub = s.substr(j, i);

                if (ispalindrome(sub))

                    st.insert(sub);
            }

        cout << "The string '" << s << "' contains " << st.size() << " palindromes." << endl;
    }
}

void X()
{
    map<string, int> mp;

    mp["zero"] = 0;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    mp["ten"] = 10;
    mp["eleven"] = 11;
    mp["twelve"] = 12;
    mp["thirteen"] = 13;
    mp["fourteen"] = 14;
    mp["fifteen"] = 15;
    mp["sixteen"] = 16;
    mp["seventeen"] = 17;
    mp["eighteen"] = 18;
    mp["nineteen"] = 19;
    mp["twenty"] = 20;
    mp["thirty"] = 30;
    mp["forty"] = 40;
    mp["fifty"] = 50;
    mp["sixty"] = 60;
    mp["seventy"] = 70;
    mp["eighty"] = 80;
    mp["ninety"] = 90;
    mp["hundred"] = 100;
    mp["thousand"] = 1000;
    mp["million"] = 1000000;

    string s;

    while (getline(cin, s))
    {
        istringstream iss(s);

        string word;

        int sum = 0, totalsum = 0;

        while (iss >> word)
        {
            if (word == "negative")

                cout << '-';

            if (word == "hundred")

                sum *= 100;

            else if (word == "thousand")
            {
                totalsum += (sum * 1000);

                sum = 0;
            }

            else if (word == "million")
            {
                totalsum += (sum * 1000000);

                sum = 0;
            }

            else

                sum += mp[word];
        }

        cout << totalsum + sum << endl;
    }
}

void W()
{
    int q;

    cin >> q;

    deque<int> q1;

    bool reveresed = true;

    while (q--)
    {
        string s;

        cin >> s;

        if (s == "push_back")
        {
            int x;

            cin >> x;

            if (reveresed)

                q1.push_back(x);

            else

                q1.push_front(x);
        }

        else if (s == "toFront")
        {
            int x;

            cin >> x;

            if (reveresed)

                q1.push_front(x);

            else

                q1.push_back(x);
        }

        else if (s == "back")
        {
            if (q1.size() == 0)

                cout << "No job for Ada?" << endl;

            else
            {
                if (reveresed)
                {
                    cout << q1.back() << endl;

                    q1.pop_back();
                }

                else
                {
                    cout << q1.front() << endl;

                    q1.pop_front();
                }
            }
        }

        else if (s == "front")
        {
            if (q1.size() == 0)

                cout << "No job for Ada?" << endl;

            else
            {
                if (reveresed)
                {
                    cout << q1.front() << endl;

                    q1.pop_front();
                }

                else
                {
                    cout << q1.back() << endl;

                    q1.pop_back();
                }
            }
        }

        else
        {
            if (q1.size() != 0)

                reveresed = !reveresed;
        }
    }
}

void U()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int n, q;

        cin >> n >> q;

        deque<int> dq;

        cout << "Case " << i << ":" << endl;

        while (q--)
        {
            string s;

            cin >> s;

            if (s == "pushLeft" or s == "pushRight")
            {
                int x;

                cin >> x;

                if (dq.size() == n)

                    cout << "The queue is full" << endl;

                else
                {
                    if (s == "pushLeft")
                    {
                        dq.push_front(x);

                        cout << "Pushed in left: " << x << endl;
                    }
                    else
                    {
                        dq.push_back(x);

                        cout << "Pushed in right: " << x << endl;
                    }
                }
            }

            else
            {
                if (dq.empty())

                    cout << "The queue is empty" << endl;

                else
                {
                    if (s == "popLeft")
                    {
                        cout << "Popped from left: " << dq.front() << endl;

                        dq.pop_front();
                    }
                    else
                    {
                        cout << "Popped from right: " << dq.back() << endl;

                        dq.pop_back();
                    }
                }
            }
        }
    }
}

void T()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        vector<int> v(n);

        multiset<int> s;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];

            if (i < k)

                s.insert(v[i]);
        }

        for (int i = 0, j = k; j < n; i++, j++)
        {
            cout << *s.rbegin() << " ";

            s.insert(v[j]);

            s.erase(s.lower_bound(v[i]));
        }

        cout << *s.rbegin() << endl;
    }
}

void S()
{
    string s;

    while (cin >> s and s != "#")
    {
        if (next_permutation(s.begin(), s.end()))

            cout << s << endl;

        else

            cout << "No Successor" << endl;
    }
}

void R()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int k, m;

        map<char, int> mp;

        cin >> k;

        while (k--)
        {
            char c;

            int x;

            cin >> c >> x;

            mp[c] = x;
        }

        cin >> m;

        cin.ignore();

        string s;

        int ans = 0;

        while (m--)
        {
            getline(cin, s);

            for (int i = 0; i < s.size(); i++)

                ans += mp[s[i]];
        }

        cout << fixed << setprecision(2) << ans / 100.0 << "$" << endl;
    }
}

void Q()
{
    int tc;

    cin >> tc;

    cin.ignore();

    while (tc--)
    {
        vector<int> v1;

        vector<string> v2;

        vector<pair<int, string>> vp;

        string s, t, u;

        getline(cin, u);

        getline(cin, s);

        getline(cin, t);

        stringstream ss(s), st(t);

        int x;

        string y;

        while (ss >> x)

            v1.push_back(x);

        while (st >> y)

            v2.push_back(y);

        for (int i = 0; i < v1.size(); i++)

            vp.push_back({v1[i], v2[i]});

        sort(vp.begin(), vp.end());

        for (auto [x, y] : vp)

            cout << y << endl;

        if (tc)

            cout << endl;
    }
}

void P()
{
    int n;

    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        s.insert(x);
    }

    if (s.size() == 1)

        cout << "NO" << endl;

    else
    {
        auto it = s.begin();

        it++;

        cout << *it << endl;
    }
}

void O()
{
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> v;

    for (int i = 0; i < m; i++)
    {
        int box, matches;

        cin >> box >> matches;

        v.push_back({matches, box});
    }

    sort(v.rbegin(), v.rend());

    int ans = 0;

    for (auto [x, y] : v)
    {
        if (n == 0)

            break;

        if (n >= y)
        {
            ans += x * y;

            n -= y;
        }

        else
        {
            ans += x * n;

            n = 0;
        }
    }

    cout << ans << endl;
}

void N()
{
    int n, m;

    cin >> n;

    int arr[n + 2];

    for (int i = 1; i <= n; i++)

        cin >> arr[i];

    cin >> m;

    while (m--)
    {
        int x, y;

        cin >> x >> y;

        arr[x - 1] += y - 1;

        arr[x + 1] += arr[x] - y;

        arr[x] = 0;
    }

    for (int i = 1; i <= n; i++)

        cout << arr[i] << endl;
}

void M()
{
    string s, t;

    cin >> s >> t;

    while (s.size() > 0 && t.size() > 0 && s.back() == t.back())
    {
        s.pop_back();

        t.pop_back();
    }

    cout << s.size() + t.size() << endl;
}

void L()
{
    int n;

    string s;

    cin >> n >> s;

    int indx = 1;

    for (int i = 1; i < n; i++)

        if (s.substr(0, i) == s.substr(i, i))
            // the goal is to find the smallest string
            // that can be repeated to form the given string
            indx = i;

    cout << n - indx + 1;
}

void K()
{
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++)

        if (s[i] == ',')

            s[i] = ' ';

    stringstream ss(s);

    string word;

    while (ss >> word)

        cout << word << endl;
}

void J()
{
    string s;

    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
        {
            for (int j = 1; j <= cnt * 2; j++)

                cout << " ";

            cout << "<" << s[i] << ">" << endl;

            cnt++;

            i += 2;
        }

        else if (s[i] == '/')
        {
            cnt--;

            for (int j = 1; j <= cnt * 2; j++)

                cout << " ";

            cout << "</" << s[i + 1] << ">" << endl;

            i += 2;
        }
    }
}

void I()
{
    int n, arr[10] = {0};

    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            for (int i = 0; i < 10; i++)

                if (arr[i] == 0)
                {
                    arr[i]++;

                    break;
                }
        }

        else if (s[i] == 'R')
        {
            for (int i = 9; i >= 0; i--)

                if (arr[i] == 0)
                {
                    arr[i]++;

                    break;
                }
        }

        else

            arr[s[i] - '0'] = 0;
    }

    for (int i = 0; i < 10; i++)

        cout << arr[i];

    cout << endl;
}

void H()
{
    string s, t, u, v = "";

    cin >> s >> t >> u;

    v = s + t;

    sort(v.begin(), v.end());

    sort(u.begin(), u.end());

    if (v == u)

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

void G()
{
    int n, i = 1;

    cin >> n;

    string s = "";

    while (s.size() <= n)
    {
        s += to_string(i);

        i++;
    }

    cout << s[n - 1] << endl;
}

void F()
{
    string s;

    cin >> s;

    string heidi = "heidi";

    int i = 0, j = 0;

    while (i < s.size() && j < heidi.size())
    {
        if (s[i] == heidi[j])

            j++;

        i++;
    }

    if (j == heidi.size())

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

void E()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        string s;

        cin >> s;

        int n = s.size(), cnt = 0;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')

                v.push_back(i);
        }

        if (v.size() == 0)
        {
            cout << 0 << endl;

            continue;
        }

        for (int i = 0; i < v.size() - 1; i++)

            cnt += v[i + 1] - v[i] - 1;

        cout << cnt << endl;
    }
}

void D()
{
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)

        cin >> arr[i];

    sort(arr, arr + n);

    cout << arr[0];

    for (int i = 1; i < n; i++)

        cout << " " << arr[i];
}

void C()
{
    string s;

    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.size(); i++)

        if (isupper(s[i]))

            cnt++;

    if (cnt != 0)

        cout << cnt + 1 << endl;

    else

        cout << 1 << endl;
}

void B()
{
    string a, b;

    cin >> a >> b;

    cout << a.size() << " " << b.size() << endl;

    cout << a + b << endl;

    swap(a[0], b[0]);

    cout << a << " " << b << endl;
}

void A()
{
    int n, queries, q, x, y, lastAnswer = 0;

    cin >> n >> queries;

    vector<vector<int>> v(n);

    while (queries--)
    {
        cin >> q >> x >> y;

        int index = (x ^ lastAnswer) % n;

        if (q == 1)

            v[index].push_back(y);

        else
        {
            lastAnswer = v[index][y % v[index].size()];

            cout << lastAnswer << endl;
        }
    }
}