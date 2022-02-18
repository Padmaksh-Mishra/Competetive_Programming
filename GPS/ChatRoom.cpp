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

    string r = "hello";
    string ip;
    int i = 0;
    bool flag = true;
    cin >> ip;
    for (auto val : ip)
    {
        if (r[i] == val)
        {
            i++;
        }
        if (i == 5)
        {
            flag = false;
            cout << "YES";
            break;
        }
    }
    if (flag)
    {
        cout << "NO";
    }
    return 0;
}