// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--)
    {
        ll X, M;
        cin >> X >> M;
        // if (X > M)
        //     cout << 0 << endl;
        // else
        
            ll nt = 0;
            ll ans;
            for (ll i = 0; i < X+1000; i++)
            {
                nt = pow(2, i);
                if (nt >= X)
                {
                    // if(nt==X){
                    //     ans = i;
                    // }else 
                    ans = i+1;
                    break;
                }
            }
            ll height ;
            if(M<ans) height = 0;
            else if (ans<M) height = M - ans + 1;
            else height = 1;
            cout << height << endl;
        
    }
    return 0;
}