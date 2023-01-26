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
	string st; cin >> st;
	vll stars;
	for(int i=0;i<n;++i){
		if(st[i]=='*'){
			stars.emplace_back(i);
		}
	}	    
	auto cscore = [&](ll k)->ll{
		ll score = 0;
		for(auto val : stars){
			score+=abs(val-k);
			k++;
		}
		//if(k>n) score = INF;
		return score;
	};
	ll s = 0,e = n,m;
	while(e-s>0){
		m = s + ((e-s)/2);
		ll ms = cscore(m);
		ll mms = cscore(m-1);
		ll mas = cscore(m+1);
		// deb(m);

		if(ms<mms&&ms<mas){
			break;
		}else if(ms>mms){
			e = m-1;
		}else s = m+1;
	}
	cout << min(cscore(m),min(cscore(s),cscore(e))) << endl;
}
