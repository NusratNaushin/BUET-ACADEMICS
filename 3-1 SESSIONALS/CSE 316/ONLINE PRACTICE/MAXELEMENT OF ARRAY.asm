.MODEL SMALL
.STACK 100H
.DATA   

ARR DB 4 , 3 , 2 ,1
LEN DB 4
.CODE
MAIN PROC

    MOV AX , @DATA
    MOV DS , AX
    
    XOR SI , SI
    MOV AL , ARR[SI]
    MOV BL , AL 
    INC SI
    MOV CL , LEN
    DEC CL
    
FIND_MAX: 
      
    MOV AL , ARR[SI]
    CMP AL , BL 
    JA NEW_MAX 
    JMP NEXT
    
    
    
NEW_MAX:
    MOV BL , AL
    JMP NEXT

NEXT:
    INC SI
    DEC CL
    JNZ FIND_MAX
    
PRINT:
    
    MOV DL , BL
    ADD DL , '0'
    MOV AH ,2
    INT 21H
   

    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
