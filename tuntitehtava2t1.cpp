#include <iostream>
#include <vector>


class Hissi {
public:
    Hissi(int alinkerros, int ylinkerros) {
        alinkerros_ = alinkerros;
        ylinkerros_ = ylinkerros;
        kerros_ = alinkerros;
    }



    void siirrykerrokseen(int kohdekerros) {
        if (kohdekerros < alinkerros_ or kohdekerros > ylinkerros_) {
            std::cout << "Kerrosta ei ole" << std::endl;
            return;
        }

        while (kerros_ < kohdekerros) {
            kerros_ylos();
        }

        while (kerros_ > kohdekerros) {
            kerros_alas();
        }
    }

    void kerros_alas() {
        kerros_ -= 1;
        std::cout << "Hissi on kerroksessa " << kerros_ << std::endl;
    }

    void kerros_ylos() {
        kerros_ += 1;
        std::cout << "Hissi on kerroksessa " << kerros_ << std::endl;
    }

private:
    int alinkerros_;
    int ylinkerros_;
    int kerros_;


};



class Talo {
public:
    Talo(int alin_kerrostaso, int ylim_kerrostaso, int hissien_lukumaara) {
        for (int i = 0; i < hissien_lukumaara; ++i) {
            hissit_.emplace_back(alin_kerrostaso, ylim_kerrostaso);
        }
    }

    void aja_hissia(int hissi_numero, int kohdekerros) {
        if (hissi_numero >= 0 && hissi_numero < hissit_.size()) {
            hissit_[hissi_numero].siirrykerrokseen(kohdekerros);
        }
        else {
            std::cout << "Hissiä ei ole olemassa" << std::endl;
        }
    }

    void palohälytys() {
        for (auto& hissi : hissit_) {
            hissi.siirrykerrokseen(1);  
        }
        std::cout << "Palohälytys! Kaikki hissit siirretty pohjakerrokseen." << std::endl;
    }

private:
    std::vector<Hissi> hissit_;
};

int main() {
    Talo talo(1, 10, 3);

    talo.aja_hissia(1, 7);

    talo.aja_hissia(5, 3);

    return 0;
}








