main:
  pushl %ebp
  movl %esp,%ebp
  //initializing a, b ,c (3 integers)
  subl $12,%esp
  pushl %ebx
  pushl %esi
  movl $13,-4(%ebp) //a = 13
  movl $5,-8(%ebp) // b = 5
  movl -4(%ebp),%eax // 13 is stored in eax
  cltd //converts 13 to double
  idivl -8(%ebp) // eax = 13/5 edx = 13%5
  movl %edx,%esi // esi = 13%5
  movl %eax,%ebx // ebx = 13/5
  movl -8(%ebp),%ebx // ebx = 5
  subl %esi,%ebx // 13%5 - 5
  movl -4(%ebp),%eax // eax =13
  imull %ebx,%eax //eax =  5 * 13
  movl %eax,-12(%ebp) // c = 65
  leal -20(%ebp),%esp
  popl %esi
  popl %ebx
  leave
  ret
