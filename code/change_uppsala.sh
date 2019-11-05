#!/bin/sh

# Author: Esttelle Sernoux

# Change Uppsala input data to tempdata_Upsala.txt file
# Replaces spaces groups by single spaces
# Output format : year month day avg avg_corrcter

# Copy original input file to temporary file
cp ../datasets/uppsala_tm_1722-2013.dat ../datasets/tempdata_uppsala.txt

# Replace spaces bunches into single spaces
sed -i s/\ \ */\ /g ../datasets/tempdata_uppsala.txt
