#ifndef ACSVPARSER_HPP_
# define ACSVPARSER_HPP_

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>

class ACsvParser
{
public:
	explicit ACsvParser(const std::string & filename = std::string());
	ACsvParser(const ACsvParser &) = default;
	ACsvParser & operator=(const ACsvParser &) = default;
	virtual ~ACsvParser();

	void setFilename(const std::string & filename);
	const std::string & getFilename() const;

	bool parse() const;
	bool parse(const std::string & filename);
	virtual void onParse(unsigned int x, unsigned int y, const std::string & value) const = 0;

protected:
	std::string		_filename;
};

#endif // !ACSVPARSER_HPP_
