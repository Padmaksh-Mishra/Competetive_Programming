// using KMP algo
# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

using namespace std;
typedef long long ll;

ll const MOD = 1e9 + 1;
int const len = 1e6 + 100;
ll p[len],hsh[len+1];

void solve();
void hsher(string const &s,int n);
void powers();
ll needleHash(string const &s,int n);


int main(){

	powers();
	int tc;cin >> tc;
	while(tc--){
		solve();
	}
	return 0;
}

void solve(){
	vector<int> v;
	string s;cin >> s;
	string needle;cin >> needle;
	int n = needle.length();
	ll nhsh = needleHash(needle,needle.length());
	hsher(s,s.length());
	int tms = s.length()-needle.length();
	int count = 0;
	for(int i = 0;i<=tms;i++){
		ll tmp = (hsh[i+n] - hsh[i] + MOD)%MOD;
		ll x = (nhsh*p[i])%MOD;
		if(tmp==x) {
			count ++;
			v.push_back(i+1);
		}
	}
	if(count) {
		cout << count << endl;
		for (auto val:v) cout << val << " ";
		cout << endl;
	}else cout << "Not Found" << endl;
	cout << endl;

	return;
}

void powers(){
	p[0] = 1;
	for(int i = 1;i<len;i++) p[i] = (p[i-1]*31)%MOD;
}

void hsher(string const &s,int n){
	hsh[0] = 0;
	for(int i=1;i<=n;i++){
		hsh[i] = (hsh[i-1] + ((s[i-1]-'a'+1)*p[i-1])%MOD)%MOD;
	}
	return;
}

ll needleHash(string const &s,int n){
	ll ihsh = 0;
	for(int i=1;i<=n;i++){
		ihsh = (ihsh + ((s[i-1]-'a'+1)*p[i-1])%MOD)%MOD;
	}
	return ihsh;		
}