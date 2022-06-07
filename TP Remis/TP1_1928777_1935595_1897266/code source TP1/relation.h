/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Titre:		 Travail pratique #1 - relation.h
/// Date:		 3 mars 2019
/// Auteurs:	 Mariam Sarwat (1928777), Yasmina Abou-Nakkoul (1897266) et Stéphanie Mansour (1935595)
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef relation_h
#define relation_h

#include <fstream>
#include <vector>
#include "individu.h"

using namespace std;

class Relation  {
public:
    Relation();

	Individu getIndividusA() const;
	int getRelation() const;
	Individu getIndividusB() const;

	void setIndividusA(Individu individu);
	void setRelation(int relation);
	void setIndividusB(Individu individu);

private:
	Individu individusA_;
	Individu individusB_;
	int relation_;
};
#endif
