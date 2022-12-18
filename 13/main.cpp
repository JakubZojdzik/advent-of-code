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

vi valA, valB;
vector<vi> ales;

bool lessthan(vi A, vi B)
{
    for(int i = 0; i < min(sz(A), sz(B)); i++)
    {
        if(A[i] == -1 && B[i] >= 0)
        {
            B.insert(B.begin() + i, -1);
            B.insert(B.begin() + i + 2, -2);
        }

        if(B[i] == -1 && A[i] >= 0)
        {
            A.insert(A.begin() + i, -1);
            A.insert(A.begin() + i + 2, -2);
        }
    }

    bool rozne = 0;
    for(int i = 0; i < min(sz(A), sz(B)); i++)
    {
        if(A[i] == B[i]) continue;
        rozne = 1;
        if(A[i] >= 0 && B[i] >= 0)
        {
            if(A[i] < B[i])
            {
                return 1;
            }
        }
        else if(A[i] < 0 && B[i] < 0)
        {
            if(A[i] == -2)
            {
                return 1;
            }
        }
        else
        {
            if(A[i] == -2)
            {
                return 1;
            }
        }
        break;
    }
    if((!rozne) && sz(A) <= sz(B)) return 1;
    return 0;
}

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);

    ifstream file("inp");
    string a, b;
    while(file >> a)
    {
        file >> b;
        valA.clear();
        valB.clear();
        bool licz = 0;
        int pocz = -1;
        for(int i = 0; i < sz(a); i++)
        {
            if(a[i] == '[')
            {
                valA.pb(-1);
                licz = 0;
            }
            else if(a[i] == ']')
            {
                if(licz)
                {
                    valA.pb(stoi(a.substr(pocz, i - pocz)));
                    licz = 0;
                }
                valA.pb(-2);
                licz = 0;
            }
            else if(a[i] == ',')
            {
                if(licz)
                {
                    valA.pb(stoi(a.substr(pocz, i - pocz)));
                    licz = 0;
                }
            }
            else
            {
                if(!licz)
                {
                    licz = 1;
                    pocz = i;
                }
            }
        }


        licz = 0;
        pocz = -1;
        for(int i = 0; i < sz(b); i++)
        {
            if(b[i] == '[')
            {
                valB.pb(-1);
                licz = 0;
            }
            else if(b[i] == ']')
            {
                if(licz)
                {
                    valB.pb(stoi(b.substr(pocz, i - pocz)));
                    licz = 0;
                }
                valB.pb(-2);
                licz = 0;
            }
            else if(b[i] == ',')
            {
                if(licz)
                {
                    valB.pb(stoi(b.substr(pocz, i - pocz)));
                    licz = 0;
                }
            }
            else
            {
                if(!licz)
                {
                    licz = 1;
                    pocz = i;
                }
            }
        }

        ales.pb(valB);
        ales.pb(valA);
    }

    ales.pb({-1, -1, 2, -2, -2});
    ales.pb({-1, -1, 6, -2, -2});

    sort(all(ales), lessthan);

    for(auto x : ales)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        nl;
    }
}

/*
[[9]]
[[8,7,6]]
*/