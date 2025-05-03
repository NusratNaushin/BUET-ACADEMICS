.MODEL SMALL
.STACK 100H
.DATA
 
MSG1 DB "UPPER CASE$" 
MSG2 DB "LOWER CASE$"
MSG3 DB "NUMBER$"
MSG4 DB "NOT AN ALPHANUM$"
.CODE
MAIN PROC  
    
    MOV AX , @DATA
    MOV DS , AX
    
    MOV AH ,1
    INT 21H
    
    
    CMP AL , '0'
    JL CHECK_ALPHA
    
    CMP AL , '9'
    JLE NUMBER   



CHECK_ALPHA: 

    CMP AL , 'A'
    JL NOT_ALPHA_NUM    
    CMP AL , 'Z'
    JLE  UPPER_CHARACTER 
    
    
    CMP AL , 'a'
    JL NOT_ALPHA_NUM    
    CMP AL , 'z'
    JLE LOWER_CHARACTER   
    
    
    JMP NOT_ALPHA_NUM
    
    
     
    
    
    LOWER_CHARACTER:
    
    LEA DX , MSG2
    
    MOV AH , 9 
    INT 21H
    JMP EXIT   
    
    
    UPPER_CHARACTER:
    
    LEA DX , MSG1
    
    MOV AH , 9 
    INT 21H 
    JMP EXIT 
    
    
    NUMBER:
    
    LEA DX , MSG3
    
    MOV AH , 9 
    INT 21H 
    JMP EXIT 
    
    
    NOT_ALPHA_NUM:
    
    LEA DX , MSG4
    
    MOV AH ,9
    INT 21H
    JMP EXIT
    
    
    
    
    
    
    
    
    


EXIT:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
