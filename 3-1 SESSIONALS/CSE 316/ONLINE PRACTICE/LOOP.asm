.MODEL SMALL
.STACK 100H
.DATA

.CODE
MAIN PROC
    
    MOV AH , 2
    MOV CX , 26
    MOV DL , 65
    

PRINT_LOOP:
    INT 21H
    INC DL
    DEC CX
    JNZ PRINT_LOOP
    
    
    
    
    


    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
