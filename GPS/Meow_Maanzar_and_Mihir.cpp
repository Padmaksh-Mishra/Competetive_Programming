//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
ll ary[200001];
void solve(){
	ll n; cin >> n;
	ll Y;cin>>Y;
	ll cats = 0,sum=0;
	ll mini = 1e9;
	for(int i=0;i<n;++i){
		cin >> ary[i];
		sum+=ary[i];
		mini=min(mini,ary[i]);
	}
	//deb(sum);
	cats += (Y/sum)*n;
	Y%=sum;

	 while(Y>=mini)
 	{
	     ll cnt = 0,sum1 = 0 ;
	     ll p = Y;
	     for(int i = 0 ; i< n ; i++ )
	     {
	         if(p-ary[i]>=0)
	         {
	             cnt++;
	             sum1 = sum1+ary[i];
	             p = p -ary[i];
	             
	         }
	     }
	     if(sum1==0){
	         cout<<cats;
	         
	     }
	     cats = cats + cnt* (Y/sum1);
	     Y = Y%sum1;
 
 	}

	cout << cats;
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
