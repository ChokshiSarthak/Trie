CCFLAGS=g++ -Wall
SRC=trie.cc
OBJ=$(SRC:.cc=.o)

trie:$(OBJ)
	$(CCFLAGS) -o $@ $^

.PHONY:clean

clean:
	rm -f $(OBJ) trie

