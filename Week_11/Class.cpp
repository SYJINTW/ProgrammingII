#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

namespace shapes
{
    using namespace std;
    struct Point{
        int x;
        int y;
        Point(int a, int b) : x{a}, y{b} {}
    };

    class Shape{
        public:
        virtual Point center() const = 0;
        virtual void shift(Point dxy) = 0;
        virtual void rotate(int angle) = 0;
        virtual void draw() = 0;
        virtual ~Shape() {}; //destructor  
    };

    class Rectangle;
    class Circle;

    class Circle : public Shape{
        private:
        Point c; // 中心點（圓心）
        int r; // 半徑
        public:
        //Constructor
        Circle(Point p, int rr) : c{p}, r{rr} {};
        // 因為是 override virtual function 所以需要在後面加 override
        Point center() const override{ 
            return c;
        }
        void shift(Point dxy) override{
            c.x += dxy.x;
            c.y += dxy.y;
        }
        void rotate(int angle) override{}
        void draw() override{
            cout << c.x << " " << c.y << " " << r << endl;
        }
        friend bool bounding(const shapes :: Rectangle &rec, const shapes :: Circle &cir);
    };

    class Rectangle : public Shape{
        private:
        Point ul;
        int w;
        int h;
        public:
        Rectangle(Point p, int width, int height) : ul{p}, w{height}, h{width} {}
        Point center() const override{
            return ul;
        }
        void shift(Point dxy) override {
            ul.x += dxy.x;
            ul.y += dxy.y;
        }
        void rotate(int angle) override {}
        void draw() override{
            cout << "(" << ul.x << "," << ul.y << ")"  << " " << w << " " << h << endl;
        }
        friend bool bounding(const shapes :: Rectangle &rec, const shapes :: Circle &cir);
    };
}

bool bounding(const shapes :: Rectangle &rec, const shapes :: Circle &cir){
    return true;
}

int main(){
	shapes :: Circle c1{{3,2},5};
	shapes :: Rectangle r1{{1, 2}, 4, 6};
	shapes :: Rectangle r2{{4, 3}, 10, 6};

    std :: vector<shapes :: Shape*> spc {&c1, &r1, &r2};

    for(auto ps : spc){
        ps->draw(); // 根據對應的 Class 去執行 function
    }
}

// Class Access control
/*
privite -> 同一個 Class 的 member function 或是 Class 的 friends
protected -> 同一個 Class 的 member function 或是 Class 的 friends 或是 derived class 的 member function
public -> 都可以訪問

繼承：
class_name : private base_class_name
class_name : protected base_class_name
class_name : public base_class_name
*/

// friend

// Destructor