CXX = g++
CXXFLAGS = -g -std=c++11 -Wall

OBJECTS = datahandler.o montecarlo.o
RM = monte main.o

monte: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

datahandler.o: datahandler.hpp
montecarlo.o: montecarlo.hpp


clean:
	rm -f $(RM) $(OBJECTS)