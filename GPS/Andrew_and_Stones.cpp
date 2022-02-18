// Name.Redacted || Coding_Duck || PM

#include <bits/stdc++.h> //iostream already included

using namespace std;
typedef long long ll;

__int32 main()         // Dekne me mast lagta hai
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll TC;
    cin >> TC;
    while (TC--)
    {
        ll n;
        cin >> n;
        bool flag;
        vector<ll> v(n);
        for (auto &val : v)
            cin >> val;
        //failing cases
        if(*max_element(v.begin()+1,v.end()-1)==1) flag = false;
        else if ((n==3)&&(v[1]&1)) flag = false;
        else flag = true;
        ll count = 0;
        if(flag){
            for(auto it = v.begin()+1; it!= v.end()-1;it++) count += (*it+1)/2;
            cout << count << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}