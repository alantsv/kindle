#include "Data.h"

#include <iostream>
using std::cout;

// Overload assignment operator
const Data &Data::operator= (const Data &date)
{
	this->dia = date.dia;
	this->mes = date.mes;
	this->ano = date.ano;
	
	return *this;
}

// Constructor
Data::Data(int d, int m, int a) 
{
	if ( m > 0 && m <= 12 ) // validate the month
		mes = m;
	
	if ( a < 0 )
		ano = 1900;
	else
		ano = a;
   
	dia = VerificaDia(d);

}

//Copy contructor
Data::Data(const Data &dateCopy)
{
	this->dia = dateCopy.dia;
	this->mes = dateCopy.mes;
	this->ano = dateCopy.ano;
}

// Print date
void Data::print() const
{
   cout << dia << '/' << mes << '/' << ano;
   
}

// Check date
int Data::VerificaDia(int diaTeste) const
{
	static const int diasPorMes[ 13 ] = 
	   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if ( diaTeste > 0 && diaTeste <= diasPorMes[ mes ] )
		return diaTeste;
	
	if ( mes == 2 && diaTeste == 29 && ( ano % 400 == 0 ||
			( ano % 4 == 0 && ano % 100 != 0 ) ) )
		return diaTeste;
	
	cout << "Dia invalido (" << diaTeste << ") configurado para 1.\n";
	return 1; 

	
}

