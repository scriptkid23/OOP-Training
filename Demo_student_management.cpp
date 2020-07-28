#include<iostream>

using namespace std;

class Human{
    int old;
    bool gender;
    string name;

    public:
        Human(){};
        Human(int old,bool gender,string name){
            this->old = old;
            this->gender = gender;
            this->name = name;
        }
        void display(){
            cout << "name"  << this->name;
            cout << "old" << this->old;
            cout << "gender" << this->gender;
        }
};
class Student:public Human{
        string class_name;
        public:
            Student():Human(){};
            Student(int old,bool gender,string name,string class_name):Human(old,gender,name){
                this->class_name = class_name;
            };
            void display(){
                Human::display();
                cout << "class name:" << this->class_name;
            }

};
class ClassRoom{
    int number_student;
    Student *student = NULL;

    public:
        string name_,class_name_;
        int old_;
        bool gender_;
        ClassRoom(int number_student){
            this->number_student = number_student;
        }
        void input(){
            this->student = new Student[this->number_student];
            for(int i = 0; i <  this->number_student; ++i){
                cout << "Name: "; cin >> name_;
                cout << "Old: "; cin >> old_;
                cout << "Class Name: "; cin >> class_name_;
                cout << "Gender:"; cin >> gender_;
                this->student[i] = Student(old_,gender_,name_,class_name_);
            }
        }
        void output(){
            for(int i = 0; i < this->number_student; ++i){
                this->student[i].display();
            }
        }

        ~ClassRoom(){
            delete []student;
        }
};

int main(){
    ClassRoom classRoom(6);
    classRoom.input();
    classRoom.output();
    return 0;
}