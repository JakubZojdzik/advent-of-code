/*
    Jakub Żojdzik
    22-12-2022
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

char tab[1000][1000];
pii poz;
pii wprz[1000], hprz[1000];

bool move(int r)
{
    if(r % 4 == 0)
    {
        if(tab[poz.fi][poz.se+1] == '.')
        {
            poz.se++;
            return 1;
        }
        if(poz.se+1 > wprz[poz.fi].se && tab[poz.fi][wprz[poz.fi].fi] == '.')
        {
            poz.se = wprz[poz.fi].fi;
            return 1;
        }
        return 0;
    }
    if(r % 4 == 1)
    {
        if(tab[poz.fi+1][poz.se] == '.')
        {
            poz.fi++;
            return 1;
        }
        if(poz.fi+1 > hprz[poz.se].se && tab[hprz[poz.se].fi][poz.se] == '.')
        {
            poz.fi = hprz[poz.se].fi;
            return 1;
        }
        return 0;
    }
    if(r % 4 == 2)
    {
        if(tab[poz.fi][poz.se-1] == '.')
        {
            poz.se--;
            return 1;
        }
        if(poz.se-1 < wprz[poz.fi].fi && tab[poz.fi][wprz[poz.fi].se] == '.')
        {
            poz.se = wprz[poz.fi].se;
            return 1;
        }
        return 0;
    }
    if(r % 4 == 3)
    {
        if(tab[poz.fi-1][poz.se] == '.')
        {
            poz.fi--;
            return 1;
        }
        if(poz.fi-1 < hprz[poz.se].fi && tab[hprz[poz.se].se][poz.se] == '.')
        {
            poz.fi = hprz[poz.se].se;
            return 1;
        }
        return 0;
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    int x = 1, y = 1;
    char c;
    ifstream f("inp");
    int h = -1, w = -1;
    while(f >> noskipws >> c)
    {
        w = max(w, x);
        h = max(h, y);
        if(c == '\n')
        {
            y++;
            if(x == 1) break;
            x = 1;
            continue;
        }

        tab[y][x] = c;
        x++;
    }
    h--;
    w--;

    for(int i = 1; i <= h; i++)
    {
        int tmp1 = INT32_MAX;
        int tmp2 = -1;
        for(int j = 1; j <= w; j++)
        {
            if(tab[i][j] == '.' || tab[i][j] == '#')
            {
                tmp1 = min(tmp1, j);
                tmp2 = max(tmp2, j);
            }
        }
        wprz[i] = {tmp1, tmp2};
    }

    for(int i = 1; i <= w; i++)
    {
        int tmp1 = INT32_MAX;
        int tmp2 = -1;
        for(int j = 1; j <= h; j++)
        {
            if(tab[j][i] == '.' || tab[j][i] == '#')
            {
                tmp1 = min(tmp1, j);
                tmp2 = max(tmp2, j);
            }
        }
        hprz[i] = {tmp1, tmp2};
    }

    poz = {1, wprz[1].fi};
    int r = 0; // 0: R, 1: D, 2: L, 3: U
    string s;
    f >> s;

    int pocz = -1;
    bool liczba = 0;
    for(int i = 0; i < sz(s); i++)
    {
        if(s[i] == 'R')
        {
            if(liczba)
            {
                liczba = 0;
                int num = stoi(s.substr(pocz, i-pocz+1));
                for(int j = 0; j < num; j++)
                {
                    if(!move(r)) break;
                }
            }
            r = (r + 1) % 4;
        }
        else if(s[i] == 'L')
        {
            if(liczba)
            {
                liczba = 0;
                int num = stoi(s.substr(pocz, i-pocz+1));
                for(int j = 0; j < num; j++)
                {
                    if(!move(r)) break;
                }
            }
            r = (r + 3) % 4;
        }
        else
        {
            if(!liczba)
            {
                liczba = 1;
                pocz = i;
            }
            if(i == sz(s)-1)
            {
                liczba = 0;
                int num = stoi(s.substr(pocz, i-pocz+1));
                for(int j = 0; j < num; j++)
                {
                    if(!move(r)) break;
                }
            }
        }
    }
    cout << 1000 * poz.fi + 4 * poz.se + r << '\n';
}

/*

*/