Student name: Clayton Strike

Hi! Thanks for grading my work. I hope my program doesn't end
up being too difficult to work with. 

The following files are included in the .zip file: 
pre.c 
shhh.c
sort.c
pre
shhh
sort
file.txt
input.txt
output.txt
readme.txt

Step 1. Put the folder wherever you plan to run it on the Linux server
and enter that directory.

2. Just to make sure no problems crop up, go ahead and edit your 
permissions with the files. Run the following command please: 

chmod ugo+rwx file.txt input.txt output.txt pre pre.c shhh shhh.c sort sort.c

3. Again, just to make sure there's no unexpected issues, go ahead and 
remake pre, sort, and shhh please. Go ahead and run the following 
commands: 

gcc -o pre pre.c
gcc -o sort sort.c
gcc -o shhh shhh.c 

4. Finally, to make sure everything is set up correctly, edit your
permissions on the new executables. Just in case. Run the following
command please: 

chmod ugo+rwx pre sort shhh

5. Let's start testing. Run the following command:

./shhh

6. Test "ls". Run the command:

ls

7. Test "ls -t -al". Run the command:

ls -t -al

8. Test "cat file.txt". It should output "file.txt printed correctly!".
Run the command:

cat file.txt

9. Test "ls -al > output.txt". Run the command: 

ls -al > output.txt

Then test that output was written correctly by running the command:

cat output.txt

10. Test "ls | more | wc". Run the command:

ls | more | wc

The output will bleed onto the shhh> line, but the output should be 
correct. You can still input the next command with no problems, it just
looks odd. 

11. Test "./pre < input.txt | ./sort > output". Run the command:

./pre < input.txt | ./sort > output.txt

Test that the output was written to the file correctly by running the 
command: 

cat output.txt 

Again, there's some problem with the shhh> output, but I didn't want
to mess with the given part of the code. You can still enter the next 
input without problems.

12. Test "exit". Run the command: 

exit

You should be sent out of the shhh program. That's it!

13. Thanks for taking the time to grade my program. I hope the rest of
your grading goes smoothly and quickly! You're a real hero. 

             .=.,
            ;c =\
          __|  _/
        .'-'-._/-'-._
       /..   ____    \
      /' _  [<_->] )  \
     (  / \--\_>/-/'._ )
      \-;_/\__;__/ _/ _/
       '._}|==o==\{_\/
        /  /-._.--\  \_
       // /   /|   \ \ \
      / | |   | \;  |  \ \
     / /  | :/   \: \   \_\
    /  |  /.'|   /: |    \ \
    |  |  |--| . |--|     \_\
    / _/   \ | : | /___--._) \
   |_(---'-| >-'-| |       '-'
          /_/     \_\
