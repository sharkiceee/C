#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stu.h"

//主函数
int main(){
    int id;
    while (1) {
        printf("\n请输入功能编号，将执行相关功能\n");
        printf("1-读取所有学生信息\n");
        printf("2-读取指定学生信息\n");
        printf("3-查询总分最高的学生\n");
        printf("4-通过学号查找信息\n");
        printf("5-对学生信息按平均成绩进行排序\n");
        printf("6-按学号顺序插入一个学生信息\n");
        printf("7-删除指定学号或姓名对应的学生\n");
        printf("8-查找某个专业的、某门课程的成绩小于某个分数的学生\n");
        printf("9-删除某个班级的、某门课程的成绩小于某个分数的学生\n");
        printf("10-更改指定学生的信息\n");
        printf("其他-退出。\n");
        scanf("%d", &id);
        switch (id) {
            case 1: {
                STU *head;
                head=(STU*) malloc(LEN);
                Inputstu(head);
                Output(head);
                break;
            }
            case 2:{
                int num,k=0;
                STU *head,*p;
                head=(STU*) malloc(LEN);
                Inputstu(head);
                printf("请输入要查找的学生学号：");
                scanf("%d",&num);
                p=head;
                while (p->next!=NULL) {
                    p=p->next;
                    if (num == p->num) {
                        OutOneNode(p);
                        k=1;
                    }
                }
                if(k!=1){
                    printf("查无此人！\n");
                    }
                break;
            }
            case 3:{
                STU *head;
                head=(STU*) malloc(LEN);
                Max(head);
                break;
            }
            case 4:{
                STU *head;
                head=(STU*) malloc(LEN);
                int num;
                printf("请输入要查找的学生学号：\n");
                scanf("%d",&num);
                Search_num(head,num);
                break;
            }
            case 5:{
                STU *head;
                head=(STU*) malloc(LEN);
                Sort_select(head);
                break;
            }
            case 6:{
                STU *head;
                STU stu;
                head=(STU*) malloc(LEN);
                printf("请输入要插入的学生信息：\n");
                Input(&stu);  //输入的函数
                InsertList(head,stu);
                break;
            }
            case 7:{
                STU *head;
                head=(STU*) malloc(LEN);
                int num;
                char name[10];
                int a;
                printf("请输入想要通过学号还是姓名删除学生信息：（通过学号则输入1，通过姓名则输入2）\n");
                              //判别通过学号还是通过姓名...
                scanf("%d",&a);
                switch (a) {
                    case 1:{
                        STU *p;
                        p=head;
                        printf("请输入要删除的学号对应的学生信息：\n");
                        scanf("%d",&num);
                        Delete_num(head,num);   //通过学号删除的函数
                        break;
                    }
                    case 2:{
                        printf("请输入要删除的姓名对应的学生信息：\n");
                        scanf("%s",name);
                        Delete_name(head,&name);   //通过姓名删除的学号
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 8:{
                STU *head;
                char major[10];
                int subject;
                int grade;
                int a;
                char *str1="computer";
                char *str2="network";
                char *str3="software";
                head=(STU*) malloc(LEN);
                printf("请输入课程编号：（1~3）\n");
                scanf("%d",&a);
                if((a!=1)&&(a!=2)&&(a!=3)){
                    for(int t=0;;t++) {   //无限次循环，直到输入正确退出
                        printf("不存在该课程，请重新输入课程编号(1~3)");
                        scanf("%d", &a);
                        if((a>0)&&(a<4)){
                            printf("\n输入成功\n");
                            break;
                        }
                    }
                }
                subject=a-1;
                printf("请输入专业(computer/network/software)??\n");
                scanf("%s",major);
                if((strcmp(major,str1)!=0)&&(strcmp(major,str2)!=0)&&(strcmp(major,str3)!=0)){
                    for(int k=0;;k++) {  //无限次循环，直到输入正确退出
                        printf("不存在该专业，请重新输入(computer/software/network)??");
                        scanf("%s", major);
                        if((strcmp(major,str1)==0)||(strcmp(major,str2)==0)||(strcmp(major,str3)==0)){
                            printf("\n输入成功\n");
                            break;
                        }
                    }
                }
                printf("请输入最高分成绩：");
                scanf("%d",&grade);
                Search_major_subject_score(head,major,subject,grade);
                break;
            }
            case 9:{
                STU *head;
                int classno;
                int subject;
                int grade;
                int a;
                head=(STU*) malloc(LEN);
                printf("请输入课程编号：（1~3）\n");
                scanf("%d",&a);
                if((a!=1)&&(a!=2)&&(a!=3)){
                    for(int t=0;;t++) {     //无限次循环，直到输入正确退出
                        printf("不存在该课程，请重新输入课程编号(1~3)");
                        scanf("%d", &a);
                        if((a>0)&&(a<4)){
                            printf("\n输入成功\n");
                            break;
                        }
                    }
                }
                subject=a-1;
                printf("请输入班级：（1班/2班）\n");
                scanf("%d",&classno);
                if((classno!=1)&&(classno!=2)&&(classno!=3)){
                    for(int t=0;;t++) {  //无限次循环，直到输入正确退出
                        printf("不存在该班级，请重新输入班级：（1班/2班）");
                        scanf("%d", &classno);
                        if((classno>0)&&(classno<4)){
                            printf("\n输入成功\n");
                            break;
                        }
                    }
                }
                printf("请输入最高分成绩：");
                scanf("%d",&grade);
                Delete_class_subject_score(head,classno,subject,grade);
                break;
            }
            case 10:{
                STU *head;
                int scoreIndex;
                head=(STU*) malloc(LEN);
                printf("请输入要更改的学生学号：\n");
                scanf("%d",&scoreIndex);
                Change(head,scoreIndex);
                break;
            }
            default:
                break;
        }
    }
}