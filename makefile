PROGRAM = verlet
CC = gcc
all: $(PROGRAM)

SOURCE = src
OUT = out

# Flags to pass to the CC
FLAGS += `sdl2-config --cflags --libs`
FLAGS += -lm

# INCLUDE any directories you want to search for headers in
# This works for including <> style headers as well
# INCLUDE +=

vpath %.c $(SOURCE)
vpath %.h $(SOURCE)

# Searches for all C files in the source,
# Then creates OBJECT file names for each
HFILES = $(shell find $(SOURCE) -type f -name '*.h' -print)
CFILES = $(shell find $(SOURCE) -type f -name '*.c' -print)
OBJECTS = $(patsubst $(SOURCE)/%.c,$(OUT)/%.o,$(CFILES))

# Compiles the main program, depends on the object files
$(PROGRAM): $(OBJECTS)
	$(info Compiling program `$@`)
	@$(CC) $(FLAGS) -o $(PROGRAM) $(OBJECTS) $(patsubst %,-I %,$(INCLUDE))

# Compiles object files into OUT
$(OUT)/%.o: %.c %.h $(HFILES)
	@mkdir -p $(shell echo "$@" | grep -E -o "((.*)\/)")
	$(info Compiling object file `$@`)
	@$(CC) $(FLAGS) -c -o $@ $<

$(OUT)/%.o: %.c
	@mkdir -p $(shell echo "$@" | grep -E -o "((.*)\/)")
	$(info Compiling object file `$@`)
	@$(CC) $(FLAGS) -c -o $@ $<

.PHONY: preprocessed run clean silent fresh

# Produces a preprocessed file into OUT
preprocessed:
	$(info Preprocessing...)
	@$(CC) $(SOURCE)/main.c -E -o $(OUT)/$(PROGRAM).i

# Makes and runs the program
run: $(PROGRAM)
	@echo --- RUNNING ---
	@./$(PROGRAM)
	@echo --- STOPPED ---

clean:
	$(info Cleaning object files...)
	@$(RM) -rf $(PROGRAM) $(OUT)

# Compiles, runs, then deletes all the evidence
silent: $(PROGRAM) run clean

# Cleans and recompiles
fresh: clean $(PROGRAM)
