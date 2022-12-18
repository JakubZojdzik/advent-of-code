/*
    Jakub Żojdzik
    18-12-2022
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

int board[1000][1000];
int najw = -1;

bool dropsand(int x = 500, int y = 0)
{
    if(board[y][x]) return 0;
    while(1)
    {
        if(y < najw+1 && !board[y+1][x]) y++;
        else if(y < najw+1 && !board[y+1][x-1]) {x--; y++;}
        else if(y < najw+1 && !board[y+1][x+1]) {x++; y++;}
        else
        {
            board[y][x] = 2;
            return 1;
        }
    }
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ifstream input("inp");
    string line;
    while(getline(input, line))
    {
        int pocz = 0, x[2], y[2], itr = 0;
        line = line + " ";
        for(int i = 0; i < sz(line); i++)
        {
            if(line[i] == ',')
            {
                x[itr] = stoi(line.substr(pocz, i-pocz));
                pocz = i+1;
            }
            if(line[i] == ' ' && pocz <= i)
            {
                y[itr] = stoi(line.substr(pocz, i-pocz));
                najw = max(najw, y[itr]);
                pocz = i+4;
                itr++;

                if(itr >= 2)
                {
                    for(int k = min(x[0], x[1]); k <= max(x[0], x[1]); k++)
                    {
                        for(int l = min(y[0], y[1]); l <= max(y[0], y[1]); l++)
                        {
                            board[l][k] = 1;
                        }
                    }
                    itr = 1;
                    x[0] = x[1];
                    y[0] = y[1];
                }
            }
        }
    }
    int res = 0;
    // cout << "najw = " << najw << '\n';
    while(dropsand()) res++;
    // for(int i = 0; i <= 13; i++)
    // {
    //     for(int j = 485; j <= 515; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     nl;
    // }
    cout << res << '\n';
}

/*

*/