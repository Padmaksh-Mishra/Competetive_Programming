# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
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
	string s; cin >> s;
	ll n = siz(s);
	vll hsh(n);
	ll k; cin >> k;
	vector<vll> v;
	for(int i=0;i<n;++i){
		ll w = 0;
		ll m = s[i]-'0';
		ll j = i;
		deb(m);
		while(s[i+1]=='0'&&i<n-1){
			w++;
			i++;
		}
		//i--;
		vll tmp = {m,w,j};
		v.emplace_back(tmp);
	}
	sort(all(v),[](vll a,vll b)->bool{
		if(a[0]==b[0]){
			return b[1]>a[1];
		}
		return a[0]>b[0];
	});
	for(auto val : v){
		cout << val[0] << " " << val[1] << " " << val[2] << endl;
		ll w = val[1];
		ll m = val[0];
		ll j = val[2];
		if(k>w){
			for(int i=j;i<j+w+1;++i){
				hsh[i]=1;
				k--;
			}
		}
	}
	for(int i=0;i<n;++i){
		if(hsh[i]==0){
			cout << s[i];
		}
	}
	cout << endl;
}
