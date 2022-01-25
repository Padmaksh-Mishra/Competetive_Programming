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

    string n;
    cin >> n;
    bool flag = false;
    stringstream temp(n);
    int s = 0;
    temp >> s;
    if ((s % 4 == 0) || (s % 7 == 0))
    {
        flag = true;
    }else{
        flag = true;
    for (auto val : n)
    {
        
        if ((val != '4') && (val != '7'))
        {
            //cout << "ANA PADA";
            flag = false;
        }
    }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}