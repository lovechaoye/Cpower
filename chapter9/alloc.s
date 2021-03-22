# 目的：用于管理内存使用的程序-
#			分配和释放内存
#
# 注意：使用这些例程的程序将要求一定大小的内存。在实际操作
#		中，我们使用的内存更大，但在回传指针前将之放在开始处。
#		我们增加一个大小字段，以及一个AVAILABLE/UNAVAILABLE标记。
#		因此内存看起来如下所示
#
##################################################################
#AVAILABLE标记#内存大小#实际内存位置#
#################################################################
#									^--返回指针指向此处
#		为了方便调用程序，返回的指针仅仅指向所请求的实际内存位置
#		这样也让我们无需更改调用程序即可更改结构

.section .data
#########全局变量###########

# 此处指向我们管理的内存的起始处
heap_begin:
	.long 0

# 此处指向我们管理的内存之后的一个内存位置
current_break:
	.long 0

#####结构信息######
# 内存区头空间大小
.equ HEADER_SIZE,8
# 头中AVAILABLE标志的位置
.equ HDR_AVAIL_OFFSET,0
# 内存区头中大小字段的位置
.equ HDR_SIZE_OFFSET,4

###############常量###################
.equ UNAVAILABLE,0	# 这是用于标记已分配空间的数字
.equ AVAILABLE,1	# 这是用于标记已回收空间的数字，此类空间可用于再分配
.equ SYS_BRK,45		# 用于中断系统调用的系统调用号

.equ LINUX_SYSCALL, 0x80 # 使系统调用号更易读

.section .text

###############函数#############################

