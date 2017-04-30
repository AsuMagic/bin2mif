#include <iostream>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <string>

int main()
{
	std::string raw(std::istreambuf_iterator<char>{std::cin}, {});

	const size_t power_of_two = static_cast<size_t>(pow(2, ceil(log(raw.size()) / log(2)))); // Inefficient, but good enough
	const int padding = static_cast<int>(log(power_of_two) / log(8));

	std::cout << "-- Generated with the bin2mif tool\n"
				 "-- https://github.com/AsuMagic/bin2mif/\n"
				 "DEPTH = " << power_of_two << ";\n"
				 "WIDTH = 8;\n"
				 "ADDRESS_RADIX = HEX;\n"
				 "DATA_RADIX = HEX;\n"
				 "CONTENT\n"
				 "BEGIN\n" << std::hex << std::uppercase << std::setfill('0');

	for (size_t offset = 0; offset < raw.size(); ++offset)
		std::cout << std::setw(padding) << offset << " : " << std::setw(2) << static_cast<unsigned>(raw[offset]) << ";\n";

	if (raw.size() != power_of_two)
		std::cout << '[' << raw.size() << ".." << power_of_two - 1 << "] : 00;\n";

	std::cout << "END;";
}
