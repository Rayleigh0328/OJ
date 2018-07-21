awk '{ for (i=1; i<=NF; ++i) if ( arr[$i] == "") { arr[$i] = 1 } else { ++arr[$i] } } END{ for (key in arr) print key, arr[key] }' words.txt | sort -k2 -r -n
