#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <String.h>
#define N 16
struct dz{	//��¼����������Ϣ 
	int dsID;//����ID
	int mydf;//�ҷ��÷�
	int dsdf;//���ֵ÷� 
};
struct fbteam{
	int ID;//��ӱ�� 
    char name[10];//�������
    int score;//��ӻ���
    int jsqs;//��ʤ����
    int zjqs;//�ܽ�����
    double pxf;//�����
    char fz; //����
    struct dz dz_score[N];//��¼ÿ����������ӵıȷ� 
    int score2;
    int jsqs2;
    int zjqs2;
}ft[N];
int n=0;//��ӵĸ���
void add(){  //�������
    n++;
    getchar();
    printf("�������%d֧��ӵ����ƣ�",n);
    gets(ft[n].name);
    printf("���������ڵ�С�飺�����һ������1��\n");
    scanf("%c",&ft[n].fz);
    ft[n].ID=n;
}
int lookup(char qdstr[]){  //�������
    int i;
    for(i=1;i<=n;i++){
        if(strcmp(ft[i].name,qdstr)==0){
            return i;
        }
    }
    return 0;
}
void myprint(int i){   //���ĳ�����Ϣ
    printf("\n������� ���� ��ʤ���� �ܽ����� С��\n");
    printf("%s\t%d\t%d\t%d\t%c\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz);
}
void print() {	//������������Ϣ 
	printf("\n������� ���� ��ʤ���� �ܽ����� С��\n");
	for(int i=1;i<=n;i++){
		printf("%s\t%d\t%d\t%d\t%c\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz);
	}
}
void mod(){    //�޸����
    int i,j;
    int x=0,y=0;    //�ȷ�
    int t;  //�����Ƚ���֧��ӵıȷ�
    int a;  //����Ҫ�޸ĵ���ӵ��±� 
    int k; //����ѡ���޸ĵ������Ϣ 
    int m; //����ѡ���ս��ӵı�� 
    char qdstr[20];
    getchar();
    printf("������Ҫ�޸ĵ�������ƣ�");
    gets(qdstr);
    a=lookup(qdstr);
    if(a!=0){
        myprint(a);
        printf("��ѡ��Ҫ�޸ĵ���Ϣ��\n");
        printf("1��������� 2���÷���� \n");
        scanf("%d",&k);
        switch(k){
            case 1:
                printf("��������ӵ������ƣ�");
                scanf("%s",ft[a].name);
                break;
            case 2:
                printf("��ѡ��Ҫ�޸�����֧���֮��ıȷ֣�\n");
                for(i=1;i<=n;i++){
                	if(ft[a].dz_score[i].dsID!=0){
                		printf("���%d���\t",ft[a].dz_score[i].dsID);
					}
				}
				printf("\n��������ӱ�ţ�");
				scanf("%d",&m);
				for(i=1;i<=n;i++){
					if(ft[a].dz_score[i].dsID==m){
						printf("\nԭ���ȷ�Ϊ��%d-%d\n",ft[a].dz_score[i].mydf,ft[a].dz_score[i].dsdf);
						t=ft[a].dz_score[i].mydf-ft[a].dz_score[i].dsdf;
						ft[a].jsqs = ft[a].jsqs-t;
						ft[m].jsqs = ft[m].jsqs-(-t);
						ft[a].zjqs = ft[a].zjqs-ft[a].dz_score[i].mydf;
						ft[m].zjqs = ft[m].zjqs-ft[a].dz_score[i].dsdf;
						if(t>0){
							ft[a].score=ft[a].score-3;
						}else if(t==0){
							ft[a].score=ft[a].score-1;
							ft[m].score=ft[m].score-1;
						}else{
							ft[m].score=ft[m].score-3;
						}
						printf("����������ӵıȷ�(��2-3)��");
						scanf("%d-%d",&x,&y);
						ft[a].dz_score[i].mydf=x;
						ft[a].dz_score[i].dsdf=y;
						ft[i].dz_score[a].dsdf=x;
						ft[i].dz_score[a].mydf=y;
						t=x-y;
						ft[a].jsqs=ft[a].jsqs+t;
						ft[m].jsqs=ft[m].jsqs+(-t);
						ft[a].zjqs=ft[a].zjqs+x;
						ft[m].zjqs=ft[m].zjqs+y;
						if(t>0){   
		                    ft[a].score=ft[a].score+3;     
		                }else if(t==0){     
		                    ft[m].score=ft[m].score+1;      
		                    ft[a].score=ft[a].score+1;
		                }else{       
		                    ft[m].score=ft[m].score+3;      
		                }
					}
				}
                break;			
            default:
                printf("��ȡ���޸ģ�\n");
                break;
        }
        print();
    }else{
        printf("�Ҳ����������Ϣ��\n");
    }
}
void del(){  //ɾ�����
    int i,j;
    int k;  //ѡ���Ƿ�ɾ��
    int a;   //��Ҫɾ������ӵ��±�
    int t;  //�Ƚ�����ӵıȷ� 
    int x=0,y=0; //��¼�ȷ� 
    char qdstr[20];
    getchar();
    printf("������Ҫɾ����������ƣ�");
    gets(qdstr);
    a=lookup(qdstr);
    if(a!=0){
        myprint(a);
        printf("��ȷ���Ƿ�ɾ����1���� 2����\n");
        scanf("%d",&k);
        switch(k){
            case 1:
            	for(i=1;i<=n;i++){
            		if(ft[a].fz==ft[i].fz && a!=i){
            			for(j=1;j<=n;j++){
            				if(ft[a].dz_score[j].dsID==i){
            					x=ft[a].dz_score[j].mydf;
			            		y=ft[a].dz_score[j].dsdf;
			            		t=x-y;
			            		ft[a].jsqs = ft[a].jsqs - t;
			            		ft[i].jsqs = ft[i].jsqs -(-t);
			            		ft[a].zjqs = ft[a].zjqs - x;
			            		ft[i].zjqs = ft[i].zjqs - y;
			            		if(t>0){
			            			ft[a].score=ft[a].score - 3;
								}else if(t==0){
									ft[a].score=ft[a].score - 1;
									ft[i].score=ft[i].score - 1;
								}else{
									ft[i].score=ft[i].score - 3;
								}
							} 
	            					
						}
					}
				}
				for(i=a;i<=n;i++){
					ft[i]=ft[i+1];
				}
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						if(ft[i].dz_score[j].dsID==a){
							ft[i].dz_score[j].dsID=0;	
							break;
						}
					}
				}
				n--;
                printf("ɾ���ɹ���\n");
                break;
            case 2:
                printf("��ȡ��ɾ����\n");
                break;
            default:
                break;
        }
        print();
    }else{
        printf("�Ҳ����������Ϣ��\n");
    }
}
void input(){    //�ɼ�����
    int i,j;
    int x=0,y=0;    //�ȷ�
    int t;  //�����Ƚ���֧��ӵıȷ�
    int p=1,q=1;
    if(n>=2){
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(ft[i].fz==ft[j].fz){
                    printf("������%s�Ӻ�%s�ӵıȷ֣���2-3����",ft[i].name,ft[j].name);
                    scanf("%d-%d",&x,&y);
                    t=x-y;
                    ft[i].jsqs+=t;
					ft[i].zjqs+=x;
					ft[j].jsqs+=(-t);
					ft[j].zjqs+=y;
					ft[i].dz_score[p].dsID=j;
					ft[i].dz_score[p].mydf=x;
					ft[i].dz_score[p].dsdf=y;
					ft[j].dz_score[q].dsID=i;
					ft[j].dz_score[q].mydf=y;
					ft[j].dz_score[q].dsdf=x;
                    if(t>0){       
                        ft[i].score+=3;                                
                    }else if(t==0){    
                        ft[i].score+=1;      
                        ft[j].score+=1;
                    }else{     
                        ft[j].score+=3;      
                	} 
				    if(j!=n){
				    	p++;
					}                   
                }	
            } 
            p=i+1;
			q=i+1; 
        } 
        printf("����Ӷ�ս�������:\n");
        for(i=1;i<=n;i++){
        	for(j=1;j<=n;j++){
        		if(ft[i].dz_score[j].dsID>0){
        			printf("���%d�� vs ���%d��:%d-%d\n",i,ft[i].dz_score[j].dsID,ft[i].dz_score[j].mydf,ft[i].dz_score[j].dsdf);	
				}
			}
		}
    }else{
        printf("�����������!(����������֧���)\n");
    }
}
void rank(){    //����
    int i,j,k;
    int a;//��¼��ͬ����ֵ���ӵ��±� 
    struct fbteam temp;
    int x=0,y=0;//��¼�������ȵ�����໥֮������ĵ÷� 
    int t;//�Ƚ��������ȵ����֮������ıȷ� 
    for(i=1;i<=n;i++){
        ft[i].pxf=ft[i].score+ft[i].jsqs*0.01+ft[i].zjqs*0.0001;
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n-i;j++){
            if(ft[j].pxf<ft[j+1].pxf){
               temp=ft[j];
               ft[j]=ft[j+1];
               ft[j+1]=temp;
            }else if(ft[j].pxf==ft[j+1].pxf){
				for(k=1;k<=n;k++){
					if(ft[j].dz_score[k].dsID==ft[j+1].ID){
						a=ft[j+1].ID;
						ft[j].zjqs2=ft[j].dz_score[k].mydf;
						ft[a].zjqs2=ft[j].dz_score[k].dsdf;
						t=ft[j].zjqs2-ft[a].zjqs2;
						ft[j].jsqs2=t;
						ft[a].jsqs2=(-t);
						if(t>0){
							ft[j].score2=3;
						}else if(t==0){
							ft[j].score2=1;
							ft[a].score2=1;
						}else{
							ft[a].score2=3;
						}
					}
				}
				if(ft[j].fz==ft[j+1].fz){
	            	if(ft[j].score2<ft[a].score2){	 //�������ȣ��Ƚ��໥֮������ĵ÷ָߵ� 
	            		temp=ft[j];
	            		ft[j]=ft[j+1];
	            		ft[j+1]=temp;
					}else if(ft[j].score2==ft[a].score2){	//�໥֮������÷���ȣ��Ƚ��໥֮������ľ�ʤ���� 
						if(ft[j].jsqs2<ft[a].jsqs2){	 
							temp=ft[j];
	            			ft[j]=ft[j+1];
	            			ft[j+1]=temp;
						}else if(ft[j].jsqs2==ft[a].jsqs2){	//�໥֮�������ʤ������ȣ��Ƚ��໥֮������Ľ����� 
							if(ft[j].zjqs2<ft[a].zjqs2){
								temp=ft[j];
	            				ft[j]=ft[j+1];
	            				ft[j+1]=temp;
							}else if(ft[j].zjqs2==ft[a].zjqs2){	//�໥֮������Ľ�������ȣ����г�ǩ 
				                int r;
				                srand((unsigned)time(NULL));
				                k=rand()%10+1;
				                if(r%2==0){
				                    temp=ft[j];
				                    ft[j]=ft[j+1];
				                    ft[j+1]=temp;
				                }else{
				                    break;
				                }					
							}
						}
					}            	         					
				}else{	//�������ȵ���ͬ�����ӽ��г�ǩ 
	                int r;
		            srand((unsigned)time(NULL));
				    k=rand()%10+1;
				    if(r%2==0){
				    temp=ft[j];
				    ft[j]=ft[j+1];
				    ft[j+1]=temp;
				    }else{
				        break;
				    }								
				}	       	                     
            }
        }
    }
    printf("������� ���� ��ʤ���� �ܽ����� С�� ����\n");
    for(i=1;i<=n;i++){
        printf("%s\t%d\t%d\t%d\t%c\t%d\n",ft[i].name,ft[i].score,ft[i].jsqs,ft[i].zjqs,ft[i].fz,i);
    }
}
int main(){
    int choice,i;
    while(1){
        //�˵�����ӵ����ӡ����ҡ��޸ġ�ɾ���������ɼ����룬��������
        printf("\n\t\t**********����С�������ֹ���ϵͳ**********\n");
		printf("\t\t\t\t1.�������\n");
        printf("\t\t\t\t2.�������\n");
        printf("\t\t\t\t3.�޸����\n");
        printf("\t\t\t\t4.ɾ�����\n");
        printf("\t\t\t\t5.�ɼ�����\n");
        printf("\t\t\t\t6.��������\n");
        printf("\t\t\t\t0.�˳�ϵͳ\n");
        printf("\t\t******************************************\n");
        printf("��ѡ��");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                char qdstr[20];
                getchar();
                printf("�����������ӵ����ƣ�");
                gets(qdstr);
                i=lookup(qdstr);
                if(i!=0){
                   myprint(i);
                }else{
                    printf("�Ҳ����������Ϣ��\n");
                }
                break;
            case 3:
                mod();
                break;
            case 4:
                del();
                break;
            case 5:
                input();
                break;
            case 6:
                rank();
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
