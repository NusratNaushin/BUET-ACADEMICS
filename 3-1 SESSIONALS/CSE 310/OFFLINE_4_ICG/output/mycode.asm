.MODEL SMALL
.STACK 1000H
.Data
	number DB "00000$"
foo PROC
L1:
	PUSH BP
	MOV BP, SP
L2:
	MOV AX, [BP+6]       ; Line 2
	PUSH AX
L3:
	MOV AX, [BP+4]       ; Line 2
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
L4:
	MOV AX, 5       ; Line 2
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JLE L5
	JMP L6
L5:
	MOV AX, 1
	JMP L7
L6:
	MOV AX, 0
L7:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L8
L9:
	MOV AX, 7       ; Line 3
	PUSH AX
	POP AX
	MOV SP, BP
	POP BP
	RET 4
	JMP L10
L8:
	JMP L10
L10:
L11:
	MOV AX, [BP+6]       ; Line 5
	PUSH AX
L12:
	MOV AX, 2       ; Line 5
	PUSH AX
	POP DX
	POP AX
	SUB AX, DX
	PUSH AX

L13:
	MOV AX, [BP+4]       ; Line 5
	PUSH AX
L14:
	MOV AX, 1       ; Line 5
	PUSH AX
	POP DX
	POP AX
	SUB AX, DX
	PUSH AX

	CALL foo
	PUSH AX
L15:
	MOV AX, 2       ; Line 5
	PUSH AX
L16:
	MOV AX, [BP+6]       ; Line 5
	PUSH AX
L17:
	MOV AX, 1       ; Line 5
	PUSH AX
	POP DX
	POP AX
	SUB AX, DX
	PUSH AX

L18:
	MOV AX, [BP+4]       ; Line 5
	PUSH AX
L19:
	MOV AX, 2       ; Line 5
	PUSH AX
	POP DX
	POP AX
	SUB AX, DX
	PUSH AX

	CALL foo
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
	MOV SP, BP
	POP BP
	RET 4
foo ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2

L20:
	MOV AX, 7       ; Line 11
	PUSH AX
	MOV [BP-2], AX
L21:
	MOV AX, 3       ; Line 12
	PUSH AX
	MOV [BP-4], AX
L22:
	MOV AX, [BP-2]       ; Line 14
	PUSH AX
L23:
	MOV AX, [BP-4]       ; Line 14
	PUSH AX
	CALL foo
	PUSH AX
	MOV [BP-6], AX
L24:
	MOV AX, [BP-6]       ; Line 15
	CALL print_output
	CALL new_line
L25:
	MOV AX, 0       ; Line 17
	PUSH AX
	ADD SP, 6
	POP BP
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
