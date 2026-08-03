CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# 1. Kill all built-in implicit rules and default suffixes completely
.SUFFIXES:
% : %,v
% : %,t
% : RCS/%,v
% : RCS/%
% : s.%
% : SCCS/s.%

# 2. Automatically find all .cpp files across the directory structure
SRC_FILES := $(shell find . -name "*.cpp")

# 3. Explicitly catch targets ending in .cpp
%.cpp:
	$(eval BASE_NAME := $(basename $@))
	$(eval SRC_PATH := $(filter %/$(BASE_NAME).cpp, $(SRC_FILES)))
	@if [ -z "$(SRC_PATH)" ]; then echo "Error: $(BASE_NAME).cpp not found."; exit 1; fi
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(SRC_PATH) -o ./bin/$(BASE_NAME)
	@./bin/$(BASE_NAME)

# 4. Explicitly catch targets WITHOUT an extension
%:
	$(eval BASE_NAME := $@)
	$(eval SRC_PATH := $(filter %/$(BASE_NAME).cpp, $(SRC_FILES)))
	@if [ -z "$(SRC_PATH)" ]; then echo "Error: $(BASE_NAME).cpp not found."; exit 1; fi
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(SRC_PATH) -o ./bin/$(BASE_NAME)
	@./bin/$(BASE_NAME)

.PHONY: %.cpp %
