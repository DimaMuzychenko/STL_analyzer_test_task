#include "STLreader.hpp"

STLreader::STLreader() {}

STLreader::STLreader(const std::string& stlFileName)
{
	stlFile.open(stlFileName, std::ifstream::binary);
}
STLreader::~STLreader()
{
	stlFile.close();
}
STLreader& STLreader::Open(const std::string& stlFileName)
{
	stlFile.close();
	stlFile.open(stlFileName, std::ifstream::binary);
	std::cout << stlFileName << " opened" << std::endl;
	return *this;
}

Solid STLreader::Read()
{
	std::cout << "3d model is being read..." << std::endl;
	std::vector<Facet> facets;
	std::vector<Point3d<float>> normals;
	std::string line;
	if (stlFile >> line)
	{
		if (line != "solid")
		{
			throw std::runtime_error("Cannot read STL file!");
		}
	}
	if (stlFile.peek() != '\n')
	{
		std::getline(stlFile, line); // ignore the first line "solid ..."
	}
	while (AnyFacetRemain())
	{
		auto faceAndNorm = ReadFacetAndNormal();
		facets.push_back(std::move(faceAndNorm.first));
		normals.push_back(std::move(faceAndNorm.second));		
	}
	if (stlFile >> line)
	{
		if (line != "endsolid")
		{
			throw std::runtime_error("Cannot read STL file!");
		}
	}
	std::getline(stlFile, line); // ignore remain characters from the last line
	std::cout << "Reading completed" << std::endl;
	return Solid(std::move(facets), std::move(normals));
}

bool STLreader::AnyFacetRemain() noexcept
{
	auto currentPos = stlFile.tellg();
	std::string nextWord;
	stlFile >> nextWord;
	stlFile.seekg(currentPos);
	return nextWord == "facet";
}

void STLreader::IgnoreWords(unsigned count) noexcept
{
	std::string ignoredWord;
	while (count > 0)
	{
		stlFile >> ignoredWord;
		--count;
	}
}

void STLreader::CheckNextWords(std::string words)
{
	std::stringstream ss(words);
	std::string fileWord, checkWord;
	while (ss >> checkWord)
	{
		stlFile >> fileWord;
		if (checkWord != fileWord)
		{
			throw std::runtime_error("Cannot read STL file!");
		}
	}
}

Point3d<float> STLreader::ReadPoint()
{
	float x, y, z;
	stlFile >> x >> y >> z;
	return Point3d<float>(x, y, z);
}

Point3d<float> STLreader::ReadNormal()
{
	CheckNextWords("normal");
	return ReadPoint();
}

Point3d<float> STLreader::ReadVertex()
{
	CheckNextWords("vertex");
	return ReadPoint();
}

Facet STLreader::ReadFacet()
{
	CheckNextWords("outer loop");
	auto first = ReadVertex();
	auto second = ReadVertex();
	auto third = ReadVertex();
	CheckNextWords("endloop");
	return Facet(first, second, third);
}

std::pair<Facet, Point3d<float>> STLreader::ReadFacetAndNormal()
{
	CheckNextWords("facet");
	auto normal = ReadNormal();
	auto facet = ReadFacet();	
	CheckNextWords("endfacet");
	return std::make_pair(std::move(facet), std::move(normal));
}
