#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input( "input.txt", fstream::in ); // plik wejściowy
    ofstream output( "output.txt", fstream::out ); // plik wyjściowy
    ofstream temp( "temp.txt", fstream::out ); // plik pomocniczy do przechowania poprawnych obiektów

    int all_objects = 0; // licznik wszystkich obiektów
    int bad_objects = 0; // licznik błędnych obiektów

    if ( input.is_open()) // sprawdzenie czy plik wejściowy poprawnie się otworzył, jeśli nie to program kończy działanie
    {
        char c; // zmienna do wczytywania znak po znaku
        string object; // zmienna do przechowywania pełnego obiektu
        int i = 1; // licznik wczytanych znaków do wyznaczania granic obiektów
        bool valid_object = false; // flaga do określania czy obiekt składa się z samych zer

        while ( input >> c ) // wczytywanie znak po znaku
        {
            if ( c == '1' && !valid_object ) // sprawdzenie czy obiekt składa się z samych zer
                valid_object = true;

            object.push_back( c ); // dopisanie bitu do obiektu

            if ( i++ == 8 ) // sprawdzenie czy wczytano już cały obiekt
            {
                int control_bit = object[object.size() - 1] - '0'; // bit kontrolny

                if (( control_bit != ++all_objects % 2 ) || !valid_object ) // sprawdzenie czy obiekt jest wadliwy
                    bad_objects++;
                else
                    temp << object; // dopisanie poprawnego obiektu do pliku tymczasowego

                // reset zmiennych przed wczytywaniem kolejnego obiektu
                valid_object = false;
                i = 1;
                object = "";
            }
        }
    }
    else
        return 1;

    // Wpisanie do pliku wejściowego liczby wszystkich obiektów oraz błędnych
    output << "Wszystkie obiekty: " << all_objects << "\n" << "Obiekty z błędami: " << bad_objects << "\n";
    input.close();
    temp.close();
    temp.open( "temp.txt", fstream::in ); // otworzenie pliku tymczasowego do odczytu zapisanych poprawnych obiektów
    output << temp.rdbuf(); // dopisanie poprawnych obiektów do pliku wyjściowego
    output.close();
    temp.close();
    remove( "temp.txt" ); // usunięcie pliku tymczasowego

    return 0;
}