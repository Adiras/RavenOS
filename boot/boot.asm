[org 0x7c00]
KERNEL_OFFSET equ 0x1000
    mov [BOOT_DRIVE], dl
    mov bp, 0x9000
    mov sp, bp
    call load_kernel
    call switch_to_pm
    jmp $ ; Infinite loop

%include "boot/print_string.asm"
%include "boot/print_string_pm.asm"
%include "boot/disk_load.asm"
%include "boot/switch_to_pm.asm"
%include "boot/gdt.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print_string
    call print_newline
    mov bx, KERNEL_OFFSET
    mov dh, 15
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET
    jmp $

BOOT_DRIVE: db 0
MSG_PROT_MODE: db "Switched into 32-bit Protected Mode", 0
MSG_LOAD_KERNEL: db "Loading kernel into memory...", 0

times 510-($-$$) db 0
dw 0xAA55

