all: example

example: examples/example.cpp
	g++ -O5 -Wall -std=gnu++0x examples/example.cpp -I. -o example
	strip example 

clean:
	rm -f example

