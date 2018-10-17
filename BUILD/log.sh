file='../log.log'
stus=` cat $file |awk NR%3==2'{print$2}'|grep "Student"|wc -l`
clas=` cat $file |awk NR%3==2'{print$2}'|grep "Class"|wc -l`

clear
echo "对学生信息进行了"$stus"次操作"
echo "对课程信息进行了"$clas"次操作"
read -p "按任意键继续" asd

flag=0
Number='000'

while [ $flag -ne 3 ]
do
	clear
	echo "*********日志分析系统*********"
	echo "1.查看对某一学生信息的所有操作"
	echo "2.查看对某一课程信息的所有操作"
	echo "3.退出系统"
	read -p "请输入您的选择" flag

	if [ $flag -eq 1 ]
	then
		read -p "请输入学号" Number
		NRS=`cat $file|awk -v var=$Number '$2=="Student" && $3==var{print NR}'`
		for NR in `echo $NRS`
		do
			awk NR==$NR-1 $file
			awk NR==$NR $file
		done
		read -p "请按任意键继续" asd
	
	elif [ $flag -eq 2 ]
	then
		read -p "请输入课程编号" Number
		NRS=`cat $file|awk -v var=$Number '$2=="Class" && $3==var{print NR}'`
		for NR in `echo $NRS`
		do
			awk NR==$NR-1 $file
			awk NR==$NR $file
		done
		read -p "请按任意键继续" asd
	
	elif [ $flag -ne 3 ]
	then
		echo "输入错误"
	fi
done




