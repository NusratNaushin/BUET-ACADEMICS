NEW_LINE MACRO
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
ENDM  

.MODEL SMALL
.STACK 100H
.DATA 
MSG DB "HELLO WORLD $" 
msg2 db "ASSEMBLY LANGUAGE $"
.CODE

MAIN PROC
    MOV AX,@DATA   ;DATA SEGMENT KISU NISI ETA CODE RE JANAILAM
    MOV DS,AX
       
       
    LEA DX,MSG
    MOV AH,9
    INT 21H 
    
    NEW_LINE 
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    
    
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN