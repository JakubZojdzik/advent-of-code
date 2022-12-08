const fs = require('fs');

const data = fs.readFileSync("inp", "utf8");
let tab = [[]];
let ok = [[]];
let j = 0;
for(let i = 0; i < data.length; i++)
{
    if(data[i] === '\n')
    {
        tab.push([]);
        ok.push([]);
        j++;
    }
    else
    {
        tab[j].push(data[i] - '0');
        ok[j].push(true);
    }
}

let akt;
for(let i = 0; i < tab.length; i++)
{
    akt = -1
    for(let j = 0; j < tab.length; j++)
    {
        if(tab[i][j] > akt)
        {
            ok[i][j] = false;
        }
        akt = Math.max(akt, tab[i][j]);
    }
    akt = -1;
    for(let j = tab.length-1; j >= 0; j--)
    {
        if(tab[i][j] > akt)
        {
            ok[i][j] = false;
        }
        akt = Math.max(akt, tab[i][j]);
    }
}

for(let j = 0; j < tab.length; j++)
{
    akt = -1
    for(let i = 0; i < tab.length; i++)
    {
        if(tab[i][j] > akt)
        {
            ok[i][j] = false;
        }
        akt = Math.max(akt, tab[i][j]);
    }
    akt = -1;
    for(let i = tab.length-1; i >= 0; i--)
    {
        if(tab[i][j] > akt)
        {
            ok[i][j] = false;
        }
        akt = Math.max(akt, tab[i][j]);
    }
}

let res = 0;
for(let j = 0; j < tab.length; j++)
{
    for(let i = 0; i < tab.length; i++)
    {
        if(ok[i][j]) res++;
    }
}
console.log(tab.length*tab.length - res);

/*
xxxxx
xxx1x
xx3xx
x3x4x
xxxxx
*/