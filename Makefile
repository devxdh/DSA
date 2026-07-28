CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# 1. Match any target ending in .cpp
%.cpp:
	@# Calculate the absolute path of the source file
	$(eval ABS_SRC := $(abspath $(PWD)/$@))
	@# Extract just the binary name (e.g., pattern1)
	$(eval BIN_NAME := $(notdir $(basename $@)))
	@# Ensure a bin/ directory exists in your current terminal location
	@mkdir -p ./bin
	@# Compile using the absolute source path, putting the binary inside ./bin/
	$(CXX) $(CXXFLAGS) $(ABS_SRC) -o ./bin/$(BIN_NAME)
	@# Immediately run the binary from the bin folder
	@./bin/$(BIN_NAME)

.PHONY: %.cpp
