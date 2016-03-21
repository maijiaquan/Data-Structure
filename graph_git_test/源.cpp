#include <iostream>

#define MaxInt 32767
#define MVNum 100
#define OK 1
#define ERROR 0

using namespace std;

//�ڽӾ���
typedef struct {
    char vexs[MVNum];     // �����
    int arcs[MVNum][MVNum]; //�ڽӾ���
    int vexnum,arcnum;     //�����ͱ���
}AMGraph;

//�ڽӱ�
typedef struct ArcNode{          //�߱�
    int adjvex;
    struct ArcNode *nextarc;
    int info;
}ArcNode;



typedef struct VNode{         //�����
    char data;
    ArcNode *firstacr;
}VNode,AdjList[MVNum];



typedef struct {
    AdjList vertices;        //�ṹ������
    int vexnum,arcnum;       //
}ALGraph;

//����ķ�㷨 ��������
typedef  struct closedge1{
    char adjvex;
    int lowcost;
}closedge1,closedge2[MVNum];

int LocateVex_ALG(ALGraph G,int v)
{
    int i=0;
     while(v != G.vertices[i].data)
         i++;

    return i;
}

//����ķ�㷨 ��������
typedef  struct closedge{
    char adjvex;
    int lowcost;
}closedge,closedge_a[MVNum];



int LocateVex_AMG(AMGraph G , char v){
    int i=0;
    while (v != G.vexs[i])
	{
        i++;
	}
	return i;
}


/*�����ڽӾ�������ͼ*/
int CreateUDN(AMGraph &G , int mode)
{  
	if(mode == 1)
	{
		G.vexnum = 5;
		G.arcnum = 6;
		G.vexs[0] = 'a';
		G.vexs[1] = 'b';
		G.vexs[2] = 'c';
		G.vexs[3] = 'd';
		G.vexs[4] = 'e';
	}
	else
	{
		/*���붥�����ͱ���*/
		cout<<"����������ͱ���";
		cin>>G.vexnum>>G.arcnum;

		/*���������*/
		for (int i = 0; i < G.vexnum; i++){
			cout<<"�����붥��";
			cin>>G.vexs[i];       
		}

		/*�����ڽӾ���*/
		for (int i=0; i<G.vexnum; i++)
			for (int j=0; j<G.vexnum; j++)
			{
				G.arcs[i][j]=MaxInt;   //Ĭ�ϱ����֮��ľ��������
			}

		/*����ڽӾ��󣬹���arcnum��������*2 ��Ԫ��*/
		for (int k=0; k < G.arcnum; k++)   //ѭ��arcnum��
		{
			char v1,v2;    
			int w;

			cout<<"�������"<<k+1<<"���ߵ��������Ȩֵw";
			cin>>v1>>v2>>w;

			int i=LocateVex_AMG(G,v1);
			int j=LocateVex_AMG(G,v2);

			G.arcs[i][j] = w;
			G.arcs[j][i]= G.arcs[i][j];   //�ԳƵ�ҲҪ���
		}
	}
    return OK;
}





int CreateUDG(ALGraph &G){        //�����ڽӱ�

    cout<<"����������ͱ���";

    cin>>G.vexnum>>G.arcnum;

    for (int i=0; i<G.vexnum; i++) {

        cout<<"�������"<<i+1<<"�����data";

        cin>>G.vertices[i].data;

        G.vertices[i].firstacr=NULL;

    }

    for (int k=0; k<G.arcnum; ++k) {

        char v1,v2;

        int i,j;

        ArcNode *p1,*p2;

        cout<<"�������"<<k+1<<"���ߵ�������";

        cin>>v1>>v2;

        i=LocateVex_ALG(G,v1);

        j=LocateVex_ALG(G,v2);

        p1=new ArcNode;

        p1->adjvex=j;

        p1->nextarc=G.vertices[i].firstacr;

        G.vertices[i].firstacr=p1;

        p2=new ArcNode;

        p2->adjvex=i;

        p2->nextarc=G.vertices[j].firstacr;

        G.vertices[j].firstacr=p2;// ��p1�ĳ�p2 2015.6.12 0��40

    }

    

    return OK;

}





