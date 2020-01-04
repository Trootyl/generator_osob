#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <set>
#include <string>

class PersonIf {
public:
    virtual const std::string& get_name() const = 0;
    virtual const std::string& get_surname() const = 0;
    virtual const std::string& get_address() const = 0;
    virtual const int& get_age() const = 0;
    virtual const std::string& get_date_of_birth() const = 0; // zwroci string w formacie "YYYY.MM.DD"
    virtual const long long& get_pesel() const = 0;
};

class Person : public PersonIf {
public:
    Person(std::string name, std::string surname, std::string address, int age, std::string date_of_birth, long long pesel, std::string pesel_str)
    {
        this->name = name;
        this->surname = surname;
        this->address = address;
        this->age = age;
        this->date_of_birth = date_of_birth;
        this->pesel = pesel;
        this->pesel_str = pesel_str;
    }
    Person() = default;
    ~Person() = default;

    const std::string& get_name() const { return name; }
    const std::string& get_surname() const { return surname; }
    const std::string& get_address() const { return address; }
    const int& get_age() const { return age; }
    const std::string& get_date_of_birth() const { return date_of_birth; } // zwroci string w formacie "YYYY.MM.DD"
    const long long& get_pesel() const { return pesel; }
    const std::string& get_pesel_str() const { return pesel_str; }
    static Person generuj_osobe();

    // Wypisywanie elementow
    friend std::ostream& operator<<(std::ostream& s, const std::shared_ptr<Person>& p)
    {
        return s << std::left << std::setw(15) << p->get_name()
                 << std::setw(15) << p->get_surname()
                 << std::setw(15) << p->get_address()
                 << std::setw(7) << p->get_age()
                 << std::setw(15) << p->get_date_of_birth()
                 << std::setw(11) << p->get_pesel_str() << std::endl;
    }

    // Sortowanie wygenerowanych osob po peselu
    struct Cmp_pesel {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            return false;
        }
    };

    // Sortowanie wygenerowanych osob po imieniu
    struct Cmp_name {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            return false;
        }
    };

    // Sortowanie wygenerowanych osob po nazwisku
    struct Cmp_surname {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            return false;
        }
    };

    // Sortowanie wygenerowanych osob po adresie
    struct Cmp_address {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            return false;
        }
    };

    // Sortowanie wygenerowanych osob po wieku
    struct Cmp_age {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            return false;
        }
    };

    // Sortowanie wygenerowanych osob po dacie urodzenia
    struct Cmp_dob {
        bool operator()(const std::shared_ptr<Person>& p1, const std::shared_ptr<Person>& p2) const
        {
            if (p1->get_date_of_birth() != p2->get_date_of_birth())
                return (p1->get_date_of_birth() < p2->get_date_of_birth());
            if (p1->get_name() != p2->get_name())
                return (p1->get_name() < p2->get_name());
            if (p1->get_surname() != p2->get_surname())
                return (p1->get_surname() < p2->get_surname());
            if (p1->get_address() != p2->get_address())
                return (p1->get_address() < p2->get_address());
            if (p1->get_age() != p2->get_age())
                return (p1->get_age() < p2->get_age());
            if (p1->get_pesel() != p2->get_pesel())
                return (p1->get_pesel() < p2->get_pesel());
            return false;
        }
    };

private:
    std::string name;
    std::string surname;
    std::string address;
    int age;
    std::string date_of_birth;
    long long pesel;
    std::string pesel_str;
};

std::array<std::string, 10> imiona{ "Andrzej", "Michal", "Zbigniew", "Karol", "Robert", "Wiktor", "Izydor", "Lukasz", "Waldemar", "Krzysztof" };
std::array<std::string, 10> nazwiska{ "Nowacki", "Kowalski", "Frankowski", "Bielik", "Glowacki", "Lewandowski", "Piszczek", "Fabianski", "Kowalewski", "Zakrzewski" };
std::array<std::string, 10> miasta{ "Szczecin", "Poznan", "Warszawa", "Kielce", "Gdansk", "Gdynia", "Zakopane", "Wroclaw", "Lodz", "Rzeszow" };
std::set<std::shared_ptr<Person>, Person::Cmp_pesel> osoby;

std::set<std::shared_ptr<Person>, Person::Cmp_name> sort_name;
std::set<std::shared_ptr<Person>, Person::Cmp_surname> sort_surname;
std::set<std::shared_ptr<Person>, Person::Cmp_address> sort_address;
std::set<std::shared_ptr<Person>, Person::Cmp_age> sort_age;
std::set<std::shared_ptr<Person>, Person::Cmp_dob> sort_dob; //date of birth

void get_data(const int type, const int start_position, const int amount);

