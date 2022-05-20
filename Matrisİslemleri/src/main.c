#include <stdio.h>
#include <stdlib.h>
#include "matrisoperations.h"

/*
* @file main.c
* @description Ana kaynak dosyamız. Kütüphanede yazdığımız kodları çağırıyoruz.
* @assignment Proje 1 
* @date 06/12/2021
* @author Mertcan KARABAŞ - mertcan.karabas@stu.fsm.edu.tr 
*/

int main(int argc, char *argv[])
{
    int islemTipi, matris1Length, matris2Length, seed;

    if(argc < 5 || argc > 5 )  
        printf("Lutfen 5 parametre giriniz.");

    if(argc == 5) {
        
        matris1Length = atoi(argv[1]);
        matris2Length = atoi(argv[2]);
        islemTipi = atoi(argv[3]);
        seed = atoi(argv[4]) ; 
    
    
        int **matris1 = matrisOlustur(matris1Length, matris1Length);
        rastgeleMatrisiDoldurma(matris1, matris1Length, matris1Length, seed);
        int **matris2 = matrisOlustur(matris2Length, matris2Length);
        rastgeleMatrisiDoldurma(matris2, matris2Length, matris2Length, seed);

        printf("\t********   Matris-1    ********\n");
        myPrint(matris1, matris1Length);
        printf("\n\t********   Matris-2    ********\n");
        myPrint(matris2, matris2Length);
        printf("\t******** Sonuc Matrisi ********\n");
        operasyon1(matris1, matris2, islemTipi, matris1Length, matris2Length);
        free(matris1);
        free(matris2);
    }

    return 0;
}