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
	string a,b; cin >> a >> b;
	vector<pair<ll,ll>> ops;
	ll x = count(all(a),'1');
	vll flips(n,x);
	ll eq = 0,neq=0;
	for(int i=0;i<n;++i){
		if(a[i]==b[i]) eq++;
		else neq++;
	}
	if(eq==0||neq==0){
		bool equal = (eq==n);
		for(int i=0;i<n;++i){
			if(a[i]=='1'){
				ops.pb(make_pair(i+1,i+1));
				equal^=1;
			}
		}
		if(!equal){
			ops.pb(make_pair(1,1));
			ops.pb(make_pair(2,n));
			ops.pb(make_pair(1,n));
		}
		cout << "YES" << endl;
		cout << siz(ops) << endl;
		for(auto move : ops){
			cout << move.f << " " << move.s << endl;
		}
	}else{
		cout << "NO" << endl;
	}
}
