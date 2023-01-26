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
	ll n; cin >> n;
	string str; cin >> str;
	vll pa(n+1,0),pb(n+1,0),pc(n+1,0);
	for(int i=0;i<n;++i){
		pa[i+1] = pa[i] + (str[i]=='a');
		pb[i+1] = pb[i] + (str[i]=='b');
		pc[i+1] = pc[i] + (str[i]=='c');
	}
	// for(auto val : pa){
	// 	cout << val << " ";
	// }
	// cout << endl;
	// for(auto val : pb){
	// 	cout << val << " ";
	// }
	// cout << endl;
	// for(auto val : pc){
	// 	cout << val << " ";
	// }
	// cout << endl;

	auto ok = [&](ll k)->bool{
		//deb(k);
		for(int i=0;i+k<n+1;++i){
			ll as = pa[i+k]-pa[i];
			ll bs = pb[i+k]-pb[i];
			ll cs = pc[i+k]-pc[i];
			if(as>max(bs,cs)){
				// cout << "TRUE" << endl;
				return true;
			}
		}
		return false;
	};	    

	if(ok(2)) cout << 2 << endl;
	else if(ok(3)) cout << 3 << endl;
	else if(ok(4)) cout << 4 << endl;
	else if(ok(7)) cout << 7 << endl;
	else cout << -1 << endl;
}
