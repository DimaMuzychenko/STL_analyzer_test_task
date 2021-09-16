#pragma once
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "Solid.hpp"

// Represents an object to read 3d model from STL ASCII file.
class STLreader
{
public:
	// Construct a default STLreader object.
	STLreader();

	// Construct a STLreader object and open a given file for reading.
	STLreader(const std::string& stlFileName);

	~STLreader();

	// Opens a given file for reading. Returns selfs object, so it is possible to call a chain of methods.
	STLreader& Open(const std::string& stlFileName);

	// Reads a given STL file and returns read solid (3d model).
	Solid Read();

private:
	// Checks if any facet is remain for reading in the file.
	bool AnyFacetRemain() noexcept;

	// Skips a given count of word in the file.
	void IgnoreWords(unsigned count) noexcept;

	// Checks whether the next words in file equals to given words.
	void CheckNextWords(std::string words);

	// Reads the next three floating point numbers from the file and return it as 3d point.
	Point3d<float> ReadPoint();

	// Reads normal vector from the file and return it.
	Point3d<float> ReadNormal();

	// Reads 3d point from the file and return it.
	Point3d<float> ReadVertex();

	// Reads three vertex from the file and return it as facet.
	Facet ReadFacet();

	// Reads whole facet block (normal vector and three vertex) and return it as pair<facet, normal>.
	std::pair<Facet, Point3d<float>> ReadFacetAndNormal();
	

private:
	std::ifstream stlFile;
};

