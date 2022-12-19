# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;


// Function to calculate the factorial
long long fact(const int& p)
{
	if (p <= 1)
		return 1;
	return p * fact(p - 1);
}

// Function to check if the
// number is prime or not
// bool isPrime(const long long& p)
// {
// 	if (p == 4)
// 		return false;

// 	// (p - 1) ! ≡ (p-1) mod p
// 	long long a = fact(p - 1) % p;
// 	if (a == p - 1)
// 		return true;
// 	return false;
// }
bool isPrime(ll n)
{
	// Corner case
	if (n <= 1)
		return false;

	// Check from 2 to n-1
	for (ll i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}
void solve(){
	ll n; cin >> n;
	vll ips(n);
	vll eve,odd;
	ll no=0;
	for(int i=0;i<n;++i){
		cin >> ips[i];
		if(ips[i]%2==0) eve.pb(ips[i]);
		else odd.pb(ips[i]);
		no+=(ips[i]==1);
	}
	if(no>0&&n>1){
		for(auto val : eve){
			if(isPrime(1+val)){
				cout << no+1 << endl;
				while(no--){
					cout << 1 << " ";
				}
				cout << val << endl;
				return;
			}
		}
	}else if(n>1){
		for(auto valo : ips){
			for(auto vale : ips){
				if(isPrime(valo+vale)){
					cout << 2 << endl;
					cout << valo << " " << vale << endl;
					return;
				}
			}
		}
	}
	if(ips[0]!=1){
		cout << 1 << endl;
		cout << ips[0] << endl;
	}else cout << 0 << endl << 0 << endl;
	return ;
}
// Driver code
int main()
{
	solve();
}

