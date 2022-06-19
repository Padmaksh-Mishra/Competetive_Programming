//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e8 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,k; cin >> n >> k;
	vector<pair<int,ll>> a;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		a.push_back({(tmp%k),tmp});
	}
	sort(a.begin(),a.end());
	ll ans = 0;
	int f = 0;
	vector<pair<int,ll>> copy = a;
	for(int i=0;i<n;i++){
		//deb(a[i].first);
		if(copy[i].first==0){
			f++;
			
			// deb(copy[i].second);
			ans += copy[i].second/k;
			// deb(ans);
			a.erase(a.begin());
		} 
	}
	// deb(a.size());
	// deb(n);
	for(int i=0;i<(a.size()>>1);++i){
		
		//deb(a[i].second);		
		ans += ((a[a.size()-i-1].second+a[i].second) / k); 
		// deb(ans);
	}
	if(a.size()!=0) ans+=a[a.size()/2].second/k;
	cout << ans << endl;   
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
