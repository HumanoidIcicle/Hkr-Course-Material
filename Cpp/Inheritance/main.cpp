#include "shapes.h"
int main() {
    Circle one(3, "yellow");
    Rect two(13,5, "green");

    one.display(one.area());
    two.display(two.area());
    return 0;
}
