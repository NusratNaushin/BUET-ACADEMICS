.MODEL SMALL
.STACK 100H

.DATA
    ; No data section needed for this program  
    
N DB 0 
NEWLINE DB 13 , 10 , '$' 

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX        ; Initialize data segment
    
    MOV AH , 1
    INT 21H 
      
    
    SUB AL , '0'
    MOV N , AL
   
    MOV AL, N            ; Compute factorial of 4
    XOR AH , AH     
    
        
    PUSH AX
    CALL FACT         ; AX will hold result: fact(4) = 24
     
    
    ; Convert AX to ASCII and display
    MOV CX, 10
    MOV BX, 0         ; We'll build the number in BX
STORE_DIGITS:
    XOR DX, DX
    DIV CX            ; AX / 10 ? Quotient in AX, Remainder in DX
    PUSH DX           ; Store remainder (digit)
    INC BX
    CMP AX, 0
    JNZ STORE_DIGITS
     
    MOV DL, 13     ; Carriage return
    MOV AH, 2
    INT 21H
    
    MOV DL, 10     ; Line feed
    MOV AH, 2
    INT 21H

PRINT_DIGITS:
    POP DX
    ADD DL, '0'
    MOV AH, 2
    INT 21H
    DEC BX
    CMP BX, 0
    JNZ PRINT_DIGITS

    ; Exit program
    MOV AH, 4CH
    INT 21H
MAIN ENDP

;----------------------------------------
; FACT PROC: Calculates factorial recursively
; Input: [BP+4] = n
; Output: AX = fact(n)
;----------------------------------------
FACT PROC NEAR
    PUSH BP
    MOV BP, SP

    CMP WORD PTR [BP+4], 1
    JG RECURSE

    MOV AX, 1          ; Base case: fact(0) or fact(1) = 1
    JMP DONE

RECURSE:
    MOV CX, [BP+4]     ; CX = n
    DEC CX             ; CX = n - 1
    PUSH CX
    CALL FACT          ; AX = fact(n-1)

    MOV CX, [BP+4]     ; CX = n again
    MUL CX             ; AX = AX * n

DONE:
    POP BP
    RET 2              ; Clean up 2 bytes of argument
FACT ENDP

END MAIN
