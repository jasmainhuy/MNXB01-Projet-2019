#!/bin/sh
#author: Philip Siemund
#Extracts only the temperature data from SMHI datasets and saves the output in a new file data_for_${DATASET}.txt
#Requires GNU awk or mawk. Check your paths! 

DATASET=$@
OUTPUTFILENAME=data_for_${DATASET}

if [[ -z "$DATASET" ]]; then
   echo "Please insert valid argument."
   exit 1
fi

awk -F';' ' 
    x==1 {
        gsub(/-/," ",$1)
        gsub(/[:,0]/,"",$2)
        tspec = sprintf("%4d %.2d %.2d 00 00 00", substr($1,1,4), substr($1,6,2), substr($1,9,2))
        t = mktime(tspec)
        gsub(" 0?", " ", $1)
        print $1, $2, $3, $4, 0 + strftime("%j", t)
    }
    /Datum/ {x=1}' /Users/philipsiemund/MNXB01-Project-2019/datasets/smhi-opendata_${DATASET}.csv >> /Users/philipsiemund/MNXB01-Project-2019/datasets/${OUTPUTFILENAME}.txt 
