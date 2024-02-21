#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL);

#define std_io freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#define mod 1000001

void AS();

signed main()
{
    fast_io;

    // std_io;

    AS();
}

void AS()
{
    int Ausar, Auset, Heru;

    while (cin >> Ausar >> Auset >> Heru)
    {
        if (Ausar == 0 && Auset == 0 && Heru == 0)

            break;

        // determine if right angle triangle

        if (Ausar * Ausar + Auset * Auset == Heru * Heru || Ausar * Ausar + Heru * Heru == Auset * Auset || Auset * Auset + Heru * Heru == Ausar * Ausar)

            cout << "right" << endl;

        else

            cout << "wrong" << endl;
    }
}

void AR()
{
    int tc;

    double quantity, price;

    cin >> tc;

    while (tc--)
    {
        cin >> quantity >> price;

        cout << fixed << setprecision(6) << (quantity > 1000 ? quantity * price * 0.9 : quantity * price) << endl;
    }
}

void AQ()
{
    int n, X = 0, Y = 0, Z = 0;

    cin >> n;

    while (n--)
    {
        int x, y, z;

        cin >> x >> y >> z;

        X += x;

        Y += y;

        Z += z;
    }

    if (X == 0 and Y == 0 and Z == 0)

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

void AP()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)

        cin >> v[i];

    while (true)
    {
        int Max = *max_element(v.begin(), v.end());

        int Min = *min_element(v.begin(), v.end());

        if (Max == Min)

            break;

        int MaxIndex = max_element(v.begin(), v.end()) - v.begin();

        int MinIndex = min_element(v.begin(), v.end()) - v.begin();

        v[MaxIndex] -= Min;
    }

    int sum = accumulate(v.begin(), v.end(), 0);

    cout << sum << endl;
}

void AO()
{
    int n, arr[8] = {0};

    cin >> n;

    for (int i = 1; i <= 7; i++)

        cin >> arr[i];

    for (int i = 1; i <= 7; i++)
    {
        n -= arr[i];

        if (n <= 0)
        {
            cout << i << endl;

            return;
        }

        if (i == 7)

            i = 0;
    }
}

void AN()
{
    int a, b;

    while (cin >> a >> b)

        cout << (a ^ b) << endl;
}

void AM()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        string s;

        cin >> s;

        int R = 0, G = 0, B = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')

                R++;

            else if (s[i] == 'G')

                G++;

            else

                B++;
        }

        cout << n - max({R, G, B}) << endl;
    }
}

void AL()
{
    int n, k, cnt = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        if (x % k == 0)

            cnt++;
    }

    cout << cnt << endl;
}

void AK()
{
    int n, sum = 0, Max = INT_MIN;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        sum += x;

        Max = max(Max, x);
    }

    cout << n * Max - sum << endl;
}

void AJ()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n;

        cin >> n;

        // Count number of 1s in binary representation

        int one1 = __builtin_popcount(n);

        // Convert integer to hexadecimal

        const char *hexNumber = to_string(n).c_str();

        // Convert hexadecimal to integer

        int decimalNumber = strtol(hexNumber, nullptr, 16);

        int one2 = __builtin_popcount(decimalNumber);

        cout << one1 << " " << one2 << endl;
    }
}

void AI()
{
    int tc;

    cin >> tc;

    int a, b, c;

    while (tc--)
    {
        cin >> a >> b >> c;

        if (a + b + c == 180)

            cout << "YES" << endl;

        else

            cout << "NO" << endl;
    }
}

void AH()
{
    map<string, string> mp;

    mp["B"] = "BattleShip";
    mp["C"] = "Cruiser";
    mp["D"] = "Destroyer";
    mp["F"] = "Frigate";
    mp["b"] = "BattleShip";
    mp["c"] = "Cruiser";
    mp["d"] = "Destroyer";
    mp["f"] = "Frigate";

    int tc;

    cin >> tc;

    while (tc--)
    {
        string s;

        cin >> s;

        cout << mp[s] << endl;
    }
}

bool visited[mod];

void AG()
{
    for (int i = 1; i <= mod; i++)
    {
        int num = i, sum = 0;

        while (num)
        {
            sum += num % 10;

            num /= 10;
        }

        if (sum + i <= mod)

            visited[sum + i] = true;
    }

    for (int i = 1; i <= mod; i++)

        if (!visited[i])

            // printf("%d\n", i);

            cout << i << endl;
}

