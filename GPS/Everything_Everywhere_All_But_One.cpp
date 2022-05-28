//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int ips[51];
void solve(){
	int n; cin >> n;
	ll sum=0;
	for(int i=0;i<n;i++) {
		cin >> ips[i];
		sum+=ips[i];
	}
	sort(ips,ips+n);
	// if(sum==n*ips[0]) {
	// 	cout << "YES" << endl;
	// 	return;
	// }
	// if(n%2==0) {
	// 	cout << "NO" << endl;
	// 	return;
	// }
	int won = false ;
	for(int i=0;i<n;i++){
		if(sum==(n*ips[i])){
			won = true;
			break;
		}
		
	}
	if(won) cout << "YES\n";
	else cout << "NO\n";
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
