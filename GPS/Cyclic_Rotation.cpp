//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int size = 2*1e5;
using namespace std;

int bexpo(int n,int p);

int a[size],b[size];
void solve(){
	int n;cin >> n;
	for(int i = 0;i<n;i++) cin >> a[i];
	for(int i = 0;i<n;i++) cin >> b[i];
	unordered_set<int> A,B;
	for(int i = n-1;i>-1;i--) {
		A.insert(a[i]);
		B.insert(b[i]);
	}
	bool possible = true;
	auto itb = B.begin();
	for(auto ita = A.begin();ita!=A.end();ita++){
		if(*ita!=*itb) {
			possible = false;
			break;
		}
		itb++;
	}
	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl;    
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
