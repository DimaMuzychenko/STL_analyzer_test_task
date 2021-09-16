#include "FacetAnalyzer.hpp"

# define PI 3.14159265358979323846

FacetAnalyzer::FacetAnalyzer() : numOfGroups(100) {}

void FacetAnalyzer::SetNumOfGroups(unsigned num)
{
	numOfGroups = num;
}

unsigned FacetAnalyzer::GetNumOfGroups() const
{
	return numOfGroups;
}

void FacetAnalyzer::ResetVector()
{
	areas.assign(numOfGroups, 0.f);
}

FacetAnalyzer& FacetAnalyzer::Analyze(const Solid& solid)
{
	std::cout << "3d model is being analyzed..." << std::endl;
	ResetVector();
	Point3d<float> downVec(0.f, 0.f, -1.f); // vector, used to defining a facet normal vector angle
	double sizeOfGroup = 180. / static_cast<double>(numOfGroups-1);
	auto& facets = solid.GetFacets();
	auto& normals = solid.GetNormals();
	for (size_t i = 0; i < solid.Size(); ++i)
	{
		float facetArea = facets[i].area();
		double angleCos = (normals[i] * downVec);
		double angle = acos(angleCos) / PI * 180;
		size_t index = static_cast<size_t>(trunc(angle / sizeOfGroup));
		areas[index] += facetArea;
	}
	std::cout << "Analysis completed" << std::endl;
	return *this;
}

void FacetAnalyzer::WriteTo(const std::string& fileName)
{
	std::cout << "Saving results..." << std::endl;
	std::ofstream report(fileName, std::ofstream::trunc);
	report << -90 << '\n';
	report << 90 << '\n';
	report << numOfGroups << '\n';
	report << '\n';
	for (auto e : areas)
	{
		report << e << '\n';
	}
	report.close();
	std::cout << "Results are saved" << std::endl;
}
