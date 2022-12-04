/*
    Jakub Żojdzik
    04-12-2022
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

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int w = 0;
    while(getline(cin, s))
    {
        int stage = 0;
        int vals[4];
        int pocz = 0;
        for(int i = 0; i < sz(s); i++)
        {
            if(s[i] == ',' || s[i] == '-')
            {
                vals[stage] = stoi(s.substr(pocz, i-pocz+1));
                stage++;
                pocz = i+1;
            }
        }
        vals[stage] = stoi(s.substr(pocz, sz(s)-pocz+1));
        if(!(vals[0] > vals[3] || vals[1] < vals[2]))
            w++;
    }
    cout << w << '\n';
}

/*

*/