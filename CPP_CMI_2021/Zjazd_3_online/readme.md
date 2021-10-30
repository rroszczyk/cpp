### CMI 3 [Zjazd 3 -- online]

```sh
.
├── zad_1
│   └── function_example.cpp
└── zad_2
    ├── with_headers
    │   ├── calc.cpp
    │   ├── calc.hpp
    │   └── maths_examples.cpp
    └── without_headers
        └── maths_examples_without_headers.cpp
```

W katalogu `zad_1` jest umieszczony przykład kodu źródłowego pokazujący prosty przykład delegowania operacji do funkcji pomocniczych (mamy funkcje: wyświetlającą powitanie ze światem (Hello, World!); do dodawania dwóch liczb zmiennoprzecinkowych; do przyjmowania (i wypisywania) od użytkownika wprowadzonego tekstu).

W katalogu `zad_2` mamy dwa katalogi (dwie wersje tego samego programu): `with_headers`, `without_headers`.
Drugi z nich pokazuje nasz kod umieszczony w jednym pliku źródłowym.
Pierwszy zaś prezentuje podział naszego kodu nie tylko na funkcje odpowiedzialne za poszczególne operacje arytmetyczne, ale również pokazany jest podział kodu na różne pliki (plik nagłówkowy: `calc.hpp`; plik implementujący wszystkie funkcje: `calc.cpp`; plik główny naszego programu (`maths_examples`) wykorzystujący nasz kod jak gotową bibliotekę).
