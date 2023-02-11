.global sumF64

.text

// double sumF64(const double x[], uint32_t count)
// address of x[0] in R0, count in R1, return sum in D0
sumF64:
    MOV R2, #0          // R2 = 0
    VMOV D0, R2, R2     // D0 = R2:R2 = 64bits of zeros
    CMP R1, #0          // is R1 = count > 0
sum_loop:
    BEQ sum_end         // if count=0, exit loop
    VLDR D1, [R0]       // D1 = *R0 = *x
    ADD R0, R0, #8      // R0 += sizeof(double) or x++
    VADD.F64 D0, D0, D1 // D0 = D0 + D1
    SUBS R1, R1, #1     // decrement count
    B sum_loop          // get next integer
sum_end:
    BX LR
