#include "Solid.hpp"


Solid::Solid() {}

Solid::Solid(const Solid& other)
{
	this->facets = other.facets;
	this->normals = other.normals;
}

Solid::Solid(Solid&& other)
{
	this->normals = std::move(other.normals);
	this->facets = std::move(other.facets);
}

Solid::Solid(const std::vector<Facet>& facets)
{
	this->facets = facets;
	CalculateNormals();
}

Solid::Solid(std::vector<Facet>&& facets)
{
	this->facets = std::move(facets);
	CalculateNormals();
}

Solid::Solid(const std::vector<Facet>& fasets, const std::vector<Point3d<float>>& normals)
{
	if (facets.size() != normals.size())
	{
		throw std::invalid_argument("Number of facets and normals are not equal!");
	}
	this->facets = fasets;
	this->normals = normals;
}

Solid::Solid(std::vector<Facet>&& facets, std::vector<Point3d<float>>&& normals)
{
	if (facets.size() != normals.size())
	{
		throw std::invalid_argument("Number of facets and normals are not equal!");
	}
	this->facets = std::move(facets);
	this->normals = std::move(normals);
}

Solid::~Solid() {}

void Solid::CalculateNormals()
{
	normals.resize(facets.size());
	for (size_t i = 0; i < facets.size(); ++i)
	{
		normals[i] = facets[i].normal();
	}
}

const std::vector<Facet>& Solid::GetFacets() const
{
	return facets;
}

const std::vector<Point3d<float>>& Solid::GetNormals() const
{
	return normals;
}

std::vector<Facet>& Solid::GetFacets()
{
	return facets;
}

std::vector<Point3d<float>>& Solid::GetNormals()
{
	return normals;
}


size_t Solid::Size() const
{
	return facets.size();
}

const std::pair<Facet, Point3d<float>>& Solid::operator[](size_t idx) const
{
	if (idx > facets.size() - 1)
	{
		throw std::out_of_range("Index is out of range!");
	}
	return std::make_pair(facets[idx], normals[idx]);
}

std::pair<Facet, Point3d<float>> Solid::operator[](size_t idx)
{
	if (idx > facets.size() - 1)
	{
		throw std::out_of_range("Index is out of range!");
	}
	return std::make_pair(facets[idx], normals[idx]);
}

void Solid::AddFacet(const Facet& facet)
{
	facets.push_back(facet);
	normals.push_back(facet.normal());
}

void Solid::AddFacet(Facet&& facet)
{
	normals.push_back(facet.normal());
	facets.push_back(std::move(facet));	
}

