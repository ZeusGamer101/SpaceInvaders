#pragma once
#include "Martien.h" 
#include "Enhancedlaser.h"
#include <string>
class UniversalBeings : public Martien {
	std::string trueApparence;
public:
	UniversalBeings(Coord coord, char apparence, unsigned short valeurPoints, std::string trueApparence);
	void deplacer() override;
};
