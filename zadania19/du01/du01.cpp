#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Vytlaci obsah pola na standardny vystup (cout/stdout).
    Format tlace:
    - prvky pola (cisla) su oddelene jednou medzerou
    - pred prvym prvkom je gulata otvaracia zatvorka (medzi zatvorkou a cislom nesmie byt medzera)
    - za poslednym prvkom je gulata zatvaracia zatvorka (medzi cislom a zatvorkou nesmie byt medzera)

    PARAMETRE:
        [in] data - pole cisiel
        [in] length - dlzka pola 'data'

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        prazdne pole: ()
        jednoprvkove pole: (10)
        10 prvkove pole: (8 -5 100000 2 1 2 4 5 -20 345)
*/

void printArray(const int * data, int length) {
    cout << "(";
    if (length > 0) {
        for (int i = 0; i < length-1; i++) {
        cout << data[i] << " ";
        }
        cout << data[length-1];
    }
    cout << ")";
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Zo standardneho vstupu nacita dve cele cisla (typu 'int') a vrati ich sucet.

    RETURN:
        sucet cisiel nacitanych zo standardneho vstupu (cin/stdin)

    VSTUPNE PODMIENKY:
        Textovy vstup zadany na standardny vstup programu obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov zadanych na standardny vstup.

    PRIKLADY:
        Ak je na standardny vstup zadany text "10 20\n" (bez uvodzoviek), tak funkcia vrati 30.
        Ak je na standardny vstup zadany text " 10 \n 20 \n" (bez uvodzoviek), tak funkcia vrati 30.
*/

int sumOfTwoNumbersFromConsole() {
    int a, b;
    cin >> a >> b;
    return a+b;
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'text' obsahuje velke pismeno, inak vrati 'false'.

    PARAMETER:
        [in] text - textovy retazec ukonceny '\0'

    RETURN:
        'true' - ak 'text' obsahuje aspon jedno velke pismeno
        'false' - ak 'text' neobsahuje ani jedno velke pismeno (plati aj pre prazdny retazec)

    POZNAMKA:
        Pri implementacii pouzite funkciu 'std::isupper'.
*/

bool containsUpperCase(const char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (isupper(text[i])) {
            return true;
        }
    }
    return false;
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Vrati 'true' ak 'data' obsahuje stupajucu postupnost, inak vrati 'false'.

    PARAMETRE:
        [in] data - pole hodnot
        [in] length - pocet prvkov pola 'data'

    RETURN:
        'true' - ak 'data' obsahuje stupajucu postupnost hodnot, alebo pocet prvkov pola je mensi ako 2
        'false' - v opacnom pripade

    PRIKLADY:
        data = {10, 11, 15, 20} => vysledok je 'true'
        data = {10, 15, 15, 20} => vysledok je 'false'
        data = {10, 11, 15, 12} => vysledok je 'false'
        data = {10}             => vysledok je 'true'
        data = {}               => vysledok je 'true'
*/

bool isAscending(const int *data, int length) {
    if (length <= 1) { return false; }
    for (int i = 0; i < length-1; i++) {
        if (!(data[i] < data[i+1])) {
            return false;
        }
    }
    return true;
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Posunie hodnoty pola 'data' o 1 miesto vyssie. Hodnotu posledneho prvku presunie na zaciatok.

    PARAMETRE:
        [in,out] data - pole hodnot, ktore bude preusporiadane
        [in] length - pocet prvkov pola 'data'

    PRIKLADY:
        {10, 20, 30, 40, 50} => {50, 10, 20, 30, 40}
        {10} => {10}
        {} => {}
*/

void shiftUp(int *data, int length) {
    int last = data[length-1];
    int tmp = data[1];
    for (int i = 0; i < length-1; i++) {
        data[i+1] = data[i];
        tmp = 
    }
    data[0] = last;
    //return data;
}

int main() {
    // testovaci kod (vymazat)
    int arr[5] = {10, 20, 30, 40, 50};
    shiftUp(arr, sizeof(arr)/sizeof(int));
    for (const int& e : arr) {
        std::cout << e << " ";
    }
    return 0;
}