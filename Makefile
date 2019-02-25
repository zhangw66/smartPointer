main: main.o Person.o RefBase.o 
	g++ $^ -o $@ -std=c++11 

%.o:%.cc
	g++ $< -c -o $@ -std=c++11 -I ./android_ref/

clean:
	rm *.o main

.PHONY: clean
