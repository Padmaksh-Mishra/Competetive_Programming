//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int a[100],b[100];
int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++) cin >> b[i];
	vector<pair<int,int>> moves;
	for(int i=0;i<n;i++) {
		for(int j = 0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				moves.push_back({j,j+1});
			}

			if(b[j]>b[j+1]){
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				moves.push_back({j,j+1});
			}
		}
	}
	//bool won = true;
	for(int i=0;i<n-1;i++){
		if(b[i]>b[i+1]){
			cout << -1 << endl;
			return;
		}
	}	
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			cout << -1 << endl;
			return;
		}
	}	
	cout << moves.size() << endl;
	for(auto val:moves){
		
		cout << val.first + 1 << " " << val.second + 1 << endl;
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
