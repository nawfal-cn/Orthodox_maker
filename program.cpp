/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchaknan <nchaknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:43:05 by nchaknan          #+#    #+#             */
/*   Updated: 2023/12/31 12:35:33 by nchaknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

string toUpper(string  str) {
	int i = 0;
	while (i < str.length()) {
		str[i] = toupper(str[i]);
		i++;
	}
	return str;
}

string firstIsUpper(string name) {
	int i = 1;
	name[0] = toupper(name[0]);
	return name;
}

void setorhodoxForm(string hppFile, string cppFile, string Filename) {
	string upperFileName = toUpper(Filename);
	string preifNotDefine = "#ifndef " + upperFileName + "_HPP";
	string prePressesureDefine = "#define " + upperFileName + "_HPP";
	string endPre = "#endif";
	int length = 0;
	ofstream file;
	file.open(hppFile);

	file << preifNotDefine << std::endl;
	file << prePressesureDefine << std::endl;
	file << "\n";
	file << "#include <iostream>\n\n";
	string classForm[] = 
	{ "class " + Filename,
		"{",
		"	private :",
		"		// put your private attributes here",
		"	public :",
		"		" + Filename + "();",
		"		~"+ Filename +"();",
		"		"+Filename+"("+Filename+" const &copy);",
		"		"+Filename+" &operator=("+Filename+" const &other);",
		"};"
	};
	for (int i = 0; i < 10; i++) {
		file << classForm[i] << std::endl;
	}
	file << "\n";
	file << endPre;
	file.close();

	file.open(cppFile);
	file << "#include \"" + Filename + ".hpp\"";
	file << "\n\n"; 
	file << Filename +"::"+Filename+"()\n";
	file << "{\n";
	file << "	std::cout<< \"" + Filename + " Created.\" << std::endl;\n";
	file << "}\n\n";
	file << Filename +"::~"+Filename+"()\n";
	file << "{\n";
	file << "	std::cout<< \"" + Filename + " Destroyed.\" << std::endl;\n";
	file << "}\n\n";
	file << Filename +"::"+Filename+"("+Filename+" const &copy)\n";
	file << "{\n";
	file << "	std::cout<< \"Creating a copy of " + Filename + ".\" << std::endl;\n";
	file << "	*this = copy;\n";
	file << "}\n\n";
	file << Filename + " &" + Filename +"::operator=("+Filename+" const &other)\n";
	file << "{\n";
	file << "	std::cout<< \"Assigning a copy of " + Filename + ".\" << std::endl;\n";
	file << "	if(this != &other)\n";
	file << "	{\n\t\t// copy your attributes here\n\t}\n";
	file << "	return(*this);\n";
	file << "}\n";
	file.close();
}

int main(int argc, char **argv) {
	if (argc != 2 ) {
		cerr << "orthodox : bad argments.\n";
		exit(1);
	}
	string fileName = firstIsUpper(argv[1]);
	string workinDir	= getcwd(NULL, 0);
	string scriptPath = workinDir + "/" + fileName;
	// string hppFile = scriptPath + ".hpp";
	// string cppFile = scriptPath + ".cpp";
	string hppFile = fileName + ".hpp";
	string cppFile = fileName + ".cpp";
	string cmdResutl = "touch " + hppFile + " " + cppFile;
	system(cmdResutl.c_str());
	setorhodoxForm(hppFile, cppFile, fileName);
}
