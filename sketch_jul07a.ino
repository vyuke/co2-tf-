#include <SD.h>
const int chipSelect = 4;  
int m=0;
int t=1000;
void setup()
{
  Serial.begin(9600);  
  Serial.print("Initializing SD card..."); 
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) 
  {  
    Serial.println("Card failed, or not present"); 
    return;
  }
  Serial.println("card initialized.");
  //SD.remove("co2data.txt");
}
void loop()
{
  int V1 = analogRead(A0);  
  float vol = V1*(5.0 / 1023.0); 
  vol = vol*(5000/2.5);
  m=m++;
  Serial.print("Cppm = ");
  Serial.print(vol);                        
  Serial.println(" ppm");                   
  File dataFile = SD.open("co2data.txt", FILE_WRITE);  
  if (dataFile) 
  {
    dataFile.print("Cppm = ");
    dataFile.print(vol);    
    dataFile.print(" ppm ");
    dataFile.print(" time+");
    dataFile.print(m);
    dataFile.print("*");
    dataFile.print(t);
    dataFile.println("ms");
    dataFile.close();
  }    
  else {
    Serial.println("error opening datalog.txt");
  } 
  delay(t);
} 



