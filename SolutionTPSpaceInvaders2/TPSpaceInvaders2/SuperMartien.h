#pragma once
#include "Martien.h"
class SuperMartien :public Martien {

public:
	SuperMartien(Coord coord, char apparence, unsigned short valeursPoints);
	void deplacer() override;
};
