//
// Created by sbakaj on 12/1/22.
//

#ifndef IMS_MAIN_HPP
#define IMS_MAIN_HPP

#include <iostream>
#include <simlib.h>
#include <string>

// zapina debugovaci mod
bool debug = true;

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
extern unsigned int pocetMordor;
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


class Mordor : public Process {
    void Behavior() override {
        info("Mordor vojaci");
        while (true) {
            switch (castBitvy) {
                case pocatek:
                    Wait(21);
                    pocetMordor--;
                    mordorStatistiky[0]++;
                    break;
                case prolomeniBrany:
                    Wait(30);
                    pocetMordor--;
                    mordorStatistiky[1]++;
                    break;
                case prijezdRohanu:
                    Wait(9);
                    pocetMordor--;
                    mordorStatistiky[2]++;
                    break;
                case vypadGondoru:
                    Wait(10);
                    pocetMordor--;
                    mordorStatistiky[3]++;
                    break;
                case posilyMordoru:
                    Wait(13);
                    pocetMordor--;
                    mordorStatistiky[4]++;
                    break;
                case posilyGondoru:
                    Wait(6);
                    pocetMordor--;
                    mordorStatistiky[5]++;
                    break;
            }
        }
    }
};




class GondorMesto : public Process {
    void Behavior() {
        info("GondorMesto vojaci");
        while (true) {
            switch (castBitvy) {
                case pocatek:
                    Wait(360);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[0]++;
                    break;
                case prolomeniBrany:
                    Wait(80);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[1]++;
                    break;
                case prijezdRohanu:
                    Wait(102);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[2]++;
                    break;
                case vypadGondoru:
                    Wait(360);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[3]++;
                    break;
                case posilyMordoru:
                    Wait(90);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[4]++;
                    break;
                case posilyGondoru:
                    Wait(310);
                    pocetGondorMesto--;
                    gondorMestoStatistiky[5]++;
                    break;
            }
        }
    }
};


class Rohan : public Process {
    void Behavior() {
        info("Rohan vojaci");
        while (true) {
            switch (castBitvy) {
                case prijezdRohanu:
                    Wait(720);
                    pocetRohan--;
                    rohanStatistiky[0]++;
                    break;
                case vypadGondoru:
                    Wait(720);
                    rohanStatistiky[1]++;
                    pocetRohan--;
                    break;
                case posilyMordoru:
                    Wait(55);
                    rohanStatistiky[2]++;
                    pocetRohan--;
                    break;
                case posilyGondoru:
                    Wait(261);
                    rohanStatistiky[3]++;
                    pocetRohan--;
                    break;
            }
        }
    }
};


class GondorPomoc : public Process {
    void Behavior() {
        info("GondorPomoc vojaci");
        while (true) {
            switch (castBitvy) {
                case posilyGondoru:
                    Wait(324);
                    pocetGondorPomoc--;
                    gondorPomocStatistiky++;
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
        (new Mordor)->Activate();
        (new GondorMesto)->Activate();
        Wait(prvniCast);
        castBitvy = prolomeniBrany;
        info("Druha cast bitvy");
        Wait(druhaCast);
        castBitvy = prijezdRohanu;
        (new Rohan)->Activate();
        info("Treti cast bitvy");
        Wait(tretiCast);
        castBitvy = vypadGondoru;
        info("Ctvrta cast bitvy");
        Wait(ctvrtaCast);
        castBitvy = posilyMordoru;
        info("Pata cast bitvy");
        Wait(pataCast);
        castBitvy = posilyGondoru;
        (new GondorPomoc)->Activate();
        Wait(sestaCast);
        info("Konec bitvy");
    }
};

#endif //IMS_MAIN_HPP
