#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000000007

const double PI = 3.1415926535897;

void H();

signed main()
{
    fast_io;

    // std_io;

    H();
}

void H()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        string s;

        cin >> s;

        for (int i = 0; i < s.size(); i++)

            if (s[i] == '0')

                s[i] = ' ';

        vector<int> v;

        stringstream ss(s);

        string word;

        while (ss >> word)

            v.push_back(word.size());

        sort(v.begin(), v.end(), greater<int>());

        int alice = 0;

        for (int i = 0; i < v.size(); i++)

            if (i % 2 == 0)

                alice += v[i];

        cout << alice << endl;
    }
}

void G()
{
    int n;

    cin >> n;

    string s = to_string(n);

    int sum = 0;

    for (int i = 0; i < s.size(); i++)

        sum += s[i] - '0';

    n % sum == 0 ? cout << "Yes" << endl : cout << "No" << endl;
}

void F()
{
    string s;

    cin >> s;

    int sum = 0;

    for (int i = 0; i < s.size(); i++)

        s[i] == '+' ? sum++ : sum--;

    cout << sum << endl;
}

bool is_prime(int num)
{

    if (num == 1)

        return false;

    for (int i = 2; i * i <= num; i++)

        if (num % i == 0)

            return false;

    return true;
}

bool isPrime(int n);

void E()
{
    int tc, n, m;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        int cnt = 0;

        cin >> n >> m;

        for (int i = n; i <= m; i++)

            if (isPrime(i))

                cnt++;

        printf("Case %d: %d\n", i, cnt);
    }
}

bool isPrime(int n)
{
    if (n <= 1)

        return false;

    if (n <= 3)

        return true;

    if (n % 2 == 0 || n % 3 == 0)

        return false;

    for (int i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return false;

    return true;
}

void D()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x;

        cin >> x;

        if (isPrime(x))

            cout << "yes" << endl;

        else

            cout << "no" << endl;
    }
}

vector<int> divisors;

void find_div(int n)
{
    for (int i = 1; i * i <= n; i++)

        if (n % i == 0)
        {
            divisors.push_back(i);

            if (n / i != i)

                divisors.push_back(n / i);
        }
}

void C()
{
    int n, boro = INT_MIN;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        boro = max(boro, v[i]);
    }

    sort(v.begin(), v.end(), greater<int>());

    divisors.clear();

    find_div(boro);

    sort(divisors.begin(), divisors.end(), greater<int>());

    for (int i = 0; i < v.size(); i++)

        if (divisors[i] != v[i])
        {
            cout << boro << " " << v[i] << endl;

            return;
        }
}

void B()
{
    int n, a, b;

    cin >> n >> a >> b;

    if (a == 1)
    {
        if ((n - 1) % b == 0)

            cout << "Yes" << endl;

        else

            cout << "No" << endl;
    }

    else
    {
        int x = 1;

        while (x <= n)
        {
            if ((n - x) % b == 0)
            {
                cout << "Yes" << endl;

                return;
            }

            x *= a;
        }

        cout << "No" << endl;
    }
}

void A()
{
    int n;

    cin >> n;

    cout << n * n;
}
