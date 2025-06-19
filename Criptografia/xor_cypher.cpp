/*
	   Copyright 2025 GabrielWindy

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#include "xor_cypher.h"

std::string encrypt(std::string input, std::string key)
{
	std::string output = input;

	for (size_t i = 0; i < input.size(); i++)
	{
		output[i] ^= key[i % key.size()];
	}

	return output;

}

int encryptFile(std::string path, std::string outputPath, std::string key)
{
	// Try to open the file

	std::fstream file;
	file.open(path);

	if (!file.is_open())	return -1;

	std::string fileContents;
	std::ostringstream tempStream;
	std::string tempLine;

	while (std::getline(file, tempLine))
		tempStream << tempLine << '\n';
	fileContents = tempStream.str();
	file.close();

	std::string encryptedOutput = encrypt(fileContents, key);

	std::ofstream output;
	std::string outputFileName = outputPath;

	output.open(outputFileName);

	if (!output.is_open())	return 1;

	output.write(encryptedOutput.c_str(), encryptedOutput.size());

	output.close();

	std::cout << "There you go! Saved to: " << outputFileName << std::endl;

	return 0;
}
