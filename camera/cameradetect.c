#include <wiringPi.h>
#include <stdlib.h>
#define LOG ~/camera/log/`date +%Y%m%d`.log
#define IMGPLACE /media/pi/nas/motion-images/today/

void init_daemon(void);//守护进程初始化函数 

int main(void)
{

init_daemon();//初始化为Daemon

wiringPiSetup();
pinMode(2,INPUT);
int i=0;
for(;;)
{
	system("echo `date +%Y%m%d%H%M%S` I am detecting.  >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log");
	sleep(0.5);
	i++;
if (i==3000)
{
	i = 0;
	system("echo `date +%Y%m%d%H%M%S` Shutdown the Light. >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log");
	system("/home/radmanxu/source/camera/shutdownlight");
}

if (digitalRead(2)==1)
{
	i=0;	
	system("echo `date +%Y%m%d%H%M%S` open the Light. >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log");
        system("/home/radmanxu/source/camera/openlight");
	system("echo `date +%Y%m%d%H%M%S` I have catched something!  >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log");
//	system("raspistill -o /media/pi/nas/motion-images/today/`date +%Y%m%d%H%M%S`.jpeg -w 800 -h 600 -t 1 -n -v >> ~/camera/log/`date +%Y%m%d`.log");
//	system("sudo bypy upload /media/pi/nas/motion-images/today/*.jpeg `date +%Y-%m-%d`/ -v >> ~/camera/log/`date +%Y%m%d`.log");
//	system("sudo rm /media/pi/nas/motion-images/today/*.jpeg -v >> ~/camera/log/`date +%Y%m%d`.log");
	system("/home/radmanxu/source/camera/takepic.sh");
	sleep(2);
}
}

return 0;
}
