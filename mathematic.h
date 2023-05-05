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
int rev_int(int sayi);                  
int pow_int(int sayi, int us);
//-----------------------------------------------------------------------------------------




// sayinin kac basamakli oldugunu hesapla
// bagimliliklar: pow_int()
int basamak_sayisi(int sayi) {
    int basamak = 1;

    while (1) {
        if (sayi < pow_int(10, basamak)) {
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




// check if num is a lasa number
int is_lasa_num(int num) {

    // exection
    if (num <10)
        return 0;

    int reverse = rev_int(num);

    if (is_prime(num) && is_prime(reverse))
        return 1;
    return 0;
}




// sayi asal mi kontrol et
int is_prime(int sayi) {
    if (sayi < 2)
        return 0;

    int bolen_sayisi = 0;
    for (int i = 2; i < sayi; i++) {
        if (sayi % i == 0)
            bolen_sayisi++;
    }

    if (bolen_sayisi == 0)
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




// reverse integer
int rev_int(int num) {
    int result = 0;
    while (num != 0) {
        result = result * 10 + result % 10;
        result = result / 10;
    }
    return result;
}




// evaluate exponential numbers
// power must be int
int pow_int(int num, int power) {
    // exception
    if (num == 0)
        return 0;

    // general calculations
    int result = 1;
    for (int i = 0; i< power;i++) {
        result *= num;
    }
    return result;
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
       return 1 * pow_int(10, us);
   }
   else {
       binary += decimal_to_binary(sayi / 2, us + 1);

       binary += kalan * pow_int(10, us);

   }
    return binary;
}
