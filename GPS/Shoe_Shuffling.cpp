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
    map<int,vector<int>> m;
	for(int i=0;i<n;i++){
		int size; cin >> size;
		m[size].push_back(i+1);
	}
	//bool allok = true;
	for(auto val:m){
		int l = val.second.size();
		if(l==1){
			cout << -1 << endl;
			return;
		}	
	}
	for(auto val:m){
		int l = val.second.size();
		for(int i = 1 ; i<l+1;i++) cout << val.second[i%l] << " ";	
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
