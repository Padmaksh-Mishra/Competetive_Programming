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
	vector<pair<ll,ll>> vp;
	vector<pair<ll,ll>> ans;
	vector<ll> hsh(n,-1);
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		if(tmp!=0) vp.pb(make_pair(tmp,i));
		else hsh[i] = 0;
	}   

	if(vp.size()==0) cout << 1 << endl << 1 << " " << n << endl;
	else if(vp.size()&1) cout << -1 << endl;
	else{
		for(int i=0;i<vp.size();i+=2){
			if((vp[i+1].s-vp[i].s)==1){

				if(vp[i].f==vp[i+1].f) ans.pb(make_pair(vp[i].s,vp[i+1].s));
				else{
					ans.pb(make_pair(vp[i].s,vp[i].s));
					ans.pb(make_pair(vp[i+1].s,vp[i+1].s));
				}
			}
			else if(vp[i].f==vp[i+1].f){
				if((vp[i+1].s-vp[i].s)%2!=0) {
					ans.pb(make_pair(vp[i].s,vp[i+1].s));
					for(int j=vp[i].s+1;j<vp[i+1].s;++j) hsh[j] = 1;
				}
				else {
					ans.pb(make_pair(vp[i].s,vp[i].s));
					hsh[vp[i+1].s-1]=1;
					ans.pb(make_pair(vp[i+1].s-1,vp[i+1].s));
				}
			}else{
				if((vp[i+1].s-vp[i].s)%2==0) {
					ans.pb(make_pair(vp[i].s,vp[i+1].s));
					for(int j=vp[i].s+1;j<vp[i+1].s;++j) hsh[j] = 1;
				}
				else {
					ans.pb(make_pair(vp[i].s,vp[i].s));

					ans.pb(make_pair(vp[i+1].s,vp[i+1].s));
				}
			}
		}
		
		for(int i=0;i<n;++i){
			if(hsh[i] == 0) ans.pb(make_pair(i,i));
		}
		sort(all(ans));
		cout << siz(ans) << endl;
		for(auto val : ans){
			cout << val.f+1 << " " << val.s+1 << endl;
		}
	}

}
