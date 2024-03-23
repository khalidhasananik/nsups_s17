#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

const int N = 1e7 + 10; // for A, D, E, L

// const int N = 11000; // for B

// const int N = 1e6 + 10; // for C, F, G

// const int N = 2e7 + 10; // for H

// const int range = 10527449; // highest prime number below 10^7

const int range = 1048578;

// const int range = 20000000;

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

int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

void S();

signed main()
{
    fast_io;

    // std_io;

    // sieve_w_pb();

    S();
}

void S()
{
    int a, b;

    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << endl;

        return;
    }

    int ttl = 0;

    for (int i = 2; i <= 5; i++)
    {
        int cnt = 0;

        while (a % i == 0)

            a /= i, cnt++;

        while (b % i == 0)

            b /= i, cnt--;

        /*
            why cnt++ and cnt--? let's say,
            a = 2^x * 3^y * 5^z and b = 2^p * 3^q * 5^r
            abs(x - p) + abs(y - q) + abs(z - r) is the minimum number of operations
            we need to perform to make a = b
         */

        ttl += abs(cnt);
    }

    if (a == b)

        cout << ttl;

    else

        cout << -1;

    cout << endl;
}

void R()
{
    int n;

    cin >> n;

    cout << n / 2520 << endl; // lcm of 2 to 10
}

void Q()
{
    int n;

    cin >> n;

    map<int, int> mp;

    while (n--)
    {
        int x;

        cin >> x;

        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)

                mp[i]++; // count the frequency of each prime factor
            // we can group the numbers with the same prime factors together
            while (x % i == 0)

                x /= i;
        }

        if (x > 1)

            mp[x]++;
    }

    int ans = 1;

    for (auto &it : mp)

        ans = max(ans, it.second);

    cout << ans << endl;
}

vector<int> divisors;

void findDiv(int n)
{
    for (int i = 1; i * i <= n; i++)

        if (n % i == 0)
        {
            divisors.push_back(i);

            if (n / i != i)

                divisors.push_back(n / i);
        }
}

void O()
{
    int n;

    while (cin >> n and n)
    {
        findDiv(n);

        int cnt = 0;

        for (int i = 0; i < divisors.size(); i++)

            for (int j = i + 1; j < divisors.size(); j++)

                if (lcm(divisors[i], divisors[j]) == n)

                    cnt++;

        cout << n << " " << cnt + 1 << endl; // +1 for the pair (n, n)

        divisors.clear();
    }
}

void N__()
{
    int tc;

    int a, b;

    cin >> tc;

    while (tc--)
    {
        cin >> a >> b;

        // gcd = a, lcm = b
        // lcm = a * b / gcd = a * b / a = b
        // a * b = gcd * lcm

        if (b % a == 0)
            // If b is not a multiple of a,
            // then there do not exist integers x and y
            // such that gcd(x, y) = a and lcm(x, y) = b.

            cout << a << " " << b << endl;

        else

            cout << -1 << endl;
    }
}

void M()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        cout << "Case " << i << ": " << __gcd(abs(x1 - x2), abs(y1 - y2)) + 1 << endl;
    }
}

bool composite[N + 10] = {false};

void compositeSieve()
{
    int size = primes.size();

    for (int i = 0; i < size; i++)

        for (int j = i; j < size; j++)
        {
            if (primes[i] * primes[j] > N)

                break;

            composite[primes[i] * primes[j]] = true;
        }
}

void L()
{
    compositeSieve();

    int n;

    while (cin >> n)
    {
        int cnt = 0;

        while (n--)
        {
            int x;

            cin >> x;

            if (composite[x])

                cnt++;
        }

        cout << cnt << endl;
    }
}

set<int> divs;

void find_div(int n)
{
    for (int i = 1; i * i <= n; i++)

        if (n % i == 0)

            divs.insert(i), divs.insert(n / i);
}

void K()
{
    int tc;

    int a, b, l;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        cin >> a >> b >> l;

        find_div(l);

        int temp = lcm(a, b);

        bool flag = true;

        for (auto x : divs)

            if (lcm(temp, x) == l)
            {
                cout << "Case " << i << ": " << x << endl;

                flag = false;

                break;
            }

        if (flag)

            cout << "Case " << i << ": impossible" << endl;

        divs.clear();
    }
}

