#include <iostream>

using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        Point();
        Point(int x,int y);
        int getX() {return x;}
        int getY() {return y;}
        // friend void  sum(Point); // lưu ý: lớp trừu tượng thì không có hàm bạn
        virtual void display() = 0; // hàm ảo thuần túy 
       // Khi là một lớp trừu tượng thì không có operator
        
};

Point::Point(){x = y = 0;}
Point::Point(int x, int y){ this->x = x; this->y = y;}

class Color{
    private:
        string color;
    public:
        Color();
        Color(string color){this->color = color;}
        string getColor(){return this->color;}
};
class Line: public Point, public Color{

    public:
    Line(int x, int y, string color):Point(x, y),Color(color){};

        void display(){
            cout << this->getX();
            cout << this->getY();
            cout << this->getColor();
        }

};
class ExceptionCustom{
    private:
        int code;
        string message;
    public:
        ExceptionCustom(int code, string message){
            this->code = code;
            this->message = message;
        }
        void display(){
            cout << "code:" << code << endl;
            cout << "message" << message;
        }
};
void checkZeroDiv(int a,int b){
    if(b == 0){
        throw ExceptionCustom(405,"Error zero div");
    }
}

class Parent{
    private:
    int x,y;
    public:
        Parent(int x,int y){
            this->x = x;
            this->y = y;
        }
    friend class ParentFriend;
    friend void sum(Parent);
          
};
class ParentFriend{
    public:
        void display(Parent p){
            cout << p.x;
            cout << p.y;
        }
};
void sum(Parent p){
    cout << p.x + p.y;
}

class Point3D{
    int x,y,z;
    public:
        Point3D(){};
        Point3D(int x,int y,int z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
        Point3D operator+(Point3D p){
            Point3D result;
            result.x = p.x + this->x;
            result.y = p.y + this->y;
            result.z = p.z + this->z;
            return result;
        }
        friend Point3D operator-(Point3D p1,Point3D p2){
            Point3D result;
            result.x = p1.x - p2.x;
            result.y = p1.y - p2.y;
            result.z = p1.z - p2.z;
            return result;
        }
        void display(){
            cout << "(" << x << "," << y << "," << z << ")";
        }
};

int main(){
    Line line_(1,3,"color");
    Line line__(2,3,"pink");

    Point *point = &line_;
    point->display();
    point = &line__;
    point->display();
    cout << endl;
    try
    {
        checkZeroDiv(3,0);
    }
    catch(ExceptionCustom &e)
    {
        e.display();
    }
    
    Point3D point_(1,2,3);
    Point3D point__(5,6,15);
    Point3D result = point_ + point__;
    result.display();
    result = point_ - point__;
    result.display();
    return 0;
}