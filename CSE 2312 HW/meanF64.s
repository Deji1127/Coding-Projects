.global meanF64

.text

// double meanF64(const double x[], uint32_t count)
// address of x[0] in R0, count in R1, return mean in D0
meanF64:
    MOV R2, #0          // R2 = 0
    VMOV D0, R2, R2     // D0 = R2:R2 = 64bits of zeros
    VMOV S4, R1         // S4 = count
    CMP R1, #0          // is R1 = count > 0
mean_loop:
    BEQ mean_div        // if count=0, exit loop
    VLDR D1, [R0]       // D1 = *R0 = *x
    ADD R0, R0, #8      // R0 += sizeof(double) or x++
    VADD.F64 D0, D0, D1 // D0 = D0 + D1
    SUBS R1, R1, #1     // decrement count
    B mean_loop         // get next integer
mean_div:
    VCVT.F64.U32 D1, S4 // D1 = count
    VDIV.F64 D0, D0, D1 // D0 = D0 / D1 
mean_end:
    BX LR
