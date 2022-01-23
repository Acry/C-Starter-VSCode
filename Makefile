define colorecho
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

# Compiler Flags
C_FLAGS     = -no-pie -ggdb -Wall -Wextra -mtune=native

# Linker Flags
LD_FLAGS    = -lm

SRC_DIR	    = src/
BUILD_DIR    = dest/

TARGETS     = second recursion

.PHONY: all
all: $(TARGETS)

second:   $(SRC_DIR)second.c
	@cc $(C_FLAGS) -o $(BUILD_DIR)$@ $< $(LD_FLAGS)

recursion:   $(SRC_DIR)recursion.c
	@cc $(C_FLAGS) -o $(BUILD_DIR)$@ $< $(LD_FLAGS)

ttt1:   $(SRC_DIR)ttt1.c
	@cc $(C_FLAGS) -o $(BUILD_DIR)$@ $< $(LD_FLAGS)
# hot compile
# while inotifywait -e close_write ./code.c; do date +%X; make > /dev/null; done

.PHONY: clean
clean:
	@cd $(BUILD_DIR) && rm $(TARGETS) 2>/dev/null || true

# $<	first dependency
# $@	target name
# $+	list of all dependencies
# $^	list of all unique dependencies