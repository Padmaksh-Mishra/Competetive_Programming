//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	// int n; cin >> n;
	// int base; cin >> base;

	// int op1 = 0,op2;
	// op2 = bexpo(10,n)-1;
	// do{
	// 	op1 = op1*10 + 1;
	// }while(op1<op2+1);
	// // deb(op1);
	// // deb(op2);	
	// op1 -= base;
	// op2 -= base;
	// if(op1>bexpo(10,n)-1) cout << op2;
	// else cout << op1;
	// cout << endl;

	int n; cin >> n;
	string base,op1 = "1",op2;
	cin >> base;
	for(int i=0;i<n;++i){
		op1+="1";
		op2+="9";
	}
	int carry = 0;
	string ans1,ans2;
	reverse(base.begin(), base.end());
	for(int i=0;i<n;++i){
		ans2 += (op2[i]-base[i])+'0';
		int tmp = (op1[i]-base[i]-carry);
		carry = 0;
		if(tmp<0){
			carry = 1;
			tmp +=10;
		}
		ans1 += tmp + '0';
	}
	ans1 += op1[n] - carry;
	reverse(ans1.begin(), ans1.end());
	reverse(ans2.begin(), ans2.end());
	ans1.erase(0, min(ans1.find_first_not_of('0'), ans1.size()-1));
	ans2.erase(0, min(ans2.find_first_not_of('0'), ans2.size()-1));

	cout << (ans1.size()==n ? ans1 : ans2) << endl;
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

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