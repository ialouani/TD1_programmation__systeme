#cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"
GCC_FLAGS=-g3 -O0
all: test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin_exec sortie_tete
clean:
	rm -f *.php~ Makefile~ *.o *.c~ test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin a.out
test_script: exo1.php
	php $<
test_syscall_write: exo3.c
	gcc -std=c99 -o $@ $^
test_syscall_write2: exo3_2.c
	gcc -std=c99 ${GCC_FLAGS} -o $@ $^
test_syscall_write3: exo4.c
	gcc -std=c99 ${GCC_FLAGS} -o $@ $^
test_write: exo4_2.c
	gcc -std=c99 -o $@ $<
ls_bin: exo4.c
	gcc -std=c99 exo4.c -o $@
ls_bin_exec: ls_bin 
	@echo "ls_personnel:(pas de details)\n"
	./$< /bin/ls ./
sortie: test_write
	od -x ./test_write
sortie_tete: test_write
	od test_write | head
#colors:
#	@$(call cyan,"ls personnel sur le repertoir courant:")
#sans \n pris en compte meme dans @echo.
#avant colors appel.
