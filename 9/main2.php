<?php
ini_set('memory_limit', '-1');

$file = fopen('inp', 'r');

$sz = 1500;
$xh = $sz / 2;
$yh = $sz / 2;

$tab = [];
$wazx = array($xh, $xh, $xh, $xh, $xh, $xh, $xh, $xh, $xh, $xh);
$wazy = array($yh, $yh, $yh, $yh, $yh, $yh, $yh, $yh, $yh, $yh);

for($i = 0; $i < $sz; $i++)
    for($j = 0; $j < $sz; $j++)
        $tab[$i][] = 0;
$itr = 0;
$tab[$xh][$yh] = 1;


function update()
{
    global $wazx, $wazy, $tab;
    for($j = 1; $j < 10; $j++)
    {
        if(abs($wazx[$j-1] - $wazx[$j]) > 1 && abs($wazy[$j-1] - $wazy[$j]) > 1)
        {
            $wazx[$j] = ($wazx[$j] + $wazx[$j-1]) / 2;
            $wazy[$j] = ($wazy[$j] + $wazy[$j-1]) / 2;
        }
        if($wazx[$j-1] - $wazx[$j] > 1)
        {
            $wazx[$j] = $wazx[$j-1]-1;
            $wazy[$j] = $wazy[$j-1];
        }
        else if($wazx[$j-1] - $wazx[$j] < -1)
        {
            $wazx[$j] = $wazx[$j-1]+1;
            $wazy[$j] = $wazy[$j-1];
        }
        else if($wazy[$j-1] - $wazy[$j] > 1)
        {
            $wazx[$j] = $wazx[$j-1];
            $wazy[$j] = $wazy[$j-1]-1;
        }
        else if($wazy[$j-1] - $wazy[$j] < -1)
        {
            $wazx[$j] = $wazx[$j-1];
            $wazy[$j] = $wazy[$j-1]+1;
        }
    }
    $tab[$wazx[9]][$wazy[9]] = 1;
}


while (($line = fgets($file)) !== false)
{
    $itr++;
    $inp = explode(' ', $line);
    if($inp[0] === 'R')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $wazx[0]++;
            update();
        }
    }
    if($inp[0] === 'L')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $wazx[0]--;
            update();
        }
    }
    if($inp[0] === 'D')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $wazy[0]++;
            update();
        }
    }
    if($inp[0] === 'U')
    {
        for($i = 0; $i < intval($inp[1]); $i++)
        {
            $wazy[0]--;
            update();
        }
    }
}
$res = 0;
for($i = 0; $i < $sz; $i++)
    for($j = 0; $j < $sz; $j++)
        $res += $tab[$j][$i];

print($res);
print("\n");
fclose($file);

/*
9 8 7 6 5 4 3 2 1 0

9 8 7 6 5 4 3 2 1 0
*/

?>