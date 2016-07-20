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
  
  void printDate(string date){
    map<string, map<string,double>>::iterator it = stocks.begin();

    cout << date << " stock info:" << endl;

    while(it != stocks.end()){
      map<string,double>::iterator itDate = it->second.begin();
      while(itDate != it->second.end()){
	if(itDate->first == date){
	  cout << it->first << " $" << itDate->second <<endl;
	}
	itDate++;
      }
    
    it++;
    }
  }

   void printStock(string symbol){

     cout.setf(ios_base::fixed, ios_base::floatfield);
     cout.precision(2);

     map<string,double>::iterator itDate = stocks[symbol].begin();

     cout << symbol << " stock info:" << endl;
     while(itDate != stocks[symbol].end()){
       cout << itDate->first << " $" << itDate->second << endl;
       itDate++;
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
	temp.insert(4,"-");
	temp.insert(7,"-");
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
  
  string stockSymbol;
  string stockDate;

  cout << "Enter a stock symbol:" << endl;
  cin >> stockSymbol;

  stocks.printStock(stockSymbol); 

  cout << "Enter a date between 2009-08-21 and 2010-08-20 in that format" << endl;
  cin >> stockDate;

  stocks.printDate(stockDate);
  
}
