#include <bits/stdc++.h>
using namespace std;


// class Vehicles{
// public:
//    //attributes/properties
// 	string FuelType;
// 	string Status;
// 	string MadeinStatus;

//     //constructors
// 	Vehicles(string fuel, string status, string madein){
// 		FuelType = fuel;
// 		Status = status;
// 		MadeinStatus = madein;
// 	}
// 	//methods
// 	void VehicleDetails(){
// 		cout<<"fueltype ->" << FuelType<<"\n";
// 		cout<<"Status ->" << Status<<"\n";
// 		cout<<"MadeinStatus ->"<<MadeinStatus<<"\n";
// 	}

// };

// int main(){
// 	//ducati_bike
// 	Vehicles ducati_bike = Vehicles("petrol","used","imported");
// 	Vehicles honda_accord = Vehicles("desiel", "new", "India");
// 	cout<<"-----------ducati_bike-------------- "<<"\n";
// 	ducati_bike.VehicleDetails();
// 	cout<<"\n\n";
// 	cout<<"-----------honda_accord-------------- "<<"\n";
// 	honda_accord.VehicleDetails();
// }























// static variable -> static in memory means cann't be destroyed 
// constant variable -> cann't be changed when declared


// oops-> A programming paradigm for write programs which uses objects and classes

// objects ->1) real world entity 
//           2) instance of a class
//           3) characterstics -> states/attributes(varaibles name) and behavior(method)
// ex - dog is a object
//           states/attributes -> breed, size, age
//           behavior -> bark, sleep, run
//
// Class   ->1)Blueprint of a objects
//          2) place where you can define objects behvaior and properties/statess
//          3) also called user defined datatype


// all the variable in a class is private by default, 
// so you have to make it public in order to access from anywhere
// access modifiers in c++
// 1) private - only accesible only in this class
// 2) public - it is accesible from anywhere
// 3) protected - accesbile from different class through inheritance


// Constructor -> special type of method that is invoked each time whenever an object of a class is created
// types of constructor->
// default constructor - automically create,no parameters
// parameterized construtor -> pass parameters ex - point(int x1, int y1){ x=x1, y=y1}
// dynamic constructor - assign values dynamically
// copy constructor - used to define new members of new class by using already declared classes


//copy constructor demo
// class Point{
// private:
// 	int x,y;
// public:
// 	//default constructor
// 	Point(int x1, int y1){
// 		x=x1;
// 		y=y1;
// 	}

// 	//copy constructor
// 	Point(const Point& p1){
// 		x = p1.x;
// 		y = p1.y;
// 	}

// 	//methods
// 	int getX(){return x;}
// 	int getY(){return y;}
// };

// int main(){
// 	//calling the normal constructor
// 	Point p1(10,15);
// 	Point p2 = p1; //calling copy constructor
// 	cout<<p1.getX()<<" "<<p2.getX();

// }



// characteritics of constructor
// 1) the name of cons is same as class name
// 2) doesn't return values
// 3) overloading is possible (parameterized constructor)

// Deconstructor-> special method. destroy the objects when its is deleted
// characteristic ->
// 1) it cann't be overloaded
// 1) doesn't take an arguments (so overloading is not possible)
// 2) it is unique in a class for one class only one deconstutor is there


// class Test_Deconstructor{
// public:
// 	Test_Deconstructor(){
// 		cout<<"constructor executed\n";
// 	}
// 	~Test_Deconstructor(){
// 		cout<<"Deconstructor executed";
// 	}
// };

// int main(){
// 	Test_Deconstructor t;

// }


// Association ->
// defines relationship b/w objects like teacher and student have one-one or
// many to one and one to many relations


// Aggregation ->
// special type of association 
// represent with has-a relationship
// ex- owner has a car


// Composition ->
// special case of aggreation
// where the object which represnt has-a relationship is itself doesn't exit
// ex -> house has a room
// but if there is no house then room is also be deleted



