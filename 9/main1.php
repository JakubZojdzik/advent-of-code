<?php
ini_set('memory_limit', '-1');

$file = fopen('inp', 'r');

$sz = 3000;
$xh = $sz / 2;
$yh = $sz / 2;
$xt = $sz / 2;
$yt = $sz / 2;

$tab = [];

for($i = 0; $i < $sz; $i++)
{
    for($j = 0; $j < $sz; $j++)
    {
        $tab[$i][] = 0;
    }
}

$itr = 0;
$tab[$xt][$yt] = 1;
while (($line = fgets($file)) !== false)
{
    $itr++;
    $inp = explode(' ', $line);
    if($inp[0] === 'R')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $xh++;
            if(abs($xh - $xt) > 1 || abs($yh - $yt) > 1)
            {
                $xt = $xh-1;
                $yt = $yh;
                $tab[$xt][$yt] = 1;
            }
        }
    }
    if($inp[0] === 'L')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $xh--;
            if(abs($xh - $xt) > 1 || abs($yh - $yt) > 1)
            {
                $xt = $xh+1;
                $yt = $yh;
                $tab[$xt][$yt] = 1;
            }
        }
    }
    if($inp[0] === 'D')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $yh++;
            if(abs($xh - $xt) > 1 || abs($yh - $yt) > 1)
            {
                $yt = $yh-1;
                $xt = $xh;
                $tab[$xt][$yt] = 1;
            }
        }
    }
    if($inp[0] === 'U')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $yh--;
            if(abs($xh - $xt) > 1 || abs($yh - $yt) > 1)
            {
                $yt = $yh+1;
                $xt = $xh;
                $tab[$xt][$yt] = 1;
            }
        }
    }
    // printf('%d: head=(%d, %d), tail=(%d, %d)', $itr, $xh, $yh, $xt, $yt);
    // print("\n");
}

$res = 0;
for($i = 0; $i < $sz; $i++)
{
    for($j = 0; $j < $sz; $j++)
    {
        // printf("%d ", $tab[$j][$i]);
        $res += $tab[$j][$i];
    }
    // print("\n");
}

print($res);
print("\n");
fclose($file);

?>