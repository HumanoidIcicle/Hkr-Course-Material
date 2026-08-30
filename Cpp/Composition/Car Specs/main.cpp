#include <ostream>
#include "parts.h"

int main() {
    Engine e("V8", 450);
    Wheel w("Alloy", 18.5);
    Transmission t("Auto", 6);

    Car car1(e,w,t);
    cout <<"\n================================" <<endl;
    car1.specs();
    car1.startCar();

    return 0;
}