// coupling  ->
// when one class has a detail info of other class
//tight coupling-> in order to change your skin you have to change your body
//loose coupling-> if you change shirt no need to change the body


// cohesion ->
// cohesive method perform single task very well
// ex -> iostream in c++ is highle cohesive because it only deals with input/output

// best practice of oops
// 1)don't repeat yourself
// 2) use encapsulation



// IMPORTANT
// 1)
// Encapsulation -> wrapping or binding data under a single unit
// ex- company -> finance and IT department
//             someone from IT dep wants to acces data of finance dep he is not 
//             direclty able to manipulate the he has to ask for permissions
// Encap. achieved -> access modifiers
// the private members can be accesile by using getters and setters

// ex->
// class Employee{
// private:
// 	//encapsulate data using access modifiers
// 	string Name;
// 	string Company;
// 	int Age;
// public:
// 	//use setters and getters to access the private members
// 	void setName(string name){
// 		Name = name;
// 	}
// 	// to get this
// 	string getName(){
// 		return Name;
// 	}

// 	//conditions checks 
// 	void setAge(int age){
// 		if(age>=18) Age = age; // only assign value if age is >=18
// 	}
// 	int getAge(){
// 		return Age;
// 	}
// };
// driver code
// int main(){
// 	Employee employee1;
// 	employee1.setName("deepak");
// 	employee1.setAge(20);
// 	cout<<employee1.getName();
// 	cout<<employee1.getAge();

// }


// 2)
// Abstraction-> showing only relevant things to user not the behind the scences
// ex -> apply brake you know car will stop but you don't know behind the scence
// advantages->
// 1) increase security (only provide details to user which is important)
// 2) code reuseablity

// real life scenario
// you asked your boss for promotion then you boss have to check several parameters in order to promote you
// this will behind the scence you only get to know the result(yes/no)

// abstract class
// class AbstractEmployee{
// 	virtual void AskForPromotion()=0; // virtual keyword tells that whoever class inherit this abstract
// 	//class has to provide the implementation of askforpromotion method;
// };

// class Employee:public AbstractEmployee{
// public:
// 	string Name;
// 	string Company;
// 	int Age;

// 	//constructor
// 	Employee(string name, string company, int age){
// 		Name = name;
// 		Company = company;
// 		Age = age;
// 	}

// 	//AskForPromotion
// 	void AskForPromotion(){
// 		if(Age>=23) cout<<Name<<" Promoted!!";
// 		else cout<<Name<<" Sorry!! you're not eligible";
// 	}
// };

// int main(){
// 	Employee employee1 = Employee("deepak","google",21);
// 	Employee employee2 = Employee("singh","google",30);
//     employee1.AskForPromotion();
//     cout<<"\n\n";
//     employee2.AskForPromotion();
// }


// 3)
// Inheritance-> when child class uses properties and behavior of parent class
// base class / parent class

// class Employee{
// public:
// 	string Name;
// 	string Company;
// 	int Age;

// 	//constructor
// 	Employee(string name, string company, int age){
// 		Name = name;
// 		Company = company;
// 		Age = age;
// 	}
// };

// //child class

// class Developer:public Employee{ // if you want to use the methods used public inheritance
// public:
// 	string Favlanguage;
// 	//constructor
// 	Developer(string name, string company, int age, string favlan):Employee(name,company,age){
// 		Favlanguage = favlan;
// 	}

// 	//method
// 	void FixBug(){
// 		cout<<Name<<" fixed bug using "<<Favlanguage;
// 	 }
// };

// int main(){
// 	Developer d1 = Developer("deepak","google",21,"c++");
// 	d1.FixBug();
// }


// 4)
// polymorphism->
// when objects have many different forms with different charactersitcs
// types of polymorphism->
// 1)CompileTime -> happens on compile time , using function overloading and method overloading
// 2)runtime-> happens due to function overriding


