#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;

struct Student
{
    int no;//学生编号
    string name;//学生姓名
    string sex;//学生性别
    string Program;//节目名称
    string form;//表演形式
    string Class;//学生班级
    string tel;//学生电话
    int f;//计数器
    double score[10];//学生成绩
    double min;//最低分
    double max;//最高分
    double avg;//平均分
    int pro;//表演方式属性值
    int rank;//排名
    char m[20][20];//初始数组
};
struct Referee
{
    string name;//裁判姓名
    string sex;//裁判性别
    string tel;//裁判电话
    char m[20][20];//初始化数组
};

/*各函数声明*/ 
void searchlistmenu(Student * s,Referee *r);
int searchByNum(Student *s,Referee *r);
int searchByName(Student *s,Referee *r);
void inputscore(Student *s);
int inputstuinf(Student *s);
void inputref(Referee *r);
void outputallinf(Student *s,int n,Referee *r);
int change(Student *s);
int readstu(Student *s);
void writestu(Student *s);
int readref(Referee *r);
void writeref(Referee *r);

//全局变量
struct Student s[100];
struct Referee r[100];
struct Student stu[100][100];

//节目名称宏定义
//#define music 1/*音乐*/
//#define dance 2/*舞蹈*/
//#define com 3/*喜剧*/ 
//#define tra 4/*悲剧*/ 
//#define magic 5/*魔术*/ 
