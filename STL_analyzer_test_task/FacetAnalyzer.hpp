#pragma once

#include <fstream>
#include <iostream>

#include "Solid.hpp"

// Represents an object to defining total facets area, grouping them by an angle between its normal and xy plane.
class FacetAnalyzer
{
public:
	// Constructs an Facet analyzer object with number of angle groups 100.
	FacetAnalyzer();

public:
	// Sets new number of angle groups.
	void SetNumOfGroups(unsigned num);

	// Returns current number of angle groups.
	unsigned GetNumOfGroups() const;

	// Defines total facets area, grouping them by an angle between its normal and xy plane.
	FacetAnalyzer& Analyze(const Solid& solid);

	// Writes a result of analyzå to a given file. The first two lines contain limits of angles range (from -90 to 90 degree). 
	// The third line means number of angle groups. Then there is an empty line.
	// And finaly, N lines containing total facets area, grouping by its normal vector angle, where N is a number of angles groups.
	void WriteTo(const std::string& fileName);
	
private:
	// Sets a new size to areas vector and fills it with zeros.
	void ResetVector();

private:
	std::vector<float> areas;
	unsigned numOfGroups;
};

