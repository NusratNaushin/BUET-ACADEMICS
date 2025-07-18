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

L1:
	MOV AX, 3       ; Line 5
	PUSH AX
	POP AX
	MOV [BP-2], AX
L2:
	MOV AX, 8       ; Line 6
	PUSH AX
	POP AX
	MOV [BP-4], AX
L3:
	MOV AX, 6       ; Line 7
	PUSH AX
	POP AX
	MOV [BP-6], AX
L4:
	MOV AX, [BP-2]       ; Line 10
	PUSH AX
L5:
	MOV AX, 3       ; Line 10
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JE L6
	JMP L7
L6:
	MOV AX, 1
	JMP L8
L7:
	MOV AX, 0
L8:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L9
L10:
	MOV AX, [BP-4]       ; Line 11
	CALL print_output
	CALL new_line
	JMP L11
L9:
	JMP L11
L11:
L12:
	MOV AX, [BP-4]       ; Line 14
	PUSH AX
L13:
	MOV AX, 8       ; Line 14
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L14
	JMP L15
L14:
	MOV AX, 1
	JMP L16
L15:
	MOV AX, 0
L16:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L17
L18:
	MOV AX, [BP-2]       ; Line 15
	CALL print_output
	CALL new_line
	JMP L19
L17:
L20:
	MOV AX, [BP-6]       ; Line 18
	CALL print_output
	CALL new_line
L19:
L21:
	MOV AX, [BP-6]       ; Line 21
	PUSH AX
L22:
	MOV AX, 6       ; Line 21
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JNE L23
	JMP L24
L23:
	MOV AX, 1
	JMP L25
L24:
	MOV AX, 0
L25:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L26
L27:
	MOV AX, [BP-6]       ; Line 22
	CALL print_output
	CALL new_line
	JMP L28
L26:
L29:
	MOV AX, [BP-4]       ; Line 24
	PUSH AX
L30:
	MOV AX, 8       ; Line 24
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L31
	JMP L32
L31:
	MOV AX, 1
	JMP L33
L32:
	MOV AX, 0
L33:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L34
L35:
	MOV AX, [BP-4]       ; Line 25
	CALL print_output
	CALL new_line
	JMP L36
L34:
L37:
	MOV AX, [BP-2]       ; Line 27
	PUSH AX
L38:
	MOV AX, 5       ; Line 27
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L39
	JMP L40
L39:
	MOV AX, 1
	JMP L41
L40:
	MOV AX, 0
L41:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L42
L43:
	MOV AX, [BP-2]       ; Line 28
	CALL print_output
	CALL new_line
	JMP L44
L42:
L45:
	MOV AX, 0       ; Line 31
	PUSH AX
	POP AX
	MOV [BP-6], AX
L46:
	MOV AX, [BP-6]       ; Line 32
	CALL print_output
	CALL new_line
L44:
L36:
L28:
L47:
	MOV AX, 0       ; Line 36
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
