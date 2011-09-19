all: bubble_sort comb_sort counting_sort lsd_radix_sort order_of_magnitude_sort pigeonhole_sort selection_sort

bubble_sort: examples/bubble_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/bubble_sort.cpp -I. -o bubble_sort
	strip bubble_sort

comb_sort: examples/comb_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/comb_sort.cpp -I. -o comb_sort
	strip comb_sort

counting_sort: examples/counting_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/counting_sort.cpp -I. -o counting_sort
	strip counting_sort

lsd_radix_sort: examples/lsd_radix_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/lsd_radix_sort.cpp -I. -o lsd_radix_sort
	strip lsd_radix_sort

order_of_magnitude_sort: examples/order_of_magnitude_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/order_of_magnitude_sort.cpp -I. -o order_of_magnitude_sort
	strip order_of_magnitude_sort

pigeonhole_sort: examples/pigeonhole_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/pigeonhole_sort.cpp -I. -o pigeonhole_sort
	strip pigeonhole_sort

selection_sort: examples/selection_sort.cpp
	g++ -O5 -Wall -std=gnu++0x examples/selection_sort.cpp -I. -o selection_sort
	strip selection_sort

clean:
	rm -f bubble_sort comb_sort counting_sort lsd_radix_sort order_of_magnitude_sort pigeonhole_sort selection_sort

