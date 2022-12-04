/*
    Jakub Żojdzik
    03-12-2022
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

bitset<500> wyst;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    string s, a, b;
    ll w = 0;
    while(getline(cin, s))
    {
        a = s.substr(0, sz(s)/2);
        b = s.substr(sz(s)/2, sz(s)/2);
        wyst.reset();
        rep(i, 0, sz(a)-1)
            wyst[int(a[i])] = 1;
        rep(i, 0, sz(b)-1)
        {
            if(wyst[int(b[i])])
            {
                wyst[int(b[i])] = 0;
                int ink = int(b[i]) - 'A' + 27;
                if(ink > 52) ink = int(b[i]) - 'a' + 1;
                w += ink;
            }
        }
    }
    cout << w << '\n';
}

/*

*/