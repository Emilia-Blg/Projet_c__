#include <iostream>
#include "Base.hpp"
#include "Unite.hpp"

using namespace std;

    Base::Base()
        {}

    Base::~Base()
        {

        }

int Base :: getPointVie()
	{
		return pointVie;
    	}

void Base :: setPointVie(int pv)
	{
		pointVie = pv;
    	}

void Base :: setPos(int posC)
	{
		posCase = posC;
    	}

int Base :: getPos()
	{
		return posCase;
    	}
 




