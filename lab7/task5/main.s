password:
  .byte 0x73,0x65,0x63,0x72,0x65,0x74,0x0
.LC0:
  .byte 0x70,0x6c,0x65,0x61,0x73,0x65,0x20,0x65,0x6e,0x74
  .byte 0x65,0x72,0x20,0x79,0x6f,0x75,0x72,0x20,0x70,0x61
  .byte 0x73,0x73,0x77,0x6f,0x72,0x64,0xa,0x0
.LC1:
  .byte 0x25,0x73,0x0
main:
  pushl %ebp
  movl %esp,%ebp
  subl $12,%esp   //char input[12];
  pushl %ebx 
  pushl $.LC0
  call printf   //prints .LC0
  leal -8(%ebp),%eax
  pushl %eax
  pushl $.LC1
  call scanf  //scanf("%s", into .LC1)
  movl $0,-12(%ebp)   //!!set value at bottom as 0
  leal 12(%esp),%esp //take value at top and put at bottom
.L2:
  cmpl $7,-12(%ebp)   //if(8 > bottom of stack) (checks if password is long enough)
  jg .L3              //jump to l3 (see if they match)
  movl %ebp,%eax      //move top of stack into eax
  addl -12(%ebp),%eax // add bottom of stack into eax
  leal -8(%eax),%eax
  cmpb $64,(%eax)   //if 64<=value @eax (checks if password is too long)
  jle .L5           //jump to l5
  movl %ebp,%eax
  addl -12(%ebp),%eax
  leal -8(%eax),%eax
  cmpb $90,(%eax)   //if( 90 > value@eax)
  jg .L5            //jump to l5
  movl %ebp,%eax
  addl -12(%ebp),%eax
  leal -8(%eax),%eax
  movl %ebp,%edx
  addl -12(%ebp),%edx
  leal -8(%edx),%edx
  movb (%edx),%cl
  addb $32,%cl
  movb %cl,(%eax)
.L5:
  incl -12(%ebp)  //increments
  jmp .L2         //return to l2
.L3:
  pushl $password
  leal -8(%ebp),%eax
  pushl %eax
  call strcmp //compares password and input
  movl %eax,%ebx
  leal 8(%esp),%esp
  cmpl $0,%ebx
  jne .L6
  xorl %eax,%eax
  jmp .L1
  jmp .L7
.L6:
  movl $-1,%eax   //sets eax to -1
  jmp .L1         //jumps to L1
.L7:
.L1:
  leal -16(%ebp),%esp   //returns
  popl %ebx
  leave
  ret
