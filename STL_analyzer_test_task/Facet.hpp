#pragma once

#include <stdexcept>

#include "Point3d.hpp"

// Represents a facet conists of three points.
struct Facet
{
public:	
	Facet(const Point3d<float>& first, const Point3d<float>& second, const Point3d<float>& third);

	bool operator==(const Facet& other) const;
		
	bool operator!=(const Facet& other) const;

	// Sets a new first point of the facet.
	void first(const Point3d<float>& newPoint);

	// Sets a new second point of the facet.
	void second(const Point3d<float>& newPoint);

	// Sets a new third point of the facet.
	void third(const Point3d<float>& newPoint);

	// Returns the first point of the facet.
	const Point3d<float>& first() const;

	// Returns the second point of the facet.
	const Point3d<float>& second() const;

	// Returns the third point of the facet.
	const Point3d<float>& third() const;

	operator const Point3d<float>* () const
	{
		return vertices;
	}

	operator Point3d<float>* ()
	{
		return vertices;
	}

	const Point3d<float>& operator[](const unsigned short idx);

	// Returns an area of the facet.
	double operator~() const;

	// Returns an area of the facet.
	double area() const;

	// Returns a unnormalized normal vector of the facet.
	const Point3d<float> operator!() const;

	// Returns a unnormalized normal vector of the facet.
	const Point3d<float> normal() const;

private:
	Point3d<float> vertices[3];
};
