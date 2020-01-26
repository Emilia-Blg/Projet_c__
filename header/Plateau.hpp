#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Unite.hpp"

using namespace std;

class Plateau{
private:
    vector<Unite*> tab;

public:
    Plateau();
    ~Plateau();

    bool placer(Unite& u, int position);
    Unite getTab(int index);
    void viderCase(int index);
    void affiche();
};
#endif
