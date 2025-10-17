#pragma once
#include <iostream>
using namespace std;

class Matrice
{
private:
	int rows;
	int cols;
	int** data;
public:
	Matrice(int , int );
	Matrice();
	Matrice(const Matrice&);
	void afficher() const;
	void remplir();
	Matrice operator+(const Matrice& ) const;
	Matrice operator-(const Matrice& ) const;
	Matrice  operator*(const Matrice& ) const;
	Matrice  operator*(const int ) const;
	Matrice transposee() const;
	Matrice operator=(const Matrice& );
	~Matrice();
};

