/*
    Jakub Żojdzik
    13-12-2022
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

int tab[507][507];
bitset<507> seen[507];

int main()
{
    // cout.tie(0);
    // cin.tie(0)->sync_with_stdio(0);

    ifstream file("inp");
    string s;
    int itr = 1;
    vpii lowest;
    pii start, end;
    while(file >> s)
    {
        tab[itr][0] = 999;
        for(int i = 0; i < sz(s); i++)
        {
            tab[itr][i+1] = s[i];
            if(s[i] == 'S' || s[i] == 'a')
            {
                lowest.pb({itr, i+1});
            }
            if(s[i] == 'S') start = {itr, i+1};
            if(s[i] == 'E') end = {itr, i+1};
        }
        tab[itr][sz(s)+1] = 999;
        itr++;
    }
    tab[start.fi][start.se] = 'a';
    tab[end.fi][end.se] = 'z';

    for(int i = 0; i <= sz(s)+2; i++)
    {
        tab[0][i] = 999;
        tab[itr][i] = 999;
    }

    queue<pii> kol;
    int papax[] = {-1, 0, 1, 0};
    int papay[] = {0, 1, 0, -1};
    int res = INT_MAX;
    bool done;
    while(!lowest.empty())
    {
        done = 0;
        start = lowest.back();
        lowest.pop_back();
        while(!kol.empty()) kol.pop();
        kol.push(start);
        int war = 0;
        for(int i = 0; i < 500; i++) seen[i].reset();
        while(!kol.empty())
        {
            int roz = kol.size();
            for(int i = 0; i < roz; i++)
            {
                pii t = kol.front();
                // debug(t);
                seen[t.fi][t.se] = 1;
                kol.pop();
                if(t == end)
                {
                    res = min(res, war);
                    done = 1;
                    break;
                }
                for(int j = 0; j < 4; j++)
                {
                    if((!seen[t.fi + papax[j]][t.se + papay[j]]) && tab[t.fi + papax[j]][t.se + papay[j]] - 1 <= tab[t.fi][t.se])
                    {
                        kol.push({t.fi + papax[j], t.se + papay[j]});
                        seen[t.fi + papax[j]][t.se + papay[j]] = 1;
                    }
                }
            }
            if(done) break;
            war++;
        }
    }
    cout << res << '\n';
}

/*

*/