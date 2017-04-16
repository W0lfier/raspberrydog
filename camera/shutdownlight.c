#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#define LOG ~/camera/log/`date +%Y%m%d`.log
#define IMGPLACE /media/pi/nas/motion-images/today/

int main(void)
{
wiringPiSetup();
pinMode(0,OUTPUT);
digitalWrite(0,1);
printf("Chinese girl is difficult");
return 0;
}
