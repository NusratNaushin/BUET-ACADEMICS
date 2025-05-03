.model small
.stack 100h
.data
    prompt db 'Enter n (1-9): $'
    result db 'Fibonacci number: $'
    newline db 0Dh, 0Ah, '$'
    n db ?
    num dw ?

.code
main proc
    mov ax, @data
    mov ds, ax

    ; Display prompt
    mov ah, 09h
    lea dx, prompt
    int 21h

    ; Read input character
    mov ah, 01h
    int 21h
    sub al, '0'       ; Convert ASCII to number
    mov n, al

    ; Print newline
    mov ah, 09h
    lea dx, newline
    int 21h

    ; Calculate Fibonacci number
    xor bx, bx    ; Clear BX (set to 0)
    mov bl, n     ; Move the 8-bit value of n into BL
    call fib          ; Call recursive Fibonacci function
    mov num, ax       ; Store result

    ; Display result message
    mov ah, 09h
    lea dx, result
    int 21h

    ; Convert number to ASCII and print
    mov ax, num
    call print_number

    ; Print newline
    mov ah, 09h
    lea dx, newline
    int 21h

    ; Exit program
    mov ah, 4Ch
    int 21h
main endp

; Recursive Fibonacci function
; Input: BX = n
; Output: AX = F(n)
fib proc
    push bx           ; Save BX
    cmp bx, 2         ; Check if n <= 2
    jle base_case     ; If n <= 2, return 1

    ; Calculate F(n-1)
    dec bx
    call fib
    push ax           ; Save F(n-1)

    ; Calculate F(n-2)
    dec bx
    call fib
    pop bx            ; Restore F(n-1) to BX
    add ax, bx        ; F(n) = F(n-1) + F(n-2)
    jmp fib_end

base_case:
    mov ax, 1         ; F(1) = F(2) = 1

fib_end:
    pop bx            ; Restore BX
    ret
fib endp

; Procedure to print number in AX
print_number proc
    push ax
    push bx
    push cx
    push dx

    mov bx, 10        ; Base 10
    mov cx, 0         ; Digit counter

convert_loop:
    mov dx, 0
    div bx            ; AX = quotient, DX = remainder
    push dx           ; Save remainder (digit)
    inc cx
    cmp ax, 0
    jne convert_loop

print_loop:
    pop dx
    add dl, '0'       ; Convert to ASCII
    mov ah, 02h
    int 21h
    loop print_loop

    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_number endp

end main