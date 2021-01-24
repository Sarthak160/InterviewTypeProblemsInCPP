#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define printall(a)        \
    for (auto it : a)      \
        cout << it << " "; \
    cout << "\n";
#define PB push_back
using namespace std;

// ALL YOU HAVE IS NOW !!!
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int32_t main()
{

    fast_io

        int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        string a, b, s1, s2;
        cin >> a >> b;
        int res = lcm(a.length(), b.length());
        int t1 = res / a.length();
        int t2 = res / b.length();

        for (int i = 0; i < t1; i++)
        {
            s1 += a;
        }

        for (int i = 0; i < t2; i++)
        {
            s2 += b;
        }
        if (s1 == s2)
        {
            cout << s1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

// sort(all(a));
// printall(a);
