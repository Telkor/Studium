#include <chrono>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using namespace std::chrono;

void fill(vector<double>& v);


void quicksort(vector<double>& v, int links, int rechts) {

      int i = links;
      int j = rechts;

      int tmp;

      int pivot = v[(links + rechts) / 2];


      while (i <= j) {

            while (v[i] < pivot)
                  i++;

            while (v[j] > pivot)
                  j--;

            if (i <= j) {

                  tmp = v[i];
                  v[i] = v[j];
                  v[j] = tmp;

                  i++;
                  j--;
            }
      }
         
      if (links < j){
        quicksort(v, rechts, j);    
      }

      if (i < rechts){
        quicksort(v, i, rechts);  
      }

            
     
           
}

/*void BubbleSort(vector <double> &vec)
{
      int schleife1, schleife2;    
      int temp;             
      int groesse = vec.size( ); 
      for(schleife1 = 0; (schleife1 < groesse) ; schleife1++)
      {
         
          for (schleife2=0; schleife2 <groesse; schleife2++)
         {
               if (vec[schleife2+1] < vec[schleife2]){ 
                    temp = vec[schleife2];             
                    vec[schleife2] = vec[schleife2+1];
                    vec[schleife2+1] = temp;
                                  
               }
          }
          
      }
      for(int i=0; i<vec.size();i++){
          cout<<vec[i]<<endl;
      }
      //cout<<&vec[2]<<endl; //Speicheradresse
     return;   
}*/

int main() {
  vector<double> v1(10000); //1e5 = 100.000 Elemente
  fill(v1);
  
  vector<double> v2 = v1; //v2 ist eine Kopie von v1
  
  steady_clock::time_point start;  //steady_clock::time_point start;
  steady_clock::time_point stop;
  
  start = steady_clock::now();
  sort(v1.begin(), v1.end());
  stop = steady_clock::now();
  cout << "sort aus stdlib: " << duration_cast<duration<double>>(stop-start).count() << endl;
  
  start = steady_clock::now();
  quicksort(v2, 0, 10000);
 
 /* for(int i=0; i<v2.size();i++){
          cout<<v2[i]<<endl;
     }
  
   for(int i=0; i<v1.size();i++){
          cout<<v1[i]<<endl;
     }
 */
   
  stop = steady_clock::now();
  cout << "Mein eigener sort: " << duration_cast<duration<double>>(stop-start).count() << endl;
  
  return 0;
  
}

void fill(vector<double>& v)
{
    srand(time(0));
  for (int i = 0; i < v.size(); i++){
        v[i] = rand()%10001;
    }
}
