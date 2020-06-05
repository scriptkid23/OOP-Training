#include <iostream>
using namespace std;
class Robot{
  string name;
  string makein;
  float weight;
  int year;
public:
  Robot(){};
  Robot(string name,string makein, float weight, int year){
    this->name  = name;
    this->makein = makein;
    this->weight = weight;
    this->year = year;
  }
  friend void setting(Robot *rb);
  void display();
  friend class Factory;

};
class TransportRobot;
class Factory;

void setting(Robot *rb) {
  cout << "Name: "; cin >> rb->name;
  cout << "makein: "; cin >> rb->makein;
  cout << "weight: "; cin >> rb->weight;
  cout << "year: "; cin >> rb->year;
}
void Robot::display(){
  cout << name << makein << weight << year;
}
class TransportRobot:public Robot{
  float velocity;
public:
  TransportRobot(string name,string makein,float weight, int year, float velocity):Robot(name,makein,weight,year){
    Robot robot(name,makein,weight,year);
    this->velocity = velocity;
  }

  friend class Factory;
};
class Factory{
  Robot* robots;
  int number;

public:
  Factory(int n){
    this->robots = new Robot[n];
    this->number = n;
  };
  void init(){
    for(int i = 0 ; i < number;i++){
      setting(&this->robots[i]);
    }
  };
  void display();
  void displayTransportRobot( TransportRobot transRobot){
    cout << transRobot.velocity;
  }
};
void Factory::display(){
  for(int i = 0; i < number; i++){
    this->robots[i].display();
  }
}

int main(int argc, char const *argv[]) {
  Factory factory(3);
  factory.init();
  factory.display();
  TransportRobot transRobot("a","b",3,6,19);
  factory.displayTransportRobot(transRobot);
  return 0;
}
