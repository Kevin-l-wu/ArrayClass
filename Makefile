Test : Main.o
	g++ Main.o -o Test
	
.PHONY:clean
clean:
	rm -rf Test
	rm -rf *.o
