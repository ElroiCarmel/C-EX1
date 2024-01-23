CC = gcc
FLAGS = -Wall -g

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
libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
libclassloops.a : basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassrec.so : basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
libclassloops.so : basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o
basicClassification.o : basicClassification.c numClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o : advancedClassificationLoop.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.0 : advancedClassificationRecursion.c numClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
main.o : main.c numClass.h
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.a *.so mains maindloop maindrec
