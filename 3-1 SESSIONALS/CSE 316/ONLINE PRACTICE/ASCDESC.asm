.MODEL SMALL
.STACK 100H
.DATA

ARR DW 60 , 50, 40, 40, 30, 20, 15, 1, 0                                  
; You can change this array to test other cases

MSG1 DB 'Ascending$'
MSG2 DB 'Descending$'
MSG3 DB 'Not Sorted$'

.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    LEA SI, ARR         ; SI points to the start of array

    MOV CX, 9          ; 17 elements in array
    DEC CX              ; For comparison, need (n-1) = 16 comparisons

    MOV AX, [SI]
    ADD SI, 2
    MOV BX, [SI]

    CMP AX, BX
    JL CHECK_ASCENDING
    JG CHECK_DESCENDING
    ; If equal, assume ascending check first
    JMP CHECK_ASCENDING

;----------------------------------------

CHECK_ASCENDING:
    LEA SI, ARR
    MOV CX, 9
    DEC CX              ; 16 comparisons

ASC_LOOP:
    MOV AX, [SI]
    ADD SI, 2
    MOV BX, [SI]
    CMP AX, BX
    JG DISPLAY_NOT_SORTED   ; If AX > BX, not ascending
    LOOP ASC_LOOP
    JMP DISPLAY_ASCENDING

;----------------------------------------

CHECK_DESCENDING:
    LEA SI, ARR
    MOV CX, 9
    DEC CX              ; 16 comparisons

DESC_LOOP:
    MOV AX, [SI]
    ADD SI, 2
    MOV BX, [SI]
    CMP AX, BX
    JL DISPLAY_NOT_SORTED   ; If AX < BX, not descending
    LOOP DESC_LOOP
    JMP DISPLAY_DESCENDING

;----------------------------------------

DISPLAY_ASCENDING:
    LEA DX, MSG1
    MOV AH, 9
    INT 21H
    JMP EXIT

DISPLAY_DESCENDING:
    LEA DX, MSG2
    MOV AH, 9
    INT 21H
    JMP EXIT

DISPLAY_NOT_SORTED:
    LEA DX, MSG3
    MOV AH, 9
    INT 21H
    JMP EXIT

;----------------------------------------

EXIT:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
