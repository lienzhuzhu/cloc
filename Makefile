all:
	gcc -std=c99 -Wall -Wextra -pedantic -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -lraylib -Iinclude src/main.c -o main

run: all
	./main

clean:
	rm main
