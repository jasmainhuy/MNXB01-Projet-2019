#!/bin/sh

#author: Philip Siemund
#Extracts only the temperature data from SMHI datasets and saves the output in a new file tempdata_${DATASET}.txt, where all occurrences of - and : are deleted

#Change the DATASET variable if needed and make sure to specify the correct paths! Also, for OSX, the '' after sed -i is apparently mandatory. For other operating systems this might throw an error 

DATASET=Lund

awk -F ';' 'x==1 {print $1 " " $2 " " $3 " " $4} /Datum/ {x=1}' /Users/home/MNXB01-Project-2019/datasets/smhi-opendata_${DATASET}.csv >> /Users/home/MNXB01-Project-2019/datasets/tempdata_${DATASET}.txt

sed -i '' 's/[-:,]//g' /Users/home/MNXB01-Project-2019/datasets/tempdata_${DATASET}.txt