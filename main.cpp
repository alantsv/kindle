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

	vector < OnlineService * > services( 4 );

	services[ 0 ] = new Kindle("A Coisa", today, me, "Amazon, Foxconn", "Terror", 1); 
	services[ 1 ] = new GoogleDocs("relatorio-parcial", true, me, "Writely Team, Google", today );
	services[ 2 ] = new Dropbox("relatorio-final.pdf", me, "Dropbox, Inc.", yesterday); 
	services[ 3 ] = new Dropbox("proactive-ethernet-congestion-control.pdf", you, "Dropbox, Inc", today);

	for ( size_t i = 0; i < services.size(); i++ )
	{
 		services[i]->print();

		Kindle *derivedPtr = dynamic_cast<Kindle *>(services[i]); 

		if ( derivedPtr !=0 )
		{
			cout << derivedPtr->getBookName() << " already enable for download!" << endl;
			cout << endl;

		} 
		cout << "----------------------------------------------------------------" << endl; 
	} 

	
	for ( size_t j = 0; j < services.size(); j++ )
	{
		
		cout << "Deleting objects " << typeid(*services[j]).name() << "..." <<endl ;
		delete services[ j ];
		cout << endl;
	}

	return 0;
}
