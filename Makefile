all:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o sig-rent-a-car *.o

clean:
	rm -f *.o *.gch sig-rent-a-car

# Remove-Item *.o -Force
# Remove-Item *.gch -Force
# Remove-Item .\sig-rent-a-car.exe -Force
