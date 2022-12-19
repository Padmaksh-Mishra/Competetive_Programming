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
	int ary[n];
	for(int i=0;i<n;i++){
		cin >> ary[i];
	}    
	int till = n-1;
	int min = ary[0];
	for(int i=n-1;i>0;i--){
		if(ary[i]<=min){
			till--;
			min = ary[i];
		}
		else break;
	}
	bool poss = true,alle=true;
	int ans = n-1-till;
	for(int i=0;i<till;i++){
		if(ary[i]>ary[i+1]){
			poss = false;
			break;
		}
	}

	for(int i=0;i<n-1;i++){
		//deb(ary[i+1]);
		if(ary[i]!=ary[i+1]){
			alle = false;
			break;
		}
	}	
	if(alle) ans = 0;
	if(poss) cout << ans;
	else cout << -1;
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

