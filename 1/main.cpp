/*
    Jakub Żojdzik
    01-12-2022
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
    vi kcal = {0};
    while (getline(cin, s))
    {
        if(s == "")
        {
            kcal.pb(0);
            continue;
        }
        kcal[sz(kcal)-1] += stoi(s);
    }
    sort(all(kcal));
    cout << kcal[sz(kcal)-1]+kcal[sz(kcal)-2]+kcal[sz(kcal)-3] << '\n';
}

/*

*/