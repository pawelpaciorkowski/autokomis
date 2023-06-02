// Paweł Paciorkowski
// Zadania końcowe - Programowanie C++
// Auto Komis

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

// Deklaracja klasy Klient
class Klient
{

public:
    Klient(std::string imie, std::string nazwisko, long long int kwota) : imie(imie), nazwisko(nazwisko), kwota(kwota), indeks(indeks) {}

    std::string getImie() const { return imie; }
    std::string getNazwisko() const { return nazwisko; }
    long long int getKwota() const { return kwota; }
    int getIndeks() const { return indeks; }              // dodana metoda getIndeks
    void setIndeks(int indeks) { this->indeks = indeks; } // dodana metoda setIndeks
    void setImie(std::string imie) { this->imie = imie; }
    void setNazwisko(std::string nazwisko) { this->nazwisko = nazwisko; }
    void setKwota(long long int kwota) { this->kwota = kwota; }

private:
    int indeks;
    std::string imie;
    std::string nazwisko;
    long long int kwota;
};

// Deklaracja klasy Auto
class Auto
{
public:
    Auto(std::string marka, std::string model, int rocznik, int przebieg) : marka(marka), model(model), rocznik(rocznik), przebieg(przebieg) {}

    std::string getMarka() const { return marka; }
    std::string getModel() const { return model; }
    int getRocznik() const { return rocznik; }
    int getPrzebieg() const { return przebieg; }
    void setIndeks(int indeks) { this->indeks = indeks; }
    void setMarka(std::string marka) { this->marka = marka; }
    void setModel(std::string model) { this->model = model; }
    void setRocznik(int rocznik) { this->rocznik = rocznik; }
    void setPrzebieg(int przebieg) { this->przebieg = przebieg; }

private:
    std::string marka;
    std::string model;
    int rocznik;
    int przebieg;
    int indeks;
};

// Deklaracja klasy ZarzadzanieSamochodami
class ZarzadzanieSamochodami
{
public:
    void dodajKlienta(Klient klient, Auto samochod)
    {

        int indeks = klienci.size() + 1; // Tworzenie unikalnego indeksu dla klienta
        klient.setIndeks(indeks);        // Ustawianie indeksu dla klienta
        klienci.push_back(klient);
        auta.push_back(samochod);
        klienciDodaniTerminal.push_back(klient); // Dodanie klienta do wektora klientów dodanych z terminala
        // zapiszDoPliku("txt");                    // Zapisz dane klienta do pliku "dane.txt"
    }

    void wyswietlWszystkichKlientow()
    {

        for (size_t i = 0; i < klienci.size(); ++i)
        {
            std::cout << "---------------------\n";
            std::cout << "Klienci AUTO KOMISU\n";
            std::cout << "---------------------\n";
            std::cout << "Indeks: " << klienci[i].getIndeks() << "\n";
            std::cout << "Imie: " << klienci[i].getImie() << "\n";
            std::cout << "Nazwisko: " << klienci[i].getNazwisko() << "\n";
            std::cout << "Kwota: " << klienci[i].getKwota() << "\n";
            std::cout << "Marka: " << auta[i].getMarka() << "\n";
            std::cout << "Model: " << auta[i].getModel() << "\n";
            std::cout << "Rocznik: " << auta[i].getRocznik() << "\n";
            std::cout << "Przebieg: " << auta[i].getPrzebieg() << "\n";
            std::cout << "\n";
        }
    }

