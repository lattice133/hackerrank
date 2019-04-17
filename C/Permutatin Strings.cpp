#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_string(int n, int pos, char **s) // position is included
{
    int i;
    int k = 1;
    int flag = 1;
    char *temp;
    while(flag){
        flag = 0;
        for(i=pos; i<n-k; i++){
            if(strcmp(s[i],s[i+1]) > 0){
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                flag = 1;
            }
        }
        k++;
    }
    return 1;
}

int find_string(int n, int pos, char **s) //find the string to replace pos
{
    char *temp;
    int i;
    temp = s[pos];
    int target = pos;
    for(i=pos+1; i<=n-1; i++)
    {
        if(strcmp(s[i],s[pos])>0) 
        {
            temp = s[i];
            target = i;
        }
    }
    if(target == pos) return pos;
    for(i=pos+1; i<=n-1; i++)
    {
        if ((strcmp(s[i],temp)<0)&&(strcmp(s[i],s[pos])>0))
        {
            temp = s[i];
            target = i;
        }
    }
    return target;
}

int next_permutation(int n, char **s)
{
    /**
    * Complete this method
    * Return 0 when there is no next permutation and 1 otherwise
    * Modify array s to its next permutation
    */
    int result = 0;
    int target,i;
    char *temp;
    for (i=n-2; i>=0; i--)
    {
        target = find_string(n,i,s);
        if (target!=i)
        {
            temp = s[i];
            s[i] = s[target];
            s[target] = temp;
            sort_string(n,i+1,s);
            return 1;

        }
    }
    return result;
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
