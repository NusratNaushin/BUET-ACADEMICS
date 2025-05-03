.MODEL SMALL
.STACK 100H
.DATA

.CODE
MAIN PROC
    
    MOV AX , 11
    
    CMP AX , 10 
    JNG ELSE
    
    
    MOV BX , 1
    JMP END_IF
    
    
    
    
    
    ELSE:
    
    MOV BX , 0
     
    
    END_IF:


    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
