cp /share/ex_data/ex3/planets.txt /share/ex_data/ex3/story.txt .
sed -r 's/([A-Z][a-z]+), (-?[0-9]+)( .*)?/In year \2, planet \1 was discovered/' planets.txt > planet-discovery.txt
grep -E '^[A-Z][a-z]{4}, (-?[0-9]+) .{1,}' planets.txt > planet-status.txt
grep -E '^[A-Z][a-z]+, (1[0-8][0-9]{2})' planets.txt | sed -r 's/([A-Z][a-z]+), (-?[0-9]+) .*/\1/' | sort | sed 's/,.*//' > planets-before-1900.txt
num_lines=$(grep -E '[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]' story.txt |sed 's/[^a-zA-Z]//g' | grep -E '^.{1,200}$' | wc -l)
