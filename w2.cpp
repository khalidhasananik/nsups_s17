#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 998244353

// const int mod = 1e9 + 7;

const double PI = 3.1415926535897;

const int Num = 1e6 + 7;

bool isprime[Num];

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

void sieve()
{
    fill_n(isprime, Num, true);

    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= Num; i++)

        if (isprime[i] && (int)i * i <= Num)

            for (int j = i * i; j <= Num; j += i)

                isprime[j] = false;
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

vector<int> factors;

void primeFactors(int n, int k)
{
    int c = 2, cnt = 0;

    while (n > 1)
    {
        if (n % c == 0)
        {
            cnt++;

            if (cnt > k - 1)
            {
                factors.push_back(n);

                return;
            }

            factors.push_back(c);

            n /= c;
        }

        else

            c++;
    }
}

void somFunc(int b)
{
    int a = 0;
    {
        a = 1;
        {
            a = 2;
            {
                a = 3;

                cout << a << endl;
            }
        }
    }

    int x = 10;

    if (x > 10)

        cout << "hello" << endl;

    while (x > 10)
    {
        cout << "hello" << endl;
    }
}

void Y();

signed main()
{
    fast_io;

    std_io;

    // sieve();

    // Y();

    somFunc(0);
}

void Y()
{
    int a, b, c;

    cin >> a >> b >> c;

    int ans1 = ((a * (a + 1)) / 2) % mod;

    int ans2 = ((b * (b + 1)) / 2) % mod;

    int ans3 = ((c * (c + 1)) / 2) % mod;

    int ans = (ans1 * ans2) % mod;

    ans = (ans * ans3) % mod;

    cout << ans << endl;
}

int arrayay[10];

void X()
{
    string s, t = "chokudai";

    cin >> s;

    arrayay[0] = 1;

    for (int i = 0; i < s.size(); i++)

        for (int j = 0; j < 8; j++)

            if (s[i] == t[j])

                arrayay[j + 1] = (arrayay[j + 1] + arrayay[j]) % mod;

    cout << arrayay[8] << endl;
}

bool leapyear(int n)
{
    return (!(n % 4) and (n % 100) or !(n % 400));
}

void W()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        string s;

        int n;

        cin >> s >> n;

        for (int i = 0; i < s.size(); i++)

            if (s[i] == '-')

                s[i] = ' ';

        int year, day;

        string month;

        stringstream ss(s);

        ss >> year >> month >> day;

        string months[13] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        map<string, int> m;

        m[months[1]] = 31;
        m[months[2]] = 28;
        m[months[3]] = 31;
        m[months[4]] = 30;
        m[months[5]] = 31;
        m[months[6]] = 30;
        m[months[7]] = 31;
        m[months[8]] = 31;
        m[months[9]] = 30;
        m[months[10]] = 31;
        m[months[11]] = 30;
        m[months[12]] = 31;

        int totalDays = 0;

        for (int i = 1; months[i] != month; i++)

            totalDays += m[months[i]];

        if (leapyear(year) and month != "January" and month != "February")

            totalDays++;

        totalDays += day + n;

        for (int i = year;; i++)
        {
            if (totalDays <= 365)
                break;

            if (leapyear(i))
                totalDays -= 366, year++;

            else
                totalDays -= 365, year++;
        }

        if (leapyear(year))
            m[months[2]] = 29;

        for (int i = 1; i <= 12; i++)
        {
            if (totalDays <= m[months[i]])
            {
                month = months[i];
                day = totalDays;
                break;
            }

            totalDays -= m[months[i]];
        }

        cout << "Case " << i << ": " << year << "-" << month << "-";

        day < 10 ? cout << "0" << day << endl : cout << day << endl;
    }
}

int arr[1005];

void V()
{
    while (cin >> arr[0])
    {
        if (arr[0] == 0)

            break;

        int indx = 1;

        while (cin >> arr[indx])
        {
            if (arr[indx] == 0)

                break;

            indx++;
        }

        int ans = 0, diff;

        for (int i = 1; i < indx; i++)
        {
            diff = arr[i] - arr[i - 1];

            ans = __gcd(ans, diff);
        }

        cout << abs(ans) << endl;
    }
}

