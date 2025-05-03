.MODEL SMALL
.STACK 100H

.DATA
    ; Example Case 1
    ; ARR DB 1, 3, 10, 12, 4, 6, 2, 9, 7, 11

    ; Example Case 2
    ARR DB 3 ,1 , 2

    LEN DB 3

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Initialize pointers and values
    XOR SI, SI                  ; index = 0
    MOV AL, ARR[SI]             ; AL = first element
    MOV BL, AL                  ; BL = max
    MOV BH, 00                  ; BH = second max

    INC SI                      ; Move to second element
    MOV CL, LEN
    DEC CL                      ; Already processed one element

FIND_LOOP:
    MOV AL, ARR[SI]
    
    CMP AL, BL
    JA  NEW_MAX                 ; If AL > max, update second_max and max
    CMP AL, BH
    JA  NEW_SECOND              ; If AL > second_max (but < max), update second

    JMP NEXT

NEW_MAX:
    MOV BH, BL                  ; second_max = max
    MOV BL, AL                  ; max = current element
    JMP NEXT

NEW_SECOND:
    CMP AL, BL
    JE NEXT                     ; Don't overwrite second_max with max
    MOV BH, AL                  ; second_max = current element

NEXT:
    INC SI
    DEC CL
    JNZ FIND_LOOP

    ; Now BH = second highest number
    ; Convert BH to ASCII and print
    MOV DL, BH
    ADD DL, 30H                 ; Convert to ASCII for 0–9
    CMP DL, '9'
    JBE PRINT_CHAR              ; If <= '9', print directly

    ; If > '9', convert to A–F (for values 10–15)
    ADD DL, 7                   ; Because 'A' = 41H and 10+30H=3AH ? 3AH + 7 = 41H = 'A'

PRINT_CHAR:
    MOV AH, 02H
    INT 21H

    ; Exit
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
