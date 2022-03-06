CC := clang
LD := clang
RM := rm -f

CFLAGS := --target=x86_64-unknown-windows -ffreestanding -fshort-wchar \
	  -mno-red-zone -mno-sse -mno-avx -mno-mmx -std=c2x -MMD -MP

CPPFLAGS := -I../gnu-efi/inc -I../gnu-efi/inc/protocol \
	    -I../gnu-efi/inc/x86_64

LDFLAGS := --target=x86_64-unknown-windows -nostdlib -Wl,-entry:efi_main \
	   -Wl,-subsystem:efi_application -fuse-ld=lld-link

LOADER := loader.efi
LOADER_OBJS := main.o
LOADER_DEPS := $(LOADER_OBJS:.o=.d)

$(LOADER): $(LOADER_OBJS)

%.efi:
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	-$(RM) $(LOADER) $(LOADER_OBJS)
distclean:
	-$(RM) $(LOADER) $(LOADER_OBJS) $(LOADER_DEPS)
.PHONY: clean distclean

-include $(LOADER_DEPS)

