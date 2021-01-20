#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
	class Shape3D
	{	
		double volume;

	public:
		double getVolume();
	
	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D
	{
		double radius;
		double pi;
	
	public:
		Sphere(double, double);
	};
	Sphere::Sphere(double r,double pi){
		if(r>0&&pi>0){
			setVolume(4.0/3.0*pi*r*r*r);
		}
		else	setVolume(0);
	}
	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};
	Cone::Cone(double radius,double height,double pi){
		if(radius>0&&height>0&&pi>0){
			setVolume(1.0/3.0*pi*radius*radius*height);
		}
		else  setVolume(0);
	}
	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;
	
	public:
		Cuboid(double, double, double);
	};
	Cuboid::Cuboid(double length,double width,double height){
		if(length>0&&width>0&&height>0){
			setVolume(length*width*height);
		}
		else  setVolume(0);
	}
	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
	Cube::Cube(double a):Cuboid(a,a,a){
		}
}


#endif
