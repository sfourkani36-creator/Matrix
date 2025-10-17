#include"Matrice.h"

int main()
{    
	int n;
	cout << "donner le nombre des matrcie que vous voulez" <<endl;
	cin >> n;	
	Matrice* a = new Matrice[n];
	for (int i = 0; i < n; i++)
	{
		cout << "remplissage de la matrice a[ " << i + 1 << "]" << endl;
		a[i].remplir();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "affichage de la matrice a[ " << i + 1 <<"]"<< endl;
		a[i].afficher();
	}
	delete[] a;
	Matrice* b = new Matrice[2];
	cout << "remplissage de la matrice b[1]" << endl;
	b[0].remplir();
	cout << "remplissage de la matrice b[2]" << endl;
	b[1].remplir();
	cout << "affichage de la matrice b[1]" << endl;	
	b[0].afficher();
	cout << "affichage de la matrice b[2]" << endl;
	b[1].afficher();
	Matrice c = b[0] + b[1];
	c.afficher();
	Matrice d = b[0] - b[1];
	d.afficher();
	Matrice e = b[0] * b[1];
	e.afficher();
	Matrice f = b[0] * 3;
	f.afficher();
	Matrice g = b[0].transposee();
	g.afficher();
	delete[] b;
}


