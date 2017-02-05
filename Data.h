#ifndef _DATA_H_
#define	_DATA_H_

#include <ostream>
using std::ostream;

class Data 
{
	//Overload output operator
	friend ostream &operator<<(ostream &, const Data &);
public:
	const Data &operator=(const Data &);
	bool operator== (const Data &) const;
	// Defined operator !=
	bool operator!= (const Data &date) const
	{
		return ! (*this == date);
	}
	Data( int = 1, int = 1, int = 1900);
	Data(const Data &);
	~Data();
	void print() const;
	 
private:
	 
	int mes;
	int dia;
	int ano;
	 
	int VerificaDia( int ) const;


};

#endif	/* DATA_H */

