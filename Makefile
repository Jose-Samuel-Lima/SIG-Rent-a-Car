all:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o sig-rent-a-car *.o

clean:
	rm -f *.o *.gch sig-rent-a-car