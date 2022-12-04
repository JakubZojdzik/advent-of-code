/*
    Jakub Żojdzik
    02-12-2022
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

constexpr int LINES = 2500;

char winwith(char x)
{
    if(x == 'A') return 'B';
    if(x == 'B') return 'C';
    if(x == 'C') return 'A';
}

char loosewith(char x)
{
    if(x == 'A') return 'C';
    if(x == 'B') return 'A';
    if(x == 'C') return 'B';
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int w = 0;
    rep(i, 1, LINES)
    {
        char a, b, c;
        cin >> a >> c;
        if(c == 'X') b = loosewith(a);
        else if(c == 'Y') b = a;
        else if(c == 'Z') b = winwith(a);

        if(b == 'A') w += 1;
        else if(b == 'B') w += 2;
        else if(b == 'C') w += 3;

        if(a == b) w += 3;
        else if((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'C' && b == 'A')) w += 6;
    }
    cout << w << '\n';
}

/*

*/