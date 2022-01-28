// Coding_Duck PM

#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TT;
    cin >> TT;
    while (TT--)
    {
        int N, X, noVacc = 0, cons_0 = 0;
        cin >> N >> X;
        bool change_left = true;
        string s;
        cin >> s;
        for (int i = 0; i < N; i++)
        {
            if (s[i] | 0 == 0)
            {
                s[i] = '?';
                cons_0++;
                if (cons_0 == X)
                {
                    noVacc++;
                    cons_0 = 0;
                }
                // if((cons_0==X-1)&&(s[i+1]&1==1)){
                //     cout << "JAADU\n";
                //     if(change_left){
                //         cout << "AYA\n";
                //         noVacc++;
                //     }
                // cons_0 = 0;
                // }
            }
            else
            {
                s[i] = '1';
                cons_0 = 0;
            }
        }
        cout << s << endl;
        cout << noVacc << endl;
    }
    return 0;
}