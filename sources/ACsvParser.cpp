#include "ACsvParser.hpp"

ACsvParser::ACsvParser(const std::string & filename)
	: _filename(filename)
{

}

ACsvParser::~ACsvParser()
{

}

void ACsvParser::setFilename(const std::string & filename)
{
	_filename = filename;
}

const std::string & ACsvParser::getFilename() const
{
	return _filename;
}

bool ACsvParser::parse()
{
	std::ifstream file;
	std::string line;

	file.open(_filename.c_str());
	if (file.is_open() == false)
		return false;

	for (unsigned int y = 0; std::getline(file, line); ++y)
	{
		std::stringstream ss(line);

		for (unsigned int x = 0; std::getline(ss, line, ';'); ++x)
			onParse(x, y, line);
	}

	file.close();
	return true;
}

bool ACsvParser::parse(const std::string & filename)
{
	setFilename(filename);
	return parse();
}
