main:
  pushl %ebp
  movl %esp,%ebp
  subl $12,%esp //grows stack by 12 bytes
  movl $13,-4(%ebp) //stores 13 in a
  movl $5,-8(%ebp) // stores 5 in b
  movl $0,-12(%ebp) //stores 0 in c
  cmpl $6,-4(%ebp) //  if(a>6)
  jle .L2
  movl $15,-8(%ebp) // stores 15 in b
.L2:
.L3:
  cmpl $14,-12(%ebp) // if 4< c
  jg .L4
  movl -12(%ebp),%eax
  addl %eax,-4(%ebp)
  incl -12(%ebp)
  jmp .L3
.L4:
  leave
  ret
