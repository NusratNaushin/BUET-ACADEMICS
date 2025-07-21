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
	MOV AX, 0       ; Line 3
	PUSH AX
	MOV [BP-4], AX
L2:
	MOV AX, 1       ; Line 4
	PUSH AX
	MOV [BP-6], AX
L3:
	MOV AX, 0       ; Line 5
	PUSH AX
	MOV [BP-8], AX
L4:
L7:
	MOV AX, [BP-8]       ; Line 5
	PUSH AX
L8:
	MOV AX, 4       ; Line 5
	PUSH AX
	POP DX
	POP AX
	CMP AX, DX
	JL L9
	JMP L10
L9:
	MOV AX, 1
	JMP L11
L10:
	MOV AX, 0
L11:

	PUSH AX
	POP AX
	CMP AX, 0
	JE L5
	JMP L12
L6:
	MOV AX, [BP-8]       ; Line 5
	PUSH AX
	INC AX
	MOV [BP-8], AX       ; Line 5
	POP AX
	JMP L4
L12:
L13:
	MOV AX, 3       ; Line 6
	PUSH AX
	MOV [BP-2], AX
L14:
	MOV AX, [BP-2]       ; Line 7
	PUSH AX
	DEC AX
	MOV [BP-2], AX       ; Line 7
	POP AX
	CMP AX, 0
	JE L15
	MOV AX, [BP-4]       ; Line 8
	PUSH AX
	INC AX
	MOV [BP-4], AX       ; Line 8
	JMP L14
L15:
	JMP L6
L5:
L16:
	MOV AX, [BP-2]       ; Line 11
	CALL print_output
	CALL new_line
L17:
	MOV AX, [BP-4]       ; Line 12
	CALL print_output
	CALL new_line
L18:
	MOV AX, [BP-6]       ; Line 13
	CALL print_output
	CALL new_line
	ADD SP, 8
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
