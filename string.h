
//---------------------------------------FUNCTIONS----------------------------------------

void str_copy(char a[], char b[]);                                // copy b to a, a = b
int contains(char *str, char karakter);
int str_len(char a[]);
int str_equals(char a[], char  b[]);                              //
char *str_merge(char *str, char *a, char *b);                     // str = a + b
//-----------------------------------------------------------------------------------------




// karakter string icinde var mi kontol et
int contains(char *str, char karakter) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == karakter)
            return 1;
        i++;
    }
    return  0;
}




// copy b to a
void str_copy(char a[], char b[]) {
    int i = str_len(b) ;
    a[i] = '\0';
    i--;
    while(i >= 0) {
        a[i] = b[i];
        i--;
    }
}




// iki stringin esitligini kontol eder
int str_equals(char a[], char  b[] ) {
    int i=0;

    while (1) {
        if (a[i] != '\0' || b[i] != '\0') {        // en az bir tanesi icin sona ulasılmamıs

            if (a[i] == '\0' || b[i] == '\0')      // en az bir tanesi icin sona ulasilmis
                return 0;
            else if (a[i] != b[i])
                return 0;
        }
        else
            return 1;

        i++;
    }
}




// string length
int str_len(char a[] ) {
    unsigned int i = 0;

    while (1) {
        if (a[i] == '\0')
            return i ;
        i++;
    }
}




char *str_merge(char *str, char *a, char *b) {
    unsigned int i = 0;
    unsigned int len = 0;

    while (a[i] != '\0')
        str[len++] = a[i++];

    i = 0;
    while (b[i] != '\0')
        str[len++] = b[i++];

    str[len] = '\0';

    return str;
}
