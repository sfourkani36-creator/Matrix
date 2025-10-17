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
	Matrice(int r, int c);
	Matrice();
	Matrice(const Matrice&);
	void afficher() const;
	void remplir();
	Matrice operator+(const Matrice& m) const;
	Matrice operator-(const Matrice& m) const;
	Matrice  operator*(const Matrice& m) const;
	Matrice  operator*(const int scalar) const;
	Matrice transposee() const;
	Matrice operator=(const Matrice& m);
	~Matrice();
};

