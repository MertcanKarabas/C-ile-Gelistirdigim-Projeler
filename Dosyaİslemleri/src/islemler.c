#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "islemler.h"

/*
* @file islemler.c
* @description Bütün yapılan işlemler, sayı toplama, basamak bulma, ve geri kalan her şey.
* @assignment Proje 2
* @date 23/01/2022
* @author Mertcan KARABAŞ - mertcan.karabas@stu.fsm.edu.tr 
*/

int sayiToplamaBuyukSayiBulma(int *sayi1, int *sayi2, int *sonuc, int sayi1boyut, int sayi2boyut) {
    //Hangi array daha büyükse onu 1. array yapıyoruz.
    if (sayi1boyut >= sayi2boyut)
        return sayiToplama(sayi1, sayi2, sonuc, sayi1boyut, sayi2boyut);    
    else
        return sayiToplama(sayi2, sayi1, sonuc, sayi2boyut, sayi1boyut);
}

int sayiToplama(int *sayi1, int *sayi2, int *sonuc, int sayi1boyut, int sayi2boyut) {
    
    int *toplam[sayi1boyut]; 
    
    int i = sayi1boyut - 1, j = sayi2boyut - 1, k = sayi1boyut - 1;
     
    int elde = 0, s = 0;

    while (j >= 0) {
        
        s = *(sayi1 + i) + *(sayi2 + j) + elde;            
        *(toplam + k) = (s % 10);
        elde = s / 10;
     
        k--;
        i--;
        j--;
    }

    while (i >= 0) {
        
        s = *(sayi1 + i) + elde;
        *(toplam + k) = (s % 10);
        elde = s / 10;
     
        i--;
        k--;
    }
    for (int i = 0; i < sayi1boyut; i++) {
        *(sonuc + i) = *(toplam + i);
    }

    return toplam;
}

long int sayiBoyutu(char fileName[])
{
    FILE *dosya = fopen(fileName, "r");
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
    } 
    char karakter;
    long int sayac = 0;
    karakter = getc(dosya);
    while (karakter != EOF) {
        if (karakter != '\n') {
                        
            karakter = getc(dosya);
            sayac++;
        }else {
            karakter = getc(dosya);
            continue;
        }
                    
    }
    
    fclose(dosya);

    return sayac;
}

int *arrayOlustur(int boyut)
{

    int *sayi;
    sayi = (int *)malloc(boyut * sizeof(int));

    return sayi;
}

