//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,r,b; cin >> n >> r >> b;
	int gaps[b+1];
	int extra = r%(b+1);
	for(int i=0;i<b+1;i++) {
		if(extra>0){
			gaps[i] = (r/(b+1)) +1;	
			extra--;
		}
		else gaps[i] = (r/(b+1));
		//deb(gaps[i]);
	}
	int s = 0,z=0;
	for(int i = 0;i<n;i++){
		//deb(gaps[z]);
		if(s==gaps[z]) {
			cout << 'B';
			s=0;
			z++;
		}
		else {
			cout << 'R';
			s++;
		}
	}    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
        cout << endl;
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