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
	vll arr(n),odds,evens;
	for(int i=0;i<n;++i) {
		cin >> arr[i];
		if(arr[i]&1) odds.pb(i);
		else evens.pb(i);
	}
	vector<pair<ll,ll>> ans;
	// if(siz(odds)>0){
	
	if(siz(evens)>0){
		ll bestEvenEver = evens[0];
		if(bestEvenEver!=0){
			ll bestOddEver = odds[siz(odds)-1];
			for(int i=0;i<siz(odds)-1;++i){
				ans.pb(make_pair(odds[i]+1,bestOddEver+1));
			}
			for(int i=1;i<n;++i){
				if(arr[i]%2==0) ans.pb(make_pair(1,i+1));
			}
		}
		else{
			bestEvenEver = evens[siz(evens)-1];
			for(int i=0;i<siz(evens)-1;++i){
				ans.pb(make_pair(evens[i]+1,bestEvenEver+1));
			}
			bestEvenEver = evens[0];
			for(int i=0;i<siz(odds);++i){
				if(bestEvenEver<odds[i]){
					ans.pb(make_pair(bestEvenEver+1,odds[i]+1));
				}
			}
		} 
	}else{
		ll bestOddEver = odds[siz(odds)-1];
		for(int i=0;i<siz(odds)-1;++i){
			ans.pb(make_pair(odds[i]+1,bestOddEver+1));
		}
	}
	if(siz(ans)==1&&ans[0].f==ans[0].s){
		cout << 0 << endl;
		return;
	}
	cout << siz(ans) << endl;
	for(auto move : ans){
		cout << move.f << " " << move.s << endl;
	}
}