void U()
{
    int q;

    cin >> q;

    while (q--)
    {
        int n;

        cin >> n;

        if (n == 1)
        {
            cout << 0 << endl;

            continue;
        }

        int cnt2, cnt3, cnt5;

        cnt2 = cnt3 = cnt5 = 0;

        while (n % 2 == 0)

            cnt2++, n /= 2;

        while (n % 3 == 0)

            cnt3++, n /= 3;

        while (n % 5 == 0)

            cnt5++, n /= 5;

        if (n != 1)

            cout << -1 << endl;

        else

            cout << cnt2 + cnt3 * 2 + cnt5 * 3 << endl;
        // let's say n = 5, divsible by 5, so cnt5 = 1,
        // why multiply cnt5 by 3?
        // because the condition is to replace the number with 4n/5
        // so, 4n/5 = 4 * 5 = 20, 20/5 = 4, divisible by 2; so, n/2; 4/2 = 2, again 2/2 = 1
        // so, everytime a number is divisible by 5,
        // we need 3 operations in total to make it 1
        // so, cnt5 * 3
        // think for cnt3 * 2 the same way
    }
}

bool larzeDiv(string a, int b)
{
    int len = a.length(), idx, rem = 0;

    a[0] == '-' ? idx = 1 : idx = 0;

    for (; idx < len; idx++)

        rem = (rem * 10) + (a[idx] - '0'), rem = rem % b;

    bool flag;

    rem == 0 ? flag = true : flag = false;

    return flag;
}

void T()
{
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        string s;

        int n;

        cin >> s >> n;

        bool flag = larzeDiv(s, n);

        cout << "Case " << i << ": ";

        flag ? cout << "divisible" << endl : cout << "not divisible" << endl;
    }
}

void S()
{
    int n;

    cin >> n;

    for (int i = 2; i * i <= n; i++)

        while (n % (i * i) == 0)

            n /= i;

    cout << n << endl;
}

void R()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        vector<int> v;

        int pow = 1;

        while (n > 0)
        {
            if (n % 10 > 0)

                v.push_back((n % 10) * pow);

            n /= 10;

            pow *= 10;
        }

        cout << v.size() << endl;

        for (auto i : v)

            cout << i << " ";

        cout << endl;
    }
}

bool larzediv(string a, int b)
{
    int len = a.length(), idx, rem = 0;

    a[0] == '-' ? idx = 1 : idx = 0;

    for (; idx < len; idx++)

        rem = (rem * 10) + (a[idx] - '0'), rem = rem % b;

    bool flag;

    rem == 0 ? flag = true : flag = false;

    return flag;
}

bool leapyear(string s)
{
    if (larzediv(s, 400))
        return true;

    else if (larzediv(s, 100))
        return false;

    else if (larzediv(s, 4))
        return true;

    else
        return false;
}

void Q()
{
    string year;

    int flag = 0;

    while (cin >> year)
    {
        if (flag != 0)
            cout << endl;

        flag = 1;

        if (leapyear(year))
        {
            cout << "This is leap year." << endl;

            if (larzediv(year, 15))
                cout << "This is huluculu festival year." << endl;

            if (larzediv(year, 55))
                cout << "This is bulukulu festival year." << endl;
        }

        else if (larzediv(year, 15))
            cout << "This is huluculu festival year." << endl;

        else
            cout << "This is an ordinary year." << endl;
    }
}

void P()
{
    int n, a, b;

    cin >> n >> a >> b;

    int ans = (a + b) % n;

    if (ans == 0)

        ans = n;

    else if (ans < 0)

        ans += n;

    cout << ans << endl;
}

void O()
{
    int a, b, cnt = 0;

    cin >> a >> b;

    while (a <= b)
    {
        a *= 3;

        b *= 2;

        cnt++;
    }

    cout << cnt << endl;
}

void N()
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

