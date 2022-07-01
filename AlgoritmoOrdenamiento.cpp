//Algoritmos de Ordenamiento 

 /*
  * Algoritmos de busqueda
  * 
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución:
  *  ./main < TestCases/test01.txt
  */

#include <vector>
#include <iostream>
#include <chrono>

using std::cout; 
using std:: cin; 
using std:: endl; 
using std:: vector; 

void swapSort(vector<int> &vector, int &compara, int &nSwaps){
  compara = nSwaps = 0; 
  for(int i=0; i < vector.size(); i++){

    for(int j=i+1; j < vector.size(); j++){

      if(vector[i] > vector[i]){
        std::swap(vector[i], vector[j]);
        nSwaps++;
      }
    }
  }
}

int main(void) {
  int i, tmp, size, key, flag; 

  auto startTime = std::chrono::high_resolution_clock::now(); 

  cin >> size; 
  cout << "Size: " << size << endl;
  
  cin >> key;
  cout << "Key: " << key << endl;
  
  cin >> flag;
  cout << "Print flag: " << flag << endl;

  //Declaracion del vector con los numeros 
  vector<int> myVector; 

  for(i = 0; i < size; i++){
    cin>>tmp; 
    myVector.push_back(tmp);
  }
  if(flag){
    cout<<"Los elementos del arreglo son : "<<endl; 
    for(i = 0; i < size; i++){
      cout<<myVector[i]<<" "<<endl; 
    }
    cout<<endl; 
  }

  int comparaciones = 0;
  int intercambios = 0; 

  swapSort(myVector, comparaciones, intercambios); 
  if(flag){
    cout<<"Los elementos del arreglo ordenado son : "<<endl; 
    for(i = 0; i < size; i++){
      cout<<myVector[i]<<" "<<endl; 
    }
    cout<<endl; 
  }
  
  //Termina conteo de tiempo de ejecucion 
  auto endTime = std::chrono::high_resolution_clock::now(); 
  auto totalTime = endTime - startTime; 

  cout<<"Tiempo de ejcucion en ms: "<<totalTime/std::chrono::milliseconds(1)<<endl;
  cout<<"Numero de comparaciones: "<<comparaciones<<endl; 
  cout<<"Numero de intercambios: "<<intercambios<<endl; 

  return 0; 
}