void islemler()
{
    FILE *dosya1, *dosya2, *dosya3, *dosya4;
    bool islem = true;
    char secim, karakter1, karakter2;
    bool kontrol1 = 0, kontrol2 = 0 , *ctrl1, *ctrl2;
    ctrl1 = &kontrol1;
    ctrl2 = &kontrol2;
    int *ptr1, *ptr2, *ptr3, *sayi1, *sayi2, *sonuc;    
    long int sayi1Boyut = sayiBoyutu("sayi11.txt");
    long int sayi2Boyut = sayiBoyutu("sayi22.txt");
    sayi1 = arrayOlustur(sayi1Boyut);
    sayi2 = arrayOlustur(sayi2Boyut);
    if (sayi1Boyut >= sayi2Boyut) {
        sonuc = arrayOlustur(sayi1Boyut);
    } else {
        sonuc = arrayOlustur(sayi2Boyut);
    }
    
    
    char csayi1[sayi1Boyut];
    char csayi2[sayi2Boyut];

    printf("---------------Buyuk Sayilar Ile Matematiksel Islemler---------------\n");
    while (islem) {

        printf("[1]-> Dosyadan sayilari oku: (1)\n");
        printf("[2]-> Okunan sayilari ekrana yaz: (2)\n");
        printf("[+/-]-> Islem seciniz: (+ veya -)\n");
        printf("[4]-> Sonucu ekrana yazdir: (4)\n");
        printf("[5]-> Cikis : (5)\n");
        gets(&secim);

        switch (secim) {

        case '1': //Dosyadan sayilari oku
            *ctrl1 = 1;
            dosya1 = fopen("sayi11.txt", "r");
            dosya2 = fopen("sayi22.txt", "r");
            if (dosya1 != NULL) {
                int i = 0;
                karakter1 = getc(dosya1);

                while (karakter1 != EOF)
                {
                    if (karakter1 != '\n')
                    {
                        csayi1[i] = karakter1;
                        *(sayi1 + i) = csayi1[i] - '0';
                        karakter1 = getc(dosya1);
                        i++;
                    }else {
                        karakter1 = getc(dosya1);
                        continue;
                    }
                    
                }
                fclose(dosya1);
            } else {
                printf("Dosya bulunamadi!\n");
            }

            if (dosya2 != NULL) {
                int j = 0;
                karakter2 = getc(dosya2);

                while (karakter2 != EOF) {
                    if (karakter2 != '\n') 
                    {
                        csayi2[j] = karakter2;
                        *(sayi2 + j) = csayi2[j] - '0';
                        karakter2 = getc(dosya2);
                        j++;
                    }else {
                        karakter2 = getc(dosya2);
                        continue;
                    }   
                }
                fclose(dosya2);
            } else {
                printf("Dosya bulunamadi!\n");
            }
            
            printf("Dosyadan sayilar basariyla okundu.\n");
            fclose(dosya1);
            fclose(dosya2);

            break;

        case '2': //Okunan sayilari ekrana yaz:
            
            dosya1 = fopen("sayi11.txt", "r");
            dosya2 = fopen("sayi22.txt", "r");
            if (*ctrl1 != 1) {
                printf("Once sayilari dosyadan okumalisiniz.\n");
            } else {
                if (dosya1 != NULL && dosya2 != NULL) { 
                    printf("1. Sayi: \n");
                    for (int i = 0; i < sayi1Boyut; i++)
                    {
                        printf("%d", *(sayi1 + i));
                    }
                    printf("\n2.Sayi: \n");
                    for (int i = 0; i < sayi2Boyut; i++)
                    {
                        printf("%d", *(sayi2 + i));
                    }
                    printf("\n");
                    fclose(dosya1);
                    fclose(dosya2);
                }
                else {
                    printf("Dosya bulunamadi!\n");
                }
            }
            break;

        case '+': //iki sayıyı topla
            dosya3 = fopen("sonuclar.txt", "a");
            if (*ctrl1 != 1) {
                printf("Once sayilari dosyadan okumalisiniz.\n");
            } else {
                *ctrl2 = 1;
                sayiToplamaBuyukSayiBulma(sayi1, sayi2, sonuc, sayi1Boyut, sayi2Boyut);
                if (dosya3 == NULL) {
                    printf("Dosya bulunamadi.\n");
                }              
                fprintf(dosya3, "Toplama sonucu: ");
                for (int i = 0; i < sayi1Boyut; i++) {
                    fprintf(dosya3, "%d", *(sonuc + i));
                }
                fprintf(dosya3, "\n\n");
                fclose(dosya3);
                printf("Basariyla iki sayi toplandi ve dosyaya yazildi.\n");
            }
            

            break;

        case '-': //iki sayıyı birbirinden çıkar

            if (*ctrl1 != 1) {
                printf("Once sayilari dosyadan okumalisiniz.\n");
            } else {
                *ctrl2 = 1;
                
                if (dosya1 != NULL && dosya2 != NULL && dosya3 != NULL) {

                    fclose(dosya1);
                    fclose(dosya2);
                    fclose(dosya3);
                } else {
                    printf("Dosya bulunamadi!\n");
                }
            }
            
            break;

        case '4': //sonucu ekrana yazdır
            if (*ctrl1 != 1 || *ctrl2 != 1) {
                printf("Once sayilari dosyadan okumalisiniz. Eger okuma yaptiysaniz toplama ve cikarma yapmalisiniz.\n");
            } else {
                for (int i = 0; i < sayi1Boyut; i++) {
                    printf("%d", *(sonuc + i));
                }
                printf("\n");
            }
            break;

        case '5':
            free(sayi1);
            free(sayi2);
            free(sonuc);
            printf("Islemler bitti hoscakalin!\n");
            islem = false;
            break;

        default:

            printf("Yanlis islem yaptiniz tekrar deneyiniz!\n");
            break;
        }
    }
}