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

    int temp, row, coloumn, i = 1;
    while (i <= 25)
    {
        cin >> temp;
        if (temp == 1)
        {
            row = (i % 5 == 0) ? (i/5) : (i/5 + 1);
            coloumn = (i % 5 == 0) ? 5 : (i % 5);
        }
        i++;
    }
    //cout << row << " " << coloumn << endl;
    cout << abs(row - 3) + abs(coloumn - 3);

    return 0;
}