#include <efi.h>

EFIAPI
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->OutputString(
            SystemTable->ConOut,
            L"Hello, world!");

    while (1) __asm__ ("cli; hlt");
}

