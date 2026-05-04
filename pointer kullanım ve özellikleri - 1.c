
#include <stdio.h>
#include <limits.h> /*    */
#include <float.h> /*    */
#include <math.h>


int main()
{
    int sayi = 5; 
    int* adres;
    printf("cop adres: %p \n", adres);
    adres = &sayi; // neden "&sayi" yerine direkt "&5" yazamıyoruz? çünkü & değişkenler için kullanılabilir.
    printf("atanmis adres: %p \n", adres);
    printf("adrese (pointer adresi olan adres degiskeninin) '*' koymamiz ile elimize gelen deger: %d \n", *adres);
    printf("simdi adres tutan degiskene '&' koyarsak ne olur? cikti: %p \n", &adres); // deneme 1
    printf("peki adres tutan degiskene '*' koyarsak ne olur cikti: %d \n", *adres); // deneme 2
    printf("simdi ise koda soyle yazsak '... , *&*adres);' cikti soyle olur: %d", *&*adres); // kod çalıştırıldığında anlaşılacağı üzere *& bize değeri verirken &* bize adresi tutan adresin adresini verir... 


    //made with love by Omer...



}