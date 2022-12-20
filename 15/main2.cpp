/*
    Jakub Żojdzik
    19-12-2022
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

constexpr int LINES = 33;
constexpr int LIMIT = 4000000;
pii poz[100];
int r[100];

set<int> byl;

int main()
{
    // cout.tie(0);
    // cin.tie(0)->sync_with_stdio(0);

    for(int i = 0; i < LINES; i++)
    {
        int X1, Y1, X2, Y2;
        scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &X1, &Y1, &X2, &Y2);
        r[i] = abs(X1 - X2) + abs(Y1 - Y2);
        poz[i] = {X1, Y1};
    }

    for(int i = 0; i <= LIMIT; i++)
    {
        if(i % 1000 == 0) cout << i << '\n';
        vpii przedz;
        for(int j = 0; j < LINES; j++)
        {
            int diff = abs(poz[j].se - i);
            if(r[j] >= diff)
            {
                debug(j, poz[j], r[j], diff);
                przedz.pb({max(0, poz[j].fi - (r[j] - diff)), min(LIMIT, poz[j].fi + (r[j] - diff))});
            }
        }
        sort(all(przedz));
        debug(przedz);
        int kon = 0;
        for(int j = 0; j < sz(przedz); j++)
        {
            if(kon < przedz[j].fi)
            {
                cout << (kon+1) << ", " << i << "\n";
                return 0;
            }
            kon = max(kon, przedz[j].se);
            if(kon+1 >= LIMIT) break;
        }
    }

    cout << sz(byl) << '\n';
}

/*

*/