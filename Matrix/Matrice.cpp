#include "Matrice.h"

Matrice::Matrice(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			this->data[i][j] = 0;
	}

}

Matrice::Matrice()
{
	cout << "donner le nombre des lignes" << endl;
	cin >> this->rows;
	cout << "donner le nombre des colognes" << endl;
	cin >> this->cols;
	this->data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			this->data[i][j] = 0;
	}
}

Matrice::Matrice(const Matrice& m)
{
	this->rows = m.rows;
	this->cols = m.cols;
	this->data = new int* [this->rows];
	for (int i = 0; i < this->rows; i++)
		this->data[i] = new int[this->cols];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			this->data[i][j] = m.data[i][j];

}

void Matrice::afficher() const
{
	cout << "la matrice est :" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}
void Matrice::remplir()
{
	cout << "donner les coefficient" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << "data[" << i << "][" << j << "]" << endl,
			cin >> this->data[i][j];
	}
}
Matrice Matrice::operator+(const Matrice& m) const
{
	if (this->rows != m.rows || this->cols != m.cols) {
		cout << "erreur les Matrices ne sont pas de meme taille" << endl;
		return *this;
	}

	Matrice result(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			result.data[i][j] = this->data[i][j] + m.data[i][j];
	return result;
}
Matrice Matrice::operator-(const Matrice& m) const
{
	if (this->rows != m.rows || this->cols != m.cols) {
		cout << "erreur les Matrices ne sont pas de meme taille" << endl;
		return *this;
	}

	Matrice result(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			result.data[i][j] = this->data[i][j] - m.data[i][j];
	return result;
}
Matrice Matrice::operator*(const Matrice& m) const
{
	if (this->cols != m.rows) {
		cout << "erreur les Matrices ne sont pas compatibles pour la multiplication" << endl;
		return *this;//c'est juste pour retourner quelque chose mieux que exit(0) qui sort du program
	}
	Matrice result(this->rows, m.cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < m.cols; j++)
			for (int k = 0; k < this->cols; k++)
				result.data[i][j] += this->data[i][k] * m.data[k][j];
	return result;
}
Matrice Matrice::operator*(const int k) const
{
	Matrice result(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			result.data[i][j] = this->data[i][j] * k;
	return result;
}
Matrice Matrice::transposee() const
{
	Matrice transpose(this->cols, this->rows);
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->cols; j++)
			transpose.data[j][i] = this->data[i][j];
	return transpose;
}
Matrice Matrice::operator=(const Matrice& m)
{
	if (this == &m)
		return *this;
	for (int i = 0; i < rows; i++)
		delete[] this->data[i];
	delete[] this->data;

	this->rows = m.rows;
	this->cols = m.cols;
	this->data = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->data[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			this->data[i][j] = m.data[i][j];
	}
	return *this;
}

Matrice::~Matrice()
{
	for (int i = 0; i < rows; i++)
		delete[] this->data[i];
	delete[] this->data;
}
