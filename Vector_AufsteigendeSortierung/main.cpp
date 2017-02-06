#include<iostream>
#include<vector>
#include<limits>
 
using namespace std;
 
template <typename T>
    bool sortierUeberpruefung(vector<T> &a ) {
        T min = numeric_limits<T>::min();
        bool b = true;
       
        for (int i = 0; i < a.size(); i++){
           
        if (a[i] > min) {
            min = a[i];
            b = true;
        }
        else if (a[i] < min) {
            b = false;
            break;
        }
    }  
    return b;
}
 
template <typename T>
    double vectordurchschnitt(vector<T> &a) {
    double sum = 0;
   
    for  (int i = 0;i < a.size(); i++)
    {
        sum += a[i];
    }
    return sum/a.size();
}
 
 
int main() {
    double x;
    vector<double> a;  
    while (cin >> x) {
        a.push_back(x);
    }
    if (sortierUeberpruefung(a) == true)
        cout << "Der Vector ist sortiert" << endl;
    else
        cout << "Der Vector ist nicht sortiert" << endl;
   
    cout << "Der Durchschnitt des Vectors betraegt: " << vectordurchschnitt(a) << endl;
   
    
    return 0;
}
