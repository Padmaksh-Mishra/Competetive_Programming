//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

ll a[100001];

void solve(){
	int n,x; cin >> n >> x;
	
	for(int i=0;i<n;++i){
		cin >> a[i];
	}	    
	ll sum=0;
	for(int i=0;i<n;i++){
		if(a[i]%x){
			cout << sum*2 << endl;
			return;
		}
		else {
			sum+=a[i];
			a[i] = a[i]/x;
		}
	}
	for(int i=0;;i=(i+1)%n){
		if(a[i]%x){
			cout << sum*2 << endl;
			return;
		}
		else {
			sum+=(a[i]);
			a[i] = a[i]/x;
		}	
	}
	cout << sum*2 << endl;
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
