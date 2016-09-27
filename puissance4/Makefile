
# Test and run on :
# =================
# Compiler    : gcc
# Version     : 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04)
# Date        : 07/02/2016 (Last update)


# Flags added to the compilation.
CFLAGS = -g -W -Wall -Wextra

# Path to the sources files.
SRC = src/

# Executable
EXEC = Puissance4

# All task (compilation and cleaning).
all: $(EXEC) clean

# The target executable file.
Puissance4: $(SRC)main.c $(SRC)menu.o $(SRC)function.o
	gcc     $(SRC)main.c $(SRC)menu.o $(SRC)function.o -o $(EXEC)

# Secondary target.
menu.o:     $(SRC)menu.c $(SRC)menu.h
	gcc -c  $(SRC)menu.c $(CFLAGS)

function.o: $(SRC)function.c $(SRC)function.h
	gcc -c  $(SRC)function.c $(CFLAGS)

clean:
	@echo "Removal of object files."
	rm -f $(SRC)*.o

