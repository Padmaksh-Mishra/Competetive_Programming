//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

typedef struct rect{
	int a,b,c,d;
	int area(){
		return((c-a)*(d-b));
	}
}rect;
void solve(){
	rect R1,R2;
	cin >> R1.a >> R1.b >> R1.c >> R1.d;
	cin >> R2.a >> R2.b >> R2.c >> R2.d;
	int areaSeen = R1.area()+R2.area() - (max(0,-max(R1.a,R2.a)+min(R1.c,R2.c))*(max(0,-max(R1.b,R2.b)+min(R1.d,R2.d))));   	
	cout << areaSeen*areaSeen << endl;
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