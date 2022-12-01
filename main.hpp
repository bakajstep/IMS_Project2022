//
// Created by sbakaj on 12/1/22.
//

#ifndef IMS_MAIN_HPP
#define IMS_MAIN_HPP

#include <iostream>
#include <simlib.h>
#include <string>

using namespace std;

// zapina debugovaci mod
bool debug = false;

enum mista {
    pocatek, prolomeniBrany, prijezdRohanu, vypadGondoru, posilyMordoru, posilyGondoru
};

// faze bitvy
extern mista castBitvy;

extern unsigned int prvniCast;
extern unsigned int druhaCast;
extern unsigned int tretiCast;
extern unsigned int ctvrtaCast;
extern unsigned int pataCast;
extern unsigned int sestaCast;


// zacetecni pocet jednotek Gondoru, ktere prisly na pomoc
extern unsigned int pocetGondorPomoc;
unsigned int gondorPomocStatistiky = 0;

// zacetecni pocet jednotek Mordoru
extern int pocetMordor;
unsigned int mordorStatistiky[6] = {0,0,0,0,0,0};

// zacetecni pocet jednotek Rohanu
extern unsigned int pocetRohan;
unsigned int rohanStatistiky[4] = {0,0,0,0};

// zacetecni pocet jednotek Gondoru ve meste
extern unsigned int pocetGondorMesto;
unsigned int gondorMestoStatistiky[6] = {0,0,0,0,0,0};


void info(const std::string& retezec) {
    // pokud debugujeme, tak vypisovat, jinak ne
    if (debug) {
        std::cerr << static_cast<int>(Time) << ": " << retezec << std::endl;
    }
}


class Fronta1Mordor : public Process {
    [[noreturn]] void Behavior() override {
        info("Mordor vojaci");
        while (true) {
            switch (castBitvy) {
                case pocatek:
                    Wait(21);
                    pocetMordor--;
                    mordorStatistiky[0]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case prolomeniBrany:
                    Wait(30);
                    pocetMordor--;
                    mordorStatistiky[1]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case prijezdRohanu:
                    Wait(30);
                    pocetMordor--;
                    mordorStatistiky[2]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case vypadGondoru:
                    Wait(36);
                    pocetMordor--;
                    mordorStatistiky[3]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case posilyMordoru:
                    Wait(36);
                    pocetMordor--;
                    mordorStatistiky[4]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(26);
                    pocetMordor--;
                    mordorStatistiky[5]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};




class Fronta1Gondor : public Process {
    [[noreturn]] void Behavior() {
        info("GondorMesto vojaci");
        while (true) {
            switch (castBitvy) {
                case pocatek:
                    Wait(360);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[0]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
                case prolomeniBrany:
                    Wait(80);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[1]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
                case prijezdRohanu:
                    Wait(102);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[2]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
                case vypadGondoru:
                    Wait(360);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[3]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
                case posilyMordoru:
                    Wait(90);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[4]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(310);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[5]++;
                    if (pocetGondorMesto == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};


class Fronta2Rohan : public Process {
    [[noreturn]] void Behavior() {
        info("Rohan vojaci");
        while (true) {
            switch (castBitvy) {
                case prijezdRohanu:
                    Wait(720);
                    pocetRohan--;
                    rohanStatistiky[0]++;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
                case vypadGondoru:
                    Wait(720);
                    rohanStatistiky[1]++;
                    pocetRohan--;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
                case posilyMordoru:
                    Wait(120);
                    rohanStatistiky[2]++;
                    pocetRohan--;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(654);
                    rohanStatistiky[3]++;
                    pocetRohan--;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};

class Fronta2Mordor : public Process {
    [[noreturn]] void Behavior() {
        info("Rohan vojaci");
        while (true) {
            switch (castBitvy) {
                case prijezdRohanu:
                    Wait(12);
                    pocetMordor--;
                    mordorStatistiky[2]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case vypadGondoru:
                    Wait(15);
                    mordorStatistiky[3]++;
                    pocetMordor--;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case posilyMordoru:
                    Wait(28);
                    mordorStatistiky[4]++;
                    pocetMordor--;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(25);
                    mordorStatistiky[5]++;
                    pocetMordor--;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};

class Fronta3Mordor : public Process {
    [[noreturn]] void Behavior() {
        info("Rohan vojaci");
        while (true) {
            switch (castBitvy) {
                case posilyMordoru:
                    Wait(36);
                    mordorStatistiky[4]++;
                    pocetMordor--;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(33);
                    mordorStatistiky[5]++;
                    pocetMordor--;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};

class Fronta3Rohan : public Process {
    [[noreturn]] void Behavior() {
        info("Rohan vojaci");
        while (true) {
            switch (castBitvy) {
                case posilyMordoru:
                    Wait(103);
                    rohanStatistiky[2]++;
                    pocetRohan--;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
                case posilyGondoru:
                    Wait(434);
                    rohanStatistiky[3]++;
                    pocetRohan--;
                    if (pocetRohan == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};


class Fronta4Gondor : public Process {
    [[noreturn]] void Behavior() {
        info("GondorPomoc vojaci");
        while (true) {
            switch (castBitvy) {
                case posilyGondoru:
                    Wait(324);
                    pocetGondorPomoc--;
                    gondorPomocStatistiky++;
                    if (pocetGondorPomoc == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};

class Fronta4Mordor : public Process {
    [[noreturn]] void Behavior() {
        info("GondorPomoc vojaci");
        while (true) {
            switch (castBitvy) {
                case posilyGondoru:
                    Wait(18);
                    pocetMordor--;
                    mordorStatistiky[5]++;
                    if (pocetMordor == 0) {
                        Stop();
                    }
                    break;
            }
        }
    }
};


/**
 * Proces zajistujici bitvu.
 */
class Bitva : public Process {
    void Behavior() {
        info("Zahajeni bitvy");
        info("Prvni cast bitvy");
        (new Fronta1Gondor)->Activate();
        (new Fronta1Mordor)->Activate();
        Wait(prvniCast);
        castBitvy = prolomeniBrany;
        info("Druha cast bitvy");
        Wait(druhaCast);
        castBitvy = prijezdRohanu;
        (new Fronta2Rohan)->Activate();
        (new Fronta2Mordor)->Activate();
        info("Treti cast bitvy");
        Wait(tretiCast);
        castBitvy = vypadGondoru;
        info("Ctvrta cast bitvy");
        Wait(ctvrtaCast);
        castBitvy = posilyMordoru;
        (new Fronta3Mordor)->Activate();
        (new Fronta3Rohan)->Activate();
        info("Pata cast bitvy");
        Wait(pataCast);
        castBitvy = posilyGondoru;
        (new Fronta4Mordor)->Activate();
        (new Fronta4Gondor)->Activate();
        Wait(sestaCast);
        info("Konec bitvy");
    }
};


#endif //IMS_MAIN_HPP
