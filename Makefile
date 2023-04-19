CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

geometry: geometry.cpp
	$(CXX) $(CXXFLAGS) -o geometry geometry.cpp
.PHONY: clean

clean:
	rm -f geometry