.global strLength

.text

/*
// uint32_t strLength(const char str[])
// add of str[0] in R0 -> return length in R0
strLength:
    MOV R1, R0     // R1 = &str[0]
    MOV R0, #0     // R0 = count
sl_loop:
    LDRSB R2, [R1] // R2 = *R1 = *str
    ADD R1, R1, #1 // R1 ++ or str++
    CMP R2, #0     // is R2 = null?
    BEQ sl_end     // yes -> exit loop
    ADD R0, R0, #1 // no -> inc length
    B sl_loop      // get next character
sl_end:
    BX LR

// uint32_t strLength(const char str[])
// add of str[0] in R0 -> return length in R0
strLength:
    MOV R1, R0         // R1 = &str[0]
    MOV R0, #0         // R0 = count
sl_loop:
    LDRSB R2, [R1], #1 // R2 = *R1 = *str
                       // R1 += sizeof(char)
                       // in other words R2 = *(R1++) = *(str++)
    CMP R2, #0         // is R2 = null?
    BEQ sl_end         // yes -> exit loop
    ADD R0, R0, #1     // no -> inc length
    B sl_loop          // get next character
sl_end:
    BX LR
*/

// uint32_t strLength(const char str[])
// add of str[0] in R0 -> return length in R0
strLength:
    MOV R1, R0         // R1 = &str[0]
    MOV R0, #0         // R0 = index
sl_loop:
    LDRSB R2, [R1, R0] // R2 = *(R1+R0) = *(&str[index])
    CMP R2, #0         // is R2 = null?
    BEQ sl_end         // yes -> exit loop
    ADD R0, R0, #1     // no -> inc length
    B sl_loop          // get next character
sl_end:
    BX LR
