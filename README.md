# Implementowane algorytmy sortowania

## Sortowanie kubełkowe
Idea działania algorytmu sortowania kubełkowego:
Podziel zadany przedział liczb na k podprzedziałów (kubełków) o równej długości.
Przypisz liczby z sortowanej tablicy do odpowiednich kubełków.
Sortuj liczby w niepustych kubełkach.
Wypisz po kolei zawartość niepustych kubełków.
[wiki](https://pl.wikipedia.org/wiki/Sortowanie_kube%C5%82kowe)

## Sortowanie szybkie (quicksort)
Na początku wybierany jest tzw. element osiowy. Następnie tablica dzielona jest na dwie podtablice. Pierwsza z nich zawiera elementy mniejsze od elementu osiowego, druga elementy większe lub równe, element
osiowy znajdzie się między nimi. Proces dzielenia powtarzany jest aż do uzyskania tablic jednoelementowych, nie wymagających sortowania. Właściwe sortowanie jest tu jakby ukryte w procesie przygotowania
do sortowania. Wybór elementu osiowego wpływa na równomierność podziału na podtablice (najprostszy
wariant – wybór pierwszego elementu tablicy – nie sprawdza się w przypadku, gdy tablica jest już prawie
uporządkowana).
[wiki](http://pl.wikipedia.org/wiki/Sortowanie_szybkie)

## Sortowanie introspektywne

Sortowanie introspektywne (introspective sort lub introsort)
Jest to metoda hybrydowa, będąca połączeniem sortowania szybkiego i sortowania przez kopcowanie. Sortowanie introspektywne pozwala uniknąć najgorszego przypadku dla sortowania szybkiego (nierównomierny
podział tablicy w przypadku, gdy jako element osiowy zostanie wybrany element najmniejszy lub największy).
[wiki](https://pl.wikipedia.org/wiki/Sortowanie_introspektywne)
