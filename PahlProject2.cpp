#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;



int main(){


  
  map<string, map<string,double>> stocks;

  map<string, double> temp;

  temp["20010101"] = 2.12;
  temp["20010102"] = 2.13;
  stocks["A"] = temp;
  temp.clear();
  temp["20010103"] = 2.14;
  temp["20010104"] = 2.15;
  stocks["B"] = temp;
  

  map<string, map<string,double>>::iterator it = stocks.begin();
  while(it != stocks.end()){
    map<string,double>::iterator itDate = it->second.begin();
    while(itDate != it->second.end()){
      cout << it->first << itDate->first << itDate->second << endl;
      itDate++;
    }
    
    it++;
  }

}
