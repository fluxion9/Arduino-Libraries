/*
SD File Manager Library .cpp file
Author: Isaac J. Newton
Date: February 28th, 2022 00:00
Released to public Domain
*/

#include "Arduino.h"
#include "SPI.h"
#include "SD.h"
#include "FileManager.h"

int FileManager::sizeOfFile(String name)
{
	File file = SD.open(name, FILE_READ);
	if(file)
	{
		int size = file.size();
		file.close();
		return size;
	}
	else {
		file.close();
		return -1;
	}
}

String FileManager::readLine(String fname, int num)
{
	File file = SD.open(fname, FILE_READ);
	if(file)
	{
		String buff = "";
		byte lines = 0;
		while(file.available())
		{
			char d = file.read();
			if(d == '\n')
			{
				lines++;
			}
			if(lines == num - 1)
			{
				buff += d;
			}
		}
		buff = buff.substring(buff.indexOf('\n') + 1);
		file.close();
		return buff;
	}
	else {
		file.close();
	 	return "";
	}
}

int FileManager::countLines(String fname)
{
	File file = SD.open(fname, FILE_READ);
	if(file)
	{
		int lines = 0;
		while(file.available())
		{
			char d = file.read();
			if(d == '\n')
			{
				lines++;
			}
		}
		file.close();
		return lines;
	}
	else {
		file.close();
		return -1;
	}
}
