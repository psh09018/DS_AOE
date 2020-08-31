#include<iostream>
#define max(x,y) (x>y?x:y)
using namespace std;
int main(){
    int N;
    cin>>N; //edge,activity index
    int temp[N][N];
    for(int i=0;i<N;i++)  //matrix initialization
        for(int j=0;j<N;j++)
            temp[i][j]=0;
    int id,u,v,dur;
    int max=0;
    for(int i=0;i<N;i++){
        cin>>id>>u>>v>>dur;
        temp[u][v]=dur;
        if(v>max)
            max=v;
    }
    int V=max+1;  //vertex
    int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j] = temp[i][j];
        }
    }
    int ee[V],le[V];
    for(int i=0;i<V;i++)  //initialization
        ee[i]=0;
    
    //ee calculation
    for(int i=0;i<V;i++)
        for(int j=0;j<i;j++)
            if(graph[j][i]!=0)
                ee[i] = max(ee[i],ee[j]+graph[j][i]);
    
    //le initialization
    le[V-1]=ee[V-1];
    le[0]=0;
    //le calculation
    for(int i=0;i<V-1;i++){
        le[i]=1000;
    }
    for(int i=V-2;i>=0;i--){
        for(int j=i;j<V;j++)
            if(graph[i][j]!=0)
                le[i]=min(le[i],le[j]-graph[i][j]);
    }
    //ee,le output
    cout<<"event\t"<<"ee\t"<<"le\t"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t"<<ee[i]<<"\t"<<le[i]<<"\t"<<endl;
    }
    cout<<endl;
    int e[N],l[N];
    int k=0;
    //e
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=0)
                e[k++] = ee[i];
        }
    }
    //l
    k=0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            if(graph[j][i]!=0)
                l[k++] = le[i]-graph[j][i];
    }
    //slack&critical
    int slack[N];
    bool cri[N];
    for(int i=0;i<N;i++){
        slack[i]=l[i]-e[i];
        if(slack[i]==0)
            cri[i]=true;
        else cri[i]=false;
    }
    cout<<"act.\t"<<"e\t"<<"l\t"<<"slack\t"<<"critical\t"<<endl;
    for(int i=0;i<N;i++){
        cout<<i+1<<"\t"<<e[i]<<"\t"<<l[i]<<"\t"<<slack[i]<<"\t";
        if(cri[i]==true)
            cout<<"Yes\t"<<endl;
        else cout<<"No\t"<<endl;
    }
    cout<<endl;
    for(int i=0;i<N;i++)
        if(slack[i]==0)
            cout<<i+1<<" ";
    cout<<endl;
}
