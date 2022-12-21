/*
    Jakub Żojdzik
    21-12-2022
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

constexpr ll LINES = 2171;

unordered_map<string, ll> vars;

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ifstream f("inp");
    string a, b, c;
    char sgn;
    while(1)
    {
        f.clear();
        f.seekg(0);
        for(ll i = 0; i < LINES; i++)
        {
            f >> a >> b;
            a = a.substr(0, sz(a)-1);
            if(!(b[0] >= '0' && b[0] <= '9'))
            {
                f >> sgn >> c;
                if(vars.find(b) != vars.end() && vars.find(c) != vars.end())
                {
                    if(sgn == '+') vars[a] = vars[b] + vars[c];
                    else if(sgn == '-') vars[a] = vars[b] - vars[c];
                    else if(sgn == '*') vars[a] = vars[b] * vars[c];
                    else if(sgn == '/') vars[a] = vars[b] / vars[c];

                    if(a == "root")
                    {
                        cout << vars[a] << '\n';
                        return 0;
                    }
                }
            }
            else
                vars[a] = stoll(b);
        }
    }
}

/*

*/