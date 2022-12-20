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
constexpr int PYT = 2000000;
int X1[100], Y1[100], X2[100], Y2[100];

set<int> byl;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 0; i < LINES; i++)
    {
        scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &X1[i], &Y1[i], &X2[i], &Y2[i]);
    }
    for(int i = 0; i < LINES; i++)
    {
        int dist = abs(X1[i] - X2[i]) + abs(Y1[i] - Y2[i]);
        dist -= abs(PYT - Y1[i]);
        if(dist >= 0)
        {
            byl.insert(X1[i]);
        }
        for(int j = 0; j < dist; j++)
        {
            byl.insert(X1[i]+j+1);
            byl.insert(X1[i]-j-1);
        }
    }
    for(int i = 0; i < LINES; i++)
    {
        if(Y2[i] == PYT) byl.erase(X2[i]);
    }

    cout << sz(byl) << '\n';
}

/*

*/