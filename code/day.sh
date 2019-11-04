#!/bin/sh

awk '
     {
        tspec = sprintf("%4d %.2d %.2d 00 00 00", substr($1,1,4), substr($2,1,2), substr($2,3,4))
        t = mktime(tspec)
        $(NF+1) = 0 + strftime("%j",t)
    } {print}' /Users/philipsiemund/MNXB01-Project-2019/datasets/tempdata_Lund.txt >> /Users/philipsiemund/MNXB01-Project-2019/datasets/tempdata_Lund_days.txt

