//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e6;
using namespace std;

bool prime[MOD + 1];
void SieveOfEratosthenes(int n=MOD + 1)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
}

void solve(){
    ll input; cin >> input;
    double root = pow(input,0.5);
    ll tmp = root;
    if(tmp == 1) {
        cout << "NO" << endl;
        return;
    }
    if(prime[tmp]&&(root-tmp==0)){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    SieveOfEratosthenes();
    int TC;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
