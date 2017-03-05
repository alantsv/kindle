#include "Data.h"

#include <iostream>
using std::cout;
using std::endl;

// Overload output operator
ostream &operator<< (ostream &output, const Data &date)
{
	switch (date.mes){
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Fev";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Ouc";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	}
	cout << " "<<date.dia << ", ";
	cout << date.ano << endl;

	return output;

}

// Overload operator ==
bool Data::operator== (const Data &date) const
{
	if (this->dia == date.dia)
		return false;
	if (this->mes == date.mes)
		return false;
	if (this->ano == date.ano)
		return false;
	
	return true;
}

// Overload assignment operator
const Data &Data::operator= (const Data &date)
{
	this->dia = date.dia;
	this->mes = date.mes;
	this->ano = date.ano;
	
	return *this;
}

// Constructor of Data class
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

//Copy constructor
Data::Data(const Data &dateCopy)
{
	this->dia = dateCopy.dia;
	this->mes = dateCopy.mes;
	this->ano = dateCopy.ano;
}

// Destructor
Data::~Data()
{
//	cout << "~Data() called" << endl;
}


// Print date
void Data::print() const
{
	cout << dia << "/" << mes << "/" << ano << endl;
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

