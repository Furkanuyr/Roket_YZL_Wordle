#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define HAKLAR 4


const char *words3[] = {"cat", "dog", "sun", "bat", "pen", "run", "bus", "box"};
const char *words4[] = {"tree", "moon", "star", "fire", "blue", "wolf", "gold", "door"};
const char *words5[] = {"apple", "grape", "table", "chair", "house", "beach", "light", "stone"};
const char *words6[] = {"orange", "planet", "rocket", "guitar", "summer", "winter", "spring", "forest"};
const char *words7[] = {"teacher", "student", "subject", "library", "picture", "history", "science", "holiday"};

const char **kelimeListeleri[] = {words3, words4, words5, words6, words7};
int kelimeSayilari[] = {8, 8, 8, 8, 8}; 


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'İ' || str[i] == 'ı') {
            printf("UYARI: Buyuk I ve kucuk i harflerini kullanmayin!\n");
        }
        str[i] = tolower((unsigned char)str[i]);
    }
}


const char* kelimeSec(int uzunlugu) {
    int index = uzunlugu - 3;
    if (index < 0 || index > 4) return NULL;
    int rastgeleIndex = rand() % kelimeSayilari[index];
    return kelimeListeleri[index][rastgeleIndex];
}


void wordleOyna(int kelimeUzunlugu) {
    const char *seciliKelime = kelimeSec(kelimeUzunlugu);
    if (seciliKelime == NULL) {
        printf("Gecersiz kelime uzunlugu.\n");
        return;
    }

    char tahmin[20];
    printf("Wordle'a hos geldiniz! %d harfli kelimeyi tahmin edin. %d hakkiniz var.\n\n", kelimeUzunlugu, HAKLAR);

    for (int hak = 0; hak < HAKLAR; hak++) {
        printf("Deneme %d/%d: ", hak + 1, HAKLAR);
        scanf("%s", tahmin);

        
        toLowerCase(tahmin);

      
        if (strlen(tahmin) != kelimeUzunlugu) {
            printf("Hata: Kelime %d harf olmali.\n\n", kelimeUzunlugu);
            continue;
        }

      
        if (strcmp(tahmin, seciliKelime) == 0) {
            printf("Tebrikler! '%s' kelimesini dogru tahmin ettiniz!\n", seciliKelime);
            return;
        }

       
        int harfBulunduMu[26] = {0};

        for (int i = 0; i < kelimeUzunlugu; i++) {
            if (tahmin[i] == seciliKelime[i]) {
                printf("Harf '%c' var, kelimenin %d. harfi\n", tahmin[i], i + 1);
                harfBulunduMu[tahmin[i] - 'a'] = 1; 
            } else {
                for (int j = 0; j < kelimeUzunlugu; j++) {
                    if (tahmin[i] == seciliKelime[j] && i != j) {
                        printf("Harf '%c' var ama yanlis yerde\n", tahmin[i]);
                        harfBulunduMu[tahmin[i] - 'a'] = 1; 
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < kelimeUzunlugu; i++) {
            if (!harfBulunduMu[tahmin[i] - 'a']) {
                printf("Harf '%c' yok\n", tahmin[i]);
            }
        }

        printf("\n");
    }

    printf("Oyun Bitti! Dogru kelime '%s' idi.\n", seciliKelime);
}


int main() {
    srand(time(NULL));

    printf("UYARI!! Buyuk I ve kucuk i kullanmayin!\n");

    int kelimeUzunlugu;
    printf("Kelime uzunlugunu girin (3-7): ");
    scanf("%d", &kelimeUzunlugu);

    if (kelimeUzunlugu < 3 || kelimeUzunlugu > 7) {
        printf("Gecersiz kelime uzunlugu. Lutfen 3 ile 7 arasinda bir sayi girin.\n");
        return 1;
    }

    wordleOyna(kelimeUzunlugu);
    return 0;
}
