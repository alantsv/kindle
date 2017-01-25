#include <iostream>
#include <string>
#include "kindleUlimeted.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
/*
3 construtores - incluindo um de cópia ok
2 métodos - não pode ser get ou set ok
1 método extra que precisa ser const
1 atributo static - inicializar no cpp ok
1 atributo static const - inicializar no cpp
1 método static - mostrar o seu uso no main
Composição com classe Data
1 array  - precisa ser realmente usado

Extra
Composição com outra classe que você criar
Essa nova classe deve ter dois atributos e dois métodos (não pode ser get ou set)
*/

int main ()
{
	string autor;
	string bookName;
	KindleUnlimeted myKindle;
	cout << "\nPor favor, entre com o nome do livro:" << endl;
	getline( cin, bookName);
	getline( cin, autor);
	myKindle.setBookName(bookName, autor);
	myKindle.downloadBook();
	return 0;

}
