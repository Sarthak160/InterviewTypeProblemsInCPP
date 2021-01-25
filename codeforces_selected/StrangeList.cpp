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
int mT(int N, int x)
{
    int ans = 0;
    while (N % x == 0)
    {
        N /= x;
        ans++;
    }
    return ans;
}
int32_t main()
{

    fast_io int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        int n, x, i = 0, j = 0, ans = 0;
        cin >> n >> x;
        vector<pair<int, int>> a;
        for (i = 0; i < n; i++)
        {
            cin >> j;
            a.PB({j, 1});
        }
        // a[i].second*x this is written because hum uski sari occurance ko ek hi bari m handle karlenge ki jab robot wha phuche to beshak kafi baar reccurred ho lekin wha a[i].second m uski sari frequency padi ho
        for (i = 0; i < a.size(); i++)
        {
            ans += a[i].first * a[i].second;
            if (a[i].first % x == 0)
            {
                a.PB({a[i].first / x, a[i].second * x});
            }
            else
            {
                break;
            }
        }
        i++;
        while (i < a.size())
        {
            ans += a[i].first * a[i].second;
            i++;
        }
        cout << ans << endl;
    }
}

// sort(all(a));
// printall(a);
