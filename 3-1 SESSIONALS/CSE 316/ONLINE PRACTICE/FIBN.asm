.MODEL SMALL
.STACK 100H
.DATA
.CODE



MAIN PROC
    
    MOV AX , 3
    PUSH AX
    CALL FIB
        
    MOV DL , AL
    ADD DL ,30H
    MOV AH , 2
    INT 21H
    
    MOV AH , 4CH
    INT 21H
       

MAIN ENDP 

FIB PROC NEAR
    PUSH BP
    MOV BP , SP
    CMP WORD PTR[BP+4] , 1
    JG END_IF
    
    MOV AX , [BP+4]
    JMP RETURN


END_IF:
    MOV CX , [BP+4]
    DEC CX
    PUSH CX
    CALL FIB
    PUSH AX
    
    
    MOV CX , [BP+4]
    SUB CX , 2
    PUSH CX
    CALL FIB
    
    POP DX
    ADD AX , DX


RETURN:
    POP BP
    RET 2
    
FIB ENDP
   




END MAIN