void J()
{
    int n;

    cin >> n;

    cin.ignore();

    while (n--)
    {
        vector<int> vec;

        string s;

        getline(cin, s);

        int num;

        stringstream iss(s);

        while (iss >> num)

            vec.push_back(num);

        int boro = INT_MIN;

        for (int i = 0; i < vec.size(); i++)

            for (int j = i + 1; j < vec.size(); j++)

                boro = max(boro, __gcd(vec[i], vec[j]));

        cout << boro << endl;
    }
}

void I()
{
    int n;

    while (cin >> n and n)
    {
        int sum = 0;

        for (int i = 1; i < n; i++)

            for (int j = i + 1; j <= n; j++)

                sum += __gcd(i, j);

        cout << sum << endl;
    }
}

vector<pair<int, int>> arr;

void sievePair()
{
    int size = primes.size();

    for (int i = 0; i < size; i++)

        if (primes[i] + 2 == primes[i + 1])

            arr.push_back({primes[i], primes[i + 1]});
}

void H()
{
    sievePair();

    int n;

    while (cin >> n)

        cout << "(" << arr[n - 1].first << ", " << arr[n - 1].second << ")" << endl;
}

void G()
{
    int n;

    while (cin >> n and n)
    {
        int cnt = 0;

        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] > n / 2)

                break;

            if (isprime[n - primes[i]])

                cnt++;
        }

        cout << cnt << endl;
    }
}

void F()
{
    int n;

    while (cin >> n and n)
    {
        for (int i = 0; i < primes.size(); i++)
        {
            if (isprime[n - primes[i]])
            {
                cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;

                break;
            }
        }
    }
}

vector<int> sumOfDivisors(N + 1, 0);

vector<int> answer(N + 1, -1);

void sieveSod()
{
    for (int i = 1; i <= N; i++)

        for (int j = i; j <= N; j += i) // every multiple of i

            sumOfDivisors[j] += i;

    for (int i = 1; i < N; i++)

        if (sumOfDivisors[i] <= N and answer[sumOfDivisors[i]] == -1)

            answer[sumOfDivisors[i]] = i;
}

void E()
{
    sieveSod();

    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        cout << answer[n] << endl;
    }
}

vector<int> ans;

void secondSieve()
{
    int size = primes.size();

    for (int i = 0; i < size; i++)

        for (int j = i + 1; j < size; j++)
        {
            if (primes[i] * primes[j] > range)

                break;

            ans.push_back(primes[i] * primes[j]);
        }

    sort(ans.begin(), ans.end());
}

void D()
{
    secondSieve();

    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        cout << ans[n - 1] << endl;
    }
}

void C()
{
    int n;

    cin >> n;

    if (n <= 2)
    {
        cout << 1 << endl;

        for (int i = 0; i < n; i++)

            cout << 1 << " ";

        cout << endl;

        return;
    }

    else
    {
        cout << 2 << endl;

        for (int i = 2; i <= n + 1; i++)

            if (isprime[i])

                cout << 1 << " ";

            else

                cout << 2 << " ";

        cout << endl;
    }
}

void B()
{
    int n, c;

    while (cin >> n >> c)
    {
        vector<int> v;

        v.push_back(1);

        for (int i = 0;; i++)
        {
            if (primes[i] > n)

                break;

            v.push_back(primes[i]);
        }

        cout << n << " " << c << ": ";

        int size = v.size();

        if (size % 2 == 0)
        {
            int cen1 = size / 2 - 1;

            int cen2 = cen1 + 1;

            int mid = (2 * c - 2) / 2;

            for (int i = cen1 - mid; i < cen1; i++)

                if (i >= 0)

                    cout << v[i] << " ";

            cout << v[cen1];

            cout << " " << v[cen2];

            for (int i = cen2 + 1; i <= mid + cen2; i++)

                if (i < size)

                    cout << " " << v[i];
        }

        else
        {
            int cen = size / 2;

            int mid = (2 * c - 1) / 2;

            for (int i = cen - mid; i < cen; i++)

                if (i >= 0)

                    cout << v[i] << " ";

            cout << v[cen];

            for (int i = cen + 1; i <= mid + cen; i++)

                if (i < size)

                    cout << " " << v[i];
        }

        cout << endl
             << endl;
    }
}

void A()
{
    int k;

    while (cin >> k and k != 0)
    {
        if (isprime[k])

            cout << 0 << endl;

        else
        {
            auto it = lower_bound(primes.begin(), primes.end(), k);

            cout << *it - *(it - 1) << endl;
        }
    }
}
