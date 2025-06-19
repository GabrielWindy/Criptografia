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
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#include "xor_cypher.h"

// Usage: criptografia <file> <keyString> <mode> [output location]
int main(int argc, const char** argv)
{
	if (argc < 4)
	{
		std::cout << "Usage: " << argv[0] << " <file> <keyString> <mode> [output location]" << std::endl;	// Tells the user what went wrong
		return 0;																							// so I can return 0
	}
	
	// Key Variables
	std::string mode = argv[3];
	std::string path = argv[1];
	std::string key = argv[2];
	std::string outputPath;

	// Output path
	if (argc == 5)
	{
		outputPath = argv[4];
	}
	else {
		outputPath = path + ".crt";
	}

	// Modes
	if (mode == "xor_crypt" || mode == "xor_decrypt")	// Decrypt is a placebo, because the algorithm works both ways, so I wont bother making separate functions.
	{
		return encryptFile(path, outputPath, key);
	}

	return 0;
}