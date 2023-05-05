/* The mbed application board has a 3-axis accelerometer with an I2C interface. An accelerometer
measures the acceleration on its own body. The angle of the accelerometer in any of the axes can be measured.
This experiment measures the pitch (or) slope of the accelerometer and print the value every 1 second*/
#include "mbed.h"
#include "MMA7660.h" // header file I2C
#include "C12832_lcd.h" // header file

C12832_LCD lcd; //On board LCD display
MMA7660 MMA(p28, p27); //I2C Accelerometer



    float calculateAngle(float ax, float ay, float az)
    { 
        float angle = atan(ax / sqrt((pow(ay,2) +pow(az,2))) ); // Pitch angle caculation using equation 2.6
        return angle;
    }

int main() 
{
    float pitch;
    lcd.cls(); // LCD is initally cleared
    
     while(1)
      {
                 
         float ax= MMA.x(); // acceleration along x axis
         float ay= MMA.y(); // acceleration along y axis
         float az= MMA.z(); // acceleration along z axis
         pitch = calculateAngle(ax,ay,az); // calculate angle function is called
         lcd.printf("Pitch: %f \n", pitch); // printing the pitch angle value
         wait_us(1000000); // waiting for 1 second

      }
}
