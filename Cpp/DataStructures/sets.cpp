#include <iostream>
#include <set>
#include <string>

using namespace std;

void show(auto it) {
    for (auto& item : it) {
        std::cout << item << ", ";
    }
    cout << std::endl;
}

int main() {
    set<string> c = {"Volvo", "BMW", "Ford", "Mazda"};
    c.insert("Toyota");
    c.insert("Tesla");
    c.insert("Audi");
    show(c);

    auto it;
    c.insert("Audi");

    if (it == c.find("Audi")) {
        cout << *it<< "Already in there.\n" << endl;
    }
    else cout << "Added to set.\n" << endl;

    show(c);
    c.erase("BMW"); //remove spec item
    return 0;
}
