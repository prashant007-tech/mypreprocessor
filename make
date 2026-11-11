exe:main.o file_inclusion.o macro_substituion.o comment_removal.o 
	cc main.o file_inclusion.o macro_substituion.o comment_removal.o -o exe
main.o:main.c
	cc -c main.c
file_inclusion.o : file_inclusion.c
	cc -c file_inclusion.c
macro_substituion.o : macro_substituion.c
	cc -c macro_substituion.c
comment_removal.o : comment_removal.c
	cc -c comment_removal.c
clear :
	@echo"cleaning up--"
	@rm -rv *.o
