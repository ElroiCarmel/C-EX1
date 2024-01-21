mains : main.o libclassrec.a
	gcc -Wall -o mains  main.o libclassrec.a
maindloop : main.o libclassloops.so
	gcc -Wall -o maindloop main.o ./libclassloops.so
maindrec : main.o libclassrec.so
	gcc -Wall -o maindrec main.o ./libclassrec.so
loops : libclassloops.a
recursives: libclassrec.a
recursived : libclassrec.so
loopd : libclassloops.so
libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
libclassloops.a : basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassrec.so : basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
libclassloops.so : basicClassification.o advancedClassificationLoop.o
	gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o
basicClassification.o : basicClassification.c numClass.h
	gcc -Wall -c basicClassification.c
advancedClassificationLoop.o : advancedClassificationLoop.c numClass.h
	gcc -Wall -c advancedClassificationLoop.c
advancedClassificationRecursion.0 : advancedClassificationRecursion.c numClass.h
	gcc -Wall -c advancedClassificationRecursion.c
main.o : main.c numClass.h
	gcc -Wall -c main.c
clean:
	rm -f *.o *.a *.so mains maindloop maindrec