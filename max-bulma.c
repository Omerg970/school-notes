#include <stdio.h>


int xbulma(int adet, int *diBasAd) //max değerini bulup döndüren fonksiyon.
{
    int* basit = diBasAd; // ismi basitleştirdik
    int frmax; // dizinin sürekli referans alacağı nokta.
    frmax = *basit; // ilk karşılaşacağı yer ilk eleman olacağı için ilk onu referans alırız.
    for(int i = 0; i < adet; i++)// referans ile kendisinden bir sonraki elemanı karşılaştıran if bloğu.
    {

        if (frmax < *(basit + i))
        {
            frmax = *(basit + i);
        } 
    }
    return frmax; // maks değeri döndürür.  
}




int main()
{
    int ornekDizi[6] = {3, 4, 2, 7, 1, 6 };
    printf("'ornekDizi' dizinin maks dgeri: %d", xbulma(6, ornekDizi));
}
