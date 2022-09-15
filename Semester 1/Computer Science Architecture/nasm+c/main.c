#include <stdio.h>
int compare_min(int a, int b);

void  main()
{
    freopen("text.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int arr[100];
    int i;
    int minn = 200000000;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(i = 0; i < n; i++)
        minn = compare_min(minn, arr[i]);
    
    printf("%x", minn);
    
}
