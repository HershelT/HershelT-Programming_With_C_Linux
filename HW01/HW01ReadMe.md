# Homework 01 - File Manipulation Tasks

**General Guidelines:**
- Do all your work in the directory `~/exercises/ex1/` that you create for this assignment.
- Use only relative paths (absolute paths are forbidden except when accessing `/share/ex_data/ex1/` for task #2).
- Test your solution by following the four validation steps provided in the assignment.

**Problem 1:**
Implement each of the following file manipulation tasks with a single Linux command.

1. **Create subdirectory:**  
   Create a subdirectory called `cs3144` inside the current directory.  
   **Solution:** `mkdir cs3144`

2. **Copy a directory:**  
   Copy `/share/ex_data/ex1/stuff` into the newly created `cs3144` directory so that it contains `stuff` (with its 9 files) as a subdirectory.  
   **Solution:** `cp -r /share/ex_data/ex1/stuff cs3144`

3. **Move a file:**  
   Move `lecture1_notes.txt` from `cs3144/stuff` to `cs3144`.  
   **Solution:** `mv cs3144/stuff/lecture1_notes.txt cs3144`

4. **Change directory:**  
   Change into the subdirectory `cs3144/stuff`.  
   **Solution:** `cd cs3144/stuff`

5. **Change permissions (alphabetic):**  
   Using an alphabetic permission specifier, add write permission to everyone for all files in the parent directory (`cs3144`) and its subdirectories (excluding `cs3144` itself).  
   **Solution:** `chmod -R a+w ../*`

6. **Remove files:**  
   Delete all files in the current directory whose names begin with `file2` or `file4` using wildcards.  
   **Solution:** `rm file2* file4*`

7. **Change file permissions (octal):**  
   Change permissions of `file01` so that the owner has read, write, and execute permissions; group users have read and execute permissions; others have no permissions.  
   **Solution:** `chmod 750 file01`

8. **Create a new file with echo:**  
   Use a single `echo` command with output redirection to create `my.newfile` in the parent directory (cs3144) containing:  
   `"this is my line of text and I am proud of it"`  
   **Solution:** `echo "this is my line of text and I am proud of it" > ../my.newfile`

9. **Return to the original directory:**  
   Move up to the directory where you started (the parent of `cs3144`).  
   **Solution:** `cd ../../`

10. **Rename a file:**  
    Change the name of `fill2` in the `cs3144/stuff` subdirectory to `file2.new`.  
    **Solution:** `mv cs3144/stuff/fill2 cs3144/stuff/file2.new`

**Problem 2:**  
Type the above commands into a solution file named `my_commands.txt` and ensure your script passes the final validation step (running `test_ex1`).
