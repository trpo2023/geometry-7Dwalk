all: geometry

geometry: geometry.cpp
	gcc -Wall -Werror -o geometry geometry.cpp

clean:
	rm geometry

run:
	./geometry