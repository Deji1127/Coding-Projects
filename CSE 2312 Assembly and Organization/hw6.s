@a. float sumF32(const float x[], uint32_t count)
// returns the sum of the elements in an array (x) containing count entries
@b. double prodF64(const double x[], uint32_t count)
// returns the product of the elements in an array (x) containing count entries
@c. double dotpF64(const double x[], const double y[],uint32_t count)
// returns the dot product of two arrays (x and y) containing count entries
@d. float maxF32(const float x[], uint32_t count)
// returns the maximum value in the array (x) containing count entries

.global sumF32
.global prodF64
.global dotpF64
.global maxF32

.text

sumF32:
        CMP         R1, #0        // check Counter
        BEQ         sumF32_exit   // Counter is Zero,
        VLDR.F32    S0, [R0]      // Load an F32 into S0
        ADD         R0, R0, #4    // Post Incr pointer
        SUB         R1, R1, #1    // Decr counter
sumF32_loop:
        CMP         R1, #0        // check counter
        BEQ  sumF32_exit          // if zero, exit
        VLDR.F32    S1, [R0]      // load another F32
        ADD         R0, R0, #4    // Post-incr pointer
        VADD.F32    S0, S0, S1    // Add the two F32's
        SUB         R1, R1, #1    // Decr counter
        B sumF32_loop
sumF32_exit:
        BX          LR            // Go back to C

prodF64:
        VSUB.F64    D0, D0, D0    // single instruction that zeros register
        CMP         R1, #0        // Check counter
        BEQ         prodF64_exit  // if zero then exit
        VLDR        D0, [R0]      // Load the 1st Factor
        ADD         R0, R0, #8    // Incr pointer
        SUB         R1, R1, #1    // Decr counter
prodF64_loop:
        CMP         R1, #0        // CCheck counter
        BEQ         prodF64_exit  // if zero then exit
        VLDR        D1, [R0]      // Load next Factor
        ADD         R0, R0, #8    // Incr pointer
        VMUL.F64    D0, D0, D1    // Multiply Factors
        SUB         R1, R1, #1    // Decr Counter
        B           prodF64_loop  // Loop to check for more Factors
prodF64_exit:
        BX          LR            // Exit to C

// This was the Integer version we did before
@dotpS32:
@  PUSH  {R4, R5}
@  MOV R3, R0
@  MOV R0, #0
@  CMP R2, #0
@  BEQ dotpS32_exit
@dotpS32_loop:
@  LDR R4, [R3], #4
@  LDR R5, [R1], #4
@  MLA R0, R4, R5, R0
@  SUBS R2, R2 ,#1
@  BNE dotpS32_loop
@dotpS32_exit:
@  BX LR


dotpF64:
@        MOV         R3, #0       // Load Zero into R3
@        VMOV        D0, R3, R3   // Load zeros into D0
        VSUB.F64    D0, D0, D0    // one instruction to zero D0
        CMP         R2, #0        // Check Counter
        BEQ         dotpF64_exit  // If zero then exit
dotpF64_loop:
        VLDR.F64    D1, [R0]      // Load 64-bit double from x[]
        VLDR.F64    D2, [R1]      // Load 64-bit double from y[]
        ADD         R0, #8        // Incr x pointer
        ADD         R1, #8        // incr y pointer
        VMLA.F64    D0, D1, D2    // D0 = D0 + (D1 * D2)
        SUBS        R2, R2, #1    // Decr Counter
        CMP         R2, #0        // Check Counter
        BNE         dotpF64_loop  // Not zero then get more
dotpF64_exit:
        BX          LR            // Exit to C

maxF32:
        VLDR.F32    S0, [R0]      // Load 1st 32-bit single in S0
        ADD         R0, R0, #4    // Incr pointer
        SUBS        R1, R1, #1    // Decr Counter
        BEQ         maxF32_exit   // If zero then exit
maxF32_loop:
        VLDR.F32    S1, [R0]      // Load the next Single
        VCMP.F32    S0, S1        // Compare
        VMRS    APSR_nzcv, FPSCR  // Need to copy flags to  other status register
        VMOVLT.F32  S0, S1        // If S0 < S1 then move S1 into S0
        ADD         R0, R0, #4    // Incr pointer
        SUBS        R1, R1, #1    // Decr Counter & set flags
        BNE         maxF32_loop   // If NOT zero Flag, then loop
maxF32_exit:
        BX          LR            // Exit to C