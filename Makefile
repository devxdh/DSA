CXX = g++
CXXFLAGS = -std=c++23 -Wall -O2

.SUFFIXES:
% : %,v
% : %,t
% : RCS/%,v
% : RCS/%
% : s.%
% : SCCS/s.%

SRC_FILES := $(shell find . -name "*.cpp")

%.cpp:
	$(eval BASE_NAME := $(basename $@))
	$(eval SRC_PATH := $(filter %/$(BASE_NAME).cpp, $(SRC_FILES)))
	@if [ -z "$(SRC_PATH)" ]; then echo "Error: $(BASE_NAME).cpp not found."; exit 1; fi
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(SRC_PATH) -o ./bin/$(BASE_NAME)
	@./bin/$(BASE_NAME)

%:
	$(eval BASE_NAME := $@)
	$(eval SRC_PATH := $(filter %/$(BASE_NAME).cpp, $(SRC_FILES)))
	@if [ -z "$(SRC_PATH)" ]; then echo "Error: $(BASE_NAME).cpp not found."; exit 1; fi
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(SRC_PATH) -o ./bin/$(BASE_NAME)
	@./bin/$(BASE_NAME)

.PHONY: %.cpp %
