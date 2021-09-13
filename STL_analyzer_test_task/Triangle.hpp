#pragma once

#include "Point3d.hpp"

struct Triangle
{
public:
	Triangle(const Point3d<float>& first, const Point3d<float>& second, const Point3d<float>& third);

	Triangle(const Triangle& other);

	const Triangle& operator=(const Triangle& other);

	bool operator==(const Triangle& other) const;

	bool operator!=(const Triangle& other) const;

	void first(const Point3d<float>& newPoint);

	void second(const Point3d<float>& newPoint);

	void third(const Point3d<float>& newPoint);

	const Point3d<float>& first() const;

	const Point3d<float>& second() const;

	const Point3d<float>& third() const;

	operator const Point3d<float>* () const;

	operator Point3d<float>* ();

	const Point3d<float>& operator[](const unsigned short idx);

	double operator~() const;

	double area() const;

	const Point3d<float>& operator!() const;

	const Point3d<float>& normal() const;

private:
	Point3d<float> vertices[3];
};
