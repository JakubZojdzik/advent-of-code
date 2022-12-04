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

bitset<500> wystA;
bitset<500> wystB;
bitset<500> wystC;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    string a, b, c;
    ll w = 0;
    while(getline(cin, a) && getline(cin, b) && getline(cin, c))
    {
        wystA.reset();
        wystB.reset();
        wystC.reset();
        rep(i, 0, sz(a)-1) wystA[int(a[i])] = 1;
        rep(i, 0, sz(b)-1) wystB[int(b[i])] = 1;
        rep(i, 0, sz(c)-1) wystC[int(c[i])] = 1;
        int badge = 0;
        rep(i, 0, 500)
            if(wystA[i] && wystB[i] && wystC[i])
                badge = i;

        int ink = int(badge) - 'A' + 27;
        if(ink > 52) ink = int(badge) - 'a' + 1;
        w += ink;
    }
    cout << w << '\n';
}

/*

*/