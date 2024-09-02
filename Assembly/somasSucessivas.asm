.data
	getNum: .asciiz "Insira um número: "
	getMul: .asciiz "Insira um multiplicador: "
	printResult: .asciiz "Resultado: "
	
.text
	li $v0, 4
	la $a0, getNum
	syscall
	
	li $v0, 5
	syscall
	
	# numéro está em t0
	move $t0, $v0
	
	# auxiliar está em t2
	move $t2, $v0

	li $v0, 4
	la $a0, getMul
	syscall
	
	li $v0, 5
	syscall
	
	# multiplicador está em t1
	move $t1, $v0
	
	# se algum valor fornecido for 0, vá para ImprimeZero
	beq $t0, $zero, imprimeZero
	beq $t1, $zero, imprimeZero
	
	# Somas sucessivas
	
	sub $t3, $t1, 1 # iterador 
	
	while:
		beq $t3, 0, saida
		add $t0, $t0, $t2
		sub $t3, $t3, 1
		j while
	
	saida:
		li $v0, 4
		la $a0, printResult
		syscall
		
		li $v0, 1
		la $a0, ($t0)
		syscall
	
	# encerre o programa
	li $v0, 10
	syscall
	
	imprimeZero: 
		li $v0, 4
		la $a0, printResult
		syscall
		
		li $v0, 1
		la $a0, ($zero)
		syscall
	
	
	
	
	