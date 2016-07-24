/**
 * File for reading stock data from a file and displaying by date or ticker.
 *
 * @file PahlProject2.cpp
 * @author Nicholas Pahl
 * @date July 25, 2016
 */

#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Class containing all stock functions and collection.
 */
class Stocks{

  //stores stock info <ticker, <date, price>>
  map<string, map<string,double>> stocks;

public:
  Stocks();
  
  //Prints all the stocks and their price for given date
  void printDate(string date){
    //iterator for stock
    map<string, map<string,double>>::iterator it = stocks.begin();

    cout << date << " stock info:" << endl;

    //loop through all stocks
    while(it != stocks.end()){
      map<string,double>::iterator itDate = it->second.begin();
      //loop through all dates
      while(itDate != it->second.end()){
	//if the date matches the user input date
	if(itDate->first == date){
	  //print the ticker and price
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
     
     //loop for all dates of given stock 
     while(itDate != stocks[symbol].end()){
       //print date and price
       cout << itDate->first << " $" << itDate->second << endl;
       itDate++;
     }    
  }

};

Stocks::Stocks(){
  //open the file
  ifstream file("sp500hst.txt");
  string line;
  string symbol = "";
  string date;
  double price;

  string temp;
  int i;

  map<string,double> stock;

  //loop for ever line in file
  while(getline(file, line)){
    //puts line as a stream
    istringstream iss(line);
    i = 0;
    //loop though line seperating by ','
    while(getline(iss, temp, ',')){
      //seperates and stores date, ticker, and price
      if(i == 0){
	temp.insert(4,"-");
	temp.insert(7,"-");
	date = temp;
      } else if (i == 1){
	//for first time through dont make new stock
	if(symbol == "");
	//if stock ticker is different make a new stock
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
