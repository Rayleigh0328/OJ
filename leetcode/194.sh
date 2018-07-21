awk '{ rows = FNR; cols = NF; for (i = 1; i<=NF; ++i) arr[rows,i]=$i; } END{ ORS=" "; for (i = 1; i<=cols; ++i){ for (j= 1; j<rows; ++j){ print arr[j,i]; } printf "%s\n", arr[rows,i]; } }' file.txt
