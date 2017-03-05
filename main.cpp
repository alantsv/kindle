#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "OnlineService.h"
#include "User.h"
#include "Data.h"
#include "Kindle.h"
#include "Dropbox.h"
#include "GoogleDocs.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

int main()
{
	Data yesterday(04, 03, 2017);
	Data today(05, 03, 2017);
	User me("Alan Veloso", 22, 201509);
	User you("Leo da Costa", 20, 201519);

	// create vector of four base-class pointers
	vector < OnlineService * > services( 4 );

	// initialize vector with various kinds of Employees
	services[ 0 ] = new Kindle("A Coisa", today, me, "Amazon, Foxconn"); 
	services[ 1 ] = new GoogleDocs("relatorio-parcial", true, me, "Writely Team, Google", today );
	services[ 2 ] = new Dropbox("relatorio-final.pdf", me, "Dropbox, Inc.", yesterday); 
	services[ 3 ] = new Dropbox("proactive-ethernet-congestion-control.pdf", you, "Dropbox, Inc", today);

	// polymorphically process each element in vector employees
	for ( size_t i = 0; i < services.size(); i++ )
	{
 		services[i]->print(); // output employee information
		// downcast pointer                            

		Kindle *derivedPtr = dynamic_cast<Kindle *>(services[i]); 

		// determine whether element points to base-salaried  commission employee
		if ( derivedPtr !=0 ) // 0 if not a BasePlusCommissionEmployee
		{
			cout << derivedPtr->getBookName() << " already enable for download!" << endl;
			cout << endl;

		} // end if
		cout << "----------------------------------------------------------------" << endl; 
	} // end for

	// release objects pointed to by vector's elements
	for ( size_t j = 0; j < services.size(); j++ )
	{
		// output class name                           
		cout << "Deleting objects " << typeid(*services[j]).name() << "..." <<endl ;
		delete services[ j ];
		cout << endl;
	} // end for

	return 0;
} // end main
