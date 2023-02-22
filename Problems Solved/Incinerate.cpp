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
	ll n,k; cin >> n >> k;
	vll v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	vector<pll> p(n);
	for(int i=0;i<n;++i){
		ll pwr; cin >> pwr;
		p[i] = make_pair(v[i],pwr);
	}	    
	ll d = k;
	ll dmgyet = k;
	sort(all(p),[](pll a,pll b)->bool{
		if(a.s>b.s){
			return true;
		}else if(a.f==b.f){
			return(a.f<b.f);
		}
		return false;
	});
	while(siz(p)){
		ll helth = p.back().f;
		ll pwr = p.back().s;
		// deb(val);
		while(helth-dmgyet<1){
			p.pop_back();
			if(siz(p)==0){
				cout << "YES" << endl;
				return;
			}
			helth = p.back().f;
			pwr = p.back().s;
		}
		d-=pwr;
		dmgyet+=d;

		if(siz(p)&&d<=0){
			// deb(d);
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
