#include <stdio.h>

int main(){
	// matriz[linha][coluna]
	int matriz[3][3] = {{3, 5, 8},
						{4, 10, 6},
						{49, 7, 9}};
						
	int i, j;
	int temp = matriz[0][0];
	
    for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (matriz[i][j] < temp)
				temp = matriz[i][j];
			
			if (temp == matriz[i][j])
			printf("a linha que contem o menor eh: %d\n", i);
		}	
	}
	printf("menor valor eh: %d\n ", temp);

}
