#include <iostream>
#include <vector>

class Julkaisu {
public:
    Julkaisu(std::string nimi) : nimi_(nimi) {}

    virtual void tulosta_tiedot() const {
        std::cout << "Julkaisun nimi: " << nimi_ << std::endl;
    }

private:
    std::string nimi_;
};

class Kirja : public Julkaisu {
public:
    Kirja(std::string nimi, std::string kirjoittaja, int sivumaara)
        : Julkaisu(nimi), kirjoittaja_(kirjoittaja), sivumaara_(sivumaara) {}

    void tulosta_tiedot() const override {
        Julkaisu::tulosta_tiedot();
        std::cout << "Kirjan on kirjoittanut " << kirjoittaja_ << std::endl;
        std::cout << "Kirjassa on " << sivumaara_ << " sivua." << std::endl;
    }

private:
    std::string kirjoittaja_;
    int sivumaara_;
};

class Lehti : public Julkaisu {
public:
    Lehti(std::string nimi, std::string paatoimittaja)
        : Julkaisu(nimi), paatoimittaja_(paatoimittaja) {}

    void tulosta_tiedot() const override {
        Julkaisu::tulosta_tiedot();
        std::cout << "Lehden päätoimittaja on " << paatoimittaja_ << std::endl;
    }

private:
    std::string paatoimittaja_;
};

int main() {
    std::vector<Julkaisu*> julkaisut;

    julkaisut.push_back(new Kirja("Hytti n:o 6", "Rosa Liksom", 200));
    julkaisut.push_back(new Lehti("Aku Ankka", "Aki Hyyppä"));

    for (const auto& julkaisu : julkaisut) {
        julkaisu->tulosta_tiedot();
        std::cout << std::endl;
    }


    for (const auto& julkaisu : julkaisut) {
        delete julkaisu;
    }

    return 0;
}

