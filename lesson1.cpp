#include <iostream>
using namespace std;

class People{
private:
  string _name;
  int _age;
  string _address;

public:
  People(){};
  People(string name,int age, string address);
  ~People(){};
  virtual void display();
  friend int operator==(People &p1,People &p2);
  string getName(){return _name;}
  int getAge(){return _age;}
  string getAddress(){return _address;}

};
People::People(string name,int age,string address){
  _name = name;
  _age = age;
  _address = address;
}
void People::display(){
  cout << "Class People" << endl;
}
int operator==(People &p1, People &p2){
  if(p1.getAge() != p2.getAge()
    || p1.getName() != p2.getName()
    || p1.getAddress() != p2.getAddress()
){
  return 0;
}
else{
  return 1;
}
}
class Student:public People{
private:
  int mssv;
  string course;
public:

  Student(){};
  Student(string name,int age,string address,int mssv,string course):People(name,age,address){
    People people(name,age,address);
    this->mssv = mssv;
    this->course = course;
  }
  void  display() {
    cout << "name: " << this->getName() << endl;
    cout << "age: " << this->getAge() << endl;
    cout << "address: " << this->getAddress() << endl;
    cout << "mssv: " << mssv << endl;
    cout << "course: " << course << endl;
  }

};
int main(int argc, char const *argv[]) {
  Student student1("s1",26,"hn",26,"van");
  Student student2("s2",28,"hn",28,"hoa");

  People *people;
  people = &student1;
  people->display();
  people = &student2;
  people->display();


  return 0;
}
