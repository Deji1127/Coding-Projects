***README***

Files included: first_code.c, message.c, classcode16.h, classcode16.c, messages.txt
------

The first_code.c program outputs to screen specific examples using recursive functions. 

The message.c program allows the user to encode and decode messages.

-------

Compilation instructions: 

--Example 1 (running first_code.c): 
gcc first_code.c classcode16.c -o prog
./prog

(Note that first_code.c is incomplete and won't work correctly with negative integers.)

Make sure to enter the first name, last name followed by the age in this format:
Jon,Doe 77


--Example 2 (running message.c):
gcc message.c classcode16.c -o message 
./message

(Make sure messages.txt is in the same directory since it is used directly in message.c)