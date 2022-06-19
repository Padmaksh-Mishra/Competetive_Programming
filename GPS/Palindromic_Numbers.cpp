//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

vector<ll> palindromes;
int isPalindrome(int n)
{
    // Find reverse of n
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
        rev = rev*10 + i%10;
 
    // If n and rev are same, then n is palindrome
    return (n==rev);
}
ll bexpo(ll n,ll p);

void solve(){
	ll dgt; cin >> dgt;
	ll n; cin >> n;
	ll tmp = bexpo(10,dgt-1);
	deb(tmp);
	deb(n);
	ll msb = n/tmp;
	msb+=2;
	if(msb>9) msb=9;
	deb(msb);
	ll no = 0;
	for(int i=0;i<dgt;i++) no += (no*10) + msb;
	deb(no);
	cout << no-n << endl;
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
ll bexpo(ll n,ll p){ 
    ll ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
