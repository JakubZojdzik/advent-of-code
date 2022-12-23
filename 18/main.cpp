/*
    Jakub Żojdzik
    23-12-2022
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

ll x[100007], y[100007], z[100007];

inline bool conn(int x1, int y1, int z1, int x2, int y2, int z2)
{
    if(x1 == x2 && y1 == y2 && abs(z1 - z2) == 1) return 1;
    if(x1 == x2 && z1 == z2 && abs(y1 - y2) == 1) return 1;
    if(z1 == z2 && y1 == y2 && abs(x1 - x2) == 1) return 1;
    return 0;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    fstream f("inp");
    string s;
    ll LINES = 0;
    while(f >> s)
    {
        ll stage = 0, pocz = 0;
        for(ll i = 0; i < sz(s); i++)
        {
            if(s[i+1] == ',' || s[i+1] == '\0')
            {
                if(stage == 0)
                {
                    x[LINES] = stoi(s.substr(pocz, i-pocz+1));
                }
                if(stage == 1)
                {
                    y[LINES] = stoi(s.substr(pocz, i-pocz+1));
                }
                if(stage == 2)
                {
                    z[LINES] = stoi(s.substr(pocz, i-pocz+1));
                }
                stage++;
                pocz = i+2;
            }
        }
        LINES++;
    }

    ll res = LINES*6;
    for(int i = 0; i < LINES; i++)
    {
        for(int j = i+1; j < LINES; j++)
        {
            if(conn(x[i], y[i], z[i], x[j], y[j], z[j])) (--res)--; // B)
        }
    }

    cout << res << '\n';
}

/*

*/