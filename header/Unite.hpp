#ifndef UNITE_HPP
#define UNITE_HPP

#include <iostream>

using namespace std;

class Unite {

 protected :
    int pointVie;
	int posCase;

 public :
    Unite();
    ~Unite();

	virtual void setPointVie(int pv);
	int getPointVie();
	virtual void setPos(int posC);
	int getPos();
};
#endif
