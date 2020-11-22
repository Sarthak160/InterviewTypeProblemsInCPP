#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ll long long
using namespace std;

int totbits(int N) {
	ll count0 = 0, count1 = 0;

	while (N > 0) {

		if (N & 1) {
			count1++;
		}

		else {
			count0++;
		}

		N = N >> 1;
	}

	return (count0 + count1);
}
ll bitsof1(ll N) {
	ll count0 = 0, count1 = 0;

	while (N > 0) {
		if (N & 1) {
			count1++;
		}

		else {
			count0++;
		}

		N = N >> 1;
	}

	return  count1;
}
void bin(ll n) {
	if (n > 1)
		bin(n>>1);
	cout<< (n & 1);
}
ll bitsof0(ll N) {
	ll count0 = 0, count1 = 0;

	while (N > 0) {

		if (N & 1) {
			count1++;
		} else {
			count0++;
		}

		N = N >> 1;
	}
	return  count0;
}

void subsetsUtil(vector<ll>& A, vector<vector<ll> >& res,
                 vector<ll>& subset, ll index) {
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {

		subset.push_back(A[i]);

		subsetsUtil(A, res, subset, i + 1);

		subset.pop_back();
	}

	return;
}

vector<vector<ll> > subsets(vector<ll>& A) {
	vector<ll> subset;
	vector<vector<ll> > res;

	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}


int main() {
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	ll mx =*max_element (arr.begin(),arr.end());

	ll lsb = totbits(mx);
    // cout<<lsb<<endl;
	vector<vector<ll> > res = subsets(arr);

	ll cnt =0,temp=0;
	for (int i = 0; i < res.size(); i++) {
		ll cnt0  =0 , cnt1 = 0;
		for (ll j = 0; j < res[i].size(); j++) {
			if(i==0 and j==0) {
				break;
			}
			temp = res[i][j];
			ll bits = totbits(temp);
            if(bits<lsb) {
				cnt0 += lsb - bits;
			}

			cnt0 += bitsof0(temp);
			cnt1 += bitsof1(temp);
		}
		if(cnt0==cnt1 and i!=0) {
			cnt++;
		}

	}
    ll bits = totbits(cnt);
    if(cnt == 0){
    bits = 1;    
    }
	
    if(bits<lsb) {
		bits = lsb - bits;
	}
	for(ll i=0; i<bits; i++) {
		cout<<0;
        
	}
	bin(cnt);
	cout<<endl;
}