    void aktualizujKlienta(int indeksKlienta)
    {
        int indeks;
        // std::cout << "Podaj indeks klienta do aktualizacji: ";
        std::cin >> indeks;

        if (indeks > 0 && indeks <= klienci.size())
        {
            // Aktualizacja danych klienta
            std::string imie, nazwisko, marka, model;
            long long int kwota, rocznik, przebieg;

            std::cout << "Podaj nowe imie klienta: ";
            std::cin >> imie;
            std::cout << "Podaj nowe nazwisko klienta: ";
            std::cin >> nazwisko;
            std::cout << "Podaj nowa kwote na koncie klienta: ";
            std::cin >> kwota;
            std::cout << "Podaj nowa marke samochodu: ";
            std::cin >> marka;
            std::cout << "Podaj nowy model samochodu: ";
            std::cin >> model;
            std::cout << "Podaj nowy rocznik samochodu: ";
            std::cin >> rocznik;
            std::cout << "Podaj nowy przebieg samochodu: ";
            std::cin >> przebieg;

            klienci[indeks - 1].setImie(imie);
            klienci[indeks - 1].setNazwisko(nazwisko);
            klienci[indeks - 1].setKwota(kwota);
            auta[indeks - 1].setMarka(marka);
            auta[indeks - 1].setModel(model);
            auta[indeks - 1].setRocznik(rocznik);
            auta[indeks - 1].setPrzebieg(przebieg);

            // Aktualizacja pliku
            std::ofstream plik("dane.txt");

            if (plik.is_open())
            {
                for (size_t i = 0; i < klienci.size(); ++i)
                {
                    plik << "---------------------\n";
                    plik << "Klienci AUTO KOMISU\n";
                    plik << "---------------------\n";
                    plik << "Indeks: " << klienci[i].getIndeks() << "\n";
                    plik << "Imie: " << klienci[i].getImie() << "\n";
                    plik << "Nazwisko: " << klienci[i].getNazwisko() << "\n";
                    plik << "Kwota: " << klienci[i].getKwota() << "\n";
                    plik << "Marka: " << auta[i].getMarka() << "\n";
                    plik << "Model: " << auta[i].getModel() << "\n";
                    plik << "Rozcznik: " << auta[i].getRocznik() << "\n";
                    plik << "Przebieg: " << auta[i].getPrzebieg() << "\n";
                    plik << "\n";
                }
                plik.close();
                std::cout << "Dane zapisane do pliku pomyslnie.\n";
            }
            else
            {
                std::cout << "Nie mozna otworzyc pliku.\n";
            }
        }
        else
        {
            std::cout << "Nieprawidlowy indeks. Aktualizacja nie powiodla sie.\n";
        }
    }

    void usunKlienta(int indeks)
    {
        if (indeks >= 1 && indeks <= klienci.size() && indeks <= auta.size())
        {
            klienci.erase(klienci.begin() + indeks - 1);
            auta.erase(auta.begin() + indeks - 1);
            std::cout << "Klient i dane o samochodzie usunieci pomyslnie.\n";

            // Aktualizacja indeksów klientów w pliku
            std::ofstream plik("dane.txt");

            if (plik.is_open())
            {
                for (size_t i = 0; i < klienci.size(); ++i)
                {
                    // plik << "---------------------\n";
                    // plik << "Klienci AUTO KOMISU\n";
                    // plik << "---------------------\n";
                    plik << "Indeks: " << (i + 1) << "\n";
                    plik << "Imie: " << klienci[i].getImie() << "\n";
                    plik << "Nazwisko: " << klienci[i].getNazwisko() << "\n";
                    plik << "Kwota: " << klienci[i].getKwota() << "\n";
                    plik << "Marka: " << auta[i].getMarka() << "\n";
                    plik << "Model: " << auta[i].getModel() << "\n";
                    plik << "Rocznik: " << auta[i].getRocznik() << "\n";
                    plik << "Przebieg: " << auta[i].getPrzebieg() << "\n";
                    plik << "\n";
                }
                plik.close();
                std::cout << "Dane zapisane do pliku pomyslnie.\n";
            }
            else
            {
                std::cout << "Nie mozna otworzyc pliku.\n";
            }
        }
        else
        {
            std::cout << "Nieprawidlowy indeks. Usuniecie nie powiodlo sie.\n";
        }
    }

    void zapiszDoPliku(std::string format)
    {
        if (format == "txt")
        {
            std::ofstream plik("dane.txt");
            if (plik.is_open())
            {
                for (size_t i = 0; i < klienci.size(); ++i)
                {

                    plik << "---------------------\n";
                    plik << "Klienci AUTO KOMISU\n";
                    plik << "---------------------\n";
                    plik << "Indeks: " << klienci[i].getIndeks() << "\n";
                    plik << "Imie: " << klienci[i].getImie() << "\n";
                    plik << "Nazwisko: " << klienci[i].getNazwisko() << "\n";
                    plik << "Kwota: " << static_cast<int>(klienci[i].getKwota()) << "\n";
                    plik << "Marka: " << auta[i].getMarka() << "\n";
                    plik << "Model: " << auta[i].getModel() << "\n";
                    plik << "Rocznik: " << auta[i].getRocznik() << "\n";
                    plik << "Przebieg: " << static_cast<int>(auta[i].getPrzebieg()) << "\n";

                    plik << "\n";
                }
                plik.close();
                std::cout << "Dane zapisane do pliku pomyslnie.\n";
            }
            else
            {
                std::cout << "Nie mozna otworzyc pliku.\n";
            }
        }
    }

