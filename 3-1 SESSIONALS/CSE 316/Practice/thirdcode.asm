.MODEL SMALL
.STACK 100H
.CODE

MAIN PROC
    
    MOV AH,1 ; INPUT NIRDESH KORE   
    INT 21H
    
    MOV BL,AL
    INT 21H
    
    MOV BH,AL
    INT 21H
    
    MOV CL,AL
    INT 21H
    
    MOV CH,AL
    
    MOV AH,2   ;EI KOITA LINE
    MOV DL,0DH ;JUST LINE BREAK
    INT 21H    ;KORAR JONNE USE KORA HOCCHE
    MOV DL,0AH ;
    INT 21H    ;
    
    MOV AH,2  ;OUTPUT NIRDESH KORE ETA NA LIKHLEO CHOLTO AS UPORE EKBAR LIKHA HOISE
    INT 21H ; EI LINE TA NA LIKHLEO CHOLTO KARON EKHON DL SET HOY NI TAI INTERRUPT ER DORKAR NEI 
    
       
    MOV DL,BL 
    INT 21H  
    
    MOV DL,BH 
    INT 21H
    
    MOV DL,CL
    INT 21H
    
    MOV DL,CH
    INT 21H
    
    
    
    
    
    
    
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN