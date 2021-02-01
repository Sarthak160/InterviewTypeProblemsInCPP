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
#define MP make_pair
#define vii vector<pair<int, int>>
#define vs vector<string>
#define pii pair<int, int>
#define rall(x) (x).begin(), (x).end(), greater<>()
using namespace std;

// ALL YOU HAVE IS NOW !!!

// Some of the Math functions of daily use ..

int Ceil_check(int k, int n)
{
    long double x = (long double)k / n;
    int x1 = k / n;
    if (x == x1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

// let's go ....
int32_t main()
{

    fast_io int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        vii intervals;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            intervals.PB({x, y});
        }

        sort(all(intervals));
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].first >= intervals[i - 1].first && intervals[i].first <= intervals[i - 1].second)
            {
                // cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
                intervals[i].first = intervals[i - 1].first;

                intervals[i - 1].first = -1;
                intervals[i].second = max(intervals[i].second, intervals[i - 1].second);
                intervals[i - 1].second = -1;
            }
        }

        vii ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].first != -1 and intervals[i].second != -1)
            {
                ans.push_back({intervals[i].first, intervals[i].second});
            }
        }

        for (auto it : ans)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
}

// sort(all(a));
// printall(a);
