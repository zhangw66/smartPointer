main: main.o Person.o smartPointer.o
	g++ $^ -o $@  

%.o:%.cc
	g++ $< -c -o $@

clean:
	rm *.o main

.PHONY: clean
