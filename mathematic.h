#include <time.h>
#include <stdlib.h>


int is_prime(int num);                   // check num if num is prime
int basamak_sayisi(int sayi);            // sayinin basamak sayisi
int bolen_derecesi(int sayi, int bolen);
int uslu_sayi(int sayi, int us);
int getRandom(int min, int max);         // generate random int between 2 number
int harshadSayisi(int sayi);



// sayi asal mi kontrol et
int is_prime(int sayi) {
    if (sayi < 2)
        return 0;

    int bolen_Sayisi = 0;
    for (int i = 2; i <= sayi; i++) {
        if (sayi % i == 0)
            bolen_Sayisi++;
    }

    if (bolen_Sayisi == 1)
        return 1;
    return 0;

}




// sayinin kac basamakli oldugunu hesapla
// bagimliliklar: uslu_sayi()
int basamak_sayisi(int sayi) {
    int basamak = 1;

    while (1) {
        if (sayi < uslu_sayi(10, basamak)) {
            break;
        }
        basamak++;
    }

    return basamak;
}



// bolen, sayiyi kac kez tam bolebilir
// bolen_derecesi(8,2) = 3,  bolen_derecesi(50,5) = 2
int bolen_derecesi(int sayi, int  bolen) {
    int us = 0;
    while (sayi % bolen == 0) {
        us++;
        sayi /= bolen;
    }
    return us;
}




// return random random integer between 2 number
// dependents: <stdlib.h>, <time.h>
int  getRandom(int lower, int upper) {
    srand(time(NULL));    //<time.h>
    return (rand() % (upper - lower + 1)) + lower;  //<stdlib.h>,
}







// sayiyi ters cevir
// ters_sayi(1234, basamak_sayisi(1234) - 1 ) = 4321
//fonksiyonu cagirirken "derece = basamak_sayisi(sayi) - 1" olmali
// bagimliliklar: basamak_sayisi()
int ters_sayi(int sayi, int derece) {

    int sonuc = 0 ;

    if (sayi < 10) {
        sonuc += sayi ;
    }
    else {

        sonuc += (sayi % 10) * uslu_sayi(10, derece);
        sonuc += ters_sayi(sayi / 10, derece - 1);
    }

    return sonuc;

}




// ustlu sayi hesapla
int uslu_sayi(int sayi, int us) {
    //istisnalar
    if (sayi == 0)
        return 0;

    // genel işlem
    int sonuc = 1;
    for (int i = 0; i< us;i++) {
        sonuc *= sayi;
    }
    return sonuc;
}




// sayi lasa sayisi mi kontrol et
int lasa_sayisi(int sayi) {

    // istisnalar
    if (sayi <10)
        return 0;

    int ters = ters_sayi(sayi, basamak_sayisi(sayi)-1);

    if (is_prime(sayi) && is_prime(ters))
        return 1;
    return 0;
}




// sayi tau sayisi mi kontrol et
//bagimliliklar: bolen_derecesi()
int tau_sayisi(int sayi) {

    int sonuc = 1;
    int carpan = sayi;
    int sayi2 = sayi;
    while (sayi != 1) {
        if (is_prime(carpan) && sayi % carpan == 0) {

            sonuc *= ( bolen_derecesi(sayi, carpan) + 1);

            while (sayi % carpan == 0) {
                sayi /= carpan;
            }
        }

        carpan--;
    }

    if (sayi2 % sonuc == 0)
        return 1;
    return 0;
}



// return 1 == harsadSayisi, 0 = degil
int harshadSayisi(int sayi) {
    int sum = 0;
    int tmp = sayi;
    while(tmp != 0) {
        sum += tmp %10;
        tmp /=10;

    }

    if (sayi % sum == 0) {
        return 1;
    }

    return 0 ;

}