    void wczytajZPliku(std::string nazwaPliku) // wczytywanie danych z pliku z danymi klient i samochodow  uwzglebniajacego obluge bledow
    {
        std::ifstream plik(nazwaPliku);

        if (plik.is_open())
        {
            klienci.clear();
            auta.clear();
            std::string imie, nazwisko, marka, model, linia;
            long long int kwota, przebieg;
            int rocznik;
            int indeks;

            while (std::getline(plik, linia)) // odczytanie całej linii z pliku
            {
                try
                {
                    if (linia.find("Indeks: ") != std::string::npos) // szukanie linii z indeksem
                    {
                        indeks = std::stoi(linia.substr(8)); // wyciągnięcie indeksu i zamiana na int (pozbycie się "Indeks: ")
                    }
                    else if (linia.find("Imie: ") != std::string::npos) // szukanie linii z imieniem
                    {
                        imie = linia.substr(6); // wyciągnięcie imienia (pozbycie się "Imie: ")
                    }
                    else if (linia.find("Nazwisko: ") != std::string::npos) // szukanie linii z nazwiskiem
                    {
                        nazwisko = linia.substr(10); // wyciągnięcie nazwiska (pozbycie się "Nazwisko: ")
                    }
                    else if (linia.find("Kwota: ") != std::string::npos) // szukanie linii z kwotą
                    {
                        kwota = std::stoi(linia.substr(7)); // wyciągnięcie kwoty i zamiana na int (pozbycie się "Kwota: ")
                    }
                    else if (linia.find("Marka: ") != std::string::npos) // szukanie linii z marką
                    {
                        marka = linia.substr(7); // wyciągnięcie marki (pozbycie się "Marka: ")
                    }
                    else if (linia.find("Model: ") != std::string::npos) // szukanie linii z modelem
                    {
                        model = linia.substr(7); // wyciągnięcie modelu (pozbycie się "Model: ")
                    }
                    else if (linia.find("Rocznik: ") != std::string::npos) // szukanie linii z rocznikiem
                    {
                        rocznik = std::stoi(linia.substr(9)); // wyciągnięcie rocznik i zamiana na int (pozbycie się "Rocznik: ")
                    }
                    else if (linia.find("Przebieg: ") != std::string::npos) // szukanie linii z przebiegiem
                    {
                        przebieg = std::stoll(linia.substr(10)); // wyciągnięcie przebiegu i zamiana na int (pozbycie się "Przebieg: ")

                        // Po odczytaniu wszystkich danych o kliencie i samochodzie, dodajemy ich do list
                        Klient klient(imie, nazwisko, kwota);
                        klient.setIndeks(indeks);
                        Auto samochod(marka, model, rocznik, przebieg);
                        samochod.setIndeks(indeks);

                        klienci.push_back(klient);
                        auta.push_back(samochod);
                    }
                }
                catch (const std::invalid_argument &ia)
                {
                    std::cerr << "Nieprawidłowy argument podczas próby konwersji na liczbę: " << ia.what() << std::endl;
                }
            }

            plik.close();
            std::cout << "Dane wczytane z pliku pomyslnie.\n";
            // wyswietlWszystkichKlientow(); // Wyświetl
        }
        else
        {
            std::cout << "Nie mozna otworzyc pliku.\n";
        }
    }

private:
    std::vector<Klient>
        klienci;
    std::vector<Auto> auta;
    std::vector<Klient> klienciDodaniTerminal; // Wektor klientów dodanych z terminala
};
void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
// Funkcja wyświetlająca menu
void wyswietlMenu()
{
    clearScreen();
    // std::cout << "\033[44;33m";
    std::cout << "             ______\n"
                 "        ____/      \\___\n"
                 "       |_______________|\n"
                 "         (o)       (o)\n";
    std::cout << "\n";
    std::cout << "----------------------------------\n";
    std::cout << "||||||||||||||||||||||||||||||||||\n";
    std::cout << "\n";
    std::cout << "||||||||||| AUTO KOMIS |||||||||||\n";
    std::cout << "\n";
    std::cout << "||||||||||||||||||||||||||||||||||\n";
    std::cout << "----------------------------------\n";
    std::cout << "|             MENU:              |\n";
    std::cout << "|--------------------------------|\n";
    std::cout << "|    [1] Dodaj Klienta           |\n";
    std::cout << "|    [2] Wczytaj dane z pliku    |\n";
    std::cout << "|    [3] Aktualizuj dane         |\n";
    std::cout << "|    [4] Usun dane z pliku       |\n";
    std::cout << "|    [5] Wyswietl dane klienta   |\n";
    std::cout << "|    [6] Zapisz do pliku         |\n";
    std::cout << "|    [7] Wyjdz z programu        |\n";
    std::cout << "|--------------------------------|\n";
    std::cout << "|          Wybierz opcje:        |\n";
    std::cout << "|--------------------------------|\n";
}

