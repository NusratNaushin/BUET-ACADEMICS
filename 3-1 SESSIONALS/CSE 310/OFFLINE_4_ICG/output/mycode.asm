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
	PUSH AX
	POP AX
	MOV i, AX
L2:
	MOV AX, i       ; Line 7
	CALL print_output
	CALL new_line
L3:
	MOV AX, 5       ; Line 9
	PUSH AX
L4:
	MOV AX, 8       ; Line 9
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV j, AX
L5:
	MOV AX, j       ; Line 10
	CALL print_output
	CALL new_line
	MOV AX, i       ; Line 12
	PUSH AX
L6:
	MOV AX, 2       ; Line 12
	PUSH AX
	MOV AX, j       ; Line 12
	PUSH AX
	POP DX
	POP AX
	MUL DX
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV [BP-2], AX
L7:
	MOV AX, [BP-2]       ; Line 13
	CALL print_output
	CALL new_line
L8:
	MOV AX, [BP-2]       ; Line 15
	PUSH AX
L9:
	MOV AX, 9       ; Line 15
	PUSH AX
	POP CX
	POP AX
	CWD
	DIV CX
	PUSH DX
	POP AX
	MOV [BP-6], AX
L10:
	MOV AX, [BP-6]       ; Line 16
	CALL print_output
	CALL new_line
L11:
	MOV AX, [BP-6]       ; Line 18
	PUSH AX
L12:
	MOV AX, [BP-4]       ; Line 18
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JLE L13
	JMP L14
L13:
	MOV AX, 1
	JMP L15
L14:
	MOV AX, 0
L15:

	PUSH AX
	POP AX
	MOV [BP-8], AX
L16:
	MOV AX, [BP-8]       ; Line 19
	CALL print_output
	CALL new_line
	MOV AX, i       ; Line 21
	PUSH AX
	MOV AX, j       ; Line 21
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JNE L17
	JMP L18
L17:
	MOV AX, 1
	JMP L19
L18:
	MOV AX, 0
L19:

	PUSH AX
	POP AX
	MOV [BP-10], AX
L20:
	MOV AX, [BP-10]       ; Line 22
	CALL print_output
	CALL new_line
L21:
	MOV AX, [BP-8]       ; Line 24
	PUSH AX
L22:
	MOV AX, [BP-10]       ; Line 24
	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JE L23
	CMP DX, 0
	JE L23
	MOV AX, 1
	JMP L24
L23:
	MOV AX, 0
L24:

	PUSH AX
	POP AX
	MOV [BP-12], AX
L25:
	MOV AX, [BP-12]       ; Line 25
	CALL print_output
	CALL new_line
	MOV AX, [BP-12]       ; Line 27
	PUSH AX
	INC AX
L26:
	MOV AX, [BP-12]       ; Line 28
	CALL print_output
	CALL new_line
L27:
	MOV AX, 0       ; Line 30
	PUSH AX
	MOV AX, 4CH
	INT 21H
main ENDP
new_line proc
      push ax
      push dx
      mov ah,2
      mov dl,0Dh
      int 21h
      mov ah,2
      mov dl,0Ah
      int 21h
      pop dx
      pop ax
      ret
      new_line endp
  print_output proc  ;print what is in ax
      push ax
      push bx
      push cx
      push dx
      push si
      lea si,number
      mov bx,10
      add si,4
      cmp ax,0
      jnge negate
      print:
      xor dx,dx
      div bx
      mov [si],dl
      add [si],'0'
      dec si
      cmp ax,0
      jne print
      inc si
      lea dx,si
      mov ah,9
      int 21h
      pop si
      pop dx
      pop cx
      pop bx
      pop ax
      ret
      negate:
      push ax
      mov ah,2
      mov dl,'-'
      int 21h
      pop ax
      neg ax
      jmp print
      print_output endp
END main
