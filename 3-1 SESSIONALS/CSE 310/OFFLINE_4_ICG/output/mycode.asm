.MODEL SMALL
.STACK 1000H
.Data
	number DB "00000$"
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2

L1:
	MOV AX, 0       ; Line 5
	PUSH AX
	POP AX
	MOV [BP-2], AX
L2:
L5:
	MOV AX, [BP-2]       ; Line 5
	PUSH AX
L6:
	MOV AX, 6       ; Line 5
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L7
	JMP L8
L7:
	MOV AX, 1
	JMP L9
L8:
	MOV AX, 0
L9:

	PUSH AX
	POP AX
	CMP AX, 0
	JE L3
	JMP L10
L4:
	MOV AX, [BP-2]       ; Line 5
	PUSH AX
	INC AX
	MOV [BP-2], AX       ; Line 5
	POP AX
	JMP L2
L10:
L11:
	MOV AX, [BP-2]       ; Line 6
	CALL print_output
	CALL new_line
	JMP L4
L3:
L12:
	MOV AX, 4       ; Line 9
	PUSH AX
	POP AX
	MOV [BP-6], AX
L13:
	MOV AX, 6       ; Line 10
	PUSH AX
	POP AX
	MOV [BP-8], AX
L14:
L16:
	MOV AX, [BP-6]       ; Line 11
	PUSH AX
L17:
	MOV AX, 0       ; Line 11
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L18
	JMP L19
L18:
	MOV AX, 1
	JMP L20
L19:
	MOV AX, 0
L20:

	PUSH AX
	POP AX
	CMP AX, 0
	JE L15
L21:
	MOV AX, [BP-8]       ; Line 12
	PUSH AX
L22:
	MOV AX, 3       ; Line 12
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV [BP-8], AX
	MOV AX, [BP-6]       ; Line 13
	PUSH AX
	DEC AX
	MOV [BP-6], AX       ; Line 13
	JMP L14
L15:
L23:
	MOV AX, [BP-8]       ; Line 16
	CALL print_output
	CALL new_line
L24:
	MOV AX, [BP-6]       ; Line 17
	CALL print_output
	CALL new_line
L25:
	MOV AX, 4       ; Line 19
	PUSH AX
	POP AX
	MOV [BP-6], AX
L26:
	MOV AX, 6       ; Line 20
	PUSH AX
	POP AX
	MOV [BP-8], AX
L27:
	MOV AX, [BP-6]       ; Line 22
	PUSH AX
	DEC AX
	MOV [BP-6], AX       ; Line 22
	POP AX
	CMP AX, 0
	JE L28
L29:
	MOV AX, [BP-8]       ; Line 23
	PUSH AX
L30:
	MOV AX, 3       ; Line 23
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV [BP-8], AX
	JMP L27
L28:
L31:
	MOV AX, [BP-8]       ; Line 26
	CALL print_output
	CALL new_line
L32:
	MOV AX, [BP-6]       ; Line 27
	CALL print_output
	CALL new_line
L33:
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
