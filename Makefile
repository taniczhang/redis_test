all:
	gcc -std=gnu99 -o redistest redistest.c -lhiredis
clean:
	rm redistest
