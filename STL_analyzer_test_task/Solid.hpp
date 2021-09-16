#pragma once
#include <vector>

#include "Facet.hpp"

// Represents a 3d model consists of facest.
class Solid
{
public:
	// Constructs an empty solid (3d model).
	Solid();

	Solid(const Solid& other);

	Solid(Solid&& other);

	// Constructs a solid based on given facets. Normal vectors is added automatically.
	Solid(const std::vector<Facet>& facets);

	// Constructs a solid based on given facets. Normal vectors is added automatically.
	Solid(std::vector<Facet>&& facets);

	Solid(const std::vector<Facet>& facets, const std::vector<Point3d<float>>& normals);

	Solid(std::vector<Facet>&& facets, std::vector<Point3d<float>>&& normals);

	~Solid();

public:
	// Returns array of facets.
	const std::vector<Facet>& GetFacets() const;

	// Returns array of facets normal vectors.
	const std::vector<Point3d<float>>& GetNormals() const;

	// Returns array of facets.
	std::vector<Facet>& GetFacets();

	// Returns array of facets normal vectors.
	std::vector<Point3d<float>>& GetNormals();

	// Returns the number of facets.
	size_t Size() const;

	// Returns pair with facet and its normal vector accordingly.
	const std::pair<Facet, Point3d<float>>& operator[](size_t idx) const;

	// Returns pair with facet and its normal vector accordingly.
	std::pair<Facet, Point3d<float>> operator[](size_t idx);

	// Adds a new faucet to the solid. Its normal vector is added automatically.
	void AddFacet(const Facet& facet);

	// Adds a new faucet to the solid. Its normal vector is added automatically.
	void AddFacet(Facet&& facet);

private:
	// Adds normal vectors to each facet.
	void CalculateNormals();

private:
	std::vector<Facet> facets;
	std::vector<Point3d<float>> normals;
};

