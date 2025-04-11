# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS = 

# Grand_prixdictor app-specific settings
GP_APP = grand_prixdictor
GP_SRC = grand_prixdictor.c
GP_OBJ = $(GP_SRC:.c=.o)

# Default target
.PHONY: default
default: $(GP_APP)

# Help command to show available targets
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make             - Build the Grand Prix predictor application"
	@echo "  make grand_prixdictor  - Build the Grand Prix predictor application"
	@echo "  make clean       - Remove all build artifacts"
	@echo "  make help        - Display this help message"

# Target to specifically build the Grand Prix predictor
.PHONY: grand_prixdictor
grand_prixdictor: $(GP_APP)

# Build the Grand Prix predictor
$(GP_APP): $(GP_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built $(GP_APP) successfully"

# Generic rule for compiling C source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
.PHONY: clean
clean:
	rm -f $(GP_OBJ) $(GP_APP)
	@echo "Cleaned up build artifacts"