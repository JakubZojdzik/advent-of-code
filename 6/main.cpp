/*
    Jakub Żojdzik
    06-12-2022
*/

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#define dt
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;

#define fi first
#define se second
#define pb push_back
#define rep(i, x, y) for(ll i = (ll)x; i <= (ll)y; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define nl cout << '\n'

int wyst[500];

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    for(int i = 0; i < sz(s); i++)
    {
        wyst[int(s[i])]++;
        if(i - 14 >= 0)
            wyst[int(s[i-14])]--;

        bool marker = 0;
        if(i - 13 >= 0)
        {
            marker = 1;
            for(int j = 0; j < 500; j++)
                if(wyst[j] >= 2)
                    marker = 0;
        }
        if(marker)
        {
            cout << i+1 << '\n';
            break;
        }
    }
}

/*
0 1 2 3 4 5
a a b c d e
*/