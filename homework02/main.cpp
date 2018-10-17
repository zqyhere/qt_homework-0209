#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

//https://blog.csdn.net/liang19890820/article/details/51838379

namespace SK {
enum SortKind{  //命名枚举值,枚举类型引用命名枚举值。
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

typedef struct{                   // 请补全结构定义: 定义学号名字，成绩列表
    QString Number;
    QString Name;
    QVector<QString> Score;
}studData;

studData stu;

QDebug operator<< (QDebug d, const studData &data) { // 运算符重载函数，直接输出studData结构
    QDebugStateSaver saver(d);
    d.nospace()<<data.Number<<"\t"<<data.Name<<"\t"<<data.Score;
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01 : result=( d1.Number> d2.Number) ;break;
    case SK::col02 : result=( d1.Name > d2.Name) ;break;
    default :
    result=( d1.Score > d2.Score);
    }
    return result;

}

class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    readFile(QString datafile);   //读取文件
    doSort(QString dataffile);     //进行比较
};

// 请补全
ScoreSorter::ScoreSorter(QString dataFile){
    QString datafilename = dataFile;
} //构造函数，初始化文件名

ScoreSorter::readFile(QString datafile){   //定义函数readfile，读取文件
    QFile file(datafile);
    if(!file.open(QFile::ReadOnly | QIODevice::Text)) {
        qDebug()<<"文件打开失败！"<<endl;
        return -1;
   }
   QTextStream read(&file);
   read.setCodec("UTF-8");
   qDebug().noquote().nospace()<<"开始读取文件："<< datafile;

   QVector<studData> vec;

   while(!read.atEnd()){
        QString line = read.readLine();
        qDebug()<<line;

        QStringList data=line.split(' ',QString::SkipEmptyParts);//去掉空项
        stu.Name = data.at(0);
        stu.Number = data.at(1);
        for(int i=2;i<data.size();i++)
        {stu.Score = data.at(i); }

   }
    file.close();
    qDebug().noquote().nospace()<<"文件读取结束:"<<datafile;
}

ScoreSorter::doSort(QString dataffile){
    for(int i=0;i<dataffile.size();i++)
    {
        myCmp cmp(i);
        std::sort(dataffile.begin(),dataffile.end(), cmp );
        qDebug()<<"当前输出第"<<i+1<<"行，排序后输出如下:"<<stu;
    }

}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) //输出信息至文件sorted_data.txt
{
    QFile file("D:/Dev/qt_homework/homework02/homework02/sorted_data.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream out(&file);
    out << msg  <<endl;
    file.flush();
    file.close();

    QTextStream ts(stdout);
    ts << msg <<endl;

}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "D:/Dev/qt_homework/homework02/homework02/data.txt";

    // 如果排序后文件已存在，则删除之   /删除了文件内容
    QFile f("sorted_data.txt");
    if (f.exists("D:/Dev/qt_homework/homework02/homework02/sorted_data.txt"))
    {//存在文件名（）指定的文件，返回true
    f.remove("D:/Dev/qt_homework/homework02/homework02/sorted_data.txt");
    }//重载函数,删除指定的文件名指定的文件

    ScoreSorter s(datafile);
    s.readFile(datafile);   //读取文件
    s.doSort(datafile);   //进行比较

    return 0;
    }

