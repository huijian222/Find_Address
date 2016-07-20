#include <stdio.h>
#include <math.h>

#define MAX_CROSS 9 

int test[3][3] = {{3,1,1},{3,3,2},{1,1,1}};   //2为当前位置 3为宝藏位置
int treasure_x[MAX_CROSS] = {0};
int treasure_y[MAX_CROSS] = {0};
int now_x = 0 , now_y = 0;
int difference_total[MAX_CROSS][3];
int temp = 0;

void Bubble_Sort(int *num, int n);
void Print(int *num, int n);
void GetAdd(void);
void move(int move_x, int move_y);
void GetTreasureAdd(void);

int main(void) {
	int f = 4;
	while(f--){
	GetAdd();
	GetTreasureAdd();
	Bubble_Sort(difference_total, temp);   
//	Print(difference_total, temp); 
	Print(test, 3); 
	puts("\n");
	move(difference_total[0][1],difference_total[0][2]);
	}

}

void Bubble_Sort(int (*num)[3], int n){     //排序获取距离最短的宝藏位置
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; i + j < n - 1; j++){
            if(num[j][0] > num[j + 1][0]){
                int temp = num[j][0];
				int temp_0 = num[j][1];
				int temp_2 = num[j][2];
                num[j][0] = num[j + 1][0];
				num[j][1] = num[j + 1][1];
				num[j][2] = num[j + 1][2];
                num[j + 1][0] = temp;
				num[j + 1][1] = temp_0;
				num[j + 1][2] = temp_2;
            }
        }
    }
}

void Print(int (*num)[3], int n)
{
    int i,k;
    for(i = 0; i < n; i++){
		for(k = 0; k <3;k++){
			printf("%d ", num[i][k]);
			
		}
	puts("\n");
	}
    return;
}


void GetAdd(void){
	int i ,j,k;
	for(i = 0; i < 3; i++){      //遍历一遍得到当前位置坐标
		for(j = 0; j < 3; j++){
			if(test[i][j] == 2){
				now_x = i;
				now_y = j;
			}
		}
	}
}

void GetTreasureAdd(void){
	int i,j,k;
	temp = 0;
	for(i = 0; i < 3; i++){      //遍历一遍得到宝藏坐标
		for(j = 0; j < 3; j++){
			if(test[i][j] == 3){
				treasure_x[temp] = i;
				treasure_y[temp] = j;
				temp++;
			}
		}
	}
	for(k = 0; k < temp; k++){ //获取当前位置和所有宝藏相差的距离	
			difference_total[k][0] = abs(now_x - treasure_x[k]) + abs(now_y - treasure_y[k]);//),treasure_x[k],treasure_y[k]};
			difference_total[k][1] = treasure_x[k];
			difference_total[k][2] = treasure_y[k];
	}
}

void move(int move_x, int move_y){ 
	GetAdd();
	test[now_x][now_y] = 1;
	test[move_x][move_y] = 2;
}