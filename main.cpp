#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"

using namespace std;

class Karta{
private:
    DinString mestopolaska;
    DinString mestodolaska;
    float duzinaputovanja;
    float cenakarte;
    int id;

public:
    Karta(){
        mestopolaska="Novi Sad";
        mestodolaska="Beograd";
        duzinaputovanja=50;
        cenakarte=100;
        id=0;
    }

    Karta(DinString a, DinString b, float c, float d, int e){
        mestopolaska=a;
        mestodolaska=b;
        duzinaputovanja=50;
        if(c>0)
            duzinaputovanja=c;
        cenakarte=100;
        if(d>0)
            cenakarte=d;
        e=id;
    }

    virtual bool jeftinaKarta()=0;

    DinString getMestopolaska()const{
        return mestopolaska;
    }

    DinString getMestodolaska()const{
        return mestodolaska;
    }

    float getDuzinaputovanja()const{
        return duzinaputovanja;
    }

    float getCenakarte()const{
        return cenakarte;
    }

    int getId()const{
        return id;
    }
};

class AvionskaKarta: public Karta{
public:

    ///kako se konstruise?
    bool jeftinaKarta(){
        if(getCenakarte()/getDuzinaputovanja()<1){
            return true;
        }
        return false;
    }

    void ispisi(){
        cout<<"mestopolaska: "<<getMestopolaska()<<endl;
        cout<<"mestodolaska: "<<getMestodolaska()<<endl;
        cout<<"duzinaputovanja: "<<getDuzinaputovanja()<<endl;
        cout<<"cenakarte: "<<getCenakarte()<<endl;
        cout<<"id: "<<getId()<<endl;
        cout<<"jeftinakarta: ";
        if(jeftinaKarta()){
            cout<<"da"<<endl;
        }else{
            cout<<"ne"<<endl;
        }
    }
};

class Putovanje{
private:
    DinString nazivputovanja;
    int maxcena;
    List<AvionskaKarta> listakarti;

public:
    Putovanje(){
        nazivputovanja="Primer";
        maxcena=1;
    }

    Putovanje(DinString a, int b){
        nazivputovanja=a;
        maxcena=1;
        if(b>0)
            maxcena=b;
    }

    DinString getNazivputovanja()const{
        return nazivputovanja;
    }

    int getMaxcena()const{
        return maxcena;
    }

    bool dodajKartu(AvionskaKarta &p){ ///nije gotovo
        if(1){
            listakarti.add(listakarti.size()+1,p);
            return true;
        }
        return false;
    }

    bool izbaciKartu(int a){
        int i;
        AvionskaKarta karta;
        for(i=0;i<=listakarti.size();i++){
            listakarti.read(i,karta);
            if(karta.getId()==a){
                listakarti.remove(i);
                return true;
            }
        }
        return false;
    }

    void ispisi(){
        int i;
        AvionskaKarta karta;
        cout<<"maxcena: "<<maxcena<<endl;
        cout<<"nazivputovanja: "<<nazivputovanja<<endl;
        cout<<"brojkarti: "<<listakarti.size()<<endl;
        for(i=0;i<=listakarti.size();i++){
            listakarti.read(i,karta);
            if(karta.jeftinaKarta()){
                karta.ispisi();
            }
        }
    }
};

int main()
{
    AvionskaKarta a1;
    AvionskaKarta a2("Subotica","Smederevo",400,1000,24);
    AvionskaKarta a3("Beograd","Nis",150,100,42);
    Putovanje p;
    p.dodajKartu(a1);
    p.dodajKartu(a2);
    p.dodajKartu(a3);
    p.ispisi();

    cout << "Hello world!" << endl;
    return 0;
}
