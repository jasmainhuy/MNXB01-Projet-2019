#!/bin/sh

#author: Philip Siemund

#Extracts only the temperature data from SMHI datasets and saves the output in a new file data_for_${DATASET}.txt
#Requires GNU awk or mawk. Change the DATASET variable if needed and make sure to specify the correct paths! 

DATASET=Lund

awk -F';' ' 
    x==1 {
        gsub("[:,-]", "")
        tspec = sprintf("%4d %.2d %.2d 00 00 00", substr($1,1,4), substr($1,5,2), substr($1,7,2))
        t = mktime(tspec)
        print $1, $2, $3, $4, 0 + strftime("%j", t)
    }
    /Datum/ {x=1}' /Users/home/MNXB01-Project-2019/datasets/smhi-opendata_${DATASET}.csv >> /Users/home/MNXB01-Project-2019/datasets/data_for_${DATASET}.txt 
