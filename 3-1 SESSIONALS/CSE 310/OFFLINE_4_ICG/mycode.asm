.MODEL SMALL
.STACK 1000H
.Data
number DB "00000$"
i DW 1 DUP (0000H)
j DW 1 DUP (0000H)

.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L1:
	MOV AX, 1       ; Line 6
	MOV i, AX
	PUSH AX
	POP AX
L2:
	MOV AX, 5+8       ; Line 9
	MOV j, AX
	PUSH AX
	POP AX
L3:
	MOV AX, i+2*j       ; Line 12
	MOV k, AX
	PUSH AX
	POP AX
L4:
	MOV AX, k%9       ; Line 15
	MOV m, AX
	PUSH AX
	POP AX
L5:
	MOV AX, m<=ll       ; Line 18
	MOV n, AX
	PUSH AX
	POP AX
L6:
	MOV AX, i!=j       ; Line 21
	MOV o, AX
	PUSH AX
	POP AX
L7:
	MOV AX, n||o       ; Line 24
	MOV p, AX
	PUSH AX
	POP AX
L8:
	MOV AX, n&&o       ; Line 27
	MOV p, AX
	PUSH AX
	POP AX
L9:
	MOV AX, -p       ; Line 33
	MOV k, AX
	PUSH AX
	POP AX