##allocate_init##
# 目的：调用此函数来初始化函数（更具体地说，此函数设置
#		heap_begin和current_break）。此函数无函数和返回值
.globl allocate_init
.type allocate_init,@function
allocate_init:
	pushl %ebp		# 函数标准处理
	movl %esp, %ebp

	# 如果发起brk系统调用时，%ebx内容为0，该调用将返回最后一个有效可用地址
	movl $SYS_BRK, %eax		# 确定中断点
	movl $0, %ebx
	int $LINUX_SYSCALL

	incl %eax				# %eax现为最后有效可用地址，
							# 我们需要此地址之后的内存的位置
	
	movl %eax,  current_break 	# 保存当前中断

	movl %eax, heap_begin	# 将当前中断保存为我们的首地址。这会使
							# 分配函数在其首次运行时从Linux获取更多内存
	movl %ebp, %esp			# 退出函数
	pop %ebp
	ret
	#####函数结束######

	##allocate##
	# 目的：此函数用于获取一段内存。它查看是否存在自由内存块，
	#		如不存在，则向Linux请求
	#
	# 参数：此函数有一个参数，就是我们要求的内存块大小
	#
	# 返回值：
	#		此函数将所分配内存的地址返回到%eax中。如果已无可用内存，
	#		就返回0到%eax
	#
	######处理#######
	# 用到的变量：
	#
	# %ecx - 保存所请求内存的大小（这是第一个也是唯一的参数）
	# %eax - 检测的当前内存区
	# %ebx - 当前中断位置
	# %edx - 当前内存区大小
	#
	# 我们检测每个以heap_begin开始的内存区，查看每一个的大小以及是否已经分配
	# 如果某个内存区大于等于所请求的大小，且可用，该函数就获取此内存区
	# 如果无法找到足够大的内存区，就向Linux请求更多内存，这种情况下
	# 此函数会向前移动current_break
	.globl allocate
	.type allocate,@function
	.equ ST_MEM_SIZE, 8		# 用于分配内存大小的栈位置
 allocate:
 	pushl %ebx				# 标准函数处理
	movl %esp, %ebp

	movl ST_MEM_SIZE(%ebp), %ecx	# %ecx将保存我们需要的大小
									# （第一个也是唯一的参数）
	movl heap_begin, %eax			# %eax将保持当前搜索位置

	movl current_break, %ebx		# %ebx将保存当前中断
 
 alloc_loop_begin:					# 此处开始循环搜索每个内存区
  
    cmpl %ebx, %eax					# 如果两者相等，就表明需要更多内存
	je move_break

	# 获取此内存区的大小
	movl HDR_SIZE_OFFSET(%eax), %edx
	# 如无可用空间，则继续搜索下一块内存区
	cmpl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax)
	je next_location

	cmpl %edx, %ecx		# 如果内存区可用，就将之与所需大小进行比较
	jle allocate_here	# 如果足够大，就跳转至allocate_here
 
 next_location:
 	addl $HEADER_SIZE, %eax	# 内存区总大小为所需大小（当前%edx中存储的值）
	addl %edx, %eax			# + 内存头8字节
							# ( AVAILABLE/UNAVAILABLE标志4字节 + 内存区大小4字节)
							# 因此将%edx与$8相加，结果存于%eax中,
							# 即可获得下一个可用内存区
	jmp alloc_loop_begin	# 查看下一个位置

 allocate_here:				# 如果执行此处代码，说明要分配的内存区头在%eax中

  # 将空间标识为不可用
   movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax)
   addl $HEADER_SIZE, %eax				# 将可用内存区头的下一个位置移入%eax
   										# (因为这是我们要返回的内容)

   movl %ebp, %esp						# 从函数中返回
   popl %ebp
   ret

 
 move_break:							# 如果执行到这里，说明已经耗尽所有可寻址内存，
 										# 需要请求更多内存
										# %ebx将保存当前数据结束处位置，%ecx保存数据大小

										# 需要增加%ebx的值，使之为我们想要内存结束的地方
  addl $HEADER_SIZE, %ebx				# 因此需要将中断与所请求数据的大小相加
  addl %ecx, %ebx						# 然后将中断与所请求数据的大小相加

  			
										# 接着就要向Linux要求更多内存

  pushl %eax							# 保存所需寄存器
  pushl %ecx
  pushl %ebx

  movl $SYS_BRK, %eax					# 重置中断（%ebx含所请求的中断点）
  int $LINUX_SYSCALL
  										# 在正常情况下，应返回新中断到%eax中，
							# 如果失败，返回值为0，否则新中断应
							# 大于等于我们请求的内存。在本程序中，
							# 我们并不关心实际中断设置在何处，
							# 只要%eax内容不为0，我们并不关心其实际值

  cmpl $0, %eax							# 检测错误情况
  je error

  popl %ebx
  popl %ecx
  popl %eax

  # 设置该内存为不可用，因为我们将分配该内存
  movl $UNAVAILABLE, HDR_AVAIL_OFFSET(%eax)
  # 设置该内存的大小
  movl %ecx, HDR_SIZE_OFFSET(%eax)

  # 将%eax移至可用内存的实际起始处。%eax现保存着返回值
  addl $HEADER_SIZE, %eax

  movl %ebx, current_break		# 保存新中断

  movl %ebp, %esp				# 从该函数返回
  popl %ebp
  ret

 error:
  movl $0, %eax					# 如果出错，就返回0
  movl %ebp, %esp
  popl %ebp
  ret
 ######函数结束#########

 ##deallocate##
 # 目的：
 #		此函数的目的是使用内存区域后将之返回到内存池中
 #
 # 参数：
 #		唯一的参数是我们要返回到内存池的内存的位置
 #
 # 返回值：
 #		无返回值
 #
 # 具体处理：
 #		你是否还记得，我们实际上将可用内存起始位置传递给程序，
 #		该起始位置就是内存区时间起始处加上8个存储位置
 #		我们只需倒退8个存储位置，然后标识此内存区为可用
 #		即可，这样分配函数就知道可以使用此内存区了

  .globl deallocate
  .type deallocate,@function

  # 要释放的内存区域栈位置
  .equ ST_MEMORY_SEG, 4
 
 deallocate:
  # 因为此函数很简单，我们无需再用
  # 专门函数获取要释放的内存地址(通常该地址为8(%ebp)),
  # 但由于我们并未将%ebp入栈或将%esp内容移至%ebp，
  # 此处使用4(%ebp)
	movl ST_MEMORY_SEG(%esp), %eax


  # 获得指向内存实际起始处的指针
  	subl $HEADER_SIZE, %eax

  # 标识该内存区为可用
 	movl $AVAILABLE, HDR_SIZE_OFFSET(%eax)

  # 返回
    ret
#########函数结束###############
