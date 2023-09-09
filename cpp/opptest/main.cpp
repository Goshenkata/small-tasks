#include <iostream>
#include "Date.h"
int main() {
    Date date;
    date.setDate(4,9,2023);

    Date copy {};
    copy.copyFrom(date);
    copy.print();
    return 0;
}
