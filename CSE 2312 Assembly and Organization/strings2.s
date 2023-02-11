.global strLength
.global strFind
.global strFindN

.text

// int32_t strFind(const char str[], char c)
// add of str[0] in R0, character value to find in R1, 
// return index in R0 of the character or -1 if not found
strFind:
    MOV R2, R0         // R2 = &str[0] = str
    MOV R0, #0         // R0 = index
sf_loop:
    LDRSB R3, [R2, R0] // R3 = *(R2+R0) = str[index]
    CMP R3, #0         // is R3 = 0 or str[index] = null?
    BEQ sf_error       // yes -> return error
    CMP R3, R1         // no -> is R3 = c?
    BEQ sf_end         // yes, return with current index in R0
    ADD R0, R0, #1     // no, increment index
    B sf_loop          // get next character
sf_error:
    MOV R0, #-1        // set return to -1 (char not found)
sf_end:
    BX LR

// int32_t strFindN(const char str[], char c, uint32_t n)
// add of str[0] in R0, character value to find in R1, instance in R2
// return index in R0 of the character or -1 if not found
strFindN:
    PUSH {R4}          // save R4 on stack (preserve context)
    MOV R3, R0         // R3 = &str[0] = str
    MOV R0, #0         // R0 = index
sfn_loop:
    LDRSB R4, [R3, R0] // R4 = *(R3+R0) = str[index]
    CMP R4, #0         // is R4 = 0 or str[index] = null?
    BEQ sfn_error      // yes -> return error
    CMP R4, R1         // no -> is R4 = c?
    BNE sfn_next       // no, get next character
    SUBS R2, R2, #1    // yes, dec instance
    BEQ sfn_end        // if instance = 0, return with current index 
sfn_next:
    ADD R0, R0, #1     // no, increment index
    B sfn_loop         // get next character
sfn_error:
    MOV R0, #-1        // set return to -1 (char not found)
sfn_end:
    POP {R4}           // restore R4 from stack (restore context)
    BX LR
