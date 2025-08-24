CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -g
DEPS := color.h vec3.h
OBJ := main.o color.o

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f *.o main
