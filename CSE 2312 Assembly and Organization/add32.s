.global add32

.text

// uint32_t add32(uint32_t x, uint32_t y)
// x in R0, y in R1, return result in R0
add32:
   ADD R0, R0, R1 // R0 <- R0 + R1
   BX LR // returns... more on this later



