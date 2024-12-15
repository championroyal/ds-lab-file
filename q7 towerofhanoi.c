#include <stdio.h>
void toh(int n, char source, char dis, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", source, dis);
        return;
    }
    toh(n-1, source, aux, dis); 
    printf("\n Move disk %d from rod %c to rod %c", n, source, dis);
    toh(n-1, aux, dis, source);
}
 
int main()
{
    int n ;
    printf("Enter the number of disk :\n");
    scanf("%d",&n);
    
    toh(n, 'A', 'C', 'B');  
    return 0;
}
