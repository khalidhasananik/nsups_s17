#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000

const double PI = 3.1415926535897;

const int N = 1e6 + 10;

void S();

signed main()
{
    fast_io;

    // std_io;

    S();
}

void S()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        int arr[n];

        for (int &i : arr)

            cin >> i;

        sort(arr, arr + n);

        int low = 0, high = arr[n - 1] - arr[0], ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int cows = 1, last_pos = arr[0];

            for (int i = 1; i < n; i++)

                if (arr[i] - last_pos >= mid)

                    cows++, last_pos = arr[i];

            cows >= k ? ans = mid, low = mid + 1 : high = mid - 1;
        }

        cout << ans << endl;
    }
}

void R()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int num;

        cin >> num;

        int n = num, max = 0, divisior = 0, cnt;

        for (int i = 2; i * i <= num; i++)
        {
            cnt = 0;

            while (num % i == 0)

                num /= i, cnt++;

            cnt > max ? max = cnt, divisior = i : 0;
        }

        if (divisior == 0)

            cout << 1 << endl
                 << n << endl;

        else
        {
            cout << max << endl;

            while (n % (divisior * divisior) == 0)

                cout << divisior << " ", n /= divisior;

            cout << n << endl;
        }
    }
}

bool is_prime(int n)
{
    if (n < 2)

        return false;

    for (int i = 2; i * i <= n; i++)

        if (n % i == 0)

            return false;

    return true;
}

void Q()
{
    int n;

    cin >> n;

    if (n == 1)

        cout << 1 << endl
             << 1 << endl;

    else if (n == 2)

        cout << 1 << endl
             << 1 << " " << 1 << endl;

    else
    {
        cout << 2 << endl;

        for (int i = 2; i <= n + 1; i++)

            cout << (is_prime(i) ? 1 : 2) << " ";
    }
}

void P()
{
    int n, gcd = 0;

    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        gcd = __gcd(gcd, x);

        for (int j = 2; j * j <= x; j++)
        {
            if (x % j == 0)

                mp[j]++;

            while (x % j == 0)

                x /= j;
        }

        if (x > 1)

            mp[x]++;
    }

    bool flag = true;

    for (auto it : mp)

        if (it.second != 1)
        {
            flag = false;

            break;
        }

    if (flag)

        cout << "pairwise coprime" << endl;

    else

        cout << (gcd == 1 ? "setwise coprime" : "not coprime") << endl;
}

void O()
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

                mp[i]++;

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

map<int, int> mp;

void divisiors(int n)
{
    for (int d = 2; d * d <= n; d++)

        while (n % d == 0)

            mp[d]++, n /= d;

    if (n > 1)

        mp[n]++;
}

void N_()
{
    int n;

    while (cin >> n && n)
    {
        mp.clear();

        divisiors(n);

        int sum = 0;

        for (auto it : mp)

            sum += (it.second * it.first);

        cout << sum << endl;
    }
}

bool isPrime[N];

vector<int> primes;

void sieve_w_pb()
{
    fill_n(isPrime, N, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (!isPrime[i])

            continue;

        primes.push_back(i);

        for (int j = i * i; j < N; j += i)

            isPrime[j] = false;
    }
}

bool composite[N + 10] = {false};

void compositeSieve()
{
    sieve_w_pb();

    int size = primes.size();

    for (int i = 0; i < size; i++)

        for (int j = i; j < size; j++)
        {
            if (primes[i] * primes[j] > N)

                break;

            composite[primes[i] * primes[j]] = true;
        }
}

void M()
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

void L()
{
    int n;

    cin >> n;

    cout << 25 << endl;
}

string smallest(int n)
{
    if (n < 10)

        return to_string(n);

    string ans = "";

    for (int i = 9; i > 1; i--)

        while (n % i == 0)

            n /= i, ans += to_string(i);

    if (n > 1)

        return "-1";

    reverse(ans.begin(), ans.end());

    return ans;
}

void K()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        cout << smallest(n) << endl;
    }
}

int binPow(int x, int l)
{
    int ans = 1;

    x %= mod;

    while (l)
    {
        if (l & 1)

            ans = (ans * x) % mod;

        x = (x * x) % mod;

        l >>= 1;
    }

    return ans;
}

void J()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        double temp = k * log10(n);

        int ans = pow(10, temp - (int)temp) * 100;

        printf("%lld...%03lld\n", ans, binPow(n % mod, k)); // n % mod is used to avoid overflow
    }
}

bool isprime[N];

void sieve()
{
    fill_n(isprime, N, true);

    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= N; i++)

        if (isprime[i] && (int)i * i <= N)

            for (int j = i * i; j <= N; j += i)

                isprime[j] = false;
}

void I()
{
    sieve();

    int n;

    cin >> n;

    while (n--)
    {
        int x;

        cin >> x;

        int sq = sqrt(x);

        cout << (sq * sq == x && isprime[sq] ? "YES" : "NO") << endl;
    }
}

void primeFactors(int m)
{
    int n = abs(m);

    cout << m << " = ";

    if (m < 0)

        cout << "-1 x ";

    for (int i = 2; i * i <= n; i++)

        if (n % i == 0)

            while (n % i == 0)
            {
                cout << i;

                n /= i;

                if (n == 1)

                    break;

                else

                    cout << " x ";
            }

    if (n > 1)

        cout << n;
}

void G()
{
    int n;

    while (cin >> n && n)

        primeFactors(n), cout << endl;
}

int binpow(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)

            res = (res * a) % 10;

        a = (a * a) % 10;

        b >>= 1;
    }

    return res;
}

void F()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int a, b;

        cin >> a >> b;

        cout << binpow(a, b) << endl;
    }
}

void E()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int x;

            cin >> x;

            for (int i = 2; i * i <= x; i++)

                while (x % i == 0)

                    mp[i]++, x /= i;

            if (x > 1)

                mp[x]++;
        }

        bool flag = true;

        for (auto it : mp)

            if (it.second % n != 0)
            {
                flag = false;

                break;
            }

        cout << (flag ? "YES" : "NO") << endl;
    }
}

vector<int> primesUnderRoot1000 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void D()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        vector<int> a(n);

        for (int &i : a)

            cin >> i;

        vector<int> b(n, -1);

        int ans = 1;

        for (int div : primesUnderRoot1000)
        {
            bool flag = false;

            for (int i = 0; i < n; i++)
            {
                if (b[i] != -1 or a[i] % div != 0)

                    continue;

                flag = true, b[i] = ans;
            }

            if (flag)

                ans++;
        }

        cout << ans - 1 << endl;

        for (int i : b)

            cout << i << " ";

        cout << endl;
    }
}

int BigMod(int a, int b, int m)
{
    a %= m;

    int res = 1;

    while (b > 0)
    {
        if (b & 1)

            res = res * a % m;

        a = a * a % m;

        b >>= 1;
    }

    return res;
}

void C()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x, y, z;

        cin >> x >> y >> z;

        if (x == 0)
            break;

        cout << BigMod(x, y, z) << endl;
    }
}

void B()
{
    int n;

    while (cin >> n && n)
    {
        map<int, int> mp;

        for (int i = 2; i * i <= n; i++)

            while (n % i == 0)

                mp[i]++, n /= i;

        if (n > 1)

            mp[n]++;

        for (auto it : mp)

            cout << it.first << "^" << it.second << " ";

        cout << endl;
    }
}

void A()
{
    int b, p, m;

    while (cin >> b >> p >> m)

        cout << BigMod(b, p, m) << endl;
}