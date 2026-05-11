#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void yazdir(int adet, ...)//girdiğimiz sayı değerlerini yazdıracak bir fonksiyon oluşturduk. !!! "..." koymayı unutmayınız.
{
    va_list liste; // burada listenin ilk değişkenini tutacak olan ADRESİ isimlendirdik. İsmi "liste", şu anda çöp bir değer tutuyor.
    va_start(liste, adet); // bu adresin nereyi tutmasını istediğimizi belirtiyoruz. burdada "adet" değişkeninden sonraki ilk elemanın adresini tutmasını istedik.
                            
    printf("liste adresi baslatildi, gosterdigi deger: %d \n", *liste);// adetten sonraki girdiğimiz ilk değişke "1". bu yüzden buranın çıktısı 1 olacaktır.
    //--------SENARYO 1---------------//
    for(int i = 0; i < adet; i++)
    {
        //printf("%d", va_arg(liste, int)); // "va_arg(liste, int)" bir nevi döngü gibidir. pointer notlarında adreslere 1 ekleyip sonraki elemana geçtiğimizdeki gibi-
        // va_arg fonksiyonu da her çalıştığında liste adresini 1(4 byte kaydırır çünkü int diye belirttik) kaydırır ve listeye atar. 
        printf("va_arg %d kez calisti ve liste adresinin gosterdigi deger: %d\n", i, *liste);
        va_arg(liste, int); //listeyi verir(verilecek bir yer yok şuan) sonra arttırır.
    }
    va_end(liste);//listeyi sonlandırmazsak liste adresi başka bir şeyi göstereceğinden sonraki senaryoda çöp değerlerle kaşılaşırız.
    printf("\n");
    //---------SENARYO 2-------------//
    liste; 
    va_start(liste, adet);
    for(int j = 0; j < adet; j++)//va_argı ilk kullanıp listeyi yazdırırsak?
    {
        va_arg(liste, int); 
        printf("va_arg %d kez calisti ve liste adresinin gosterdigi deger: %d\n", j, *liste);
    }
    va_end(liste);
    printf("\n");
    //----------SENARYO 3-----------//
    liste; 
    va_start(liste, adet);
    for(int k = 0; k < adet; k++)//printf teki va_arg işlem sıralamasını açıklamak için bu döngüyü kurdum: va_arg ++i; şeklinde çalışsaydı burada ilk göreceğimiz değer 3 olurdu. i++ mantığında oldu-
    // için bize ilk 1in adresini verip sonra kaydırdığı için fazla kaydırma yapmıyor.
    {
        printf("%d ", va_arg(liste, int));//listeyi printf e verir, sonra arttırır.
    }
    va_end(liste);
    printf("\n\n");



    printf("liste adresinin gosterdigi son deger(cop deger): %d\n", *liste);//va_argın listeyi değiştirdiği gösterilir.

    va_end(liste);
}

int main() 
{
    yazdir(4, 1, 3, 4, 1);//ilk eleman adeti tanımlar. diğerleri ...'ya aittir.
}


//sevgilerle ömer..