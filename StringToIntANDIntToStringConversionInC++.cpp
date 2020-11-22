#include <bits/stdc++.h>
#define int long long
using namespace std;

string intToString(int n)
{
    int temp = 0;
    string ans;
    while (n != 0)
    {
        temp = n % 10;
        ans += temp + '0';
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int stringToInt(string s)
{
    int ans = 0;
    int ten = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ans = ans + (ten * (s[i] - '0'));
        ten *= 10;
    }

    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    string its = intToString(n);
    cout << "This is a string converted integer  " << its << endl;
    string s;
    cin >> s;
    int sti = stringToInt(s);
    cout << "This is a integer converted string  " << sti << endl;
}