void CHECK(ALGraph G){

    char d;

    int i;

    for (int j=0; j<G.vexnum; j++) {

            cout<<"����Ҫcheck��data";

        cin>>d;

        i=LocateVex_ALG(G,d);

        cout<<"data��adjvexΪ"<<i;

    }

}





void Print_AMG(AMGraph G){

    for (int k=0; k<G.vexnum; k++)

        cout<<G.vexs[k];

    for (int i=0; i<G.vexnum; i++){

        cout<<endl;

        for (int j=0; j<G.vexnum; j++)

            cout<<G.arcs[i][j]<<" ";

    }

        

}



void Print_ALG(ALGraph G){

    for (int i=0 ; i<G.vexnum; i++) {

        cout<<i;

        cout<<G.vertices[i].data;

        ArcNode *p;

        p=new ArcNode;

        p=G.vertices[i].firstacr;

        while(p!=NULL ) {

            cout<<"��"<<p->adjvex;

            p=p->nextarc;

        }

        cout<<endl;

    }

    

}



int visited[MVNum]={0};

void DFS1(ALGraph G,char d){

    ArcNode *p;

    int v,w;

    v=LocateVex_ALG(G,d);

    cout<<d;

    visited[v]=-1;

    p=G.vertices[v].firstacr;

    while (p!=NULL) {

        w =p->adjvex;

        if (visited[w]!=-1)

            DFS1(G, w);

        p = p->nextarc;

    }
}

void DFS2(ALGraph G,int v){    //�ڽӱ�ͼ�ı���

    ArcNode *p;

    int w;

    cout<<v;

    visited[v]=true;

    p=G.vertices[v].firstacr;

    while (p!=NULL) {

        w=p->adjvex;

        if(!visited[w])

            DFS2(G, w);

        p=p->nextarc;

    }

}





//int Min(closedge A){
//
//    for(int i=0;i<G.vexnum;i++){
//
//        int a=closedge[i].lowcost;
//
//        if
//
//            }
//
//    return i;
//
//}


//
//void MiniSpanTree_Prim(AMGraph G,char u){
//
//    int k=LocateVex_AMG(G, u);
//
//    for (int j=0; j<G.vexnum; j++)
//
//        if (j!=k)
//
//            closedge_a[j]={u,G.arcs[k][j]};
//
//    closedge_a[k].lowcost=0;
//
//    for{int i=1;i<G.vexnum;++i){
//
//        k=Min(closedge_a);
//
//        int u0=closedge_a[k].adjvex;
//
//        int v0=G.vexs[k];
//
//        cout<<u0<<v0<<endl;
//
//        closedge_a[k].lowcost=0;
//
//        for (int j=0; j<G.vexnum; j++) {
//
//            if(G.arcs[k][j]<closedge_a[j].lowcost)
//
//                closedge_a[j]={G.vexs[k],G.arcs[k][j]};
//
//        }
//
//    }
//
//        return OK;
//
//    }
//

int main() {

    while (true) {

        cout<<endl<<"��ѡ��"<<endl;
        cout<<"1------�ڽӾ���"<<endl;
        cout<<"2------�ڽӱ�"<<endl;
        cout<<"3------������С������_����ķ�㷨"<<endl;

        int a;
        cin>>a;

        switch (a) {
            case 1:{
				cout<<"��ѡ��1ʹ����������ͼ��2�Զ�������ͼ"<<endl;
                int mode;
				cin>>mode;
				AMGraph G_M;
				CreateUDN(G_M , mode);
                Print_AMG(G_M);}break;

            case 2:{
                ALGraph G_L;
                CreateUDG(G_L);  // CHECK( G);//cout<<"�������һ�������������������data";cin>>d;
                Print_ALG(G_L);

                cout<<"�����������"<<endl;

                int v=0; //�ڽӱ�ͼ�ı���

                DFS2(G_L, v);}break;

        }

    }

}



