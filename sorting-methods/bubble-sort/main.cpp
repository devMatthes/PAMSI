#include <iostream>
#include <chrono>

void bubble_sort(int *tab, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(tab[j] < tab[j-1])
            {
                int temp;
                temp = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = temp;
            }
        }
    }
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

    bubble_sort(tablica, n);

    auto end = std::chrono::steady_clock::now();

    for(int i=0; i<n; i++)
    {
        std::cout << tablica[i] << std::endl;
    }

    std::cout << "Czas w sekundach: " << std::chrono::duration_cast<std::chrono::seconds>(end-start).count() << std::endl;

    return 0;
}