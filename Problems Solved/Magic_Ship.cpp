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
	ll sx,sy,dx,dy; cin >> sx >> sy >> dx >> dy;
	ll n; cin >> n;
	string wind; cin >> wind;
	pll fullc = {0,0};
	for(char c : wind){
		if(c=='U') fullc.s++;
		else if(c=='D') fullc.s--;
		else if(c=='L') fullc.f--;
		else fullc.f++;
	}
	auto findnc = [&](ll mid)->ll{
		pll nc = {sx,sy};
		nc.f += (fullc.f)*(mid/n);
		nc.s += (fullc.s)*(mid/n);
		ll leftover = (mid%n);
		for(int i=0;i<leftover;++i){
			char c = wind[i];
			if(c=='U') nc.s++;
			else if(c=='D') nc.s--;
			else if(c=='L') nc.f--;
			else nc.f++;
		}
		//nc.f+=sx;nc.s+=sy;
		ll moves = abs(dx-nc.f) + abs(dy-nc.s);
		return moves;
	};

	ll s=0,e=1e18,mid;
	while(e-s>1){
		mid = s + ((e-s)>>1);
		ll moves = findnc(mid);
		if(moves>mid){
			s = mid + 1;
		}else{
			e = mid;
		}
	}
	if(findnc(s)<=s) cout << s << endl;
	else if(findnc(e)<=e) cout << e << endl;
	else cout << -1 << endl;
}