void AF()
{
    int tc, n;

    cin >> tc;

    while (tc--)
    {
        cin >> n;

        if ((n >= 0 and n <= 5) and n != 3 and n != 4)

            cout << "NO" << endl;

        else

            cout << "YES" << endl;
    }
}

void AD()
{
    int n, rev = 0;

    cin >> n;

    while (n != 0)
    {
        rev = rev * 10 + n % 10;

        n /= 10;
    }

    cout << rev << endl;
}

void AC()
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

void AB()
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

void AA()
{
    int n;

    cin >> n;

    map<string, string> mp;

    string s1, s2;

    cin.ignore();

    while (n--)
    {
        getline(cin, s1);

        getline(cin, s2);

        mp[s1] = s2;
    }

    cin >> n;

    cin.ignore();

    while (n--)
    {
        getline(cin, s1);

        cout << mp[s1] << endl;
    }
}

void Z()
{
    string s;

    set<string> st;

    while (getline(cin, s))
    {
        int n = s.size();

        for (int i = 0; i < n; i++)

            if (!isalpha(s[i]))

                s[i] = ' ';

            else

                s[i] = tolower(s[i]);

        stringstream ss(s);

        string word;

        while (ss >> word)

            st.insert(word);
    }

    for (auto it : st)

        cout << it << endl;
}

void Y()
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

    for (int i = 0; i < n; i++)

        cout << v[i] << " " << mp[v[i]] << endl;
}

void X()
{
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int x = x2 - x1;

    int y = y2 - y1;

    cout << max(abs(x), abs(y)) << endl;
}

void W()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        if (n == 1 or n == 0)
        {
            cout << n << endl;

            continue;
        }

        int ans = n / (k + 1);

        cout << n - (ans * k) << endl;
    }
}

void V()
{
    int q;

    cin >> q;

    while (q--)
    {
        int n;

        cin >> n;

        int ans = 0;

        if (n == 1)
        {
            cout << 0 << endl;

            continue;
        }

        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
                ans++;
            }

            else if (n % 3 == 0)
            {
                n = (2 * n) / 3;
                ans++;
            }

            else if (n % 5 == 0)
            {
                n = (4 * n) / 5;
                ans++;
            }

            else if ((n % 2 != 0 && n % 3 != 0) && (n % 5 != 0))
            {
                if (n != 1)
                {
                    cout << -1 << endl;
                    break;
                }
            }

            if (n == 1)
            {
                cout << ans << endl;
                break;
            }
        }
    }
}

void U()
{
    int a, b;

    cin >> a >> b;

    if ((a + b) % 2 == 0)

        cout << (a + b) / 2 << endl;

    else

        cout << "IMPOSSIBLE" << endl;
}

void T()
{
    string s;

    cin >> s;

    int count = 0;

    int n = s.size();

    for (int i = 0; i < n; i++)

        if (s[i] == '4' || s[i] == '7')

            count++;

    if (count == 4 || count == 7)

        cout << "YES" << endl;

    else

        cout << "NO" << endl;
}

void S()
{
    int n, count = 0;

    cin >> n;

    int arr[n], comp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        comp[i] = arr[i];
    }

    sort(comp, comp + n);

    for (int i = 0; i < n; i++)

        if (arr[i] != comp[i])

            count++;

    if (count > 2)

        cout << "NO" << endl;

    else

        cout << "YES" << endl;
}

void R()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        double L;

        cin >> L;

        double W = L * 6 / 10;

        double R = L / 5;

        double red = acos(-1) * R * R;

        double green = L * W - red;

        cout << fixed << setprecision(2) << red << " " << green << endl;
    }
}

void Q()
{
    string s, t;

    cin >> s >> t;

    int hour1, hour2, min1, min2;

    hour1 = (s[0] - '0') * 10 + (s[1] - '0');

    hour2 = (t[0] - '0') * 10 + (t[1] - '0');

    min1 = (s[3] - '0') * 10 + (s[4] - '0');

    min2 = (t[3] - '0') * 10 + (t[4] - '0');

    int total1 = hour1 * 60 + min1;

    int total2 = hour2 * 60 + min2;

    int time = (total1 + total2) / 2;

    int hour = time / 60;

    int min = time % 60;

    cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << min << endl;
}

