#include <iostream>
#include <chrono>

void quicksort(int *tab, int left, int right)
{
    int i = left, j = right, temp;
    int axis = tab[(left+right)/2];

    do
    {
        while(tab[i] < axis) i++;
        while(tab[j] > axis) j--;
        if(i <= j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }
    while(i <= j);
    if(j > left) quicksort(tab, left, j);
    if(i < right) quicksort(tab, i, right);
}

int main()
{
    int n = 5;
    int *tablica = new int [n];

    tablica[0] = 30;
    tablica[1] = 10202;
    tablica[2] = 984;
    tablica[3] = 266;
    tablica[4] = 1;

    for(int i=0; i<n; i++)
    {
        std::cout << tablica[i] << std::endl;
    }

    auto start = std::chrono::steady_clock::now();

    quicksort(tablica, 0, n-1);

    auto end = std::chrono::steady_clock::now();

    for(int i=0; i<n; i++)
    {
        std::cout << tablica[i] << std::endl;
    }

    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;

    return 0;
}