# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;
int isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return 0;
        }
    }
    // Return "Yes"
    return 1;
}
int findPeriod(string A)
{
    int length = A.size();
  
    // Initially consider there is no period for given
    // String
    int period = -1;
  
    /*set two pointers one(i) at
    index 0 and other(j) at index 1. increment j till
    first character is obtained in the string*/
    int i = 0;
    for (int j = 1; j < length; j++) {
        int currChar = A[j];
        int comparator = A[i];
  
        /*If current character matches with first
         *character
         *update period as the difference of j and i*/
        if (currChar == comparator) {
            period = (j - i);
            i++;
        }
  
        /* if any mismatch occurs in between set i to
         * zero also check if current character again
         * matches
         * with starting character. If matches, update
         * period*/
        else {
            if (currChar == A[0]) {
                i = 1;
                period = j;
            }
            else {
                i = 0;
                period = -1;
            }
        }
    }
  
    /*check if the period is exactly dividing
     * string if not reset the period to -1
     * this eliminates partial substrings like
     * e.g string -"GEEKSFORGEEKS" */
  
    period = (length % period != 0) ? -1 : period;
    return period;
}

void solve(){
	int n; cin >> n;
	string p; cin >> p;
	int i = 0;
	// reverse(all(p));
	string q = "";
	// q+=p[i];
	// if(isPalindrome(p+q)==1){
	// 	cout << q << endl;
	// 	return;
	// }
	// while(n--){
	// 	++i;
	// 	q+=p[i];
	// 	if(isPalindrome(p+q)==1) break;
	// }
	int period = findPeriod(p);
	if(period==-1) q = p;
	else {
		q = p.substr(0,period);
		if(isPalindrome(q)==0) q = p.substr(0,(n+1)/2);
	}
	cout << q << endl;

}

int main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 