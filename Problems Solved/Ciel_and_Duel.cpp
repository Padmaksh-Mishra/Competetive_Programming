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
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,m; cin >> n >> m;
	multiset<ll> atk,dff,ms,mss;
	ll ans = 0,anss = 0;
	for(int i=0;i<n;++i){
		string s; cin >> s;
		ll tmp; cin >> tmp;
		if(s=="ATK") atk.insert(tmp);
		else dff.insert(tmp);
	}	    
	for(int i=0;i<m;++i){
		ll mtp; cin >> mtp;
		ms.insert(mtp);
		mss.insert(mtp);
	}
	// Only attack attacks
	for(auto val : atk){
		if(siz(mss)==0) break;
		auto it = prev(mss.end());
		if(*it>val){
			anss+=(*it-val);
			mss.erase(it);
		}else break;
	}

	//Complete all 
	bool ex = true;
	for(auto val : dff){
		auto it = ms.upper_bound(val);
		if(it!=ms.end()){
			ms.erase(it);
		}else{
			ex = false;
			break;
		}
	}	
	for(auto val : atk){
		auto it = ms.lower_bound(val);
		if(it!=ms.end()){
			ans+=(*it - val);
			ms.erase(it);
		}else{
			ex = false;
			break;
		}
	}

	if(!ex){
		cout << anss << endl;
		return;
	}
	if(ex) for(auto val : ms) ans+=val;
	cout << max(ans,anss) << endl;
}
