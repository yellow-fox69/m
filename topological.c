#include <stdio.h>

void readgraph(int n,int a[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d", &a[i][j]);
    }
}

void find_indegree(int n, int a[10][10], int indegre[])
{
    int i,j,sum;
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        sum+=a[i][j];
        
        indegre[j]=sum;
    }
}

void topological_sort(int n, int a[10][10])
{
    int i, k, u, v, top, t[10],indegre[10],s[10];
    find_indegree(n,a,indegre);
    top=-1;
    for(i=0;i<n;i++)
    {
        if(indegre[i]==0) s[++top]=i;
    }
    while(top!=-1)
    {
        u=s[top--];
        t[k++]=u;
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                indegre[v]--;
                if(indegre[v]==0)
                {
                    s[++top]=v;
                }
            }
        }
    }
    printf("The topological sort sequence is: ");
    for(i=0;i<n;i++)
    printf("%d",t[i]);
}

void main()
{
    int n, a[10][10];
    printf(" \n Enter number of values");
    scanf("%d",&n);
    
    printf("\n Enter adjacency matrix");
    readgraph(n,a);
    topological_sort(n,a);
}
