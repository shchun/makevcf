all:
	gcc -o makevcf main.c
clean:
	rm -f *.o makevcf
