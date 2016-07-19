#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>

using namespace std;

class Stocks{

  map<string, map<string,double>> stocks;

public:
  Stocks();

  void printStock(){
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

};

Stocks::Stocks(){
  ifstream file("sp500hst.txt");
  string line;
  string symbol = "";
  string date;
  double price;

  string temp;
  int i;

  map<string,double> stock;

  while(getline(file, line)){
    istringstream iss(line);
    i = 0;
    while(getline(iss, temp, ',')){
      if(i == 0){
	date = temp;
      } else if (i == 1){
	if(symbol == "");
	else if(temp != symbol){
	  stocks[symbol] = stock;
	  stock.clear();
	}
	symbol = temp;
      } else if (i == 2){
	price = stod(temp);
      }
      i++;
    }
    stock[date] = price;
  }

  stocks[symbol] = stock;

}

int main(){
  Stocks stocks;

  stocks.printStock(); 
  
  /*
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
*/

}
