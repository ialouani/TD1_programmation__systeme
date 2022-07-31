#cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"
GCC_FLAGS=-g3 -O0
MEMCHECK=valgrind
all: test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin_exec sortie_tete sortie_tete2 test_write2 version_read__1 read_testing read_version_finale open_close_read_write dup_2_manuels fork_test test_exo7 exo7 rien exo8_v1 rslt rslt_v2 infos test_general exo9 rien2 
#open_close_read_write est la copie conforme de cp .
clean:
	rm -f *.php~ Makefile~ *.o *.c~ test_syscall_write test_syscall_write2 test_syscall_write3 test_write ls_bin a.out test_write2 version_read__1 read_testing read_version_finale file open_close_read_write dup_2_manuels tricky.txt fork_test test_exo7 exo7 rien exo8_v1 file_intermediaire ecrire lire exo8_v2 test_general test_final.txt exo9 *.txt~
test_script: exo1.php
	php $<
rien: exo7_3.php
	php $<
rien2: exo9_2.php
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
open_close_read_write: exo6.c
	gcc $< -o $@

.PHONY: creation build tests_generaux
creation:
	rm -f tricky.txt
	touch tricky.txt
dup_2_manuels: creation exo6_2.c
	gcc exo6_2.c -o $@
fork_test: exo6_3.c
	gcc $< -o $@
.PHONY: test_fstat open
test_exo7: exo7.c
	gcc -std=c99 $^ -o $@
exo7: exo7_2.c
	gcc $^ -o $@
.PHONY: exo8 creations_exo8 exo9 TD1
creation2:
	rm -f file_intermediaire
	touch file_intermediaire
exo8_v1: exo8.c creation2
	gcc $< -o $@
.PHONY: v1 v2 link
rslt: ecrire lire
	./ecrire ./lire
ecrire: exo8_ecrivain.c
	gcc $< -o $@
lire: exo8_lecteur.c
	gcc $< -o $@
exo8_v2: exo8_v22.c
	gcc $< -o $@
rslt_v2: exo8_v2 ecrire
	./$< ./ecrire
.PHONY: infos
infos: exo8_v2
	file exo8_v2
test_general:exo9_1.c
	gcc $< -o $@
	$(MEMCHECK) ./$@
.PHONY: essais tests rslts
building:
	rm -f test.txt
	touch test.txt
	echo a 5 > test.txt
	touch test_final.txt
exo9: building exo9.c
	gcc exo9.c
	./a.out test.txt test_final.txt
#avec les fopen (FILE* f) et les fprintf et les cast(s) on peut
#construire manuellement non le fichier test.txt


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
