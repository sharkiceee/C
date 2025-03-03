//
// Created by 86137 on 2023/7/11.
//

#ifndef SSSA_STU_H
#define SSSA_STU_H

#endif //SSSA_STU_H
#define LEN sizeof(STU)
#define N 12

struct Student{
    char name[15];//姓名
    char major[10];//专业（computer,software,network）
    int classNo;//班级(1-2)
    int num;//学号
    int score[3];//3门课的成绩(0-2)
    struct Student *next;//指向下一结点的指针
};
typedef struct Student STU;

//函数声明
void Output (STU *head);
void Max(STU *head);
void OutOneNode(STU *p);
void Input(STU *p);
void Inputstu(STU *head);
void Search_num(STU * head ,int num);
void  InsertList(STU * head, STU stu );
void  Delete_num(STU *head,int num);
void Sort_select(STU *head);
void  Delete_name(STU *head,char name[10]);
void Change(STU *head,int scoreIndex);
void YesNo(STU *head);
STU *CreateList(char *filename,STU *head);
void Search_major_subject_score(STU *head, char major[20], int subject , int grade);
void  Delete_class_subject_score(STU *head, int classno, int subject, int grade);
