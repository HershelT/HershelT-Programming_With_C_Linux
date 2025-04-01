# Homework 02 – Piped Sequences and Parsing

## General Notes
- Only use the commands from weeks 1-2:  
  `cp`, `cat`, `head`, `tail`, `cut`, `paste`, `wc`, `sort`, `uniq`, `tr`
- Do not use `grep` or `sed` in your solutions.
- Use relative paths except when copying from the shared directory.
  - Exception: copying from `\share\ex_data\ex2\`.

---

## Problem 1 – Parsing planets.txt

The file `planets.txt` contains one planet per line with the format:  
`<planet>, <year> [<status>]`  
Where:
- `<planet>` starts with an uppercase letter followed by lowercase letters.
- `<year>` is a four-digit discovery year or `-1` if unknown.
- `<status>` (optional) is additional text without punctuation.

Write piped sequences for the tasks below. Each command (or piped sequence) will be recorded in a solution file `ex2.1.sh` (one command per line).

1. **Copy planets.txt:**  
   **Solution:**  
   `cp /share/ex_data/ex2/planets.txt .`

2. **Sort the file weighted by year then by name (reverse alphabetical for same year):**  
   **Solution:**  
   `sort -t, -k2,2n -k1,1r planets.txt > planets2.txt`

3. **Generate planets3.txt with planet name (in upper-case) and year of discovery from lines 4-7:**  
   Format: `<PLANET>:<year>` (omit optional status).  
   **Solution:**  
   `head -n7 planets.txt | tail -n4 | cut -d, -f1,2 | tr ',' ':' | tr a-z A-Z > planets3.txt`

4. **Append to planets2.txt the count of planets with unknown year (`-1`):**  
   (A single line containing the count.)  
   **Solution:**  
   *[Piped sequence without using grep, sed, or awk]*

5. **Generate planets5.txt with each line in the format:**  
   `<pl>[<space><STATUS>]`  
   where `<pl>` are the first two letters (lower-case) of the planet’s name and `<STATUS>` is the optional status. Remove trailing white spaces.  
   **Solution:**  
   `cut -d' ' -f1 planets.txt | tr -d -c '[:alpha:]' | tr A-Z a-z | cut -c1-2 | paste -d' ' - planets.txt > planets5.txt`

**All Commands in ex2.1.sh (each on a separate line):**
```
cp /share/ex_data/ex2/planets.txt .
sort -t, -k2,2n -k1,1r planets.txt > planets2.txt
head -n7 planets.txt | tail -n4 | cut -d, -f1,2 | tr ',' ':' | tr a-z A-Z > planets3.txt
...existing command for appending unknown year count to planets2.txt...
cut -d' ' -f1 planets.txt | tr -d -c '[:alpha:]' | tr A-Z a-z | cut -c1-2 | paste -d' ' - planets.txt > planets5.txt
```

---

## Problem 2 – Parsing story.txt

The file `story.txt` contains the text of *Animal Farm* from the Gutenberg Project. Write piped sequences for the tasks below. Each command (or piped sequence) will be recorded in a solution file `ex2.2.sh` (one command per line).

1. **Copy story.txt:**  
   **Solution:**  
   `cp /share/ex_data/ex2/story.txt .`

2. **Switch vowels in lines 218-237 (permutation: A→E→I→O→U→A; same for lower-case):**  
   The transformed text should be saved as `story-switched-vowels.txt`.  
   **Solution:**  
   `head -n237 story.txt | tail -n20 | tr aeiou eioua | tr AEIOU EIOUA > story-switched-vowels.txt`

3. **Count the occurrences of single and double quotes in story.txt:**  
   **Solution:**  
   `cat story.txt | tr -d -c "'\"" | wc -m`

4. **Print to letter-stats.txt the four most frequent non-space characters that occur as the 3rd character in each line:**  
   Each output line should have the format: `-<count>-<char>`  
   Sort by count (descending) and alphabetically when counts are equal.  
   **Solution:**  
   *[Piped sequence without using grep or sed]*

5. **List all distinct words from story.txt into story-words.txt:**  
   Definition of word: non-empty contiguous sequence of characters without white spaces or punctuation; case-insensitive. The list should be in lower-case and alphabetical order.  
   **Solution:**  
   `tr -cs '[:alnum:]' '\n' < story.txt | tr A-Z a-z | sort | uniq > story-words.txt`

**All Commands in ex2.2.sh (each on a separate line):**
```
cp /share/ex_data/ex2/story.txt .
head -n237 story.txt | tail -n20 | tr aeiou eioua | tr AEIOU EIOUA > story-switched-vowels.txt
cat story.txt | tr -d -c "'\"" | wc -m
...existing command for letter-stats.txt...
tr -cs '[:alnum:]' '\n' < story.txt | tr A-Z a-z | sort | uniq > story-words.txt
```

---

Remember to source the corresponding shell scripts (e.g., `source ex2.1.sh` and `source ex2.2.sh`) to execute your solutions.
