# Homework 03 – Advanced Piped Sequences & Bash Scripts

## General Notes
- A piped sequence is an ordered series of Linux commands connected using the pipe symbol (`|`).
- Use only the commands taught in class.
  - For `grep`: only options `-E`, `-v`, and `-c` are allowed.
  - For `sed`: use only the `-r` option.
- Use relative paths (the only exception is `/share/ex_data/ex3/`).
- Your solution scripts must run correctly from any location in the file system.

---

## Problem 1 – Parsing planets.txt and story.txt

**File Format – planets.txt:**  
Each line is formatted as:  
`<planet>, <year>[ <status>]`  
Where:
- `<planet>`: An uppercase letter followed by lowercase letters (e.g., Mars).
- `<year>`: A four-digit discovery year or `-1` for unknown.
- `<status>`: Optional descriptive text (contains spaces but no punctuation).
- Note: The comma and space characters are literal.

**story.txt:** Contains the text of *Animal Farm* with no specific format.

### Task 1: Copy Files  
Copy both `planets.txt` and `story.txt` from `/share/ex_data/ex3/` to the current directory.  
**Answer:**  
`cp /share/ex_data/ex3/planets.txt . | cp /share/ex_data/ex3/story.txt .`

### Task 2: Reformat Discovery Information  
Reformat each line of `planets.txt` (omitting the optional status) so that it reads:  
```
In year <year>, planet <planet> was discovered
```  
**Answer:**  
`sed -r 's/([A-Z][a-z]+), ([0-9]{4}|-1)( .*)?/In year \2, planet \1 was discovered/' planets.txt > planet-discovery.txt`

### Task 3: Filter by Planet Name Length and Status  
Generate `planet-status.txt` with lines from `planets.txt` where the planet name contains exactly five letters and a non-empty status is present.  
**Answer:**  
`grep -E '^[A-Z][a-z]{4}, (-?[0-9]+|-1) .{1,}' planets.txt > planet-status.txt`

### Task 4: List Planets Discovered Between 1000 and 1899  
Extract and sort alphabetically the names of planets discovered between 1000 and 1899 (ignoring planets with unknown year). The output file should contain only planet names.  
**Answer:**  
`grep -E '^[A-Z][a-z]+, (1[0-8][0-9]{2})' planets.txt | sed -r 's/([A-Z][a-z]+), (-?[0-9]+).*/\1/' | sort | sed 's/,.*//' > planets-before-1900.txt`

### Task 5: Count Specific Lines in story.txt  
Assign a bash variable `num_lines` with the number of lines in `story.txt` that satisfy both:
- The line contains a word with a vowel immediately followed by either `cc` or `ss` and then a punctuation character.
- The line contains at most 200 letters (a-z or A-Z).  
**Answer:**  
`num_lines=$(grep -E '[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]' story.txt | tr -cd '[:alpha:]' | awk 'length <= 200' | wc -l)`

### Task 6: Extract Words Following "Snowball's"  
Output to `snowballs_words.txt` all distinct lower-case words that immediately follow the text "Snowball's". A word follows if:
- It follows "Snowball's" after one or more white spaces.
- It consists solely of lower-case letters.
- It is terminated by a white space or punctuation.  
**Answer:**  
`sed -r "s/Snowball's ([a-z]+)[[:space:][:punct:]]*/\1/g" story.txt | sort | uniq > snowballs_words.txt`

---

**All Combined Commands (for file ex3.1.sh):**
```
cp /share/ex_data/ex3/planets.txt /share/ex_data/ex3/story.txt .
sed -r 's/([A-Z][a-z]+), (-?[0-9]+)( .*)?/In year \2, planet \1 was discovered/' planets.txt > planet-discovery.txt
grep -E '^[A-Z][a-z]{4}, (-?[0-9]+) .{1,}' planets.txt > planet-status.txt
grep -E '^[A-Z][a-z]+, (1[0-8][0-9]{2})' planets.txt | sed -r 's/([A-Z][a-z]+), (-?[0-9]+).*/\1/' | sort | sed 's/,.*//' > planets-before-1900.txt
num_lines=$(grep -E '[aeiou](cc|ss)[[:alpha:]]*[[:punct:]]' story.txt | tr -cd '[:alpha:]' | awk 'length <= 200' | wc -l)
sed -r "s/Snowball's ([a-z]+)[[:space:][:punct:]]*/\1/g" story.txt | sort | uniq > snowballs_words.txt
```
*Ensure that file ex3.1.sh contains exactly six lines (one per command).*

---

## Problem 2 – Bash Scripts for Storage Size Calculation

This problem requires two bash scripts.

### Script: get-storage.sh  
**Objective:**  
Print the storage size (in bytes, as reported by `ls -l`) for the file or directory provided in the bash variable `my_item`.  
**One-Liner Answer:**  
`ls -ld $my_item | tr -s ' ' | cut -d ' ' -f 5`

### Script: subtree-storage.sh  
**Objective:**  
Recursively calculate and print the total storage size in bytes for the directory tree rooted at a given path.  

**Requirements:**
- If the script does not receive exactly one argument, print:  
  `Usage: <SCRIPT_PATH> PATH`  
  and exit with status 1.
- If the argument is not a valid path, print:  
  `<ARG> is not a valid path`  
  and exit with status 2.
- If the argument is a file, output its size (using `get-storage.sh`) and exit with status 0.
- If the argument is a directory, recursively compute the total storage by summing the sizes of all items (files and directories) in its subtree, then exit with status 0.

**Sample Implementation:**
```bash
#!/bin/bash
# ...existing code...
if [ "$#" != 1 ]; then
    echo "Usage: $0 PATH"
    exit 1
fi

if [ ! -e "$1" ]; then
    echo "$1 is not a valid path"
    exit 2
fi

if [ -f "$1" ]; then
    my_item="$1"
    echo `source get-storage.sh`
    exit 0
fi

if [ -d "$1" ]; then
    my_item="$1"
    total_size=0
    for item in `ls -A "$my_item"`; do
        total_size=$(( total_size + $(./subtree-storage.sh "$my_item/$item") ))
    done
    echo $total_size
    exit 0
fi
# ...existing code...
```
*Remember to grant executable permissions and include the proper shebang (`#!/bin/bash`) at the top of both scripts.*

---

*Ensure to source and test your scripts (e.g., `source ex3.1.sh` for Problem 1 commands, and run the storage scripts accordingly).*