void P()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int a, b;

        cin >> a >> b;

        if (a > b)

            cout << ">" << endl;

        else if (a < b)

            cout << "<" << endl;

        else

            cout << "=" << endl;
    }
}

void O()
{
    int n, k, l, c, d, p, nl, np;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    cout << min({k * l / nl, c * d, p / np}) / n << endl;
}

void N()
{
    int tc;

    cin >> tc;

    while (tc--)
    {
        int x, y, z;

        cin >> x >> y >> z;

        if (z > (x * y) / 2)

            cout << "YES" << endl;

        else

            cout << "NO" << endl;
    }
}

void M()
{
    string s;

    int i = 1;

    while (cin >> s and s != "*")
    {
        if (s == "Hajj")

            cout << "Case " << i << ": "
                 << "Hajj-e-Akbar" << endl;

        else

            cout << "Case " << i << ": "
                 << "Hajj-e-Asghar" << endl;

        i++;
    }
}

void L()
{
    int n, od = 0, ev = 0, odindex = 0, evindex = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        if (x % 2 == 0)

            ev++, evindex = i + 1;

        else

            od++, odindex = i + 1;
    }

    if (ev == 1)

        cout << evindex << endl;

    else

        cout << odindex << endl;
}

void K()
{
    int x1, v1, x2, v2;

    cin >> x1 >> v1 >> x2 >> v2;

    if (v1 > v2 && (x2 - x1) % (v1 - v2) == 0)
        // the difference in their positions decreases by(v1 - v2).
        // So, if (x2 - x1) is a multiple of(v1 - v2),
        //  after a certain number of jumps,
        // the difference in their positions will become 0,
        // which means they meet.
        cout
            << "YES" << endl;

    else

        cout << "NO" << endl;
}

void J()
{
    string s;

    cin >> s;

    int n = s.size();

    int hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[n - 2] == 'P' && hour != 12)

        hour += 12;

    else if (s[n - 2] == 'A' && hour == 12)

        hour = 0;

    cout << setfill('0') << setw(2) << hour << s.substr(2, n - 4) << endl;
}

void I_v2()
{
    int n, Max = INT_MIN, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        if (x > Max)
        {
            Max = x;

            ans = 1;
        }

        else if (x == Max)

            ans++;
    }

    cout << ans << endl;
}

void I_v1()
{
    int n, Max = INT_MIN;

    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        Max = max(Max, x);

        mp[x]++;
    }

    cout << mp[Max] << endl;
}

void H()
{
    int n = 5, Max = INT_MIN, Min = INT_MAX, sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        Max = max(Max, x);

        Min = min(Min, x);

        sum += x;
    }

    cout << sum - Max << " " << sum - Min << endl;
}

void G()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";

        for (int j = 0; j < i + 1; j++)
            cout << "#";

        cout << endl;
    }
}

void F()
{
    int n;

    cin >> n;

    int pos = 0, neg = 0, zero = 0;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        if (x > 0)

            pos++;

        else if (x < 0)

            neg++;

        else

            zero++;
    }

    cout << fixed << setprecision(6) << (double)pos / n << endl;

    cout << fixed << setprecision(6) << (double)neg / n << endl;

    cout << fixed << setprecision(6) << (double)zero / n << endl;
}

void E()
{
    int n;

    cin >> n;

    int arr[n][n];

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)

            cin >> arr[i][j];

    int diag1 = 0, diag2 = 0;

    for (int i = 0; i < n; i++)
    {
        diag1 += arr[i][i];

        diag2 += arr[i][n - i - 1];
    }

    cout << abs(diag1 - diag2) << endl;
}

void D()
{
    int n = 3;

    int alice[n], bob[n], al = 0, bo = 0;

    for (int i = 0; i < n; i++)

        cin >> alice[i];

    for (int i = 0; i < n; i++)

        cin >> bob[i];

    for (int i = 0; i < n; i++)
    {
        if (alice[i] > bob[i])

            al++;

        else if (alice[i] < bob[i])

            bo++;
    }

    cout << al << " " << bo << endl;
}

void C()
{
    int n, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        ans += x;
    }

    cout << ans << endl;
}

void B()
{
    int n, ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;

        cin >> x;

        ans += x;
    }

    cout << ans << endl;
}

void A()
{
    int a, b;

    cin >> a >> b;

    cout << a + b << endl;
}