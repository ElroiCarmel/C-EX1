CC = gcc
FLAGS = -Wall -g
LIB_LOOP_OBJ = basicClassification.o advancedClassificationLoop.o
LIB_REC_OBJ = basicClassification.o advancedClassificationRecursion.o
DEPS = numClass.h
CLEAN_FILES = *.o *.a *.so mains maindloop maindrec

all : loops recursives recursived loopd mains maindloop maindrec
mains : main.o libclassrec.a
	$(CC) $(FLAGS) -o $@  main.o libclassrec.a
maindloop : main.o libclassloops.so
	$(CC) $(FLAGS) -o $@ main.o ./libclassloops.so
maindrec : main.o libclassrec.so
	$(CC) $(FLAGS) -o $@ main.o ./libclassrec.so
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
%.o : %.c $(DEPS)
	$(CC) $(FLAGS) -fPIC -c $< -o $@

.PHONY : clean all loops recursives recursived loopd

clean:
	rm -f $(CLEAN_FILES)
