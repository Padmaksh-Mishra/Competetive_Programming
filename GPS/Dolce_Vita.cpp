//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;
const ll siz = 2*1e5;
ll sums[siz];
int bexpo(int n,int p);

void solve(){
	int n; cin >> n; 
	int x; cin >> x;
	cin >> sums[0];
	for(int i = 1;i<n;i++){
        int tmp; cin >> tmp;
        sums[i] = sums[i-1] + tmp;
    }
    ll pkt = 0;
    sort(sums,sums + n);
    pkt = upper_bound(sums,sums+n,x) - 1 - sums;
    for(int d = 1 ;x>0;d++){
        x-=pkt;
        pkt+= upper_bound(sums,sums+n,x) - 1 - sums;
    }   
    cout << pkt << endl;
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
