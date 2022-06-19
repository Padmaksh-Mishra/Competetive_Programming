//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e18 +7;
using namespace std;

int bexpo(int n,int p);
int n;
ll cost = 1;
ll mc = MOD ;

void treeDfs(int x,int y,int parentx,int parenty){
	cout << x << " " << y << endl;
	if(x==n||y==n){
		deb(cost);
		mc = min(mc,cost);
		cost--;	
		//return;
	}
	if(x>=n||y>=n) return;
	if(x==parentx&&y==parenty) return;
	cost++;
	treeDfs(x+y,y,x,y);
	treeDfs(x,x+y,x,y);
	
}


void solve(){
	cin >> n;
	if(n==1){
		cout << 0;
		return;
	}
	else if(n==2) {
		cout << 1;
		return;
	}
	treeDfs(2,1,1,1);
	treeDfs(1,2,1,1);
	cout << min(mc,cost);
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
