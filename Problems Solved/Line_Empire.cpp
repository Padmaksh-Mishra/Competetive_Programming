//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll INF = 2*1e5 + 1;
using namespace std;

ll empires[INF],sums[INF];
void sumer();

int n,a,b; 


void solve(){

	cin >> n >> a >> b;
	empires[0] = 0;
	for(int i= 1;i<n+1;i++) cin >> empires[i];
	ll tmp;
	ll mini = 1e18;
	sumer();
	for(int i = 0;i<n+1;i++){

		tmp = ((a+b)*empires[i]) + b*(sums[n]-sums[i] - ((n-i)*empires[i])) ;
		mini = (mini>=tmp) ? tmp : mini;
	}
	cout << mini << endl;
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

void sumer(){
	sums[0] = 0;
	for(int i = 1;i<n+1;i++) sums[i] = empires[i] + sums[i-1];
}