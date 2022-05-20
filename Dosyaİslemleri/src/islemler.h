#ifndef ISLEMLER_H_  
#define ISLEMLER_H_ 

/*
* @file islemler.h
* @description islemler.c dosyasında bulunan dosyaların headerları bulunuyor.
* @assignment Proje 2
* @date 23/01/2022
* @author Mertcan KARABAŞ - mertcan.karabas@stu.fsm.edu.tr 
*/

int *arrayOlustur(int boyut);
long int sayiBoyutu(char fileName[]);
int sayiToplama(int *sayi1, int *sayi2, int *sonuc, int sayi1boyut, int sayi2boyut);
int sayiToplamaBuyukSayiBulma(int *sayi1, int *sayi2, int *sonuc, int sayi1boyut, int sayi2boyut);
void islemler();

#endif