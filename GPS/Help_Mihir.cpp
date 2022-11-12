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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,q,m; cin >> n >> q >> m;
	vll ips(n+1);
	for(int i=0;i<n;++i){
		cin >> ips[i+1];
	}	    
	ll task[q][3];
	for(int i=0;i<q;++i){
		cin >> task[i][0] >> task[i][1] >> task[i][2];
	}
	vll doon(m);
	for(int i=0;i<n;++i){
		cin >> doon[i];
	}
	for(auto indx : doon){
		ll ans = ips[indx];
		// deb(indx);
		for(int i=0;i<q;++i){
			// cin >> task[i][0] >> task[i][1] >> task[i][2];
			if(task[i][0]==2){
				if(indx<=task[i][2]&&indx>=task[i][1]) 
					ans = ips[(task[i][2]+task[i][1]-indx)]; 
			}
			else{
				if(indx<=task[i][2]&&indx>=task[i][1]) 
					ans = ips[task[i][1]+((indx+1-task[i][1])%(task[i][2]-task[i][1]))];
			}
			// deb(indx);
			deb(ans);

		}

		cout << ans << " " ;
	}
	cout << endl;
}
