//Algoritmo de Busqueda Secuencial con vectores 

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

int linearSearch(std::vector<int> nums, int key, int &compara){
  int i = 0; 
  while(i < nums.size() && nums[i] != key){
    i++; 
    compara++; 
  }
  
  if( i < nums.size()){
    return i; 
  }else{
    return -1; 
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

  cout<<"Key buscado esta en el indice: "<<linearSearch(myVector, key, comparaciones)<<endl;

  auto endTime = std::chrono::high_resolution_clock::now(); 
  auto totalTime = endTime - startTime; 

  cout<<"Tiempo de ejcucion en ms: "<<totalTime/std::chrono::milliseconds(1)<<endl;
  cout<<"Numero de comparaciones: "<<comparaciones<<endl; 

  return 0; 
}