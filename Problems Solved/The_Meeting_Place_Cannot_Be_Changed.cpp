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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	vector<ll> l(n),v(n);
	for(int i=0;i<n;++i){
		cin >> l[i];
	}
	for(int i=0;i<n;++i){
		cin >> v[i];
	}	    
	auto ok = [&](double mid)->bool{
		double maxs = -1,mine = DBL_MAX;
		for(int i=0;i<n;++i){
			maxs = fmax(maxs,l[i] - (mid*v[i]));
			mine = fmin(mine,l[i] + (mid*v[i]));
		}
		return (maxs<=mine);
	};
	double s=0,e=DBL_MAX,mid;
	int i=10000;
	while((e-s>1e-6)&&(i--)){
		mid = s + ((e-s)/2);
		if(ok(mid)){
			e = mid;
		}else{
			s = mid;
		}
	}
	cout<<fixed<<setprecision(10);
	cout << mid << endl;
}