// function overloding -> same name with different parameters
// function overriding -> parent class and child class have same function name 
//                       and return type


// class Employee{
// public:
// 	string Name;
// 	string Company;
// 	int Age;

// 	//contructor
// 	Employee(string name,string company,int age){
// 		Name = name;
// 		Company = company;
// 		Age = age;
// 	}

// 	//method for child
// 	virtual void Work(){
// 		cout<<Name<<" Doing his/her job , reading emials"<<"\n";

// 	}
// };


// class Developer: public Employee{
// public:
// 	string Favlang;
// 	//contructor
// 	Developer(string name,string company,int age,string favlang):Employee(name,company,age){
// 		Favlang = favlang;
// 	}

// 	//method
// 	void Work(){
// 		cout<<Name<<" works with "<<Favlang<<"\n";
// 	}
// };


// class Teacher: public Employee{
// public:
// 	string Subject;
// 	//constructor
// 	Teacher(string name,string company,int age,string sub):Employee(name,company,age){
// 		Subject = sub;
// 	}
// 	//method
// 	void Work(){
// 		cout<<Name<<" teachs "<<Subject<<"\n";
// 	}
// };


// int main(){
// 	Developer d = Developer("deepak","google",21,"c++");
// 	Teacher  t = Teacher("singh", "youtube",35,"history");

// 	Employee *e1 = &d;
// 	Employee *e2 = &t;
// 	e1->Work();
// 	e2->Work();
// 	// d.Work();
// 	// t.Work();
// }










//Revision

// class AbstractEmployee{
// 	virtual void AskForPromotion()=0;
// };

// class Employee: public AbstractEmployee{
// protected:
// 	string Name;
// 	string Company;
// 	int Age;
// public:
// 	void setName(string name){
// 		Name = name;
// 	}
// 	void setCompany(string company){
// 		Company = company;
// 	}
// 	void setAge(int age){
// 		Age = age;
// 	}

// 	string getName(){
// 		return Name;
// 	}
// 	string getCompany(){
// 		return Company;
// 	}
// 	int getAge(){
// 		return Age;
// 	}
// 	// //constructor
// 	Employee(string name,string company,int age){
// 		Name = name;
// 		Company = company;
// 		Age=age;
// 	}

// 	//method
// 	void EmployeeDetails(){
// 		cout<<"Name -> "<<Name<<"\n";
// 		cout<<"Company -> "<<Company<<"\n";
// 		cout<<"Age -> "<<Age<<"\n";
// 	}

// 	void AskForPromotion(){
// 		if(Age>=21) cout<<Name<<" promoted!!\n";
// 		else cout<<Name<<" not eligible\n";
// 	}

// 	virtual void Work(){
// 		cout<<Name<<" default work"<<"\n";
// 	}

// };


// class Developer: public Employee{
// public:
// 	string Favlang;
// 	//constructor
// 	Developer(string name,string company,int age,string favlang):Employee(name,company,age){
// 		Favlang = favlang;
// 	}

// 	//method
// 	void Work(){
// 		cout<<Name<<" fixed bug using "<<Favlang<<"\n";
// 	}
// };













// class Teacher: public Employee{
// public:
// 	string Sub;
// 	//constructor
// 	Teacher(string name,string company,int age, string sub):Employee(name,company,age){
// 		Sub = sub;
// 	}

// 	//method
// 	void Work(){
// 		cout<<Name<<" teaches " <<Sub<<"\n";
// 	}
// };

// int main(){
// 	Developer d = Developer("deepak","google",21,"c++");
// 	Teacher t = Teacher("singh","youtube",35,"history");

// 	Employee *e1 = &d;
// 	Employee *e2 = &t;

// 	e1->Work();
// 	e2->Work();
// 	// Employee employee1 = Employee("deepak","google",20);
// 	// Employee employee2 = Employee("singh","google",22);

