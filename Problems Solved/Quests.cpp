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
	ll n,c,d; cin >> n >> c >> d;
	vll coins(max(d+2,n),0);
	for(int i=0;i<n;++i){
		cin >> coins[i];
	}	   
	sort(all(coins),greater<ll>()); 
	auto valid = [&](ll k)->bool{
		ll money = 0;
		for(int i=0;i<d;++i){
			money+=coins[i%(k+1)];
		}
		return (money>=c);
	};
	ll s=0,e=d+2;
	ll mid = 0;
	while(e-s>1){
		mid = (e+s)/2;
		if(valid(mid)){
			s=mid;
		}else{
			e = mid-1;
		}
	}
	if(s>d) cout << "Infinity" << endl;
	else if(valid(e)) cout << e << endl;
	else if(valid(mid)) cout << mid << endl;
	else if(valid(s)) cout << s << endl;
	else cout << "Impossible" << endl;
}
