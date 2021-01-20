#ifndef FUNCTION_H
#define FUNCTION_H
#include <vector>
#define PI 3

namespace oj
{
	struct Point
	{
		Point(int, int);
        int x;
        int y;
    };

	class Shape 
	{	
	public:
		Shape();
		inline int getArea() const
		{
			return area;
		}
        virtual void draw() = 0;
		virtual ~Shape();

	protected:
        std::vector<Point> points;
		int area;
	};

	class Rectangle : public Shape
	{
	public:
		Rectangle();
        void draw();
		
	private:
		int width;
		int height;
	};

	class Circle : public Shape
	{
	public:
		Circle();
        void draw();
		
	private:
		int radius;
	};
}

#endif