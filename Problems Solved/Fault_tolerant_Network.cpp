//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

int rowA[200000],rowB[200000];
void solve(){
	int n; cin >> n;
	for(int i = 0;i<n;i++) cin >> rowA[i];
	for(int i = 0;i<n;i++) cin >> rowB[i];
	int A1 = rowA[0],B1 = rowB[0],An = rowA[n-1],Bn = rowB[n-1];
	rowB[n]=rowA[n]=-MOD;
	int cost1 = abs(A1-B1);
	int cost2 = abs(An-Bn);
	sort(rowA,rowA + n);sort(rowB,rowB+n);
	int cost3 = min(abs(A1-*upper_bound(rowB,rowB+n,A1)),abs(A1-*(upper_bound(rowB,rowB+n,A1)-1)));
	int cost4 = min(abs(B1-*upper_bound(rowA,rowA+n,B1)),abs(B1-*(upper_bound(rowA,rowA+n,B1)-1)));
	int cost5 = min(abs(An-*upper_bound(rowB,rowB+n,An)),abs(An-*(upper_bound(rowB,rowB+n,An)-1)));
	int cost6 = min(abs(Bn-*upper_bound(rowA,rowA+n,Bn)),abs(Bn-*(upper_bound(rowA,rowA+n,Bn)-1)));
	cout << min(cost1,cost3+cost4) + min(cost2,cost5+cost6) << endl;
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
