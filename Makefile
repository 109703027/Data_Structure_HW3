CC = g++
CPPFLAGS = -lm
EXE = main.exe
OBJS = main.o public.o SkipList.o SortedArray.o Treap.o HashTable.o

$(EXE) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(EXE) $(OBJS)

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean :
	rm $(EXE) $(OBJS)
