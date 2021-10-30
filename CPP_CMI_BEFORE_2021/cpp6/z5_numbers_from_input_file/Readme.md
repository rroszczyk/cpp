### Jak uruchomić?

```sh
user@user:$ g++ nums_from_file.cpp
user@user:$ ./a.out zakupy.txt
```

### Co się dzieje w kodzie?

1. Ponieważ potrzebujemy dostać się do pliku, to załączamy bibliotekę `fstream`.
2. Ustalamy maksymalną długość liczby (z ilu cyfr może się składać) : `int MAX_NUM_LENGTH = 32;` -- jeśli będzie więcej, to program zachowa się nieprzewidywalnie.
3. Plik wejściowy (ścieżka do pliku) będzie przekazywany w parametrach uruchomienia programu `argv[1]`. Jeśli go nie przekażemy (`argc != 2`), to program zakończy działanie `return -1;`.
4. Otwieramy plik (`ifstream myInputFile(filename);`) z nazwą zapisaną w zmiennej `filename`. Odwołując się do nazwy `myInputFile` możemy pobierać kolejne znaki z naszego pliku (do zmiennej `char c`).
5. Ustalamy napis, to którego będziemy zapisywali kolejne cyfry kolejnej liczby. Długość liczby (liczba cyfr) nie może przekroczyć 32 cyfr, ale `num` ma rozmiar `MAX_NUM_LENGTH + 1` ponieważ ostatni znak rezerwujemy dla specjalnego oznaczenia zakończenia napisu `\0`.
6. Wewnątrz pętli `while` wczytujemy kolejne znaki z pliku tekstowego.
7. Jeżeli wczytany znak jest cyfrą (`if( c >= '0' && c <= '9' )`), to dostawiamy ją do naszego napisu: `num[numId++] = c;`.
8. W odwrotnym przypadku sprawdzamy, czy ostatnio wczytaliśmy jakąś cyfrę. Jeżeli wczytaliśmy, to ustawiamy znak końca tekstu `\0`, a wszystko, co się znajduje przed tym znakiem, jest aktualnie znalezioną liczbą.
9. Wypisujemy znalezioną liczbę (z niewidocznym znakiem `\0` końca tekstu).
10. "Czyścimy" naszą zmienną do przechowywania cyfr kolejnej liczby.