int main()
{

    ZarzadzanieSamochodami zarzadzanie;
    int wybor;

    std::string nazwaPliku = "dane.txt"; // Nazwa pliku do wczytania

    // Wczytanie danych z pliku na starcie programu
    // zarzadzanie.wczytajZPliku(nazwaPliku);

    // Klient janKowalski("Jan", "Kowalski", 10000);
    // Auto seatIbiza("Seat", "Ibiza", 2016, 100000);
    // zarzadzanie.dodajKlienta(janKowalski, seatIbiza);

    do
    {
        wyswietlMenu();
        std::cin >> wybor;

        switch (wybor)
        {
        case 1:
        {
            std::string imie, nazwisko, marka, model;
            long long int kwota, rocznik, przebieg;

            std::cout << "Podaj imie klienta: ";
            std::cin >> imie;
            std::cout << "Podaj nazwisko klienta: ";
            std::cin >> nazwisko;
            std::cout << "Podaj kwote na koncie klienta: ";
            std::cin >> kwota;
            std::cout << "Podaj marke samochodu: ";
            std::cin >> marka;
            std::cout << "Podaj model samochodu: ";
            std::cin >> model;
            std::cout << "Podaj rocznik samochodu: ";
            std::cin >> rocznik;
            std::cout << "Podaj przebieg samochodu: ";
            std::cin >> przebieg;

            Klient nowyKlient(imie, nazwisko, kwota);
            Auto nowySamochod(marka, model, rocznik, przebieg);
            zarzadzanie.dodajKlienta(nowyKlient, nowySamochod);
            break;
        }

        case 2:
        {
            std::string nazwaPliku;
            std::cout << "Podaj nazwe pliku do wczytania: ";
            std::cin >> nazwaPliku;
            zarzadzanie.wczytajZPliku(nazwaPliku);
            break;
        }

        case 3:
        {
            int indeksAktualizowanegoKlienta;
            std::cout << "Podaj indeks klienta do aktualizacji: ";
            // std::cin >> indeksAktualizowanegoKlienta;
            if (std::cin.fail())
            {
                std::cout << "Musisz podac liczbe!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            zarzadzanie.aktualizujKlienta(indeksAktualizowanegoKlienta);
            break;
        }

        case 4:
        {
            int indeksUsuwanegoKlienta;
            std::cout << "Podaj indeks klienta do usuniecia: ";
            std::cin >> indeksUsuwanegoKlienta;
            if (std::cin.fail())
            {
                std::cout << "Musisz podac liczbe!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            zarzadzanie.usunKlienta(indeksUsuwanegoKlienta);
            break;
        }

        case 5:
        {
            zarzadzanie.wyswietlWszystkichKlientow();
            break;
        }

        case 6:
        {

            zarzadzanie.zapiszDoPliku("txt");
            break;
        }

        case 7:
        {
            std::cout << "Wyjscie z programu.\n";
            break;
        }

        default:
        {
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }
        }
        if (wybor != 7)
        {
            std::cout << "Nacisnij ENTER aby kontynuowac...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (wybor != 7);

    return 0;
}