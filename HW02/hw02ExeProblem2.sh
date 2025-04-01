cp /share/ex_data/ex2/story.txt .
head -n237 story.txt | tail -n20 | tr aeiou eioua | tr AEIOU EIOUA > story-switched-vowels.txt
cat story.txt | tr -d -c "'\"" | wc -m
cut -c3 story.txt | tr -s ' '| tr -d ' ' |  sort | uniq -c | sort -k1,1nr -k2,2 |  head -n5 | tail -n4 | tr -s ' ' | tr ' ' '-' > letter-stats.txt
tr -cs '[:alnum:]' '\n' < story.txt | tr A-Z a-z | sort | uniq > story-words.txt