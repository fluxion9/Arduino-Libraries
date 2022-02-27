#include <SPI.h>
#include <SD.h>
#include <FileManager.h>
#include <SoftwareSerial.h>
#define cs 10
SoftwareSerial serial(5, 6); //rx, tx
FileManager FM;
String filename = "data.txt";
void setup()
{
	serial.begin(9600);
	if(!SD.begin(cs))
	{
		serial.println("card failed, or not present. ");
		while(1);
	}
	serial.println("card initialized. ");
}

void loop()
{
	//To check the size of the file in bytes
	serial.print(FM.sizeOfFile(filename));
	serial.println(" bytes.");
	//To count number of lines
	serial.print(FM.countLines(filename));
	serial.println(" lines.");
	//To read data on line 2
	serial.print("got: ");
	serial.print(FM.readLine(filename, 2));
	serial.println(" on line 2. ");
	while(1);
}
