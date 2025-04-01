cp /share/ex_data/ex2/planets.txt .
sort -t' ' -k2,2n -k1,1r planets.txt > planets2.txt
head -n7 planets.txt | tail -n4 | cut -d' ' -f1,2 |  tr ',' ':' | tr -d ' ' | tr a-z A-Z > planets3.txt
cat planets.txt | tr ',' '\n' | tr -s ' ' | cut -d' ' -f2 | tr -d -c '[:digit:]-\n' | tr -d '[:digit:]' | tr -d '\n' | wc -m >> planets2.txt
after creating file ex2.1.sh, run the following command to execute it:
source ex2.1.sh