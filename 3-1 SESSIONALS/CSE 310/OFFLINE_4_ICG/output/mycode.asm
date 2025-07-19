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

L1:
	MOV AX, [BP-2]       ; Line 3
	PUSH AX
L2:
	MOV AX, 0       ; Line 3
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L3
	JMP L4
L3:
	MOV AX, 1
	JMP L5
L4:
	MOV AX, 0
L5:

	PUSH AX
L6:
	MOV AX, [BP-2]       ; Line 3
	PUSH AX
L7:
	MOV AX, 10       ; Line 3
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L8
	JMP L9
L8:
	MOV AX, 1
	JMP L10
L9:
	MOV AX, 0
L10:

	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JNE L11
	CMP DX, 0
	JNE L11
	MOV AX, 0
	JMP L12
L11:
	MOV AX, 1
L12:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L13
L14:
	MOV AX, 100       ; Line 4
	PUSH AX
	MOV [BP-2], AX
	JMP L15
L13:
L16:
	MOV AX, 200       ; Line 6
	PUSH AX
	MOV [BP-2], AX
L15:
L17:
	MOV AX, [BP-2]       ; Line 8
	PUSH AX
L18:
	MOV AX, 20       ; Line 8
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L19
	JMP L20
L19:
	MOV AX, 1
	JMP L21
L20:
	MOV AX, 0
L21:

	PUSH AX
L22:
	MOV AX, [BP-2]       ; Line 8
	PUSH AX
L23:
	MOV AX, 30       ; Line 8
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L24
	JMP L25
L24:
	MOV AX, 1
	JMP L26
L25:
	MOV AX, 0
L26:

	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JE L27
	CMP DX, 0
	JE L27
	MOV AX, 1
	JMP L28
L27:
	MOV AX, 0
L28:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L29
L30:
	MOV AX, 300       ; Line 9
	PUSH AX
	MOV [BP-2], AX
	JMP L31
L29:
L32:
	MOV AX, 400       ; Line 11
	PUSH AX
	MOV [BP-2], AX
L31:
L33:
	MOV AX, [BP-2]       ; Line 13
	PUSH AX
L34:
	MOV AX, 40       ; Line 13
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L35
	JMP L36
L35:
	MOV AX, 1
	JMP L37
L36:
	MOV AX, 0
L37:

	PUSH AX
L38:
	MOV AX, [BP-2]       ; Line 13
	PUSH AX
L39:
	MOV AX, 50       ; Line 13
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L40
	JMP L41
L40:
	MOV AX, 1
	JMP L42
L41:
	MOV AX, 0
L42:

	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JE L43
	CMP DX, 0
	JE L43
	MOV AX, 1
	JMP L44
L43:
	MOV AX, 0
L44:

	PUSH AX
L45:
	MOV AX, [BP-2]       ; Line 13
	PUSH AX
L46:
	MOV AX, 60       ; Line 13
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L47
	JMP L48
L47:
	MOV AX, 1
	JMP L49
L48:
	MOV AX, 0
L49:

	PUSH AX
L50:
	MOV AX, [BP-2]       ; Line 13
	PUSH AX
L51:
	MOV AX, 70       ; Line 13
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JG L52
	JMP L53
L52:
	MOV AX, 1
	JMP L54
L53:
	MOV AX, 0
L54:

	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JE L55
	CMP DX, 0
	JE L55
	MOV AX, 1
	JMP L56
L55:
	MOV AX, 0
L56:

	PUSH AX
	POP DX
	POP AX
	CMP AX, 0
	JNE L57
	CMP DX, 0
	JNE L57
	MOV AX, 0
	JMP L58
L57:
	MOV AX, 1
L58:

	PUSH AX
	POP AX

	CMP AX, 0

	JE L59
L60:
	MOV AX, 500       ; Line 14
	PUSH AX
	MOV [BP-2], AX
	JMP L61
L59:
L62:
	MOV AX, 600       ; Line 16
	PUSH AX
	MOV [BP-2], AX
L61:
L63:
	MOV AX, [BP-2]       ; Line 17
	CALL print_output
	CALL new_line
L64:
	MOV AX, 0       ; Line 19
	PUSH AX
	ADD SP, 2
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
