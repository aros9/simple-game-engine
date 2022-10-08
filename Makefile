all: compile link

compile:
	g++ -c src/*.cpp
	mv *.o build

link:
	g++ build/*.o -o Main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f Main build/*.o

run:
	./Main