//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;


int divSum(int num)
{
    // Final result of summation of divisors
    int result = 0;
    if(num == 1) // there will be no proper divisor
      return result;
    // find all divisors which divides 'num'
    for (int i=2; i<=sqrt(num); i++)
    {
        // if 'i' is divisor of 'num'
        if (num%i==0)
        {
            // if both divisors are same then add
            // it only once else add both
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
 
    // Add 1 to the result as 1 is also a divisor
    return (result + 1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        ll X,A,B;
        cin >> X >> A >> B;
        int f = X/A;
        int N = B*f;
        int s = divSum(N) + N;
        if (s==X){
            cout << N << endl;
        }else cout << -1 << endl;
    }
    return 0;
}