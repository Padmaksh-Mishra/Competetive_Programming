// Name.Redacted || Coding_Duck || PM


///////////////////////////////////////////////////////////////////////
//////////////      I WAS NEVER ABLE TO DO THIS         ///////////////
///////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h> //iostream already included
# define endl "\n"
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
        ll Hp, Dp, Hm, Dm, k, w, a;
        cin >> Hp >> Dp >> Hm >> Dm;
        cin >> k >> w >> a;
        bool won = false;
        for (int i = 0; i < k + 1; i++)
        {
            Hp = (Hp + ((k - i) * a));
            Dp =(Dp + (i * w));
            
            ll attacksPlayer = (Hm%Dp) ? (Hm/Dp)+1 : (Hm/Dp);
            ll attacksMonster = (Hp%Dm) ? (Hp/Dm)+1 : (Hp/Dm);
            if(attacksMonster>=attacksPlayer){
                won = true;
                break;
            }
        }
        
        if (won) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}