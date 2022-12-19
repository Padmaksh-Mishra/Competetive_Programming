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
	char c; cin >> c;
	ll x;
	ll hsh[3] = {0,0,0};
	string s; cin >> s;
	ll dg = 0;
	for(int i=0;i<n;++i){
		if(s[i]=='g'){
			dg=i+1;
			break;
		}
	}
	// deb(dg);
	for(int i=n-1;i>=0;--i){
		if(s[i]=='r') x=0;
		else if(s[i]=='y') x=1;

		if(s[i]=='g') dg=1;
		else{
			hsh[x] = max(hsh[x],dg);
			dg++;
		}
	}
	if(c=='r') x=0;
	else if(c=='y') x=1;
	else x=2;
	cout << hsh[x] << endl;
}
