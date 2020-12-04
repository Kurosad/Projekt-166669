#include <iostream>
#include<fstream>
#include <cstdlib>
#include<string>

using namespace std;
//Obsluga plikow

int w;//wielkosc tablic
int *taba; //Tablica A
int *tabb;//Tablica B
//a wlasciwie ich deklaracje


void wpisz()                    //Funkcja umozliwajaca wpisanie tablicy recznie
{
    int k;                      //Ta zmienna pomocnicza powstala na wypadek gdyby
                                //jednak ktos postanowil, dac nieprawidlowy rozmiar
    cout<<"Z ilu pozycji ma sie skladac tablica?\n";
    cin>>k;                     //gdyby tutaj bylo w to kompilator wyrzucilby blad alokacji

    if(k<=0){                   //Zabezpieczenie przed zadeklarowaniem ,,ujemnej" tablicy
        cout<<"Prosimy podac liczbe wieksza od zera"<<endl; }//stosowny komunikat
    else{
        w=k;
    taba = new int[w];          //deklaracja tablicy dynamicznej
    for(int i=0; i<w; i++)
    {
        cout<<"Podaj "<<i+1<<". element: ";
        cin>>taba[i];
        cout<<i+1<<". wyraz to "<<taba[i]<<endl; //testowanie
    }
}

}

void wczytaj_z_pliku()
{
    int pom[500];                   //deklarujemy tablice pomocnicza
    string pomocniczy;              //deklarujemy pomocnicznego stringa
    int liczenie=0;                 //zmienna przechowujaca wielkosc wczytanej tablicy

    ifstream plik;
    plik.open("dane.txt",ios::in);  //podajemy sciezke do pliku z odpowiednio sformatowanymi danymi wejsciowymi
    if(!plik.good())                //sprawdzamy czy nie wystepuja kody bledow
    {
        cout << "Blad pliku!" << endl;
    }
    else
    {
        while(getline(plik, pomocniczy))
        {
            //cout<<pomocniczy<<endl;   //tylko do testowania poprawnosci danych

            pom[liczenie]=atoi(pomocniczy.c_str());//konwetujemy typ string na typ int
            liczenie++;
        }
        w=liczenie;
        taba = new int[w];              //tworzymy dynamiczna tablice A

        cout<<"Wczytana tablica: "<<endl;
        for(int i=0; i<w; i++)
        {
            taba[i]=pom[i];                     //przepisujemy wartosci z tabeli pomocniczej do tabeli A
            cout<<taba[i]<<" ";
        }


        plik.close();                   //zamkniecie pliku i zwolnienie pamieci
    }
}




void stworzenieb()
{

    tabb = new int[w];

    for(int i=0; i<w-1; i++)
    {
        int licznik=0;
        for(int j=i+1; j<w; j++)
        {
            if(taba[i]<taba[j])
            {
                licznik++;
            }
            tabb[i]=licznik;

        }

    }
    tabb[w-1]=0;//ostatni element tablicy B zawsze bedzie zerem
    //wszystko ponizej to tak na prawde tylko sprawdzenie poprawnosci danych i element interfejsu uzytkownika
    cout<<endl;

    for(int i=0; i<w; i++)
    {

        cout<<i+1<<". wyraz B to "<<tabb[i]<<endl;
    }
}

void zapisz_do_pliku()
{
    fstream plik;
    plik.open("dane.txt",ios::out); //stworzenie pliku/nadpisanie pliku
    for(int i=0; i<w; i++)      //wpisanie po kolei kolejnych wartosci do pliku, w takim formacie,
                                //aby pozniej mozna bylo tego uzyc jako pliku wejsciowego
    {

        plik<<tabb[i]<<endl;
    }

    plik.close();

}

void funkcja()
{
    int wybor;
    int blad=5;
    while(wybor!=4)
    {
        cout<<"\n  MENU GLOWNE PROGRAMU \n\n";
        cout<<"*******************************************" <<endl<<endl;
        cout<<" 1. Wpisz tablice A recznie"<<endl;
        cout<<" 2. Wczytaj tablice A z pliku\n";
        cout<<" 3. Zapisz obecna tablice B do pliku txt\n";
        cout<<" 4. Wyjscie"<<endl<<endl;
        cout<<"*******************************************" <<endl<<endl;
        cout<<"Twoj wybor:";
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {   case 1:
                wpisz();
                stworzenieb();
                break;
            case 2:
                wczytaj_z_pliku();
                stworzenieb();
                break;
            case 3:
                zapisz_do_pliku();
                break;
            case 4:
                cout<<"Dziekuje za skorzystanie z programu :)"<<endl;
                break;
            default:
            cout<<"Wybrano nieprawidlowa opcje."<<endl;
            cout<<"Liczba nieudanych prob po ktorych program sie wylaczy: "<<blad-1<<endl;
                                                        //informujemy uzytkownika o zabezpieczeniu
            blad--;                                     //dekrementujemy wartosc testowa
            if(blad<=0)
                wybor=4;
        }
    }
    cout<<"Do widzenia!"<<endl;
    delete [] taba;
    delete [] tabb;
}


int main()
{

    funkcja();
    /* funkcje umieszczne w aktualnym komentarzu sluzyly jedynie w celach testowych
        //wpisz();
        wczytaj_z_pliku();
        stworzenieb();
        zapisz_do_pliku();
    */

    return 0;
}
