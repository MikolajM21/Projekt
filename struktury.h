/** @file */
#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/** struktura listy jednokierunkowej - przechowuje dane zaladowane z pliku txt */
typedef struct listaOsob
{
    char* pesel;    ///< nr PESEL przechowywany w liscie
    char* imie;     ///< napis przechowywany w liscie (imie)
    char* nazwisko; ///< napis przechowywany w liscie (nazwisko)
    struct listaOsob* next; ///< adres nastepnego elementu w liscie

} listaOsob;

/** struktura listy jednokierunkowej - przechowuje dane wyszukiwanych osob */
typedef struct historia
{
    char* peselH; ///< nr PESEL przechowywany w liscie historii
    char* imieH;    ///< napis przechowywany w liscie historii (imie)
    char* nazwiskoH;    ///< napis przechowywany w liscie historii (nazwisko)
    struct historia* next; ///< adres nastepnego elementu w liscie
}historia;

