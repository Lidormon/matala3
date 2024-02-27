CC=gcc
CFLAGS= -Wall 
AR=ar
all: Main
#----------------------------------
Main: Main.o  
	$(CC) $(CFLAGS) -o Main Main.o 
#--------------------------------
# libmat.a: StrList.o
# 	$(AR) -rcs libmat.a StrList.o 
StrList.o: StrList.c StrList.h 
	$(CC) $(CFLAGS) -c StrList.c -o StrList.o
Main.o: Main.c StrList.h 
	$(CC) $(CFLAGS) -c Main.c -o Main.o

#--------------------------
.PHONY: clean all
clean:
	rm -f *.o  Main
