//ALGORITMOS DE ORDENAMIENTO 

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

void merge(vector<int> &vector, int low, int medio, int high){

  int i, j, k; 
  
  int n1 = medio - low + 1; 
  int n2 = high - medio; 
  
  std::vector<int> L(n1);
  std::vector<int> R(n2); 

  for( i = 0; i < n1; i++)
    L[i] = vector[low + i];
  
  for( j = 0; j < n2; j++)
    R[j] = vector[medio + 1 + j]; 

  i = j = 0; 
  k = low; 

  while(i < n1 && j < n2){
    
    if(L[i] < R[j]){
      vector[k] = L[i];
      i++; 
    }
    else{
      vector[k] = L[j]; 
      j++; 
    }
    k++; 
  }

  while(i < n1){
    vector[k] = L[i]; 
    i++; 
    k++; 
  }

  while(j < n2){
    vector[k] = R[j]; 
    j++; 
    k++; 
  }
} 

void mergeSort(vector<int> &vector, int low, int high){

  if( low < high){

    int medio = (low + high) / 2; 

    //Ordena recursivamente las dos mitades
    mergeSort(vector, low, high);
    mergeSort(vector, medio + 1, high); 

    //Fusiona las dos mitades 
    merge(vector, low, medio, high);  
  }
  
}

int particion(vector<int> &vector, int inicio, int final){
  int pivote = vector[inicio]; 

  int i = inicio+1; 
  for(int j = i; j <= final; j++){
    if(vector[j] < pivote){
      std::swap(vector[i], vector[j]); 
      i++; 
    }
  }
  std:: swap(vector[inicio], vector[i-1]);
  return i-1; 
}

void quickSort(vector<int> &vector, int inicio, int fin){
  if(inicio < fin){
    auto pivote = particion(vector, inicio, fin); 
    quickSort(vector, inicio, pivote-1); 
    quickSort(vector, pivote+1 , fin); 
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
   
  //mergeSort(myVector,0, myVector.size()-1, comparaciones);

  quickSort(myVector, 0, myVector.size());
  
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

  return 0; 
}