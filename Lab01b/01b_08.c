#include <stdio.h>

void transposta(int matriz[][3]){
	int M2[3][3];
	
	printf("matriz original:\n");
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
	printf("\n");
	printf("matriz transporta:\n");
	for (int i = 0; i < 3; i++){
	
		for (int j = 0; j < 3; j++)
			M2[i][j] = matriz[j][i];
	}
	
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", M2[i][j]);
        printf("\n");
    }
	
}


int main(){
	int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
//	printf("%d",transposta(M));
	transposta(M);
//	printf("\n");

}
