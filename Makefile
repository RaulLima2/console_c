OBJS = interface.o commands.o tree_decision.o commands_repl.o get_commands.o repl.o main.o
SOURCE = code/interface/interface.c code/commands/commands.c  code/tree_decision/tree_decision.c code/commands_repl_c/commands_repl.c code/get_commands/get_commands.c code/repl_code/repl.c main.c
OUT = main
CC = gcc
CFLAGS = -g3 -c -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(SOURCE) -lm -o $(OUT) $(LFLAGS)

main: $(OBJS)
	$(CC) -g $(SOURCE) -lm -o $(OUT)

interface.o: code/interface/interface.c
	$(CC) $(CFLAGS) code/interface/interface.c -std=c99

commands.o: code/commands/commands.c
	$(CC) $(CFLAGS) code/commands/commands.c -std=c99

tree_decision.o: code/tree_decision/tree_decision.c
	$(CC) $(CFLAGS) code/tree_decision/tree_decision.c -std=c99


commands_repl.o: code/commands_repl_c/commands_repl.c
	$(CC) $(CFLAGS) code/commands_repl_c/commands_repl.c -std=c99

get_commands.o: code/get_commands/get_commands.c
	$(CC) $(CFLAGS) code/get_commands/get_commands.c -std=c99

repl.o: code/repl_code/repl.c
	$(CC) $(CFLAGS) code/repl_code/repl.c -std=c99

main.o: main.c
	$(CC) $(CFLAGS) main.c -std=c99

cls:
	rm -rf $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
