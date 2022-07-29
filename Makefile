#cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"
GCC_FLAGS=-g3 -O0
all: test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin_exec sortie_tete sortie_tete2 test_write2 version_read__1 read_testing read_version_finale
clean:
	rm -f *.php~ Makefile~ *.o *.c~ test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin a.out test_write2 version_read__1 read_testing read_version_finale file
test_script: exo1.php
	php $<
test_syscall_write: exo3.c
	gcc -std=c99 -o $@ $^
test_syscall_write2: exo3_2.c
	gcc -std=c99 ${GCC_FLAGS} -o $@ $^
test_syscall_write3: exo4.c
	gcc -std=c99 ${GCC_FLAGS} -o $@ $^
test_write: exo4_2.c
	gcc -std=c99 -Dx=5 -o $@ $<
test_write2: exo5_2.c
	gcc -std=c99 -Dx=5 -o $@ $<
ls_bin: exo4.c
	gcc -std=c99 exo4.c -o $@
ls_bin_exec: ls_bin 
	@echo "ls_personnel:(pas de details)\n"
	./$< /bin/ls ./
sortie: test_write
	od -x ./test_write
sortie_tete: test_write
	od test_write | head
sortie_tete2: test_write2
	od test_write2 | head
version_read__1: exo5.c
	gcc -std=c99 $^ -o $@
read_testing: exo5_3.c
	rm -f file && touch file
	gcc $< -o $@
read_version_finale: exo5.c
	gcc $< -o $@
#soit l'enlever previsualiser le resultat pas directement suivant la remarque
#ci-dessus soit laisser comme cela.(reecriture apres une seule et unique
#creation)
#ca revient presque au meme mais des petites ~nuances~ soient PRESENTES.
#a executer sur le read_version_finale 2 fois le temps que file const apres
#se relit pas a pas...
#colors:
#	@$(call cyan,"ls personnel sur le repertoir courant:")
#sans \n pris en compte meme dans @echo.
#avant colors appel.
