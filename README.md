Codebook
========

To je zbirka implementacij algoritmov, ki se pogosto pojavljajo na programerskih
tekmovanjih. Implementacije smo nabirali skozi leta, zdaj pa smo se jih odločili
zbrati na enem mestu. Algoritmi so implemetirani vsak v svoji datoteki in
vključeni v glavni dokument.

Algoritmi
---------
Vsak algoritem vsebuje naslednje podatke:

 * vhodni parametri
 * izhod
 * časovna zahtevnost
 * prostorska zahtevnost
 * implementacijo v C++ (lahko tudi še v kakšnem jeziku)
    + `.h` datoteko, ki definira vse potrebne funkcije in simbole ter vključi vse potrebne headerje
    + `.cpp` datoteko, ki v prvi vrstici includa svojo `.h` datoteko in nato implementira algoritem,
      začenši z vrstico 3.
    + `_test.cpp` datoteko, ki vsebuje teste, ki preverjajo pravilnost algoritma.
 * dokaz testiranja na terenu (link ali drugačen opis naloge)
 * morebitne dependancije (npr. potrebuje `dijkstra.h`)
 * morebitne dodatne opombe

Dodajanje
---------
Vsak nov algoritem mora imeti vse ustrezne podatke zgoraj. Datoteki s testi in
implementacijo dajte v pravo mapo `implementacija/nekaj/algoritem(.h|.cpp|_test.cpp)` Vsak algoritem
je implementiran kot ena ali več funkcij ali kot razred. Ko ste dodali teste (lahko tudi iz testnih
datotek), je vse kar je treba narediti, da poženete skripto `full_test.sh`, ki avtomatsko prevede,
testira in preveri stil vaše kode. Ko je ta skripta brez napak in je algoritem vključen v glavni
dokument, lahko commitate.

Primer uporabe:

    $ ./full_test.sh
    Compiling tests ...
    g++ -g -Wall -Wextra -pthread -std=c++11 -isystem ./googletest/include  -c -o
    ../implementacija/ts/gcd_test.o ../implementacija/ts/gcd_test.cpp
    g++ -isystem ./googletest/include -g -Wall -Wextra -pthread -std=c++11 -lpthread
    ../implementacija/ts/gcd_test.o gtest_main.a -o run_tests && rm -f ../implementacija/ts/gcd_test.o
    Running tests ...
    Running main() from gtest_main.cc
    [==========] Running 4 tests from 1 test case.
    [----------] Global test environment set-up.
    [----------] 4 tests from GcdTest
    [ RUN      ] GcdTest.Zero
    [       OK ] GcdTest.Zero (0 ms)
    [ RUN      ] GcdTest.Divisor
    [       OK ] GcdTest.Divisor (0 ms)
    [ RUN      ] GcdTest.General
    [       OK ] GcdTest.General (0 ms)
    [ RUN      ] GcdTest.Negative
    [       OK ] GcdTest.Negative (0 ms)
    [----------] 4 tests from GcdTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 4 tests from 1 test case ran. (0 ms total)
    [  PASSED  ] 4 tests.
    Checking code style ...
    Done processing ./implementacija/ts/gcd_test.cpp
    Total errors found: 0
    Done processing ./implementacija/ts/gcd.h
    Total errors found: 0
    Done! All looks great!
    $

Pri uporabi `full_test.sh` je možno kot prvi argument podati tudi filter za teste, da ne požene
vseh. Primer:

    $./full_test.sh Gcd*

Jure Slak
