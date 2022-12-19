//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001]; // 2D matrix
bool isPal(string s, int i, int j)
{
	// Base condition
	if (i > j)
		return 1;

	// check if the recursive tree
	// for given i, j
	// has already been executed
	if (dp[i][j] != -1)
		return dp[i][j];

	// If first and last characters of
	// substring are unequal
    if((s[j] != '?')) s[j] = ~((int)s[i]-48);
    if((s[i] != '?')) s[i] = ~((int)s[j]-48);
	if ((s[i] != s[j]) && (s[j] != '?')&&(s[i] != '?'))
		return dp[i][j] = 0;

	// memoization
	return dp[i][j] = isPal(s, i + 1, j - 1);
}

int countSubstrings(string s)
{
	memset(dp, -1, sizeof(dp));
	int n = s.length();
	int count = 0;

	// 2 for loops are required to check for
	// all the palindromes in the string.
	for (int i = 0; i < n-4; i++)
	{
		for (int j = i + 4; j < n; j++)
		{
			// Increment count for every palindrome
			if (isPal(s, i, j))
				count++;
		}
	}
	// return total palindromic substrings
	return count;
}

void solve(){
    int N; cin >> N;
    string S; cin >> S;
    if(countSubstrings(S)>0) cout << "IMPOSSIBLE" << endl;
    else cout << "POSSIBLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int p = 0;
    while(TC--){
        p++;
        cout << "Case #" << p << ": ";
        solve();
    }
    return 0;
}
