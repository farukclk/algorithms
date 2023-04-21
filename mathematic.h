#include <time.h>    // get_random()
#include <stdlib.h>  // get_random()


//---------------------------------------FUNCTIONS----------------------------------------

int basamak_sayisi(int sayi);              // sayinin basamak sayisi
int bolen_derecesi(int sayi, int bolen);
int decimal_to_binary(int sayi, int us);
int get_random(int min, int max);          // generate random int between 2 number
int is_harshad_num(int sayi);
int is_lasa_num(int sayi);
int is_prime(int sayi);                    // check num if num is prime
int is_tau_num(int sayi);
int ters_cevir(int sayi);                  
int uslu_sayi(int sayi, int us);
//-----------------------------------------------------------------------------------------




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
int get_random(int lower, int upper) {
    srand(time(NULL));    //<time.h>
    return (rand() % (upper - lower + 1)) + lower;  //<stdlib.h>,
}




// sayi lasa sayisi mi kontrol et
int is_lasa_num(int sayi) {

    // istisnalar
    if (sayi <10)
        return 0;

    int ters = rev_int(sayi, basamak_sayisi(sayi)-1);

    if (is_prime(sayi) && is_prime(ters))
        return 1;
    return 0;
}




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




// sayi tau sayisi mi kontrol et
//bagimliliklar: bolen_derecesi()
int is_tau_num(int sayi) {

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
int is_harshad_num(int sayi) {
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




// sayiyi ters cevir
int ters_cevir(int sayi) {
    int sonuc = 0;
    while (sayi != 0) {
        sonuc = sonuc * 10 + sayi % 10;
        sayi = sayi / 10;
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




// us = 0
int decimal_to_binary(int sayi, int us ) {
   int binary = 0;

   if (sayi == 0) {
       return 0;
   }

   int kalan = sayi % 2;
   int bolum = sayi / 2;

   if (bolum == 0 && kalan == 1) {
       return 1 * uslu_sayi(10, us);
   }
   else {
       binary += ikilik_sayi(sayi / 2, us + 1);

       binary += kalan * uslu_sayi(10, us);

   }
    return binary;
}
