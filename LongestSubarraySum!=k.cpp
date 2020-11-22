#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int sum = 0;
    for (auto &i : a) {
      cin >> i;
      (sum += i) %= x;
 
    }
    if (sum != 0) {
      cout << n << endl;
    } else {
      int l = 0, r = n - 1;
      while (a[l] % x == 0 && l < n) {
        l++;
      }
      while (a[r] % x == 0 && r >= 0) {
        r--;
      }
      if (l < r) {
        cout << max(n - 1 - l , r) << endl;
      } 
      if(l==n&&r==-1){
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}