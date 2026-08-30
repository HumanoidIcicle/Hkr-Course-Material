#include <iostream>
#include "ComputerSystem.h"

int main() {
    Computer gamingPC("Gaming Beast", "Intel i9-13900K", 5, "DDR5", 32, "NVMe SSD", 2000);
    Computer officePC("Office Pro", "Intel i5-12400", 2, "DDR4", 16, "SATA SSD", 512);
    Computer laptop("UltraBook", "AMD Ryzen 7 5800U", 4, "LPDDR4", 16, "NVMe SSD", 1000);

    // Display specifications
    cout << "=== COMPUTER SPECIFICATIONS ===" << endl;

    gamingPC.specs();
    officePC.specs();
    laptop.specs();
    return 0;
}