void productOfThree(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int a = n / i;

            for (int j = i + 1; j * j < a; j++)
            // j * j < a is enough casuse if
            // j * j == a then a is a perfect square
            // and we can't find a third number
            {
                if (a % j == 0)
                {
                    cout << "YES" << endl;

                    cout << i << " " << j << " " << a / j << endl;

                    return;
                }
            }
        }
    }

    cout << "NO" << endl;

    return;
}

void M()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        productOfThree(n);
    }
}

void L()
{
    int n, k;

    cin >> n >> k;

    factors.clear();

    primeFactors(n, k);

    if (factors.size() < k)

        cout << -1 << endl;

    else

        for (int i = 0; i < factors.size(); i++)

            cout << factors[i] << " ";

    cout << endl;
}

void K()
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
    {
        if (divisors[i] != v[i])
        {
            cout << boro << " " << v[i] << endl;

            return;
        }
    }
}

void J()
{
    string s;

    while (cin >> s)
    {
        int sum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (isupper(s[i]))

                sum += s[i] - 'A' + 27;

            else

                sum += s[i] - 'a' + 1;
        }

        if (sum == 1)

            cout << "It is a prime word." << endl;

        else if (isPrime(sum))

            cout << "It is a prime word." << endl;

        else

            cout << "It is not a prime word." << endl;
    }
}

void I()
{
    int n, k;

    cin >> n >> k;

    divisors.clear();

    find_div(n);

    sort(divisors.begin(), divisors.end());

    if (k > divisors.size())

        cout << -1 << endl;

    else

        cout << divisors[k - 1] << endl;
}

void H()
{
    int n, sum = 0, i = 1;

    cin >> n;

    for (;; i++)
    {
        if (sum >= n)

            break;

        sum += i;
    }

    cout << i - 1 << endl;
}

void G()
{
    int n;

    cin >> n;

    divisors.clear();

    find_div(n);

    sort(divisors.begin(), divisors.end());

    for (int i = 0; i < divisors.size(); i++)

        cout << divisors[i] << " ";

    cout << endl;
}

void F()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, m;

        cin >> n >> m;

        for (int i = n; i <= m; i++)

            if (isPrime(i))

                cout << i << endl;
    }
}

void E()
{
    int n;

    cin >> n;

    if (n - 2 > 0 and isPrime(n - 2))

        cout << 2 << " " << n - 2 << endl;

    else

        cout << -1 << endl;
}

void D()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        set<int> s, t;

        for (int i = 0; i < n; i++)
        {
            int x;

            cin >> x;

            s.insert(x);
        }

        int num = *s.begin() * *s.rbegin();

        for (int i = 2; i * i <= num; i++)

            if (num % i == 0)
            {
                t.insert(i);

                t.insert(num / i);
            }

        s == t ? cout << num << endl : cout << -1 << endl;
    }
}

vector<int> divisors_also_divisible_by_2;

void find_div_2(int n)
{
    for (int i = 1; i * i <= n; i++)

        if (n % i == 0)
        {
            if (i % 2 == 0)

                divisors_also_divisible_by_2.push_back(i);

            if (n / i != i)

                if ((n / i) % 2 == 0)

                    divisors_also_divisible_by_2.push_back(n / i);
        }
}

void C()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x;

        cin >> x;

        divisors_also_divisible_by_2.clear();

        find_div_2(x);

        cout << divisors_also_divisible_by_2.size() << endl;
    }
}

void B()
{
    sieve();

    int n;

    while (cin >> n)
    {
        string s = to_string(n);

        reverse(s.begin(), s.end());

        int rev = stoi(s);

        if (isprime[n] && isprime[rev] && n != rev)

            cout << n << " is emirp." << endl;

        else if (isprime[n])

            cout << n << " is prime." << endl;

        else

            cout << n << " is not prime." << endl;
    }
}

void A()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x;

        cin >> x;

        divisors.clear();

        find_div(x);

        cout << accumulate(divisors.begin(), divisors.end(), 0) - x << endl;
    }
}