/*
Meno a priezvisko:

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du02.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
     Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// ULOHA c.1 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na zaciatok zoznamu

    PRIKLADY:
        list={} a val=0 ... zoznam po vykonani funkcie ... {0}
        list={-3} a val=1 ... zoznam po vykonani funkcie ... {1,-3}
        list={6,6,6,8} a val=10 ... zoznam po vykonani funkcie ... {10,6,6,6,8}
*/

// pomocna funkcia na vytvorenie noveho uzla
Node* createNode(const int val) {
    Node *node = new Node;
    node->data = val;
    node->next = nullptr;
    return node;
}

void prependNode(List* list, const int val) {
    Node * newNode = createNode(val);
    newNode->next = list->first;
    list->first = newNode;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.2 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla pridaneho na koniec zoznamu

    PRIKLADY:
        list={} a val=7 ... zoznam po vykonani funkcie ... {7}
        list={0} a val=1 ... zoznam po vykonani funkcie ... {0,1}
        list={1,2,3,4,5} a val=6 ... zoznam po vykonani funkcie ... {1,2,3,4,5,6}
*/

void appendNode(List* list, const int val) {
    Node * newNode = createNode(val);

    if (!list->first) {
        list->first = newNode;
    } else {
        Node *node = list->first;
        while (node->next) {
            node = node->next;
        }
        node->next = newNode;
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.3 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),
    ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.

    PARAMETRE:
        [in] data - vstupne pole cisiel
        [in] n - dlzka vstupneho pola

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci vsetky hodnoty zo vstupneho pola 'data' (v zachovanom poradi).
        V pripade prazdneho pola (dlzka 0), funkcia vrati prazdny zoznam (prazdny zoznam je taky, kde smernik 'first'
        ukazuje na 'nullptr'). V pripade neplatnej dlzky (ak je parameter 'n' zaporny), funkcia vrati 'nullptr'.

    PRIKLADY:
        data={1} a n=1 ... vrati zoznam ... {1}
        data={7,6,41,2} a n=4 ... vrati zoznam ... {7,6,41,2}
        data={3,2,1} a n=0 ... vrati zoznam ... {}
        data={6,3,9,10} a n=-7 ... vrati ... 'nullptr'
*/

List* createListFromArray(const int* data, const int n) {
    // dynamica alloc without malloc -> int *data = new int[7] {2};
    if (n < 0) { return nullptr; }

    List *list = new List;
    list->first = nullptr;

    for (int i = n-1; i >= 0; i--) {
        prependNode(list, data[i]);
    }

    return list;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.4 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'. Symetricky zoznam ma
    tvar 0,1,2,...val...2,1,0.

    PARAMETRE:
        [in] val - hodnota uzla podla, ktoreho sa vytvori novy symetricky zretazeny zoznam (uzol v strede zoznamu).

    RETURN:
        Vytvoreny zretazeny zoznam obsahujuci prvky v takom poradi, aby bol symetricky. V pripade 'val'<0, funkcia vrati
        'nullptr'.

    PRIKLADY:
        val=-31 ... vrati ... nullptr
        val=0 ... vrati zoznam ... {0}
        val=1 ... vrati zoznam ... {0,1,0}
        val=2 ... vrati zoznam ... {0,1,2,1,0}
        val=3 ... vrati zoznam ... {0,1,2,3,2,1,0}
        val=4 ... vrati zoznam ... {0,1,2,3,4,3,2,1,0}
        val=6 ... vrati zoznam ... {0,1,2,3,4,5,6,5,4,3,2,1,0}
*/

List* createSymmetricList(const int val) {
    if (val < 0) { return nullptr; }

    List *list = new List;
    list->first = createNode(val);

    for (int i = val-1; i >= 0; i--) {
        prependNode(list, i);
        appendNode(list, i);
    }
    
    return list;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.5 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.

    PARAMETRE:
        [in,out] list - vstupny zretazeny zoznam

    RETURN:
        Result::SUCCESS, ak bol prvy uzol vymazany
        Result::FAILURE, ak nebol prvy uzol vymazany (vstupny zoznam bol prazdny)

    PRIKLADY:
        list={} ... funkcia vrati Result::FAILURE
        list={5} ... zoznam po vykonani funkcie ... {} a vrati Result::SUCCESS
        list={10,10,10} ... zoznam po vykonani funkcie ... {10,10} a vrati Result::SUCCESS
        list={3,2,1} ... zoznam po vykonani funkcie ... {2,1} a vrati Result::SUCCESS
*/

Result removeFirstNode(List* list) {
    if (list->first) {
        Node *nextFirst = list->first->next;
        delete list->first;
        list->first = nextFirst;
        return Result::SUCCESS;
    }
    return Result::FAILURE;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.6 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hodnota uzla, ktory sa hlada

    RETURN:
        Funkcia vrati prvy uzol, ktory obsahuje hodnotu 'val'. Ak sa taky uzol v zozname nenachadza alebo je vstupny
        zoznam prazdny, vtedy funkcia vrati 'nullptr'.

    PRIKLADY:
        list={}, val=10 ... funkcia vrati 'nullptr'
        list={2}, val=3 ... funkcia vrati 'nullptr'
        list={1,2,3,4,5,6}, val=-1 ... funkcia vrati 'nullptr'
        list={1}, val=1 ... funkcia vrati uzol s hodnotou 1
        list={5,9,18}, val=9 ... funkcia vrati uzol s hodnotou 9
*/

Node* findNodeInList(List* list, const int val) {
    Node * node = list->first;
    while (node) {
        if (node->data == val) {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.7 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
    rovnake hodnoty uzlov v rovnakom poradi).

    PARAMETRE:
        [in] list1 - prvy zretazeny zoznam
        [in] list2 - druhy zretazeny zoznam

    RETURN:
        'true' - ak su vstupne zoznamy rovnake
        'false' - ak vstupne zoznamy nie su rovnake

    PRIKLADY:
        list1={1}
        list2={}
        Funkcia vrati 'false'.

        list1={}
        list2={5,3}
        Funkcia vrati 'false'.

        list1={}
        list2={}
        Funkcia vrati 'true'.

        list1={1}
        list2={1}
        Funkcia vrati 'true'.

        list1={4,-9,2}
        list2={4,-9,2}
        Funkcia vrati 'true'.

        list1={3,2,1}
        list2={1,2,3}
        Funkcia vrati 'false'.

        list1={2}
        list2={7,4,5}
        Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
    
}

//-------------------------------------------------------------------------------------------------
// MAIN
//-------------------------------------------------------------------------------------------------
int main() {
    // testovaci kod (vymazat)
    List *list = new List;
    list->first = nullptr;
    appendNode(list, 5);
    appendNode(list, 4);
    cout << findNodeInList(list, 8)->data << endl;

    cout << "{";
    for (Node *head = list->first; head; head = head->next ) {
        cout << head->data << ", ";
    }
    cout << "}";
    // for (const int& e : arr) {
    //     std::cout << e << " ";
    // }
    return 0;
}