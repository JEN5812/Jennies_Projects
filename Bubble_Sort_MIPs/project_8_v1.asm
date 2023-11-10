             .data
           #variables
 NumberArray:       .space     40
 IntPrompt:   .asciiz   "Enter a Number 1-10: "
 NumberPrompt:      .asciiz   " Input a Number "
 Error:          .ascii    "Error Your Number is Wrong,"
 space:          .asciiz   " "
 ArrayOutput:     .asciiz   "Sorted Array: "

        .text
        j main

ErrorMessage: 
	# Message of Error
         li $v0 4
         la $a0 Error
         syscall 
 
ReadingTheCount: 
          # User Input
          # Prompting
          li $v0 4
          la $a0, IntPrompt
          syscall
          
          # Input
          li $v0 5
          syscall 
          
          # Checking the Values
	  # Branch if Less than One
          li $t1, 1
          blt $v0, $t1 ErrorMessage
          
          # Branch if Greater than Ten
          li $t1, 10
          bgt $v0, $t1 ErrorMessage
          
          # Saving the Count
          move $s1, $v0
          
         # Returning the Control back to Caller
          jr $ra 

# Read in Numbers       
ReadNums: 
        # S1 = Array Count
	# S0 = Array Pointer 
	# t1 iteration count (iterate by 1)
	# t2 address count (iterate by 4)
	# Loading in 0 
          li $t1, 0
          
	ReadingLoop:
		# iterate count
          	addi $t1, $t1, 1
     
          	# Displaying the Number Input User is At
          	li $v0 1
          	la $a0, ($t1)
          	syscall
     
          	# Display Prompt
          	li $v0 4
          	la $a0, NumberPrompt
          	syscall
     
          	# User Input
          	li $v0 5
          	syscall
     
          	# Save to Array
          	sw $v0 ($s0)
          
          	# iterate address 
          	addi $s0 $s0 4 
          	# Loop Back until Sufficient Numbers have been Read
          	blt $t1, $s1, ReadingLoop
          	
          # Return to Caller
          jr $ra
     
BSort: 
        # $s1 Array Count 
	# $t1 Array Value 1
	# $t2 Array Value 2
	# $t3 Array Index 
	# $t4 Array Address 
	# $a0 Swap Conditions (0 no swap, 1 swap)
     
     	# Initialize
          li $t3 1
          la $t4, NumberArray
     
          # Branch Loop
          beqz $a0 BExit
          li $a0 0 # <- will be set 1 should swap occur
     
          # Jump to Array Bubble (Skip arraySwap)
          j ArrayBubble
     
ArraySwap:
          # Swap, (note: Address has been prematurely incrimented)
          sw $t2, -4($t4)
          sw $t1, 0($t4)
          
     	  # Swapping Condition
          li $a0 1
 
ArrayBubble: 
          # Index Through Array for Swapping
          lw $t1, 0($t4)
          lw $t2, 4($t4)
     
          # iterlate Index & Address 
          addi $t3, $t3, 1
          addi $t4, $t4, 4
     
          # Exit Loop if Out of Bounds ( index > array count) 
          bgt $t3, $s1, BSort
     
          # Initiate the Swap so it should be Val1 > Val2
          bgt $t1, $t2, ArraySwap
          
          # Val1 is NOT Bigger than Val2, Continue to Next Index
          blt $t1, $t2, ArrayBubble
     
BExit:
	  # Return Control to Caller 
          jr $ra
     
PrintNums: 
          li $t0 1
          la $t1 NumberArray


          # Printing
          li $v0 4
          la $a0 ArrayOutput
          syscall
     
          PrintLoop:
               # Print One Array Number
               li $v0 1
               lw $a0,($t1)
               syscall
          
               # Space
               li $v0 4
               la $a0, space
               syscall
          
               # iterate
               addi $t1, $t1, 4
               addi $t0, $t0, 1
          
               # Branch Loop ( Index < arrayCount)
               ble $t0, $s1, PrintLoop
          
          # Return
          jr $ra
          

main:
          
          # S0 Array Pointer
	  # t2 Current Array Address 
	
	  # iterate count
          li $t1 0
          li $t2 0
          la $s0 NumberArray
         
          # Read in Numbers
          jal ReadingTheCount
          jal ReadNums
         
          # Bubble Sort
          li $a0 1
          jal BSort
         
          # Displaying Results
          jal PrintNums
         
          jr $ra         
          
  

