# raspberrydog

树莓派gpio控制家用电器，与相机检测运动自动拍照上传百度云盘脚本。

## 文件包含： 

    cameradetect.c 
    init.c 
    onlight.c 
    shutdownlight.c 
    donecameradetect.sh 
    takepic.sh 

## 树莓派unbutu系统下安装方法：

运行环境配置 

    sudo update;sudo upgrade 
    sudo apt-get install gcc git 

## 源码编译还需要wiringpi，下载及安装详见地址http://wiringpi.com/ 

## 上传百度云盘需要bypy支持，详情：https://github.com/houtianze/bypy 
安装： 

    git https://github.com/radmanxu/raspberrydog.git 
    cd raspberry gcc cameradetect.c init.c -o cameradetect -lwiringPi 
    gcc shutdownlight.c -o shutdownlight -lwiringPi 
    gcc onlight.c -o onlight -lwiringPi 
    ln -s cameradetect /bin/cameradetect 
    ln -s donecameratect.sh /sbin/donecameradetect 
    ln -s shutdownlight /bin/shutdownlight 
    ln -s onlight /bin/onlight 
    ln -s takepic.sh /bin/takepic 

## 运行 

开灯 

    onlight 
    
关灯

    shutdownlight 
    
打开运动检测

    cameradetect 
    
关闭运动检测

    donecameradetect 
    
拍照并上传百度云盘

    takepic 
    
