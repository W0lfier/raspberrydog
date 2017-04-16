#自动拍照上传百度云盘的bash命令

raspistill -o /home/radmanxu/source/camera/cache/`date +%Y%m%d%H%M%S`.jpeg -t 1 -h 600 -w 800 -n -v
bypy upload /home/radmanxu/source/camera/cache/*.jpeg `date +%Y-%m-%d`/ -v >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log
rm /home/radmanxu/source/camera/cache/*.jpeg -v >> /home/radmanxu/source/camera/log/`date +%Y%m%d`.log

