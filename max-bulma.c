#include <stdio.h>


int xbulma(int adet, int *diBasAd) //max değerini bulup döndüren fonksiyon.
{
    int* basit = diBasAd;
    int frmax;
    frmax = *basit;
    for(int i = 0; i < adet; i++)
    {

        if (frmax < *(basit + i))
        {
            frmax = *(basit + i);
            continue;
        } 
    }
    return frmax;   
}




int main()
{
    int ornekDizi[6] = {3, 4, 2, 7, 1, 6 };
    printf("'ornekDizi' dizinin maks dgeri: %d", xbulma(6, ornekDizi));
}