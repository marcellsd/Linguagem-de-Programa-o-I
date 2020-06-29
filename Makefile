GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall
PROGRAM = diary

$(PROGRAM): main.o app.o diary.o time.o date.o
	$(GCC) -o $(PROGRAM) main.o app.o diary.o date.o time.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

app.o:  src/app.cpp
	$(GCC) $(GCC_FLAGS) -c  src/app.cpp

diary.o: src/diary.cpp
	$(GCC) $(GCC_FLAGS) -c src/diary.cpp

date.o: src/date.cpp
	$(GCC) $(GCC_FLAGS) -c src/date.cpp

time.o: src/time.cpp
	$(GCC) $(GCC_FLAGS) -c src/time.cpp