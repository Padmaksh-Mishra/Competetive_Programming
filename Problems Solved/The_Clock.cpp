//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'


const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);


void solve(){
	int HH,MM,x;
	scanf("%d:%d %d",&HH,&MM,&x);
	int ans = 0;
	cout << HH << " " << MM << " " << x << endl;
	int h,m;
	m = MM+x;
	h = m/60;
	h%=24;
	m%=60;
	if((h%10==m/10)&&(h/10==m%10)) ans++;
	// while(h!=HH||m!=MM){
	// 	if((h%10==m/10)&&(h/10==m%10)) ans++;
	// 	m = MM+x;
	// 	h = m/60;
	// 	h%=24;
	// 	m%=60;	
		
	// 	//deb(new_time);
	// }

	cout << ans << endl;  
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
