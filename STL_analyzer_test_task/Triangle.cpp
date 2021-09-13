#include "Triangle.hpp"

#include <stdexcept>

Triangle::Triangle(const Point3d<float>& first, const Point3d<float>& second, const Point3d<float>& third)
{
	vertices[0] = first;
	vertices[1] = second;
	vertices[2] = third;
}

Triangle::Triangle(const Triangle& other)
{
	vertices[0] = other.vertices[0];
	vertices[1] = other.vertices[1];
	vertices[2] = other.vertices[2];
}

const Triangle& Triangle::operator=(const Triangle& other)
{
	if (this != &other)
	{
		vertices[0] = other.vertices[0];
		vertices[1] = other.vertices[1];
		vertices[2] = other.vertices[2];
	}
	return *this;
}

bool Triangle::operator==(const Triangle& other) const
{
	return vertices[0] == other.vertices[0] &&
		vertices[1] == other.vertices[1] &&
		vertices[2] == other.vertices[2];
}

bool Triangle::operator!=(const Triangle& other) const
{
	return !(*this == other);
}

void Triangle::first(const Point3d<float>& newPoint)
{
	vertices[0] = newPoint;
}

void Triangle::second(const Point3d<float>& newPoint)
{
	vertices[1] = newPoint;
}

void Triangle::third(const Point3d<float>& newPoint)
{
	vertices[2] = newPoint;
}

const Point3d<float>& Triangle::first() const
{
	return vertices[0];
}

const Point3d<float>& Triangle::second() const
{
	return vertices[1];
}

const Point3d<float>& Triangle::third() const
{
	return vertices[2];
}

Triangle::operator const Point3d<float>* () const
{
	return vertices;
}

Triangle::operator Point3d<float>* ()
{
	return vertices;
}

const Point3d<float>& Triangle::operator[](const unsigned short idx)
{
	if (idx > 2)
		throw std::out_of_range("Index mast be in range from 0 to 2.");
	return vertices[idx];
}

double Triangle::operator~() const
{
	return this->area();
}

double Triangle::area() const
{
	return ~(this->normal());
}

const Point3d<float>& Triangle::operator!() const
{
	return this->normal();
}

const Point3d<float>& Triangle::normal() const
{
	return (vertices[1] - vertices[0]) % (vertices[2] - vertices[0]);
}
