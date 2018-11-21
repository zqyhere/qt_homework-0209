﻿### 第三次提交：*2018.10.31*
  #### 目前状况：  
    完成实验三基本要求，增加菱形选择，按钮具有图片标记  
 # 作业仓库：qt_homework-0209

---
## 1.homework01  提交日期：2018.09.15  **实现作业一要求，共提交1次**
 +  第一次提交 *2018.09.15*：  
    实现作业一要求：   
    1. 取出最高8位（HHI）,次高位(LHI)、次低8位(HLI)和最低8位(LLO)【用宏实现】，
    并将结果存入可QList对象 Values中。
    2. 返回最高8位和次高8位的最大值，次低8位和最低8位的最小值【用宏实现】。
    3. 组合成一个新的32位无符号整数型，改变顺序重新组合。
    4. 使用 std： ：sort函数，将列表中数字按照从大到小排序。
  + 第二次提交 *2018.09.19*：
    1. 更改仓库格式，添加README

---
## 2.lab01 提交日期：2018.10.12  **实现实验一基本要求，共提交1次**
 +  第一次提交 *2018.10.12*:   
    实现实验一要求：
    1. 对任意成员变量排序，将输入的四名学生分别按“姓名、课程一成绩、课程二成绩排序”。

---
## 3.homework02 提交日期：2018-10-18，实现作业二要求的功能，共提交了4次。

 + 第一次提交：*2018.10.16*
  实现：   
  1.完成读取文件，运行无错误 完成readfile函数     
  2.编写其他类出现问题，整改中   

 + 第二次提交：*2018.10.18*  
 
  1.基本框架写出  
  2.readfile存在问题，关于vector score 怎么存入一门成绩，进行dosort排序 

 + 第三次提交：*2018.10.18*  
   
   1.构建有错误，问题可能是mycmp调用的时候，数据类型不匹配   
   2.设想：结构体成员、dosort、mycmp可以优化，number，name可以写入vector  


 + 第四次提交：*2018.10.18*  
   
   1.改用Qstringlist，方便删除   
   2.实现功能，可以同时输出文件和控制台，并覆盖文件
   3.成员选取错误，导致无法向mycmp传送匹配类型数据，已改正
---
## 4.lab02 提交日期：2018-11-13，实现实验二要求的功能，共提交了4次。

 + 第一次提交：*2018.10.28*  
    第一次尝试新建dialog .h和.cpp文件，进行窗口编写，后来类比颜色选择QColorDialog的写法，决定删除两个文件。  
    直接在MainWindow上编写，目前可以实现弹出文件选择窗口。 
    接下来，将使用过滤器，使其只显示JPG,PNG等类别的文件以及将图片放在绘图编辑窗口。 
 + 第二次提交：*2018.10.29*  
    目前状况：  
    只显示JPG,PNG等类别的文件以及将图片放在绘图编辑窗口。 
    尝试在水平工具栏里设置图片选择按钮，但是QToolButton里不能使用setShapeType等函数，按理来说放在垂直QpushBytton应该可以的，但是不知道为什么出问题，所以放置在了垂直栏  
    下一次在尝试一下防在水平工具栏里，给按钮做上标记图画，并且增加菱形按钮    
 + 第三次提交：*2018.10.31*    
    目前状况：  
    完成实验三基本要求，增加菱形选择，按钮具有图片标记  
 + 第四次提交：*2018.11.13*  
    目前状况：  
    完成实验三基本要求，更改resize event,使图片和画布内容可以随着窗口大小而调整
 ---
## 5.lab03 提交日期：2018-11-22，实现实验三要求的功能，共提交了2次。

 + 第一次提交：*2018.11.16*  
   目前状况：
   增加按钮选项，将时间改为动态时间，初步读程序 
 + 第二次提交：*2018.11.22*  
   目前状况：
   完成实验三基本要求：  
	1.加入AQI，增加城市选择，从网络上获取新的数据  
	2.更改y坐标轴范围，使范围可以根据数值自适应  
	3.将页面打开的默认状态设置为查询气温 
       

  