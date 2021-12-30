//QuickSort
//Kacper Hnatyszyn 3prT5

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ilosc;
clock_t start, stop;
double czas;

void quicksort(int* tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do {
		while (tablica[i] < v) i++;
		while (tablica[j] > v) j--;
		if (i <= j) {
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++; j--;
			}
	} while (i <= j);

	if (j > lewy) quicksort(tablica, lewy, j);
	if (i < prawy) quicksort(tablica, i, prawy);
}

int main()
{
	cout << "Porowaneni czasow sortowania v.1" << endl;

	cout << "Ile losowych liczb w tablicy: ";
	cin >> ilosc;

	//dynamiczna alokacja tablicy
	int* tablica;
	tablica = new int[ilosc];

	//inicjowanie generatora
	srand(time(NULL));

	//wczytywanie  liczb do tablicy
	for (int i = 0; i < ilosc; i++)
	{
		tablica[i] = rand() % 1000000 + 1;
	}

	cout << "Przed posortowaniem: " << endl;
	for (int i = 0; i < ilosc; i++)
	{
		cout << tablica[i] << " ";
	}

	cout << endl << "Sortuje teraz szybkoo. Prosze czekac!" << endl;

	start = clock();
	quicksort(tablica, 0, ilosc-1);
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;

	cout << "Po posortowaniu: " << endl;
	for (int i = 0; i < ilosc; i++)
	{
		cout << tablica[i] << " ";
	}

	cout << endl << "Czas sortowania szybkiegoooo: " << czas << " s" << endl;

	delete[] tablica;

	return 0;
}
