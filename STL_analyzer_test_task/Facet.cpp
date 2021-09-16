#include "Facet.hpp"

Facet::Facet(const Point3d<float>& first, const Point3d<float>& second, const Point3d<float>& third)
{
	vertices[0] = first;
	vertices[1] = second;
	vertices[2] = third;
}

bool Facet::operator==(const Facet& other) const
{
	return vertices[0] == other.vertices[0] &&
		vertices[1] == other.vertices[1] &&
		vertices[2] == other.vertices[2];
}

bool Facet::operator!=(const Facet& other) const
{
	return !(*this == other);
}

void Facet::first(const Point3d<float>& newPoint)
{
	vertices[0] = newPoint;
}

void Facet::second(const Point3d<float>& newPoint)
{
	vertices[1] = newPoint;
}

void Facet::third(const Point3d<float>& newPoint)
{
	vertices[2] = newPoint;
}

const Point3d<float>& Facet::first() const
{
	return vertices[0];
}

const Point3d<float>& Facet::second() const
{
	return vertices[1];
}

const Point3d<float>& Facet::third() const
{
	return vertices[2];
}

const Point3d<float>& Facet::operator[](const unsigned short idx)
{
	if (idx > 2)
		throw std::out_of_range("Index mast be in range from 0 to 2.");
	return vertices[idx];
}

double Facet::operator~() const
{
	return this->area();
}

double Facet::area() const
{
	return ~(this->normal())/2;
}

const Point3d<float> Facet::operator!() const
{
	return this->normal();
}

const Point3d<float> Facet::normal() const
{
	return (vertices[1] - vertices[0]) % (vertices[2] - vertices[0]);
}
