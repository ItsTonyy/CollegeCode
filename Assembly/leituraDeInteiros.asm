.data
	saudacao: .asciiz "Olá. Por favor, forneça sua idade: "
	saida: .asciiz "Sua idade é: "
	
.text
	# Imprimir uma string
	li $v0, 4 
	la $a0, saudacao
	syscall
	
	li $v0, 5
	syscall
	
	# valor fornecido está em t0
	move $t0, $v0
	
	li $v0, 4 
	la $a0, saida
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall