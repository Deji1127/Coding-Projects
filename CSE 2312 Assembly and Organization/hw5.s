@a. int32_t sumS32(const int32_t x[], uint32_t count)
@// returns sum of the values in the array (x) containing count entries.
@b. int32_t dotpS32(const int32_t x[], const int32_t y[], uint32_t count) 
@// returns the dot product of the values in the arrays (x and y) containing count entries.
@c. uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count) 
@// returns number of values in the array (x) containing count entries that are > limit
@d. int32_t findCityAligned (const char city[], const BUSINESS2 business[], uint32_t count)
@// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
@ If the city is not found, return a value of -1. You can assume that C default alignment is used for this problem.
@e. int32_t findCityPacked (const char city[], const BUSINESS2 business[], uint32_t count)
@// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
@If the city is not found, return a value of -1. You can assume that C packing is used for this problem.

.global sumS32
.global dotpS32
.global countAboveLimit
.global findCityAligned
.global findCityPacked

.text

int32_t sumS32(const int32_t x[], uint32_t count)
// returns sum of the values in the array (x) containing count entries

sumS32:
  MOV R3, R0 //take what's in R0 (the array) and put it in R3
  MOV R0, #0 //R0 becomes null/0
sumS32_loop:
  CMP R1, #0 //is the amount of entries 0 (null)
  BEQ sumS32_exit //if it is the exit the program
  LDR R2, [R3], #4 //take what's in R3 (the array), then put it in R2, then increment R3
  ADD R0, R0, R2 //add what's in R2 and R0 and place it in R0
  SUB R1, R1, #1 //decrement the amount of values in the array
  B sumS32_loop //redo the loop/get next value in the array
sumS32_exit:
  BX LR

int32_t dotpS32(const int32_t x[], const int32_t y[], uint32_t count)
// returns the dot product of the values in the arrays (x and y)
// containing count entries

dotpS32:
  PUSH  {R4, R5} //push needed registers
  MOV R3, R0 //take what's in R0 (array x) and put it in R3
  MOV R0, #0 //make R0 null/0
  CMP R2, #0 //check is the amount of entries in both arrays 0?
  BEQ dotpS32_exit //if it is the exit the loop and program
dotpS32_loop:
  LDR R4, [R3], #4 //take what's in R3 (the current value in array x) and put it in R4 then incrememnt R3 (the array)
  LDR R5, [R1], #4 //take what's in R1 (the current value in array y) and put it in R5 then increment R1 (the array)
  MLA R0, R4, R5, R0 //multiply the values in R4 and R5 and add what's in R0 and place result in R0
  SUBS R2, R2 ,#1 //decrement the amount of entries and set falg (for zero)
  BNE dotpS32_loop //get next values/ repeat loops
dotpS32_exit:
  POP {R4, R5}
  BX LR

uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count) 
// returns number of values in the array (x) containing count entries
that are > limit

countAboveLimit:
	PUSH {R4} //push needed registers
	MOV R3, R0 //take what's in R0 (the array) and put in R3        
	MOV R0, #0 //zero out R0       
countAboveLimitLoop:
	CMP R2, #0 //is the amount of values in the array null/0
	BEQ countAboveLimitEnd //if it is, jump to end and terminate program
	LDR R4, [R3], #4 //take what's R3 (the current element of the array) and put it in R5 then increment R3
	CMP R4, R1 //cmp the limit with the current value of the array
	ADDGT R0, R0, #1 //if current value is greater, add 1 to R0 and place result in R0
	SUB R2, R2, #1 //decrement the amount of values in the array
	B countAboveLimitLoop //get next value/repeat loop
countAboveLimitEnd:
	POP {R4}
	BX LR

int32_t findCityAligned (const char city[], const BUSINESS2 business[], uint32_t
count)
// returns the index of the first entry in the array (business) containing
count entries which matches the requested city. If the city is not
found, return a value of -1. You can assume that C default alignment is
used for this problem.

findCityAligned:
    PUSH {R4-R7, R8, R9, R10} 
    MOV R5, R0 //move what's in R0 (the city) into R5
    MOV R4, R1 //move what's in R1 (the array of structs) into R4     
    ADD R4, R4, #72 //go to R4 (current struct), go to the city(position #72), then place in R4 
    MOV R3, #112 //move the ending position of the current struct (#112) to R3
    MOV R10, #0 //clear out R10
test_string:
    CMP R2, #0 //is the amount of structs in the array null?
    BEQ test_exit_not_found //if it is, end program and go to end
    MOV R6, R4 //else take what's in R4 (the first letter of the city) and place in R6
    MOV R7, R0 //move the what's in R0 (the city name) into R7
test_string_loop:
    LDRSB R8, [R6], #1 //take what's in R6 (the first letter of the city name from struct) and put in R8 and increment R6
    LDRSB R9, [R7], #1 //take what's in R7(the first letter of the city) and put in R9 and increment R7
    CMP R8, R9 //are those letters the same
    BNE next_business// if they're not, jump to next_business
    CMP R8, #0 //compare the first letter of the city from the struct with 0
    BEQ test_exit_found //if it's null the jump to test_exit_found
    B test_string_loop //get next letters/ redo loop
next_business:
    ADD R4, R4, R3 //add what's in R3 (ending of the current struct) with R4 (the size to get to city name) and place in R4
    ADD R10, R10, #1 //increment R10 (the index of the struct in the array)
    SUBS R2, R2, #1 //decrement the amount of structs in array
    B test_string //go back to test_string
test_exit_found:
    MOV R0, R10 //move R10 (the current index of the struct from the array) into R0
    POP {R4-R7, R8, R9, R10} //clear registers 
    BX  LR
test_exit_not_found: 
    MOV R0, #-1 //return -1
    POP {R4-R7, R8, R9, R10} //clear registers
    BX  LR


findCityPacked:
    PUSH {R4-R7, R8, R9, R10}
    MOV R5, R0	    
    MOV R4, R1	     
    ADD R4, R4, #71  
    MOV R3, #108     
    MOV R10, #0	  
    CMP R2, #0	     
    B test_string
test_string:
    CMP R2, #0 //is the amount of structs in the array null?
    BEQ test_exit_not_found //if it is, end program and go to end
    MOV R6, R4 //else take what's in R4 (the first letter of the city) and place in R6
    MOV R7, R0 //move the what's in R0 (the city name) into R7
test_string_loop:
    LDRSB R8, [R6], #1 //take what's in R6 (the first letter of the city name from struct) and put in R8 and increment R6
    LDRSB R9, [R7], #1 //take what's in R7(the first letter of the city) and put in R9 and increment R7
    CMP R8, R9 //are those letters the same
    BNE next_business// if they're not, jump to next_business
    CMP R8, #0 //compare the first letter of the city from the struct with 0
    BEQ test_exit_found //if it's null the jump to test_exit_found
    B test_string_loop //get next letters/ redo loop
next_business:
    ADD R4, R4, R3 //add what's in R3 (ending of the current struct) with R4 (the size to get to city name) and place in R4
    ADD R10, R10, #1 //increment R10 (the index of the struct in the array)
    SUBS R2, R2, #1 //decrement the amount of structs in array
    B test_string //go back to test_string
test_exit_found:
    MOV R0, R10 //move R10 (the current index of the struct from the array) into R0
    POP {R4-R7, R8, R9, R10} //clear registers 
    BX  LR
test_exit_not_found: 
    MOV R0, #-1 //return -1
    POP {R4-R7, R8, R9, R10} //clear registers
    BX  LR
