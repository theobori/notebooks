CC = g++
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

INC = include
BIN = euler
CPPFLAGS = #-Ofast #-g3
CPPLIBS = -lm -L include

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) $(CLIBS) $(CPPFLAGS) -o $@

clean:
	$(RM) *~
	$(RM) #*#
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) *.a

re: fclean all