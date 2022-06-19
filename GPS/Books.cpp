//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int times[10000],ips[100000];

void solve(){
	int n,t; cin >> n >> t;
	int books = n;
	ll sum = 0;
	for(int i=0;i<n;i++) {
		cin >> ips[i];
		sum+=ips[i];
	}
	int start = 0,end = n-1;
	while(sum>=t){
		// deb(sum);
		// deb(ips[start]);
		// deb(ips[end]);
		if(ips[start]>ips[end]){
			sum-=ips[start];
			start++;
			books--;
		}else{
			sum-=ips[end];
			books--;
			end--;
		}
	}
	cout << books << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    //cin >> TC;
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
