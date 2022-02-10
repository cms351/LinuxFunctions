# LinuxFunctions
Imitation Linux terminal commands as its own C program. 

Instructions: 

This was a university project for my operating systems class. Basically, the task was to implement the pipe command and 
the "<" and ">" (input and output redirect) commands like you would see in the Linux terminal.
This project was super fun because I was working with C for the first time, it was my first time working with file descriptors, 
first time piping things like this. It was really cool. 
All of the steps should work, but I have run into some occassional cosmetic bugs within the terminal. It doesn't affect the 
program's main functionality nor is it difficult to troubleshoot. If you encounter any bugs within the program, just exit 
the program, reopen it, and continue on the step you were previously on. Also, please consider that a portion of this code 
was supplied by my professor and I was tasked with completing the program. Some of the coding style in the supplied portion
can be pretty rough - I did not write that and was not permitted to change it. 

As of writing this 2/09/2022, I'm more focused on my other projects and don't plan on revisiting this program. This is only here
to demonstrate my ability to work with C for potential employers. 

For a tour of the program, please follow these steps: 

(1) Pull these files onto your local machine, put them in a folder together wherever you want. Enter your Linux terminal and enter
that directory. 

(2) Just to make sure there's no unexpected issues, go ahead and remake the make files. (Probably overkill, I know). 
Run these commands: 
```
gcc -o pre pre.c 

gcc -o sort sort.c 

gcc -o shhh shhh.c 
```
(3) Time to start testing the code. Run the following command: 
```
./shhh 
```
If that doesn't work, it's probably a permissions problem. This is overkill, but this command should fix any problems with that:
```
chmod ugo+rwx file.txt input.txt output.txt pre pre.c shhh shhh.c sort sort.c
```
Then just try to run this command again: 
```
./shhh
```
(4) Ok, once you're in the shhh program, let's test something simple. Run the command: 
```
ls
```
(5) Now try: 
```
ls -t -al 
```
(6) Try printing a txt file. This should output "file.txt printed correctly!". Run the command: 
```
cat file.txt
```
(7) Let's text the output redirect command. Run the command: 
```
ls -al > output.txt 
```
then run the command: 
```
cat output.txt 
```
(8) Let's test the piping. Run the command: 
```
ls | more | wc 
```
(9) Finally, let's go crazy with a input redirect, output redirect, and some piping. Run the command: 
```
./pre < input.txt | ./sort > output.txt
```
Then run the command: 
```
cat output.txt
```
This should output a sorted list from the list of names in input.txt. 

(10) Obviously, that was just a rundown of the testing I've done. Feel free to play around with the code!

(11) When you're ready to exit the program, run the command: 
```
exit 
```
(12) Thank you for checking out my code! Let me know what you think of the source code. This was probably the most enjoyable 
university project I've done so I'm excited to share it with others. 
