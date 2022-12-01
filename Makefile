CPP=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -g -O2
EXECUTABLE=main
# VARGS=--tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes
OBJS=main.o

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CPP) $(CFLAGS) -o $(EXECUTABLE) $^ -lsimlib -lm

main.o: main.cpp
	$(CPP) $(CFLAGS) -c $^

# create tar archive with the necessary files for submission
tar:
	tar -czvf 8_xserej00_xbakaj00.tar.gz *.cpp *.hpp Makefile -C ./../docs/documentation/ documentation.pdf

# create zip archive with the necessary files for submission
zip:
	zip -jr 8_xserej00_xbakaj00.zip *.cpp *.hpp Makefile ./../docs/documentation/documentation.pdf

valgrind: $(EXECUTABLE)
	valgrind $(VARGS) ./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *.o *.gch