#include <iostream>
using namespace std;
class DB;
class DM{
int meters;
int centimeters;
public:
    void initialize();
    friend void add( DM&, DB&);
    void display();
};

class DB{
int feet;
int inches;
public:
    void initialize();
    friend void add( DM&, DB&);
    void display();
};

void DM::initialize(){
cout<<"Enter length in meters and centimeters"<<endl;
cin>>meters>>centimeters;
}

void DM::display(){
cout<<meters<<" meters and "<<centimeters<<" centimeters"<<endl;
}

void DB::display(){
cout<<feet<<" feet and "<<inches<<" inches"<<endl;
}

void DB::initialize(){
cout<<"Enter length in feet and inches"<<endl;
cin>>feet>>inches;
}

void add(DM& x,DB& y){
int choice;
cout<<"Enter 1.To get sum in meters and centimeters"<<endl<<
        "2.To get sum in feet and inches"<<endl<<
        "3.To exit"<<endl;
        cin>>choice;

        switch(choice){
    case 1:
        DM resultdm;
        resultdm.meters=x.meters;
        resultdm.centimeters=x.centimeters+(y.inches*2.54)+(y.feet*30.4800164592);
        if(resultdm.centimeters>100){
            resultdm.meters+=resultdm.centimeters/100;
            resultdm.centimeters=resultdm.centimeters%100;
        }
        resultdm.display();
        break;
    case 2:
        DB resultdb;
        resultdb.feet=y.feet;
        resultdb.inches=y.inches+(x.centimeters*0.3937008)+(x.meters*39.3701);
        if(resultdb.inches>12){
            resultdb.feet+=resultdb.inches/12;
            resultdb.inches=resultdb.inches%12;
        }
        resultdb.display();
        break;
    case 3:
        break;
    default:
        cout<<"Wrong choice"<<endl;
        }

}

main(){
DB db1;
DM dm1;
db1.initialize();
dm1.initialize();
add(dm1,db1);
}
