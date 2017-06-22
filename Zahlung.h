#ifndef ZAHLUNG_H
#define ZAHLUNG_H
#include <iostream>
#include <string>

using namespace std;

class Zahlung {
public:
    Zahlung();
    virtual ~Zahlung();

private:
    double betrag;
    string waehrung;
};

#endif /* ZAHLUNG_H */