// Pobieramy aktualna date
std::time_t t = std::time(0);
std::tm* now = std::localtime(&t);
const int aktualny_rok = now->tm_year + 1900;
const int aktualny_miesiac = now->tm_mon + 1;
const int aktualny_dzien = now->tm_mday;

int main(int argc, char* argv[])
{
    // Obsluga wyjatkow - brak parametrow
    if (argv[1] == NULL) {
        std::cout << "Nie podano liczby osob do wygenerowania, ani parametrow wyswietlania danych." << std::endl << std::endl;
        std::cout << "Uruchom program jeszcze raz podajac po nazwie programu nastepujace parametry: " << std::endl;
        std::cout << "argv[1]: Liczbe osob do wygenerowania w przedziale od 1 do 1.000.000." << std::endl;
        std::cout << "argv[2]: Parametry sortowania:   0 - pesel,   1 - imie,   2 - nazwisko,   3 - adres,   4 - wiek,   5 - data urodzenia." << std::endl;
        std::cout << "argv[3]: Od ktorej z kolei osoby wypisywac dane." << std::endl;
        std::cout << "argv[4]: Ile osob wypisac." << std::endl << std::endl;
        std::cout << "Ostatnie 3 argumenty mozesz podac kilkukrotnie (od 1 do 10 razy)." << std::endl;
        return 0;
    }

    // Obsluga wyjatkow - zla liczba parametrow
    if (argc % 3 != 2 || argc < 5 || argc > 32) {
        std::cout << "Podales zla liczbe argumentow." << std::endl << std::endl;
        std::cout << "Uruchom program jeszcze raz podajac po nazwie programu nastepujace parametry: " << std::endl;
        std::cout << "argv[1]: Liczbe osob do wygenerowania w przedziale od 1 do 1.000.000." << std::endl;
        std::cout << "argv[2]: Parametry sortowania:   0 - pesel,   1 - imie,   2 - nazwisko,   3 - adres,   4 - wiek,   5 - data urodzenia." << std::endl;
        std::cout << "argv[3]: Od ktorej z kolei osoby wypisywac dane." << std::endl;
        std::cout << "argv[4]: Ile osob wypisac." << std::endl << std::endl;
        std::cout << "Ostatnie 3 argumenty mozesz podac kilkukrotnie (od 1 do 10 razy)." << std::endl;
        return 0;
    }

    srand(time(0));

    int liczba_wygenerowanych_osob = atoi(argv[1]);

    for (int i = 0; i < liczba_wygenerowanych_osob; ++i)
        osoby.emplace(std::make_shared<Person>(Person::generuj_osobe()));

    for (int i = 2; i < argc; i += 3) {
        get_data(atoi(argv[i]), atoi(argv[i + 1]), atoi(argv[i + 2]));
    }

    return 0;
}

