CXX = g++
CXXFLAGS= -pedantic -Wall -Werror -std=c++17   
SOURCES = $(wildcard *.cpp)

main: $(SOURCES) 
	$(CXX) $^ -o $@ $(CXXFLAGS)

main_1: main
	./main --group 102 103 > test.txt

main_2: main
	./main --subject Matematika Fyzika > test.txt
	
main_3: main
	./main --statistics > statistics.txt

main_4: main
	./main > test.txt	

clean:
	rm -f main test.txt
