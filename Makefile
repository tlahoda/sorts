all: bubblesort combsort countingsort orderofmagnitudesort pigeonholesort selectionsort

bubblesort: examples/bubblesort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/bubblesort.cpp -I. -o bubblesort
	strip bubblesort

combsort: examples/combsort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/combsort.cpp -I. -o combsort
	strip combsort

countingsort: examples/countingsort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/countingsort.cpp -I. -o countingsort
	strip countingsort

orderofmagnitudesort: examples/orderofmagnitudesort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/orderofmagnitudesort.cpp -I. -o orderofmagnitudesort
	strip orderofmagnitudesort

pigeonholesort: examples/pigeonholesort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/pigeonholesort.cpp -I. -o pigeonholesort
	strip pigeonholesort

selectionsort: examples/selectionsort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/selectionsort.cpp -I. -o selectionsort
	strip selectionsort

clean:
	rm -f bubblesort combsort countingsort orderofmagnitudesort pigeonholesort selectionsort

