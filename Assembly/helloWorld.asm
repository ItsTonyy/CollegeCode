.data
	#área para dados na memória principal
	
	#mensagem a ser exibida para o usuário
	msg: .asciiz "Hello, World!"

.text
	#área para instruções do programa
	
	#instrução para impressão de string
	li $v0, 4
	
	#indicar o endereço em que está a mensagem
	la $a0, msg
	
	#imprima o valor de a0
	syscall 