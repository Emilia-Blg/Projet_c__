
CXX=g++
CXXFLAGS=-Wall 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

Jeu: Jeu.o Pion.o Unite.o Archer.o Fantassin.o Base.o Plateau.o SuperSoldat.o Catapulte.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core 
