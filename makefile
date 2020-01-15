PROGRAM = ${shell basename "$$PWD"}
CC = gcc

SOURCE = src
HEADER = inc
OUTPUT = out

# Flags to pass to the CC
FLAGS += -lm `sdl2-config --cflags --libs`
FLAGS += -pedantic

# INCLUDE any directories you want to search for headers in
# This works for including <> style headers as well
# INCLUDE = inc

vpath %.c $(SOURCE)
vpath %.h $(HEADER)

# Searches for all C files in the source,
# Then creates OBJECT file names for each
HFILES = $(shell find $(HEADER) -type f -name '*.h' -print)
CFILES = $(shell find $(SOURCE) -type f -name '*.c' -print)
OBJECTS = $(patsubst $(SOURCE)/%.c,$(OUTPUT)/%.o,$(CFILES))

# Compiles the main program, depends on the object files
# $(patsubst %,-I %,$(INCLUDE))
$(PROGRAM): $(OBJECTS)
	$(info Compiling program `$@`)
	@$(CC) $(FLAGS) -o $(OUTPUT)/$(PROGRAM) $(OBJECTS)

# Compiles object files into OUTPUT
$(OUTPUT)/%.o: %.c $(HFILES)
	@mkdir -p $(shell echo "$@" | grep -E -o "((.*)\/)")
	$(info Compiling object file `$@`)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER)

# All the user-defined make routines
.PHONY: preprocessed run clean silent fresh

# Produces a preprocessed file into OUTPUT
preprocessed:
	$(info Preprocessing...)
	@$(CC) $(SOURCE)/main.c -E -o $(OUTPUT)/$(PROGRAM).i

# Makes and runs the program
run: $(PROGRAM)
	@echo --- RUNNING ---
	@./$(OUTPUT)/$(PROGRAM)
	@echo --- STOPPED ---

clean:
	$(info Cleaning object files...)
	@$(RM) -rf $(OUTPUT)

# Compiles, runs, then deletes all the evidence
silent: $(PROGRAM) run clean

# Cleans and recompiles
fresh: clean $(PROGRAM)
