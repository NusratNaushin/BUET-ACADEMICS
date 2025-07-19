.MODEL SMALL
.STACK 1000H
.Data
	number DB "00000$"
	a DW 1 DUP (0000H)
	b DW 1 DUP (0000H)
	c DW 1 DUP (0000H)
.CODE

func_a PROC
	PUSH BP
	MOV BP, SP
L1:
	MOV AX, 7       ; Line 4
	PUSH AX
	POP AX
	MOV a, AX
L2:
	POP BP
	RET
func_a ENDP
foo PROC
L3:
	PUSH BP
	MOV BP, SP
L4:
	MOV AX, [BP+4]       ; Line 8
	PUSH AX
L5:
	MOV AX, 3       ; Line 8
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV [BP+4], AX
L6:
	MOV AX, [BP+4]       ; Line 9
	PUSH AX
L7:
	POP AX
	POP BP
	RET 2
foo ENDP
bar PROC
L8:
	PUSH BP
	MOV BP, SP
L9:
	MOV AX, 4       ; Line 14
	PUSH AX
L10:
	MOV AX, [BP+4]       ; Line 14
	PUSH AX
	POP DX
	POP AX
	MUL DX
	PUSH AX
L11:
	MOV AX, 2       ; Line 14
	PUSH AX
L12:
	MOV AX, [BP+4]       ; Line 14
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

	MOV AX, c       ; Line 15
	PUSH AX
L13:
	POP AX
	POP BP
	RET 4
bar ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2

L14:
	MOV AX, 5       ; Line 22
	PUSH AX
	POP AX
	MOV [BP-2], AX
L15:
	MOV AX, 6       ; Line 23
	PUSH AX
	POP AX
	MOV [BP-4], AX
	CALL func_a
	PUSH AX
L16:
	MOV AX, a       ; Line 26
	CALL print_output
	CALL new_line
L17:
	MOV AX, [BP-2]       ; Line 28
	PUSH AX
	CALL foo
	PUSH AX
	POP AX
	MOV [BP-6], AX
L18:
	MOV AX, [BP-6]       ; Line 29
	CALL print_output
	CALL new_line
L19:
	MOV AX, [BP-2]       ; Line 31
	PUSH AX
L20:
	MOV AX, [BP-4]       ; Line 31
	PUSH AX
	CALL bar
	PUSH AX
	POP AX
	MOV [BP-8], AX
L21:
	MOV AX, [BP-8]       ; Line 32
	CALL print_output
	CALL new_line
L22:
	MOV AX, 6       ; Line 34
	PUSH AX
L23:
	MOV AX, [BP-2]       ; Line 34
	PUSH AX
L24:
	MOV AX, [BP-4]       ; Line 34
	PUSH AX
	CALL bar
	PUSH AX
	POP DX
	POP AX
	MUL DX
	PUSH AX
L25:
	MOV AX, 2       ; Line 34
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
L26:
	MOV AX, 3       ; Line 34
	PUSH AX
L27:
	MOV AX, [BP-2]       ; Line 34
	PUSH AX
	CALL foo
	PUSH AX
	POP DX
	POP AX
	MUL DX
	PUSH AX
	POP DX
	POP AX
	SUB AX, DX
	PUSH AX

	POP AX
	MOV [BP-4], AX
L28:
	MOV AX, [BP-4]       ; Line 35
	CALL print_output
	CALL new_line
L29:
	MOV AX, 0       ; Line 38
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
