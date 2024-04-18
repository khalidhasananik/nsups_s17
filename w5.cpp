#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

const int N = 1e6 + 10;

void Z();

signed main()
{
    fast_io;

    // std_io;

    Z();
}

void Z()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        cout << k + (k - 1) / (n - 1) << endl;
    }
}

void Y()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int n, cnt = 0;

        cin >> n;

        vector<int> v(n, 0);

        for (int &i : v)

            cin >> i;

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) // a
        {
            for (int j = i + 1; j < n; j++) // b
            {
                int ans = v[i] + v[j];

                auto low = lower_bound(v.begin(), v.end(), ans); // search for c

                cnt += (low - v.begin() - j - 1);
                // number of elements between j and low, a + b > c,
                // and -1 because of 0 based indexing
            }
        }

        cout << "Case " << i << ": " << cnt << endl;
    }
}

void X()
{
    int tc;

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, k = 0, ans = 0;

        cin >> n;

        int a[n] = {0};

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            int temp = a[i] - a[i - 1];

            k = max(k, temp);
        }

        ans = k;

        for (int i = 1; i <= n; i++)
        {
            int temp = a[i] - a[i - 1];

            if (temp == k)

                k--;

            else if (temp > k)
            {
                ans++;

                break;
            }
        }

        cout << "Case " << t << ": " << ans << endl;
    }
}

void W()
{
    int tc, cas = 0;

    cin >> tc;

    while (tc--)
    {
        int n, q;

        cin >> n >> q;

        vector<int> arr(n, 0);

        for (int &i : arr)

            cin >> i;

        cout << "Case " << ++cas << ":" << endl;

        while (q--)
        {
            int x, y;

            cin >> x >> y;

            auto lower = lower_bound(arr.begin(), arr.end(), x);

            auto upper = upper_bound(arr.begin(), arr.end(), y);

            upper--;

            cout << upper - lower + 1 << endl;
        }
    }
}

void V()
{
    int n, q;

    cin >> n;

    vector<int> arr(n, 0);

    for (int &i : arr)

        cin >> i;

    cin >> q;

    while (q--)
    {
        int x;

        cin >> x;

        auto lower = lower_bound(arr.begin(), arr.end(), x);

        lower == arr.begin() ? cout << "X " : cout << *prev(lower) << " ";

        auto upper = upper_bound(arr.begin(), arr.end(), x);

        upper == arr.end() ? cout << "X" : cout << *upper;

        cout << endl;
    }
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

                cout << x - *prev(s.lower_bound(x)) << endl;

            else

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

        cin >> x, sum += x, vec[i] = sum;
    }

    cin >> m;

    while (m--)
    {
        int x;

        cin >> x;

        cout << lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1 << endl;
    }
}

void R()
{
    int n, m;

    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int &i : a)

        cin >> i;

    for (int &i : b)

        cin >> i;

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)

        cout << upper_bound(a.begin(), a.end(), b[i]) - a.begin() << " ";

    cout << endl;
}

void Q()
{
    int n, q;

    cin >> n >> q;

    vector<int> a(n);

    for (int &i : a)

        cin >> i;

    while (q--)
    {
        int x, ans = -1;

        cin >> x;

        int l = 0, r = n - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (a[m] == x)
            {
                ans = m;

                r = m - 1;
            }

            else if (a[m] < x)

                l = m + 1;

            else

                r = m - 1;
        }

        cout << ans << endl;
    }
}

int l = 0, r = 0;

void P()
{
    int q;

    cin >> q;

    vector<int> v(N);

    bool flag = true;

    while (q--)
    {
        char ch;

        int id;

        cin >> ch >> id;

        if (flag)
        {
            v[id] = l;

            l--, r++;

            flag = false;
        }

        else
        {
            if (ch == 'L')

                v[id] = l--;

            else if (ch == 'R')

                v[id] = r++;

            else

                cout << min(abs(v[id] - l), abs(v[id] - r)) - 1 << endl;
        }
    }
}

void O()
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

    set<int> s[4]; // color 1, 2, 3

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

                s[i].erase(ans); // erasing the price
        }
    }
}

int divs[N], arr[11][N];

void precompute()
{
    for (int i = 2; i <= N; i++)

        if (divs[i] == 0)

            for (int j = i; j <= N; j += i)

                divs[j]++; // number of divisors

    for (int i = 0; i <= 10; i++) // i is the number of divisors

        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = arr[i][j - 1] + (divs[j] == i); // prefix sum of divisors
            // (divs[j] == i) is 1 if number of divisors of j is i
        }
}

void L()
{
    precompute();

    int t;

    cin >> t;

    while (t--)
    {
        int a, b, n;

        cin >> a >> b >> n;

        cout << arr[n][b] - arr[n][a - 1] << endl;
    }
}

void K()
{
    string s;

    cin >> s;

    int n = s.size();

    vector<int> v(n + 1, 0);

    for (int i = 1; i < n; i++)

        v[i] = (s[i] == s[i - 1]) ? 1 : 0;

    for (int i = 1; i <= n; i++)

        v[i] += v[i - 1];

    int q;

    cin >> q;

    while (q--)
    {
        int l, r;

        cin >> l >> r;

        cout << v[r - 1] - v[l - 1] << endl;
    }
}

void J()
{
    int n, t, c;

    cin >> n >> t >> c;

    int count = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        x <= t ? count++ : count = 0;

        ans += (count >= c);
    }

    cout << ans << endl;
}

