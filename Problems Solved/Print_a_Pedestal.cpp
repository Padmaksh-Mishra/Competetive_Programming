//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	int rem = n%3;
	if(n==6) {
		cout << "2 3 1 \n";
		return;
	}
	if(n==7){
		cout << "2 4 1 \n";
		return;
	}
	if(rem==0){
		int val = n/3;
		cout << val << " " << val + 1 << " " << val - 1;
	}else if(rem==1){
		int val = n/3;
		cout << val << " " << val + 2 << " " << val -1;
	}else{
		int val = n/3;
		cout << val+1 << " " << val + 2 << " " << val - 1;
	}    
	cout << endl;

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
