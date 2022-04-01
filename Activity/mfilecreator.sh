#!/bin/bash
 
now="$(date +'%Y%m%d_%H%M')"

#printf "Current date in dd/mm/yyyy format %s\n" "$now"
outfile="TODO_.$(date +%Y%m%d_%H%M)."txt"

echo "${now}"  >> $outfile
# command to backup scripts goes here
# ...