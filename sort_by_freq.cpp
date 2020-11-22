// prob name -
//author - COOL
#include <iostream>
#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < n; i++)
#define ff first
#define ss second
#define int long long int
#define endl "\n"
#define mii map<int, int>
#define umii unordered_map<int, int>
#define vi vector<int>
#define fi(i, a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define fo(i, a, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << a[i] << " ";    \
    }
#define PB push_back
#define MP make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define mk(arr, n, type) type *arr = new type[n];
#define pw(b, p) pow(b, p) + 0.1
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define Pi 3.14159265358979
#define minall(a) *min_element(a, a + n)
#define maxall(a) *max_element(a, a + n)
using namespace std;

/*                                   ____
  ||     //\\    ||\  /||   || / || ||   ||   //\\
  ||    //  \\   || \/ ||   ||/  || ||___||  //  \\
  ||   //____\\  ||    ||   ||\  || ||\\    //____\\
  ||  //      \\ ||    ||   || \ || || \\  //      \\
*/

void lets_do_it()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

mii mp;

bool sort_by_value(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return mp[a.first] < mp[b.first];
    return a.second > b.second;
}

int32_t main()
{
    //lets_do_it();
    w(t)
    {
        int n, k;
        cin >> n;
        int a[n];
        fi(i, a, n)
            umii vis;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            vis[a[i]] = 0;
        }
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            if (vis[a[i]] == 0)
            {
                v.PB(make_pair(a[i], mp[a[i]]));
                vis[a[i]] = 1;
            }
        }

        sort(v.begin(), v.end(), sort_by_value);

        for (auto it : v)
        {
            int temp = it.first;
            while (it.second--)
            {
                cout << temp << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
