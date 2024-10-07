CXX = gcc
CXXFLAGS = -I./include
OUT = bin/bin.out

SRC = run.c src/*.c -lm 

run:
	@$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)
	@./$(OUT)
