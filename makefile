# Compiler to use (g++ or gcc):
CC = g++

# Main source file:
MAINFILE = ./example1.cpp

# output executable:
OUTPUT = out

# Other Files to compile Too:
OTHERFILES =

# Other Flags to add:
OTHERFLAGS =

# Language standart the compiler should use:
# (automatically the version amCode.cpp was compiled in)
# Can be replaced by an std=c++VERSION in OTHERFLAGS as Last takes priority 
LANGUAGESTD = --std=c++23

# Default target (for development/debugging)
all: $(OUTPUT)

$(OUTPUT): $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Og -Wall -Wextra -pedantic -O2

# Production target (optimized and stripped binary)
prod: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Os -s -DNDEBUG -Wall -Wextra -pedantic

# optimized for speed
fast: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Ofast -Og -Wall -Wextra -pedantic

# optimized for speed, but without debug
pfast: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Ofast -s -DNDEBUG -Wall -Wextra -pedantic

# optimized for space/memory efficiency
space: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Oz -Og -Wall -Wextra -pedantic -O2

# optimized for space/memory efficiency, but without debug
pspace: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Oz -s -DNDEBUG -Wall -Wextra -pedantic

# Just everything thrown together
max: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Os -Ofast -Oz -Og -Wall -Wextra -pedantic

# Just everything thrown together, but without debug
pmax: $(MAINFILE) $(OTHERFILES)
	$(CC) $(MAINFILE) $(OTHERFILES) -o $(OUTPUT) $(LANGUAGESTD) $(OTHERFLAGS) -Os -Ofast -Oz -s -DNDEBUG -Wall -Wextra -pedantic

# Clean target (works for Linux and Windows)
clean:
	rm $(OUTPUT)
clear:
	rm $(OUTPUT)