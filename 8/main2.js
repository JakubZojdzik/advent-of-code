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
        ok[j].push(1);
    }
}

let akt, res = 0;
for(let i = 0; i < tab.length; i++)
{
    for(let j = 0; j < tab.length; j++)
    {
        akt = 0;
        for(let k = i+1; k < tab.length; k++)
        {
            akt++;
            if(tab[k][j] >= tab[i][j])
            {
                break;
            }
        }
        ok[i][j] *= akt;
        akt = 0;
        for(let k = i-1; k >= 0; k--)
        {
            akt++;
            if(tab[k][j] >= tab[i][j])
            {
                break;
            }
        }
        ok[i][j] *= akt;
        akt = 0;
        for(let k = j+1; k < tab.length; k++)
        {
            akt++;
            if(tab[i][k] >= tab[i][j])
            {
                break;
            }
        }
        ok[i][j] *= akt;
        akt = 0;
        for(let k = j-1; k >= 0; k--)
        {
            akt++;
            if(tab[i][k] >= tab[i][j])
            {
                break;
            }
        }
        ok[i][j] *= akt;
        res = Math.max(res, ok[i][j]);
    }
}
console.log(res);


/*
xxxxx
xxx1x
xx3xx
x3x4x
xxxxx
*/