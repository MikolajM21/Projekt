/** @file */
/*
PROGRAMOWANIE KOMPUTEROW
Projekt: Walidacja i ekstrakcja danych z nr PESEL.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include <cstring>
#include <cstdio>
#include "struktury.h"

bool menu(int& x)
{
    while (x != 0 && x != 1)
    {
        printf("\nAby wprowadziæ nr PESEL wpisz 1, jeœli chcesz wyjœæ z programu wpisz 0: ");
        scanf("%d", &x);
        if (x != 0 && x != 1)  printf("\nB³¹d! Spróbuj ponownie.\n");
    }
    system("cls");
    if (x == 1) return true;
    else return 0;
}
char kopiaTymczasowa(char* tab, char* tab2)
{
    for (int i = 0; i < 11; i++)
    {
        tab2[i] = tab[i];
    }
    tab2[11] = '\0';
    return *tab2;
}
void zaladujDane(listaOsob** pHead)
{
    FILE* plik;
    if ((plik = fopen("dane.txt", "r")) != NULL) {
        while (!feof(plik)) {
            char* pesel2 = (char*)malloc(12 * sizeof(pesel2));
            char* imie2 = (char*)malloc(20 * sizeof(imie2));
            char* nazwisko2 = (char*)malloc(50 * sizeof(nazwisko2));
            if (fscanf(plik, "%s", pesel2));
            if (fscanf(plik, "%s", imie2));
            if (fscanf(plik, "%s", nazwisko2));
            listaOsob* nowy = (listaOsob*)malloc(sizeof(listaOsob));
            nowy->pesel = pesel2;
            nowy->imie = imie2;
            nowy->nazwisko = nazwisko2;
            nowy->next = (*pHead);
            *pHead = nowy;
        }
        fclose(plik);
    }
}
char korektaAscii(char* tab)
{
    for (int i = 0; i < 11; i++)
    {
        tab[i] = tab[i] - 48;
    }
    return *tab;
}
bool walidacja(char* tab)
{
    int w = (tab[0] * 9 + tab[1] * 7 + tab[2] * 3 + tab[3] + tab[4] * 9 + tab[5] * 7 + tab[6] * 3 + tab[7] + tab[8] * 9 + tab[9] * 7);
    if ((w%10) == tab[10]) return true;
    else return false;
}
void porownaj(listaOsob** pHead, char* tab2, historia** glowa)
{
    int czyZnalezione = 0;
    listaOsob* tmp = *pHead;
    historia* pom = *glowa;
    if (pHead == NULL) printf("\nB³¹d!\n\n");
    historia* nowe = (historia*)malloc(sizeof(historia));
    while (tmp != NULL)
    {
        if (strcmp(tmp->pesel, tab2) == 0)
        {
            printf("\n PESEL: %s\n Imiê: %s\n Nazwisko: %s\n", tmp->pesel, tmp->imie, tmp->nazwisko);

            nowe->peselH = tmp->pesel;
            nowe->imieH = tmp->imie;
            nowe->nazwiskoH = tmp->nazwisko;
            nowe->next = (*glowa);
            *glowa = nowe;
            czyZnalezione = 1;
            tmp = NULL;
        }
        else tmp = tmp->next;
    }
    if (czyZnalezione == 0) printf("\nBrak podanego nr PESEL w bazie!\n");
}
void jakaPlec(char* tab)
{
    if ((tab[9] % 2) == 0) printf(" P³eæ: Kobieta");
    else printf(" P³eæ: Mê¿czyzna");
}
void dataUrodzenia(char* tab)
{
    int rok, miesiac, dzien;
    rok = tab[0] * 10 + tab[1];
    miesiac = tab[2] * 10 + tab[3];
    if (miesiac > 80 && miesiac < 93)
    {
        rok = 1800 + rok;
        miesiac = miesiac - 80;
    }
    else if (miesiac > 0 && miesiac < 13)
    {
        rok = 1900 + rok;
    }
    else if (miesiac > 20 && miesiac < 33)
    {
        rok = 2000 + rok;
        miesiac = miesiac - 20;
    }
    else if (miesiac > 40 && miesiac < 53)
    {
        rok = 2100 + rok;
        miesiac = miesiac - 40;
    }
    else if (miesiac > 60 && miesiac < 73)
    {
        rok = 2200 + rok;
        miesiac = miesiac - 60;
    }
    printf("\n Rocznik: %d", rok);
    dzien = tab[4] * 10 + tab[5];
    if (miesiac < 10)     printf("\n Data urodzenia: %d.0%d.%d", dzien, miesiac, rok);
    else     printf("\n Data urodzenia: %d.%d.%d", dzien, miesiac, rok);

}
void nrSerii(char* tab)
{
    int seria = tab[6] * 1000 + tab[7] * 100 + tab[8] * 10 + tab[9];
    printf("\n Numer serii: %d\n", seria);
}
void wypisz_historie(historia** glowa)
{

    historia* wsk = *glowa;

    if (glowa == NULL) printf("LISTA JEST PUSTA");

    int i = 1;
    while (wsk != NULL)
    {
        printf("%d %s %s %s\n", i, wsk->peselH, wsk->imieH, wsk->nazwiskoH);
        wsk = wsk->next;
        i++;
    }
}
void zapisz_historie(historia** glowa)
{
    FILE* plikH;
    historia* ptr = *glowa;
    int i = 1;
    if ((plikH = fopen("historia.txt", "w")) != NULL)
    {
        while (ptr != NULL)
        {
            fprintf(plikH, "%d.  %s %s %s\n", i, ptr->peselH, ptr->imieH, ptr->nazwiskoH);
            ptr = ptr->next;
            i++;
        }
        fclose(plikH);
    }
    else
    {
        printf("\nB³¹d zapisu do pliku historii!\n");
        wypisz_historie(glowa);
    }
}
void usun(listaOsob* wskaznik)
{

    listaOsob* pom = wskaznik;
    listaOsob* next = nullptr;

    while (nullptr != pom)
    {
        next = pom->next;
        free(pom);
        pom = next;
    }
}
void usunH(historia* wskaznikH)
{

    historia* pomH = wskaznikH;
    historia* next = nullptr;

    while (nullptr != pomH)
    {
        next = pomH->next;
        free(pomH);
        pomH = next;
    }
}
