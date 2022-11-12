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
	vll ips(n),cpy(n);
	for(int i=0;i<n;++i){
		cin >> ips[i];
		cpy[i] = ips[i];
	}
	sort(all(cpy));
	if(n&1){
		if(ips[0]!=cpy[0]){
			cout << "NO" << endl;
			return;
		}
		for(int i=1;i<n;i+=2){
			if((ips[i]!=cpy[i+1]||ips[i+1]!=cpy[i])&&(ips[i]!=cpy[i]||ips[i+1]!=cpy[i+1])){
				cout << "NO" << endl;
				return;
			}
		}
	}else{
		for(int i=0;i<n;i+=2){
			if((ips[i]!=cpy[i+1]||ips[i+1]!=cpy[i])&&(ips[i]!=cpy[i]||ips[i+1]!=cpy[i+1])){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}
