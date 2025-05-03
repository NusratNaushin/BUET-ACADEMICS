.MODEL SMALL
.STACK 100H

.DATA
    N DB 0              ; To store the value of n
    NEWLINE DB 13 , 10 , '$'

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX          ; Initialize data segment

    MOV AH, 1
    INT 21H             ; Read input (n)

    SUB AL, '0'         ; Convert ASCII to integer
    MOV N, AL           ; Store n

    MOV AL, N           ; Compute sum of first n numbers
    XOR AH, AH          ; Clear AH for 16-bit operations

    PUSH AX
    CALL SUM            ; AX will hold the result of sum(1 to n)
    
    ; Convert AX to ASCII and display
    MOV CX, 10
    MOV BX, 0           ; We will build the number in BX
STORE_DIGITS:
    XOR DX, DX
    DIV CX              ; AX / 10 ? Quotient in AX, Remainder in DX
    PUSH DX             ; Store remainder (digit)
    INC BX
    CMP AX, 0
    JNZ STORE_DIGITS

    MOV DL, 13          ; Carriage return
    MOV AH, 2
    INT 21H
    
    MOV DL, 10          ; Line feed
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
; SUM PROC: Calculates sum of first n numbers
; Input: [BP+4] = n
; Output: AX = sum(1 to n)
;----------------------------------------
SUM PROC NEAR
    PUSH BP
    MOV BP, SP

    CMP WORD PTR [BP+4], 1    ; If n == 1, sum(1) = 1
    JG RECURSE

    MOV AX, 1                 ; Base case: sum(1) = 1
    JMP DONE

RECURSE:
    MOV CX, [BP+4]            ; CX = n
    DEC CX                    ; CX = n - 1
    PUSH CX
    CALL SUM                  ; AX = sum(1 to n-1)

    MOV CX, [BP+4]            ; CX = n
    ADD AX, CX                ; AX = sum(1 to n-1) + n

DONE:
    POP BP
    RET 2                      ; Clean up 2 bytes of argument
SUM ENDP

END MAIN
