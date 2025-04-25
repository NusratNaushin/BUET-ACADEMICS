.MODEL SMALL

.STACK 100H

.DATA

    CR EQU 0DH ; CURSER LINE ER SHURUTE NIYE JAY
    LF EQU 0AH ; NEW LINE 
    
    MSG1 DB 'ENTER A UPPER CASE LETTER : $'
    MSG2 DB CR , LF , 'IN LOWER CASE IT IS : $'
    CHAR DB ?
    

.CODE
            
MAIN PROC
    
     ;INITIALIZE DS
     MOV AX , @DATA
     MOV DS , AX 
     
     
     ;PRINT USER PROMPT
     LEA DX , MSG1
     MOV AH , 9
     INT 21H
     
              
     ;INPUT UPPER CASE CHAR CONVERT IT TO LOWER CASE
     MOV AH , 1  
     INT 21H
     ADD AL,20H ; BORO HAATER LETTER A = 65    CHOTO HAATER LETTER a = 65+32(20H) = 97 
     MOV CHAR , AL;
        
     ;DISPLAY ON THE NEXT LINE
     
     LEA DX , MSG2
     MOV AH , 9 
     INT 21H
     
     ;DISPLAY THE LOWER CASE CHARACTER
     
     MOV AH , 2
     MOV DL , CHAR
     INT 21H
     
     
     
     
     MOV AH , 4CH
     INT 21H
     
MAIN ENDP


END MAIN