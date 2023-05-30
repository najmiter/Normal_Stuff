STD = g++ -std=c++20

Captain:
	make exe && clear && ./exe

exe: *.o
	$(STD) *.o -o exe

%.o: %.cpp
	$(STD) -c $^

clean:
	rm *.o exe
