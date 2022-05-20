#ifndef MATRISOPERATIONS_H_  
#define MATRISOPERATIONS_H_

/*
* @file main.c
* @description Matrisoperations.c dosyasında bulunan dosyaların headerları bulunuyor.
* @assignment Proje 1
* @date 06/12/2021
* @author Mertcan KARABAŞ - mertcan.karabas@stu.fsm.edu.tr 
*/

void myPrint(int **matris, int matrisLength);
int **operasyon1(int **matris1, int **matris2, int islemTipi, int matris1Length, int matris2Length);
void rastgeleMatrisiDoldurma(int **matris, int satir, int sutun, int seed);
int **matrisOlustur(int satir, int sutun);

#endif