void I()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for (int &i : v)

        cin >> i;

    // we make |b1| operations to make a1 equal to b1.
    // we must make |b2 - b1| operations to make a2 equal to b2.

    int ans = 0;

    ans += abs(v[0]);

    for (int i = 1; i < n; i++)

        ans += abs(v[i] - v[i - 1]);

    cout << ans << endl;
}

void H()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        vector<int> v(n), prefixsum(n, 0);

        for (int &i : v)

            cin >> i;

        for (int i = 1; i < n - 1; i++)

            if (v[i] > v[i - 1] && v[i] > v[i + 1])

                prefixsum[i] = 1;

        for (int i = 1; i < n; i++)

            prefixsum[i] += prefixsum[i - 1];

        int peaks = INT_MIN, idx = -1;

        for (int i = 0; i + k - 2 < n; i++)
        {
            int temp = prefixsum[i + k - 2] - prefixsum[i]; //-2 because of 0 based indexing

            if (temp > peaks)

                peaks = temp, idx = i;
        }

        cout << peaks + 1 << " " << idx + 1 << endl;
    }
}

bool isprime[N];

vector<int> primes;

void sieve_w_pb()
{
    fill_n(isprime, N, true);

    isprime[0] = isprime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (!isprime[i])

            continue;

        primes.push_back(i);

        for (int j = i * i; j < N; j += i)

            isprime[j] = false;
    }
}

bool isdidgitprime(int n)
{
    string s = to_string(n);

    int sum = 0;

    for (int i = 0; i < s.size(); i++)

        sum += s[i] - '0';

    return isprime[sum];
}

vector<int> digit(N, 0);

void Digitprime()
{
    for (int i = 0; i < primes.size(); i++)

        if (isdidgitprime(primes[i]))

            digit[primes[i]] = 1;
}

vector<int> newdigit(N, 0);

void prefixsum()
{
    newdigit[0] = digit[0];

    for (int i = 1; i < N; i++)

        newdigit[i] = newdigit[i - 1] + digit[i];
}

void G()
{
    sieve_w_pb();

    Digitprime();

    prefixsum();

    int n;

    scanf("%lld", &n);

    while (n--)
    {
        int l, r;

        scanf("%lld %lld", &l, &r);

        cout << newdigit[r] - newdigit[l - 1] << endl;
    }
}

void F()
{
    int n;

    cin >> n;

    vector<int> v(n);

    int total = 0;

    for (int &i : v)

        cin >> i, total += i;

    int sum = 0, cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum += v[i];

        if (sum * 2 == total)

            cnt++;
    }

    cout << cnt << endl;
}

void E()
{
    int n;

    cin >> n;

    deque<int> dq(n + 1);

    for (int i = 0; i < n; i++)

        cin >> dq[i];

    for (int i = n - 2; i >= 0; i--)

        dq[i] += dq[i + 1]; // prefix sum from right

    int q;

    cin >> q;

    while (q--)
    {
        int x;

        cin >> x;

        if (x == 2)
        {
            int o;

            cin >> o;

            dq.push_front(dq.front() + o);
        }

        else
        {
            int l, r;

            cin >> l >> r;

            cout << dq[l - 1] - dq[r] << endl;
        }
    }
}

void D()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, u;

        cin >> n >> u;

        vector<int> v(n + 1, 0);

        while (u--)
        {
            int l, r, val;

            cin >> l >> r >> val;

            v[l] += val;

            v[r + 1] -= val;
        }

        for (int i = 1; i <= n; i++)

            v[i] += v[i - 1];

        int q;

        cin >> q;

        while (q--)
        {
            int x;

            cin >> x;

            cout << v[x] << endl;
        }
    }
}

void C()
{
    int n, m;

    cin >> n >> m;

    vector<int> v(n);

    for (int &i : v)

        cin >> i;

    vector<int> ans(n);

    set<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(v[i]);

        ans[i] = s.size();
    }

    while (m--)
    {
        int x;

        cin >> x;

        cout << ans[x - 1] << endl;
    }
}

void B()
{
    int n, k, q;

    cin >> n >> k >> q;

    vector<int> v(200005, 0);

    while (n--)
    {
        int l, r;

        cin >> l >> r;

        v[l]++;

        v[r + 1]--; // cancel out the increment at r+1
    }

    /*
        say, l = 91 and r 94
        then, v[91]++ and v[95]--
        l = 92 and r = 97
        then, v[92]++ and v[98]--
    */

    for (int i = 1; i < 200005; i++)

        v[i] += v[i - 1];

    /*
        now, when we do prefix sum, we get
        v[91] to v[94] = 1, v[95] = -1
        v[92] to v[94] = 2 , v[95] to v[97] = 1, v[98] = -1
    */

    for (int i = 1; i < 200005; i++)

        v[i] = (v[i] >= k) ? 1 : 0;

    for (int i = 1; i < 200005; i++)

        v[i] += v[i - 1]; // prefix sum

    while (q--)
    {
        int l, r;

        cin >> l >> r;

        cout << v[r] - v[l - 1] << endl;
    }
}

void A()
{
    int n, q;

    cin >> n;

    int arr[n + 1];

    for (int i = 1; i <= n; i++)

        cin >> arr[i];

    int prefix[n + 1];

    prefix[0] = 0;

    for (int i = 1; i <= n; i++)

        prefix[i] = prefix[i - 1] + arr[i];

    cin >> q;

    while (q--)
    {
        int l, r;

        cin >> l >> r;

        cout << prefix[r + 1] - prefix[l] << endl;
    }
}