.global strMid
.global strCat
.text

// void strCat(char strTo[], const char strFrom[])
// R0 = add of strTo[0], R1 = add of strFrom[0]
strCat:
    LDRSB R2, [R0], #1 // get character from strTo
    CMP R2, #0         // is char = null?
    BNE strCat         // no, get next character
    SUB R0, R0, #1     // back up to null
strCat_loop:
    LDRSB R2, [R1], #1 // get character from strFrom
    CMP R2, #0         // is character a null?
    BEQ strCat_end     // yes, exit
    STRB R2, [R0], #1  // store character in strTo
    B strCat_loop      // get next character
strCat_end:
    MOV R2, #0         // add null terminator to strTo
    STRB R2, [R0] 
    BX LR

// void strMid(char strTo[], const char strFrom[], uint32_t offset, uint32_t length)
// R0 = add of strTo[0], R1 = add of strFrom[0], R2 = offset, R3 = length
strMid:
    PUSH {R4}
strMid_loop1:
    CMP R2, #0         // is offset = 0?
    BEQ strMid_loop2   // yes, go to copy loop
    LDRSB R4, [R1], #1 // get character from strFrom
    CMP R4, #0         // is char a null?
    BEQ strMid_end     // yes, offset beyond end of string -> exit
    SUB R2, R2, #1     // dec offset
    B strMid_loop1     // get next character

                       // R1 now points at strFrom[offset]
                       // this current contains a null 
strMid_loop2:
    CMP R3, #0         // is length = 0?
    BEQ strMid_end     // yes, copying all characters -> exit
    LDRSB R4, [R1], #1 // get character from strFrom
    CMP R4, #0         // is char a null?
    BEQ strMid_end     // yes, end of string found before length characters copied -> exit
    STRB R4, [R0], #1  // store character
    SUB R3, R3, #1     // decrement length
    B strMid_loop2     // get next character

strMid_end:
    MOV R4, #0         // add null to end of strTo
    STRB R4, [R0]    
    POP {R4}
    BX LR

