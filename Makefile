Test : Main.o Array.o
	g++ Main.o Array.o -o Test
	
.PHONY:clean
clean:
	rm -rf Test
	rm -rf *.o
