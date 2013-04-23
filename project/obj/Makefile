OBJ = $(wildcard *.o)

all: $(EXEC)
	
$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o "$(TOP)/$(EXEC)"

clean:
	@rm -f *.o
