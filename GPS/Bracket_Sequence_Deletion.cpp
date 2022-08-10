//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 

# include <bits/stdc++.h>

using namespace std;

# define PM ios_base::sync_with_stdio(false); 
# define IS cin.tie(NULL); 
# define LEGENDARY cout.tie(NULL);
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define For(i,a,b) for(ll i = a; i < b; ++i)

const ll MOD = 1e9 +7;
vector<char> stk(500001);


void setIO(string name = "sublime") {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}

void solve(){
	int n; cin >> n;
	int top = 1;
	
	// // deb(top);
	// int lenth = top-1;
	// int moves = 0;
	// For(i,1,top){
	// 	if(stk[i]==stk[i+1]){
	// 		lenth-=2;
	// 		moves++;
	// 		i++;
	// 	}
	// }
	For(i,1,n+1){
		char tmp; cin >> tmp;
		// deb(tmp);
		if(stk[top-1]==tmp){
			top-=2;
		}else{
			stk[top]=tmp;
		}
		top++;
	}
	int lenth = n-top+1;
	int moves = 1;
	for(int i=1;i<top-1;++i){
		if(stk[i]=='('&&stk[i+1]==')'){
			moves++;
			i++;
			lenth-=2;
		}
	}
	cout << moves << " " << lenth << endl;
}

int main(){

    PM IS LEGENDARY

    setIO();	//Google and other non judges

    int TC = 1;
    cin >> TC;
    For(i,0,TC){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

