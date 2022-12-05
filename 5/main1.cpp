/*
    Jakub Żojdzik
    05-12-2022
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

ll stacks = 9;
ll moves = 504;
stack<char> tab[100007];
stack<char> frominp[100007];
ll vals[3];

int main()
{
    string s;
    int counter = 8;
    while(counter--)
    {
        getline(cin, s);
        for(int i = 0; i < sz(s); i++)
            if(s[i] == '[')
                frominp[i/4+1].push(s[i+1]);
    }
    for(int i = 1; i <= stacks; i++)
    {
        while(!frominp[i].empty())
        {
            tab[i].push(frominp[i].top());
            frominp[i].pop();
        }
    }
    getline(cin, s);
    getline(cin, s);
    while(moves--)
    {
        string syf;
        int a, b, c;
        cin >> syf >> a >> syf >> b >> syf >> c;
        for(int i = 0; i < a; i++)
        {
            tab[c].push(tab[b].top());
            tab[b].pop();
        }
    }
    for(int i = 1; i <= stacks; i++)
    {
        if(!tab[i].empty())
        {
            cout << tab[i].top();
        }
    }
    nl;
}

/*

*/