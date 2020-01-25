#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Unite.hpp"

using namespace std;

class Plateau{
	private:
		Unite tab[14];
	public:

		Plateau();

		~Plateau();

		void placer(Unite u, int position);

		Unite getTab(int index);
				
};
#endif
