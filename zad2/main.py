import sys


def main():
    print('Program do konwersji liczb - aby przerwać działanie należy wcisnąć Ctrl-C\n')

    try:
        while True:
            print('1.Zamiana liczb dziesiętnych na binarne')
            print('2.Zamiana liczb binarnych na dziesiętne\n')

            # Wprowadzanie trybu działania
            mode = input('Proszę wybrać tryb działania aplikacji wprowadzając odpowiadający numer: ')

            # Sprawdzenie poprawności wprowadzonego trybu
            if mode not in ['1', '2']:
                print('\nWprowadzono niepoprawny numer\n')
                continue

            # Wprowadzenie liczby do konwersji
            number = input('\nProszę wprowadzić liczbę do konwersji: ')

            # Konwersja z dziesiętnej na binarną
            if mode == '1':
                try:
                    result = bin(int(number))[2:]
                except ValueError:
                    print('\nWprowadzono niepoprawną liczbę dziesiętną\n')
                    continue
            # Konwersja z binarnej na dziesiętną
            else:
                try:
                    result = int(number, 2)
                except ValueError:
                    print('\nWprowadzono niepoprawną liczbę binarną\n')
                    continue

            # Wypisanie wyniku do konsoli
            print(f'\nWynik konwersji: {result}\n')

    # Przerwanie programu przy pomocy Ctrl-C
    except KeyboardInterrupt:
        sys.exit('\n\nPrzerywam działanie programu')


if __name__ == '__main__':
    main()
