#ifndef DATA_H
#define	DATA_H

class Data 
{
public:
    Data();
    Data( int = 1, int = 1, int = 1900 );
    Data(const Data &);
    void print() const;
    
private:
    
    int mes;
    int dia;
    int ano;
    
    int VerificaDia( int ) const;


};

#endif	/* DATA_H */

