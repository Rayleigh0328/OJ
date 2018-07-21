# Read from the file file.txt and output the tenth line to stdout.

cnt=0
result=""
while IFS='' read -r line || [[ -n "$line" ]]; do
    cnt=$((cnt + 1))
    if [ $cnt -eq 10 ]; then
        result=$line
        break
    fi
done < file.txt 
echo $result
