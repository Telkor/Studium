/* 
 * File:   fileLister.hpp
 * Author: mroth
 *
 * Created on 21. Dezember 2016, 10:50
 */

#ifndef FILELISTER_HPP
#define	FILELISTER_HPP
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>

namespace id3Reader
{

struct id3Header
{
	char TAG[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	char genre[1];
};

inline std::string cleanString(const char* input, const int len = 30)
{
	std::string erg = "";
	for(int i = 0; i < len; i++)
	{
		if(input[i] == '\0')
			break;
		erg+=input[i];
	}
	return erg;
}

struct LiedLoader
{
	std::string titel;
	std::string interpret;
	std::string pfad;
	std::string genre;
	float laenge;
	int jahr;
};

inline std::vector<LiedLoader> listSongs(const std::string& path)
{

#ifdef __linux
	const std::string cmd = std::string("ls \"") + path + "\"";
#elif __win32
	const std::string cmd = "dir \"" + path + "\"";
#else
#error Platform nicht unterstuetzt!
#endif

	using std::string;

	std::vector<LiedLoader> liste;
	system((cmd + " > liste.txt").c_str());

	std::ifstream input("liste.txt");
	if (!input)
	{
		std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
		return liste;
	}

	while (!input.eof())
	{
		string line;
		getline(input, line);
		if (line.find(".mp3") != string::npos)
		{
			//We found an mp3 file!
			const string mp3path = path + "/" + line;
			//DEBUG
			std::cout << mp3path << std::endl;

			std::ifstream mp3(mp3path.c_str(), std::ios::binary);
			if (mp3.good())
			{
				//scan for id3v1 Tag
				mp3.seekg(-128, std::ios::end);
				id3Header id3;
				mp3.read(reinterpret_cast<char*>(&id3), sizeof(id3));
				
				//DEBUG
//				std::cout << id3.TAG << std::endl;
//				std::cout << id3.title << std::endl;
//				std::cout << id3.artist << std::endl;
//				std::cout << id3.album << std::endl;
//				std::cout << id3.year << std::endl;
//				std::cout << id3.comment << std::endl;
//				std::cout << id3.genre << std::endl;
				
				LiedLoader lied;
				lied.titel = cleanString(id3.title);
				lied.interpret = cleanString(id3.artist);
				lied.jahr = atoi(cleanString(id3.year,4).c_str());
				lied.pfad = "\"" + mp3path + "\"";
				liste.push_back(lied);
			}
		}
	}

	system("rm liste.txt");
	return liste;
}

}


#endif	/* FILELISTER_HPP */

