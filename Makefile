main: main.o Person.o smartPointer.o
	g++ $^ -o $@ -std=c++11 

%.o:%.cc
	g++ $< -c -o $@ -std=c++11

clean:
	rm *.o main

.PHONY: clean
