#include <iostream>

#include "Point3d.hpp"
#include "Facet.hpp"
#include "STLreader.hpp"
#include "Solid.hpp"
#include "FacetAnalyzer.hpp"


int main(int argc, char* argv[])
{
	if (argc == 2) // for drag and drop opening
	{
		STLreader reader;
		Solid solid = reader.Open(argv[1]).Read();
		FacetAnalyzer anal;
		anal.Analyze(solid).WriteTo("output.txt");
		std::cout << "Displaying results..." << std::endl;
		system("python plotting.py");
	}
	return 0;
}