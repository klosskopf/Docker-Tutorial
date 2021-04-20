mandelbrot: mandelbrot.cpp
	g++ -Wall -O3 -o mandelbrot mandelbrot.cpp

clean:
	rm -f mandelbrot

.PHONY : clean
