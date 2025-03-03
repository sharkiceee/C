#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stu.h"

//������
int main(){
    int id;
    while (1) {
        printf("\n�����빦�ܱ�ţ���ִ����ع���\n");
        printf("1-��ȡ����ѧ����Ϣ\n");
        printf("2-��ȡָ��ѧ����Ϣ\n");
        printf("3-��ѯ�ܷ���ߵ�ѧ��\n");
        printf("4-ͨ��ѧ�Ų�����Ϣ\n");
        printf("5-��ѧ����Ϣ��ƽ���ɼ���������\n");
        printf("6-��ѧ��˳�����һ��ѧ����Ϣ\n");
        printf("7-ɾ��ָ��ѧ�Ż�������Ӧ��ѧ��\n");
        printf("8-����ĳ��רҵ�ġ�ĳ�ſγ̵ĳɼ�С��ĳ��������ѧ��\n");
        printf("9-ɾ��ĳ���༶�ġ�ĳ�ſγ̵ĳɼ�С��ĳ��������ѧ��\n");
        printf("10-����ָ��ѧ������Ϣ\n");
        printf("����-�˳���\n");
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
                printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
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
                    printf("���޴��ˣ�\n");
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
                printf("������Ҫ���ҵ�ѧ��ѧ�ţ�\n");
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
                printf("������Ҫ�����ѧ����Ϣ��\n");
                Input(&stu);  //����ĺ���
                InsertList(head,stu);
                break;
            }
            case 7:{
                STU *head;
                head=(STU*) malloc(LEN);
                int num;
                char name[10];
                int a;
                printf("��������Ҫͨ��ѧ�Ż�������ɾ��ѧ����Ϣ����ͨ��ѧ��������1��ͨ������������2��\n");
                              //�б�ͨ��ѧ�Ż���ͨ������...
                scanf("%d",&a);
                switch (a) {
                    case 1:{
                        STU *p;
                        p=head;
                        printf("������Ҫɾ����ѧ�Ŷ�Ӧ��ѧ����Ϣ��\n");
                        scanf("%d",&num);
                        Delete_num(head,num);   //ͨ��ѧ��ɾ���ĺ���
                        break;
                    }
                    case 2:{
                        printf("������Ҫɾ����������Ӧ��ѧ����Ϣ��\n");
                        scanf("%s",name);
                        Delete_name(head,&name);   //ͨ������ɾ����ѧ��
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
                printf("������γ̱�ţ���1~3��\n");
                scanf("%d",&a);
                if((a!=1)&&(a!=2)&&(a!=3)){
                    for(int t=0;;t++) {   //���޴�ѭ����ֱ��������ȷ�˳�
                        printf("�����ڸÿγ̣�����������γ̱��(1~3)");
                        scanf("%d", &a);
                        if((a>0)&&(a<4)){
                            printf("\n����ɹ�\n");
                            break;
                        }
                    }
                }
                subject=a-1;
                printf("������רҵ(computer/network/software)??\n");
                scanf("%s",major);
                if((strcmp(major,str1)!=0)&&(strcmp(major,str2)!=0)&&(strcmp(major,str3)!=0)){
                    for(int k=0;;k++) {  //���޴�ѭ����ֱ��������ȷ�˳�
                        printf("�����ڸ�רҵ������������(computer/software/network)??");
                        scanf("%s", major);
                        if((strcmp(major,str1)==0)||(strcmp(major,str2)==0)||(strcmp(major,str3)==0)){
                            printf("\n����ɹ�\n");
                            break;
                        }
                    }
                }
                printf("��������߷ֳɼ���");
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
                printf("������γ̱�ţ���1~3��\n");
                scanf("%d",&a);
                if((a!=1)&&(a!=2)&&(a!=3)){
                    for(int t=0;;t++) {     //���޴�ѭ����ֱ��������ȷ�˳�
                        printf("�����ڸÿγ̣�����������γ̱��(1~3)");
                        scanf("%d", &a);
                        if((a>0)&&(a<4)){
                            printf("\n����ɹ�\n");
                            break;
                        }
                    }
                }
                subject=a-1;
                printf("������༶����1��/2�ࣩ\n");
                scanf("%d",&classno);
                if((classno!=1)&&(classno!=2)&&(classno!=3)){
                    for(int t=0;;t++) {  //���޴�ѭ����ֱ��������ȷ�˳�
                        printf("�����ڸð༶������������༶����1��/2�ࣩ");
                        scanf("%d", &classno);
                        if((classno>0)&&(classno<4)){
                            printf("\n����ɹ�\n");
                            break;
                        }
                    }
                }
                printf("��������߷ֳɼ���");
                scanf("%d",&grade);
                Delete_class_subject_score(head,classno,subject,grade);
                break;
            }
            case 10:{
                STU *head;
                int scoreIndex;
                head=(STU*) malloc(LEN);
                printf("������Ҫ���ĵ�ѧ��ѧ�ţ�\n");
                scanf("%d",&scoreIndex);
                Change(head,scoreIndex);
                break;
            }
            default:
                break;
        }
    }
}