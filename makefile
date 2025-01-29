all: test

test: test.o functions_to_implement.o
    g++ -o test test.o functions_to_implement.o

test.o: test.cpp
    g++ -c test.cpp

functions_to_implement.o: functions_to_implement.cpp
    g++ -c functions_to_implement.cpp

clean:
    rm -f *.o test