// Generator osob
Person Person::generuj_osobe()
{
    // Generujemy imie, nazwisko i adres z dostepnej puli oraz wiek
    std::string imie = imiona[rand() % 10];
    std::string nazwisko = nazwiska[rand() % 10];
    std::string adres = miasta[rand() % 10];
    int wiek = (rand() % 90) + 10;

    // Deklarujemy zmienne, ktore wykorzystamy pozniej
    std::string data_urodzenia;
    long long numer_pesel;

    // Ustawiamy rok urodzenia osoby, na podstawie aktualnej daty i wygenerowanego wieku osoby.
    // Dodatkowo rok zamieniamy na stringa, ktorego dodamy do stringa z data urodzenia.
    int rok_urodzenia_int = aktualny_rok - wiek;
    std::string rok_urodzenia = std::to_string(rok_urodzenia_int);

    // Generujemy miesiac urodzenia osoby. Dodatkowo miesiac zamieniamy na stringa, ktorego dodamy do stringa z data urodzenia.
    // W przypadku miesiecy w zakresie 1-9 dodajemy do stringa "0" z przodu miesiaca.
    int miesiac_urodzenia_int = rand() % 12 + 1;
    std::string miesiac_urodzenia;
    if (miesiac_urodzenia_int < 10) {
        miesiac_urodzenia = "0" + std::to_string(miesiac_urodzenia_int);
    }
    else {
        miesiac_urodzenia = std::to_string(miesiac_urodzenia_int);
    }

    // Generujemy dzien urodzenia osoby. Zakres z jakiego mozemy wygenerowac dzien zalezny jest od miesiaca jaki wczesniej wygenerowalismy.
    // Dzien zamieniamy na stringa, ktorego dodamy do stringa z data urodzenia. W przypadku dni w zakresie 1-9 dodajemy do stringa "0" z przodu dnia.
    int dzien_urodzenia_int;
    switch (miesiac_urodzenia_int) {
    case 1:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 2:
        dzien_urodzenia_int = rand() % 28 + 1;
        break;
    case 3:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 4:
        dzien_urodzenia_int = rand() % 30 + 1;
        break;
    case 5:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 6:
        dzien_urodzenia_int = rand() % 30 + 1;
        break;
    case 7:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 8:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 9:
        dzien_urodzenia_int = rand() % 30 + 1;
        break;
    case 10:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    case 11:
        dzien_urodzenia_int = rand() % 30 + 1;
        break;
    case 12:
        dzien_urodzenia_int = rand() % 31 + 1;
        break;
    }
    std::string dzien_urodzenia;
    if (dzien_urodzenia_int < 10) {
        dzien_urodzenia = "0" + std::to_string(dzien_urodzenia_int);
    }
    else {
        dzien_urodzenia = std::to_string(dzien_urodzenia_int);
    }

    // Przypisujemy do zmiennej z data urodzenia stringi z rokiem, miesiacem i dniem urodzenia w formacie YYYY.MM.DD
    data_urodzenia = rok_urodzenia + "." + miesiac_urodzenia + "." + dzien_urodzenia;

    // Ustawiamy stringa z numerem pesel.
    // Laczymy po kolei: 2 ostatnie cyfry roku urodzenia, miesiac urodzenia (+20 w przypadku osob urodzonych od 2000r.), dzien urodzenia + 5 losowych cyfr.
    std::string pesel_string = rok_urodzenia.substr(2);
    if (rok_urodzenia_int >= 2000) {
        miesiac_urodzenia_int += 20;
        miesiac_urodzenia = std::to_string(miesiac_urodzenia_int);
        pesel_string += miesiac_urodzenia;
    }
    else {
        pesel_string += miesiac_urodzenia;
    }
    pesel_string += dzien_urodzenia;
    std::string ostatnich_5_cyfr_nr_pesel = std::to_string(rand() % 90000 + 10000);
    pesel_string += ostatnich_5_cyfr_nr_pesel;

    // Zamieniamy stringa z numerem pesel na wartosc typu long long i przypisujemy ja do zmiennej z numerem pesel.
    numer_pesel = stoll(pesel_string);

    // Zwracamy obiekt klasy Person z wygenerowanymi danymi.
    return Person(imie, nazwisko, adres, wiek, data_urodzenia, numer_pesel, pesel_string);
}

// Pobieranie danych z listy osob i odpowiednie wyswietlanie ich.
void get_data(const int type, const int start_position, const int amount)
{
    // type = po czym sortujemy liste osob:   0 - pesel,   1 - imie,   2 - nazwisko,   3 - adres,   4 - wiek,   5 - data urodzenia
    // start_position = od ktorej pozycji chcemy wypisywac dane
    // amount = ile pozycji wypisac

    int check_amount = 0;

    // W zaleznosci od wybranego typu sortowania kopiujemy osoby naszej bazy do nowej bazy posortowanej wg naszego wyboru i wyswietlamy ja.
    // W przypadku wyboru sortowania po peselu korzystamy juz z naszej posortowanej bazy bez kolejnego kopiowania.
    switch (type) {
    case 0: {
        auto it0 = osoby.begin();
        for (it0 = std::next(it0, start_position - 1); it0 != sort_dob.end(); ++it0) {
            std::cout << *it0;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    case 1: {
        for (auto const& elem : osoby)
            sort_name.emplace(elem);
        auto it1 = sort_name.begin();
        for (it1 = std::next(it1, start_position - 1); it1 != sort_name.end(); ++it1) {
            std::cout << *it1;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    case 2: {
        for (auto const& elem : osoby)
            sort_surname.emplace(elem);
        auto it2 = sort_surname.begin();
        for (it2 = std::next(it2, start_position - 1); it2 != sort_surname.end(); ++it2) {
            std::cout << *it2;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    case 3: {
        for (auto const& elem : osoby)
            sort_address.emplace(elem);
        auto it3 = sort_address.begin();
        for (it3 = std::next(it3, start_position - 1); it3 != sort_address.end(); ++it3) {
            std::cout << *it3;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    case 4: {
        for (auto const& elem : osoby)
            sort_age.emplace(elem);
        auto it4 = sort_age.begin();
        for (it4 = std::next(it4, start_position - 1); it4 != sort_age.end(); ++it4) {
            std::cout << *it4;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    case 5: {
        for (auto const& elem : osoby)
            sort_dob.emplace(elem);
        auto it5 = sort_dob.begin();
        for (it5 = std::next(it5, start_position - 1); it5 != sort_dob.end(); ++it5) {
            std::cout << *it5;
            ++check_amount;
            if (check_amount == amount)
                break;
        }
        break;
    }

    default:
        break;
    }
}