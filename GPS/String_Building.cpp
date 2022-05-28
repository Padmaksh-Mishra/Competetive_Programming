//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	string s; cin >> s;
	int x = 0;
	int l = s.length();
	bool yes = true;
	char pc = s[0];
	x++;
	for(int i = 1;i<l;i++){
		// deb(s[i]);
		// deb(x);
		if(s[i]==pc) x++;
		else {
			//deb(x);
			// if((x%3!=0)&&(x%2!=0)){
			// 	if(((x-3)%2!=0)){
			// 		yes = false;
			// 		//deb(yes);
			// 		break;
			// 	}
			// }
			if(x==1){
				yes = false;
			}
			pc = s[i];
			x=1;;
		}
		
	}
	if(x==1) yes = false;
	if(yes) cout << "YES\n";
	else cout << "NO\n";    
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