// 	// employee1.AskForPromotion();
// 	// employee2.AskForPromotion();
// 	// employee1.setName("deepak");
// 	// employee1.setCompany("google");
// 	// employee1.setAge(21);

// 	// cout<<employee1.getAge();
// }







// class Person{
// public:
// 	string Name;
// 	//constructor
// 	Person(string name){
// 		Name = name;
// 	}
// };



// class CarName{
// public:
// 	string Name;
// 	string Color;

// 	CarName(string name,string color){
// 		Name = name;
// 		Color = color;
// 	}
// };

// class DriverName{
// public:
// 	string Name;
// 	int Yrofexp;

// 	Driver(string name,int yoe){
// 		Name = name;
// 		if(Yrofexp>=10) Yrofexp = yoe;
// 	}
// };


// class MP: public Person{
// public:
// 	string Name;
// 	// string CarName;
// 	// string DriverName;
// 	int SpendingLimit;
// 	MP(string name,int spendinglimit):Person(name){
// 		SpendingLimit = 50000;
// 	}

// 	//method
// 	void details(){
// 		cout<<Name<<" has spending limit "<<SpendingLimit<<"\n";
// 	}
// };


// class Constituency{
// public:
// 	string Name;
// 	int Area;
// 	string Mpofconstituency;

// 	//constructor
// 	Constituency(int name,int area,string mp){
// 		Name = name;
// 		Area = area;
// 		Mpofconstituency = mp;
// 	}

// 	//method
// 	void ConstituencyDetails(){
// 		cout<<"Name ->"<<Name<<"\n";
// 		cout<<"Area -> "<<Area<<"\n";
// 		cout<<"Mpofconstituency"<<Mpofconstituency<<"\n";
// 	}
// };





// class Minister: public MP{
// public:
// 	string Name;
// 	string CarName;
// 	string DriverName;
// 	int SpendingLimit;
// 	//constructor
// 	Minister(string name, int spendinglimit, string carname,string driver):MP(name,spendinglimit){
// 		SpendingLimit = 70000;
// 		CarName = carname;
// 		DriverName = driver;
// 	}
// 	void details(){
// 		cout<<"Name ->"<<Name<<"\n";
// 		cout<<"carname->"<<CarName<<"\n";
// 		cout<<"DriverName ->"<<DriverName<<"\n";
// 		cout<<"SpendingLimit ->"<<SpendingLimit<<"\n";
// 	}
// };

// class PM: public Minister{
// public:
// 	string Name;
// 	string CarName;
// 	string DriverName;
// 	int SpendingLimit;
// 	int NoofCars;

// 	PM(string name,int spendinglimit,string carname,string drivername,int noofcar):Minister(name,spendinglimit,carname,drivername){
// 		NoofCars = noofcar;
// 		SpendingLimit = 170000;
// 	}

// 	//method
// 	void details(){
// 		cout<<"Name ->"<<Name<<"\n";
// 		cout<<"carname->"<<CarName<<"\n";
// 		cout<<"DriverName ->"<<DriverName<<"\n";
// 		cout<<"SpendingLimit ->"<<SpendingLimit<<"\n";
// 		cout<<"NoofCars->"<<NoofCars<<"\n";
// 	}
// };


// int main(){
// 	PM pmofindia = PM("modi",CarName("audi","blue"),DriverName("deepak",20),170000,5);
// }






//music player


// class Song{
// public:
// 	//attributes/properties
// 	string SongName;
// 	string SongTitle;
// 	string SingerName;

// 	//consturtor
// 	Song(string songname, string songtitle,string singername){
// 		SongTitle = songtitle;
// 		SongName = songname;
// 		SingerName = singername;
// 	}
// };

// class MusicPlayer{
// public:
// 	string SongRequest;
// 	int size;
// 	CircularLinkedlist playerlist;

// 	MusicPlayer(string songreq, int s, )
// };