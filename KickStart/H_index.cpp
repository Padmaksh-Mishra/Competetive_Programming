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
    ll i = 0;

    while (TC--)
    {
        i++;
        ll N,temp;
        cin >> N;
        vector<ll> citations;
        cout << "Case #" << i << ": ";
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            citations.push_back(temp);
            sort(citations.begin(), citations.end());
            //ll ans = (citations[i] < i+1) ? citations[i] : i+1;
            ll ans = (citations[0] > i+1) ? i+1 : *(lower_bound(citations.begin(),citations.end(),i+1));
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}