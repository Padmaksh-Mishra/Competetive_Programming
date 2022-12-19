# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	vll nh(51),lh(27);
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		nh[tmp]++;
	}
	deb()
	ll ns,ls;ns=ls=0;   
	for(int i=0;i<51;++i){
		ns=max(nh[i],ns);
	} 
	string s; cin >> s;
	for(int i=0;i<siz(s);++i){
		lh[s[i]-'a']++;
	}
	for(int j=0;j<27;++j){
		ls=maxlh[j];
	}

	if(ns>=ls) cout << "YES" << endl;
	else cout << "NO" << endl;
}
