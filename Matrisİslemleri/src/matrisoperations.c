#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrisoperations.h"

/*
* @file main.c
* @description Matrisi oluşturma, doldurma, yazdırma ve ana fonksiyon bu dosyada bulunuyor.
* @assignment Proje 1
* @date 06/12/2021
* @author Mertcan KARABAŞ - mertcan.karabas@stu.fsm.edu.tr 
*/

int **matrisOlustur(int satir, int sutun) {

    int i, **matris;
    matris = (int **)malloc(satir * sizeof(int *));

    for (i = 0; i < satir; i++) 
        matris[i] = (int *)malloc(sutun * sizeof(int));  
    
    return matris;
}

void rastgeleMatrisiDoldurma(int **matris, int satir, int sutun, int seed) {

    int i, j;
    srand(seed);
    
    for (i = 0; i < satir; i++) 
        for (j = 0; j < sutun; j++)
            matris[i][j] = 1 + (rand() % 10); 
         
}

void myPrint(int **matris, int matrisLength) {

    int i, j;
    for (i = 0; i < matrisLength; i++) {
        for (j = 0; j < matrisLength; j++) {
            printf("%d\t", matris[i][j]);
        }
        printf("\n\n");
    }
}

int **operasyon1(int **matris1, int **matris2, int islemTipi, int matris1Length, int matris2Length) {

    int sonucMatrisiBoyutu = 0, dolguDegeri;

    if (islemTipi == 0) {
        
        dolguDegeri = 0;
        sonucMatrisiBoyutu = (matris1Length - matris2Length) + (2 * dolguDegeri) + 1;
        
        int **sonucMatrisi = matrisOlustur(sonucMatrisiBoyutu, sonucMatrisiBoyutu);
        int anaMatrisSatir, anaMatrisSutun, satir, sutun, ihtimalSayisi;
        int toplam = 0, matris2Sutun = 0, matris2Satir = 0; //2.matris satir ve sutununda donmek icin kullailan
        
        for (ihtimalSayisi = 0; ihtimalSayisi < sonucMatrisiBoyutu * sonucMatrisiBoyutu; ihtimalSayisi++) { //Çikti matrisindeki kutucuk sayisi yani ihtimalimiz.
            for (anaMatrisSatir = 0; anaMatrisSatir < sonucMatrisiBoyutu; anaMatrisSatir++) { //1.matris ustunde kaydirma işlemlerimizde kullandigimiz satir dongusu.
                for (anaMatrisSutun = 0; anaMatrisSutun < sonucMatrisiBoyutu; anaMatrisSutun++) { //1.matris ustunde kaydirma işlemlerimizde kullandigimiz sutun dongusu.
                    for (satir = anaMatrisSatir; satir < anaMatrisSatir + matris2Length; satir++) { //1.matris ustunde olan bolgemizde donme islemi yapmak icin kullandigimiz satir dongumuz.
                        for (sutun = anaMatrisSutun; sutun < anaMatrisSutun + matris2Length; sutun++) { //1.matris ustunde olan bolgemizde donme islemi yapmak icin kullandigimiz sutun dongumuz.

                            toplam += matris2[matris2Satir][matris2Sutun] * matris1[satir][sutun];
                            
                            if (matris2Sutun == matris2Length - 1) {
                                matris2Satir++;
                                matris2Sutun = 0;
                            } else {
                                matris2Sutun++;
                            }
                        }
                    }

                    sonucMatrisi[anaMatrisSatir][anaMatrisSutun] = toplam;
                    matris2Satir = 0;
                    matris2Sutun = 0;
                    toplam = 0;
                }
            }
        }

        myPrint(sonucMatrisi, sonucMatrisiBoyutu);
        free(sonucMatrisi);
        return sonucMatrisi;
   
    } else if (islemTipi == 1) {

        dolguDegeri = (matris2Length - 1) / 2;
        sonucMatrisiBoyutu = (matris1Length - matris2Length) + (2 * dolguDegeri) + 1;
        
        int **sonucMatrisi = matrisOlustur(sonucMatrisiBoyutu, sonucMatrisiBoyutu);
        int a = 0, b = 0, i, j; // a ve b girilen matris1 ustunde dolasmamii saglayan satir ve sutunların karsiliklari.
        int yeniMatris[matris1Length + 2][matris1Length + 2]; //Yeni matrisimizi olusturuyoruz ve icini dolduruyoruz.
        
        for (i = 0; i < matris1Length + 2; i++) {
            for (j = 0; j < matris1Length + 2; j++) {
                if (i == 0 || j == 0 || i == matris1Length + 2 - 1 || j == matris1Length + 2 - 1) {
                    yeniMatris[i][j] = 0;
                    if ((j == matris1Length + 2 - 1 && i != 0)) {
                        a++;
                        b = 0;
                    }
                
                } else {
                   
                    if (j == matris1Length + 2 - 1) {
                        a++;
                        b = 0;
                    } else {
                        yeniMatris[i][j] = matris1[a][b];
                        b++;
                    }
                }
            }
        }
        
        int anaMatrisSatir, anaMatrisSutun, satir, sutun, ihtimalSayisi;
        int toplam = 0, matris2Sutun = 0, matris2Satir = 0;
        
        for (ihtimalSayisi = 0; ihtimalSayisi < sonucMatrisiBoyutu * sonucMatrisiBoyutu; ihtimalSayisi++) {
            for (anaMatrisSatir = 0; anaMatrisSatir < sonucMatrisiBoyutu; anaMatrisSatir++) {
                
                if (anaMatrisSatir == matris1Length+2 - matris2Length + 1)  //Ana matrisin satirinde arrayin disina cikmamak icin kullanilan sart kosulu.
                    break; 
                
                for (anaMatrisSutun = 0; anaMatrisSutun < sonucMatrisiBoyutu; anaMatrisSutun++) {
                    
                    if (anaMatrisSutun == matris1Length+2 - matris2Length + 1) //Ana matrisin sutununda arrayin disina cikmamak icin kullanilan sart kosulu.  
                        break;
                                
                    for (satir = anaMatrisSatir; satir < anaMatrisSatir + matris2Length; satir++) {
                            for (sutun = anaMatrisSutun; sutun < anaMatrisSutun + matris2Length; sutun++) {

                                toplam += matris2[matris2Satir][matris2Sutun] * yeniMatris[satir][sutun];
                                if (matris2Sutun == matris2Length - 1) {
                                    matris2Satir++;
                                    matris2Sutun = 0;
                                } else {
                                    matris2Sutun++;
                                }
                            }
                        }

                        sonucMatrisi[anaMatrisSatir][anaMatrisSutun] = toplam;
                        matris2Satir = 0;
                        matris2Sutun = 0;
                        toplam = 0;
                    
                }
            }
        }

        myPrint(sonucMatrisi, sonucMatrisiBoyutu);
        free(sonucMatrisi);
        return sonucMatrisi;
   
    } else 
        printf("Islem tipi sadece 0 veya 1 olabilir.");
}