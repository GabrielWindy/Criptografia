#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

std::string encrypt(std::string input, std::string key)
{
	std::string output = input;

	for (size_t i = 0;  i < input.size(); i++)
	{
		output[i] ^= key[i % key.size()];
	}

	return output;

}

// Usage: criptografia <file> <keyString>
int main(int argc, const char** argv)
{
	if (argc < 3)
	{
		std::cout << "Usage: " << argv[0] << " <file> <keyString>" << std::endl;	// Tells the user what went wrong
		return 0;																	// so I can return 0
	}

	// Try to open the file

	std::fstream file;
	file.open(argv[1]);

	if (!file.is_open())	return -1;

	std::string fileContents;
	std::ostringstream tempStream;
	std::string tempLine;

	while (std::getline(file, tempLine))
		tempStream << tempLine << '\n';
	fileContents = tempStream.str();
	file.close();
	
	std::string encryptedOutput = encrypt(fileContents, argv[2]);

	std::ofstream output;
	std::string outputFileName = argv[1];
	outputFileName += ".crt";
	output.open(outputFileName);

	if (!output.is_open())	return 1;

	output.write(encryptedOutput.c_str(), encryptedOutput.size());

	output.close();

	std::cout << "There you go! Saved to: " << outputFileName << std::endl;

	return 0;
}