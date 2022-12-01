#include <cstring>
#include "main.hpp"

// delka bitvy v hodinach
#define CAS_BITVA 18
#define MIN_TO_DS 600


mista castBitvy = pocatek;

// delak jednotlivych casti bitvy v deci sekundach
unsigned int prvniCast = 360 * MIN_TO_DS;
unsigned int druhaCast = 0 * MIN_TO_DS;
unsigned int tretiCast = 60 * MIN_TO_DS;
unsigned int ctvrtaCast = 60 * MIN_TO_DS;
unsigned int pataCast = 60 * MIN_TO_DS;
unsigned int sestaCast = 540 * MIN_TO_DS;

//pocty jednotek na jednotlivych armad
unsigned int pocetGondorPomoc = 10000;
unsigned int pocetMordor = 75000;
unsigned int pocetRohan = 6000;
unsigned int pocetGondorMesto = 8500;

int main() {
    unsigned celkovaDoba = CAS_BITVA * 60 * 60 * 10; //cas je v deci sekundach
    info("Zacatek simulace");
    Init(0, celkovaDoba);
    (new Bitva)->Activate();
    Run();
    info("---------------- Pocty ztrat v jednotlivych fazich ----------------");
    info("Faze bitvy -                      1     2       3       4       5       6");
    info("Armada Mordoru:                " + std::to_string(mordorStatistiky[0]) + "  " +
         std::to_string(mordorStatistiky[1]) + "  " +
         std::to_string(mordorStatistiky[2]) + "  " + std::to_string(mordorStatistiky[3]) + "  " +
         std::to_string(mordorStatistiky[4]) + "  " + std::to_string(mordorStatistiky[5]));
    info("Armada Mordoru:                " + std::to_string(mordorStatistiky[0]) + "  " +
         std::to_string(mordorStatistiky[1]) + "  " +
         std::to_string(mordorStatistiky[2]) + "  " + std::to_string(mordorStatistiky[3]) + "  " +
         std::to_string(mordorStatistiky[4]) + "  " + std::to_string(mordorStatistiky[5]));
    info("Armada Mordoru:                " + std::to_string(mordorStatistiky[0]) + "  " +
         std::to_string(mordorStatistiky[1]) + "  " +
         std::to_string(mordorStatistiky[2]) + "  " + std::to_string(mordorStatistiky[3]) + "  " +
         std::to_string(mordorStatistiky[4]) + "  " + std::to_string(mordorStatistiky[5]));
    info("Armada Gondoru posily:         " + std::to_string(pocetGondorPomoc));
    info("Konec simulace");
    info("-------------------- Koncove statistiky vojaku --------------------");
    info("Armada Mordoru:                " + std::to_string(pocetMordor));
    info("Armada Gondoru vojaci z mesta: " + std::to_string(pocetGondorMesto));
    info("Armada Rohanu:                 " + std::to_string(pocetRohan));
    info("Armada Gondoru posily:         " + std::to_string(pocetGondorPomoc));
    info("Konec simulace");
}
