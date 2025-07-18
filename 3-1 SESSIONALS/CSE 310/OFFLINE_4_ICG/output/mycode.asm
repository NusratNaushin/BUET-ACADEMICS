.MODEL SMALL
.STACK 1000H
.Data
	number DB "00000$"
	a DW 1 DUP (0000H)
	b DW 1 DUP (0000H)
	c DW 1 DUP (0000H)
.CODE

	MOV [BP+2], AX
foo PROC
	PUSH BP
	MOV BP, SP
L1:
	MOV AX, [BP-0]       ; Line 4
	PUSH AX
L2:
	MOV AX, 3       ; Line 4
	PUSH AX
	POP DX
	POP AX
	ADD AX, DX
	PUSH AX
	POP AX
	MOV [BP-0], AX
L3:
	MOV AX, [BP-0]       ; Line 5
	PUSH AX
L4:
	POP BP
	RET 2
foo ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2

L5:
	MOV AX, 5       ; Line 12
	PUSH AX
	POP AX
	MOV [BP-2], AX
L6:
	MOV AX, 6       ; Line 13
	PUSH AX
	POP AX
	MOV [BP-4], AX
L7:
	MOV AX, [BP-2]       ; Line 14
	PUSH AX
	CALL foo
	POP AX
	MOV [BP-6], AX
L8:
	MOV AX, [BP-6]       ; Line 15
	CALL print_output
	CALL new_line
L9:
	MOV AX, 0       ; Line 16
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
