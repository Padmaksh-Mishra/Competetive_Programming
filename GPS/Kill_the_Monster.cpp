// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll TC;
    cin >> TC;
    while (TC--)
    {
        long long Hp, Dp, Hm, Dm, k, w, a;
        cin >> Hp >> Dp >> Hm >> Dm;
        cin >> k >> w >> a;
        bool won = false;
        for (int i = 0; i < k + 1; i++)
        {
            Hp = ((Hp + ((k - i) * a)));
            Dp =(Dp + (i * w));
            // cout << term_1 << " " << term_2 << endl;
            ll attacks = Hp % Dm == 0 ? (Hp/Dm) : (Hp/Dm)+1 ;
            if ((attacks)*Dp >= Hm)
            {
                won = true;
                break;
            }
        }
        
        if (won)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}