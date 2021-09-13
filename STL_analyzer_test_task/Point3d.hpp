#pragma once

#include<stdexcept>

//The 3d point is an array with 3 dimension components(x, y, z).
template< class T > struct Point3d
{
public:
	Point3d()
	{
		elems[0] = 0;
		elems[1] = 0;
		elems[2] = 0;
	}

	Point3d(const T& x, const T& y, const T& z)
	{
		elems[0] = x;
		elems[1] = y;
		elems[2] = z;
	}

	Point3d(const Point3d& other)
	{
		elems[0] = other.elems[0];
		elems[1] = other.elems[1];
		elems[2] = other.elems[2];
	}

	Point3d(const T array[])
	{
		elems[0] = array[0];
		elems[1] = array[1];
		elems[2] = array[2];
	}

	const Point3d& operator=(const Point3d& other)
	{
		if (this != &other)
		{
			elems[0] = other.elems[0];
			elems[1] = other.elems[1];
			elems[2] = other.elems[2];
		}

		return *this;
	}

	const Point3d& operator=(const T array[])
	{
		elems[0] = array[0];
		elems[1] = array[1];
		elems[2] = array[2];

		return *this;
	}

	bool operator==(const Point3d& other)
	{
		return
			elems[0] == other.elems[0] &&
			elems[1] == other.elems[1] &&
			elems[2] == other.elems[2];
	}

	bool operator!=(const Point3d& other)
	{
		return !((*this) == other);
	}

	void x(const T& newx)
	{
		elems[0] = newx;
	}

	void y(const T& newy)
	{
		elems[1] = newy;
	}

	void z(const T& newz)
	{
		elems[2] = newz;
	}

	const T& x() const
	{
		return elems[0];
	}

	const T& y() const
	{
		return elems[1];
	}

	const T& z() const
	{
		return elems[2];
	}

	operator const T* () const
	{
		return elems;
	}

	operator T* ()
	{
		return elems;
	}

	const T& operator[](const unsigned short idx)
	{
		if (idx > 2)
			throw std::out_of_range();
		return elems[idx];
	}

	void operator+=(const Point3d& other)
	{
		elems[0] += other.elems[0];
		elems[1] += other.elems[1];
		elems[2] += other.elems[2];
	}

	void operator-=(const Point3d& other)
	{
		elems[0] -= other.elems[0];
		elems[1] -= other.elems[1];
		elems[2] -= other.elems[2];
	}

	// Returns a langht of the vector.
	double operator~() const
	{
		return std::sqrt(elems[0] * elems[0] +
			elems[1] * elems[1] +
			elems[2] * elems[2]);
	}

	void operator*=(const double& factor)
	{
		elems[0] *= factor;
		elems[1] *= factor;
		elems[2] *= factor;
	}

	void operator/=(const double& factor)
	{
		elems[0] /= factor;
		elems[1] /= factor;
		elems[2] /= factor;
	}

	// Normalize the vector.
	void operator!()
	{
		(*this) /= ~(*this);
	}

private:
	T elems[3];
};

template < class T > const Point3d<T> operator+(
	const Point3d<T>& lhs, const Point3d<T>& rhs)
{
	return Point3d<T>(lhs.x() + rhs.x(),
		lhs.y() + rhs.y(),
		lhs.z() + rhs.z());
}

template < class T > const Point3d<T> operator-(
	const Point3d<T>& lhs, const Point3d<T>& rhs)
{
	return Point3d<T>(lhs.x() - rhs.x(),
		lhs.y() - rhs.y(),
		lhs.z() - rhs.z());
}

template < class T >const Point3d<T> operator*(
	const Point3d<T>& point, const double& factor)
{
	return Point3d<T>(point.x() * factor, point.y() * factor, point.z() * factor);
}

template < class T > const Point3d<T> operator*(
	const double& factor, const Point3d<T>& point)
{
	return Point3d<T>(point.x() * factor, point.y() * factor, point.z() * factor);
}

template < class T > const Point3d<T> operator/(
	const Point3d<T>& point, const double& factor)
{
	return Point3d<T>(point.x() / factor, point.y() / factor, point.z() / factor);
}

// Scalar product of two vectors.
template < class T > double operator*(
	const Point3d<T>& lhs, const Point3d<T>& rhs)
{
	return lhs.x() * rhs.x() +
		lhs.y() * rhs.y() +
		lhs.z() * rhs.z();
}

// Vector product of two vectors.
template < class T > const Point3d<T> operator%(
	const Point3d<T>& lhs, const Point3d<T>& rhs)
{
	Point3d<T> result;
	result.x(lhs.y() * rhs.z() - lhs.z() * rhs.y());
	result.y(lhs.z() * rhs.x() - lhs.x() * rhs.z());
	result.z(lhs.x() * rhs.y() - lhs.y() * rhs.x());
	return result;
}

// Returns normalized representation of the vector.
template < class T > const Point3d<T> operator!(
	const Point3d<T>& vector)
{
	Point3d<T> result;
	result = vector / (~vector);
	return result;
}
