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
int pocetMordor = 75000;
unsigned int pocetRohan = 6000;
unsigned int pocetGondorMesto = 8500;

int main() {
    unsigned celkovaDoba = CAS_BITVA * 60 * 60 * 10; //cas je v deci sekundach
    info("Zacatek simulace");
    Init(0, celkovaDoba);
    (new Bitva)->Activate();
    Run();
    info("Konec simulace");
    cout << "---------------- Pocty ztrat v jednotlivych fazich ----------------" << endl;
    char buf[256];
    char pattern[]  = "%15s     %7d %7d %7d %7d %7d %7d";
    sprintf(buf, pattern, "", 1, 2, 3, 4, 5, 6);
    cout << buf << endl;
    sprintf(buf, pattern, "Mordor", mordorStatistiky[0], mordorStatistiky[1], mordorStatistiky[2], mordorStatistiky[3], mordorStatistiky[4], mordorStatistiky[5]);
    cout << buf << endl;
    sprintf(buf, pattern, "Gondor mesto", gondorMestoStatistiky[0], gondorMestoStatistiky[1], gondorMestoStatistiky[2], gondorMestoStatistiky[3], gondorMestoStatistiky[4], gondorMestoStatistiky[5]);
    cout << buf << endl;
    sprintf(buf, pattern, "Rohan", 0, 0, rohanStatistiky[0], rohanStatistiky[1], rohanStatistiky[2], rohanStatistiky[3]);
    cout << buf << endl;
    sprintf(buf, pattern, "Mordor", 0, 0, 0, 0, 0, gondorPomocStatistiky);
    cout << buf << endl;
    cout << "-------------------- Koncove statistiky vojaku --------------------" << endl;
    char pattern1[]  = "%22s     %7d";
    sprintf(buf, pattern1, "Armada Mordoru", pocetMordor);
    cout << buf << endl;
    sprintf(buf, pattern1, "Armada Gondoru mesto", pocetGondorMesto);
    cout << buf << endl;
    sprintf(buf, pattern1, "Armada Rohanu", pocetRohan);
    cout << buf << endl;
    sprintf(buf, pattern1, "Armada Gondoru posily", pocetGondorPomoc);
    cout << buf << endl;
    cout << "---------------------- Delka trvani simulace ----------------------" << endl;
    cout << "Cas:" << Time/10/60 << " min" << endl;
    cout << "Cas:" << Time/10/60/60 << " hod" << endl;
}
