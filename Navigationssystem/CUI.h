/* 
 * File:   CUI.h
 * Author: fs
 *
 * Created on 3. Januar 2018, 18:19
 */

#ifndef CUI_H
#define	CUI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class CUI {
public:
    CUI();
    virtual ~CUI();
    int zeigeMenu();
    void Ortneu();
    void Ortloeschen();
    void NamenEinlesen();
    void NamenSchreiben();
    void NamenAusgeben();
    void StartZielEingeben();
    //int Beenden();
        
private:
    CUI(const CUI& orig);
    vector<string*> Ortsname;
    string Ort_Dateiname;
};

#endif	/* CUI_H */

