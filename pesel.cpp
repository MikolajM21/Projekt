/** @file */

/*
PROGRAMOWANIE KOMPUTEROW
Projekt: Walidacja i ekstrakcja danych z nr PESEL.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"

int main()
{
    setlocale(LC_CTYPE, "Polish");
    listaOsob* pHead = nullptr;
    historia* glowa = nullptr;
    int n = 99;
    char* tab =(char*) malloc(n * sizeof(int)); // przechowuje wprowadzony PESEL
    char* tab2 = (char*)malloc(11 * sizeof(int)); //przechowuje wprowadzony PESEL w pierwotnym formacie
    int x = 2; //pomocnicza zmienna do menu
 
    while (menu(x))
    {
        x = 2;
        printf("\nWprowadź nr PESEL: ");
        scanf("%s", tab);
        kopiaTymczasowa(tab, tab2);
        zaladujDane(&pHead);
        korektaAscii(tab);
        if (walidacja(tab))
        {
            printf("\nNumer PESEL prawidłowy.\n");
            porownaj(&pHead, tab2,&glowa);
            jakaPlec(tab);
            dataUrodzenia(tab);
            nrSerii(tab);
            printf(" Cyfra kontrolna: %d\n", tab[10]);
        }
        else printf("\nBłąd! Podany numer PESEL jest nieprawidłowy!\n\n");

        menu(x);
    }

    zapisz_historie(&glowa);
    free(tab);
    free(tab2);
    usun(pHead);
    usunH(glowa);
    printf("\nMiłego dnia!\n");
    return 0;
}