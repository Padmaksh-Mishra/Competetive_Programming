//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int a,b; cin >> a >> b;
	int aa =a,bb=b;
	for(int i=0;i<a+b;i++){
		if(i%2==0){
			if(bb>0){
				cout << 1;
				bb--;
			}else {
				cout << 0;
				aa--;
			}
		}
		else{
			if(aa>0){
				cout << 0;
				aa--;
			}else {
				cout << 1;
				bb--;
			}
		}
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
