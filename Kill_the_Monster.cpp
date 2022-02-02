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
        ll Hp, Dp, Hm, Dm, k, w, a;
        cin >> Hp >> Dp >> Hm >> Dm;
        cin >> k >> w >> a;
        bool won = false;
        double term_1, term_2;
        for (int i = 0; i < k + 1; i++)
        {
            term_1 = (((double)Hp + (k - i) * a) / Dm);
            term_2 = ((double)Hm / (Dp + (i * w)));
            // cout << term_1 << " " << term_2 << endl;
            if (term_1 - term_2 + 1 > 0)
            {
                won = true;
                break;
            }
        }
        // term_1 = (5/3);
        // cout << term_1 << endl;
        if (won)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}