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
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	//deb(n);
	if(n%2!=0) {
		cout << "NO" << endl;
		return;
	}    
	sort(a,a+n);
	int finally[n];
	int c=n>>1;
	int comp = a[c-1];
	//deb(comp);
	// for(int i=c;i<n;i++){
	// 	if(a[i]<=comp){
	// 		cout << "NO" << endl;
	// 		return;
	// 	}
	// }
	// if(a[c]<=comp){
	// 	cout << "NO" << endl;
	// 	return;
	// 	}
	// cout << "Yes" << endl;
	
	int ans1[c],ans2[c];
	for(int i=0;i<c;i++){
		ans1[i] = a[i];
	}
	for(int i=0;i<c;i++){
		ans2[i] = a[i+c];
	}
	int e=0,d=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			finally[i]=ans1[e];
			//cout << ans1[e] << " ";
			e++;
		}
		if(i%2!=0){
			finally[i]=ans2[d];
			//cout << ans2[d] << " ";
			d++;
		}
	}
	
	for(int i = 1;i<n+5;i++){
		if((finally[(i-1)%n]>finally[i%n])&&(finally[(i+1)%n]>finally[i%n])){
			continue;
		}
		else if((finally[(i-1)%n]<finally[i%n])&&(finally[(i+1)%n]<finally[i%n])){
			continue;
		}else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++) cout << finally[i] << " ";
	cout << endl;

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
