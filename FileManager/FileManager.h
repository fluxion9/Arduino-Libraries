/*
SD File Manager Library header file
Author: Isaac J. Newton
Date: February 28th, 2022 00:00
Released to public Domain
*/

#ifndef FileManager_h
#define FileManager_h
#include "Arduino.h"
#include "SD.h"
#include "SPI.h"

class FileManager
{
	public:
		int sizeOfFile(String name);
		String readLine(String fname, int num);
		int countLines(String fname);
	private:
};

#endif
