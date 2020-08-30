#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struktury.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef FUNKCJE_H
#define FUNKCJE_H

/** Menu programu
@param x zmienna pomocnicza
*/
bool menu(int& x);
/** Funkcja tworzy kopie wprowadzonego nr PESEL
@param tab wprowadzony nr PESEL
@param tab2 kopia zmiennej tab
*/
char kopiaTymczasowa(char* tab, char* tab2);
/** Funkcja pobiera dane z pliku txt do listy osob
@param pHead adres listy
*/
void zaladujDane(listaOsob** pHead);
/** Funkcja, ktora zmienia format nr PESEL
@param tab wprowadzony nr PESEL
*/
char korektaAscii(char* tab);
/** Funkcja sprawdzajaca poprawnosc wprowadzonego nr PESEL
@param tab wprowadzony nr PESEL
*/
bool walidacja(char* tab);
/** Funkcja porownujaca wprowadzony nr PESEL z numerami w bazie, zapisuje historie wyszukiwan do osobnej listy
@param pHead adres listy osob
@param tab2 kopia wprowadzonego nr PESEL
@param glowa adres listy historii
*/
void porownaj(listaOsob** pHead, char* tab2, historia** glowa);
/** Funkcja odczytuje plec z nr PESEL
@param tab wprowadzony nr PESEL
*/
void jakaPlec(char* tab);
/** Funkcja odczytuje i wypisuje rocznik oraz pelna date urodzenia
@param tab wprowadzony nr PESEL
*/
void dataUrodzenia(char* tab);
/** Funkcja odczytuje i wypisuje nr serii
@param tab wprowadzony nr PESEL
*/
void nrSerii(char* tab);
/** Funkcja wypisuje historie na ekranie w przypadku niepowodzenia zapisania jej do pliku txt
@param glowa adres listy
*/
void wypisz_historie(historia** glowa);
/** Funkcja zapisuje historie do pliku .txt
@param glowa adres listy
*/
void zapisz_historie(historia** glowa);
/** Funkcja usuwa liste osob
@param nowy_element wskaznik na liste
*/
void usun(listaOsob* wskaznik);
/** Funkcja usuwa liste historii
@param nowy_element wskaznik na liste historii
*/
void usunH(historia* wskaznikH);
#endif