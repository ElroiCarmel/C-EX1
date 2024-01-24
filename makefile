CC = gcc
FLAGS = -Wall -g
LIB_LOOP_OBJ = basicClassification.o advancedClassificationLoop.o
LIB_REC_OBJ = basicClassification.o advancedClassificationRecursion.o

all : loops recursives recursived loopd mains maindloop maindrec
mains : main.o libclassrec.a
	$(CC) $(FLAGS) -o mains  main.o libclassrec.a
maindloop : main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so
maindrec : main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so
loops : libclassloops.a
recursives : libclassrec.a
recursived : libclassrec.so
loopd : libclassloops.so
libclassrec.a : $(LIB_REC_OBJ)
	ar -rcs $@ $^
libclassloops.a : $(LIB_LOOP_OBJ)
	ar -rcs $@ $^
libclassrec.so : $(LIB_REC_OBJ)
	$(CC) -shared -o $@ $^
libclassloops.so : $(LIB_LOOP_OBJ)
	$(CC) -shared -o $@ $^
basicClassification.o : basicClassification.c numClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o : advancedClassificationLoop.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.0 : advancedClassificationRecursion.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
main.o : main.c numClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY : clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec
