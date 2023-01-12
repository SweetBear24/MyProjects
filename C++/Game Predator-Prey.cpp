/* The plant is a carrot, the herbivore is a hare, the predator is a wolf.
The plant lives 5 cycles and dies. The hare breeds with a 25% chance. Both the hare and the wolf have a hunger score of 1.
If the wolf has a hunger value of less than 0.5, it can move 2 squares around itself instead of one.
If the wolf ate more than 2 hares, then after moving or eating the hare on the previous cell, it will leave behind a new wolf.
Such reproduction occurs once in the life of a wolf. Minimum 5 wolves per field.
If this number
 decreases, it is necessary to create a new wolf on the border of the field. */

/*Растение – морковь, травоядное животное – заяц, хищник – волк.
Растение живет 5 циклов и погибает. Заяц размножается с вероятностью в 25%. И заяц, и волк имеет показатель голода равный 1. 
Если волк имеет показатель голода меньше чем 0,5 может перемещаться на 2 клетки вокруг себя, а не на одну. 
Если волк съел больше 2 зайцев, то после перемещения или съедения зайца на предыдущей клетке оставит после себя нового волка. 
Такое размножение происходит один раз за жизнь волка. Минимум 5 волков на поле. 
В случае если это количество уменьшится – необходимо создать нового волка на границе поля.*/

#include<Windows.h>
#include<time.h>
#include<vector>
#include<iostream>
using namespace std;
int kol_vo_R = 10;
int kol_vo_W = 10;
int kol_vo_G = 10;
int sex_R = 0;
int eat = 0;
const int n = 20;
int A[n][n];

class Wolf {
public:
	int life;
	bool sex;
	int x;
	int y;
	Wolf() {
		x = rand() % 20;
		y = rand() % 20;
		A[x][y] = 5;
	}
	void hod() {
		int k = rand() % 8 + 1;
		if ((k == 1) && (y != 0)) {
			if(A[x][y--]==3){
				eat++;
			}
			A[x][y] = 0;
			y--;
			A[x][y] = 5;
		}
		if ((k == 2) && (y != 0) && (x != 19)) {
			if(A[x++][y--]==3){
				eat++;
			}
			A[x][y] = 0;
			y--;
			x++;
			A[x][y] = 5;
		}
		if ((k == 3) && (x != 19)) {
			if(A[x++][y]==3){
				eat++;
			}
			A[x][y] = 0;
			x++;
			A[x][y] = 5;
		}
		if ((k == 4) && (y != 19) && (x != 19)) {
			if(A[x++][y++]==3){
				eat++;
			}
			A[x][y] = 0;
			x++;
			y++;
			A[x][y] = 5;
		}
		if ((k == 5) && (y != 19)) {
			if(A[x][y++]==3){
				eat++;
			}
			A[x][y] = 0;
			y++;
			A[x][y] = 5;
		}
		if ((k == 7) && (x != 0)) {
			if(A[x++][y]==3){
				eat++;
			}
			A[x][y] = 0;
			x--;
			A[x][y] = 5;
		}
		if ((k == 8) && (y != 0) && (x != 0)) {
			if(A[x--][y--]==3){
				eat++;
			}
			A[x][y] = 0;
			x--;
			y--;
			A[x][y] = 5;
		}
	}
};

class Rabbit{
private:
	int x;
	int y;
public:
	int life;
	Rabbit() {
		x = rand() % 20;
		y = rand() % 20;
		A[x][y] = 3;
	}
	void hod() {
		int m = rand() % 8 + 1;
		if ((m == 1) && (y != 0)) {
			if(A[x][y--]==5){
				A[x][y] = 0;
				y--;
				A[x][y] = 5;
			}
			else{
				A[x][y] = 0;
				y--;
				A[x][y] = 3;
			}
		}
		if ((m == 3) && (x != 19)) {
  			if(A[x++][y]==5){
				A[x][y] = 0;
				x++;
				A[x][y] = 5;
			}
			else{
				A[x][y] = 0;
				x++;
				A[x][y] =  3;
			}
		}
		if ((m == 4) && (y != 19) && (x != 19)) {
			if(A[x++][y++]==5){
				A[x][y] = 0;
				x++;
				y++;
				A[x][y] = 5;
			}
			else{
				A[x][y] = 0;
				x++;
				y++;
				A[x][y] = 3;
			}
		}
		if ((m == 5) && (y != 19)) {
		   	A[x][y] = 0;
			y++;
			A[x][y] = 3;
		}
		if ((m == 6) && (y != 19) && (x != 0)) {
				A[x][y] = 0;
				x--;
				y++;
				A[x][y] = 3;
		}
		if ((m == 7) && (x != 0)) {
			A[x][y] = 0;
			x--;
			A[x][y] = 3;
		}
				
		if ((m == 8) && (y != 0) && (x != 0)) {
			A[x][y] = 0;
			y--;
			x--;
			A[x][y] = 3;
		}
	}	
};   
class Grass{
private:
	int x;
	int y;
public:
	Grass () {
		x = rand() % 20;
		y = rand() % 20;
		A[x][y] = 1;
	}  
 	void spam() {
		x = rand() % 20;
		y = rand() % 20;
		if(A[x][y] == 0){
			A[x][y] = 1;
		}	
	};
};
void Field() {

	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
};

int main() {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}

	vector<Grass> G(0);	
	for (int i = 0; i < kol_vo_G; i++){
		Grass trava;
		G.push_back(trava);
	}
	vector<Wolf> W(0);
	for (int i = 0; i < kol_vo_W; i++){
		Wolf volk;
		W.push_back(volk);
	}
	vector<Rabbit> R(0);
	for (int j = 0; j < kol_vo_R; j++)	{
		Rabbit Zaya ;
		R.push_back(Zaya);
	}
	Field();
	int life_grass = 0;
	int sex_R = 0;            
	while (true)
	{    
		for (int i = 0; i < kol_vo_G; i++)
		{   
			Grass trava;
		}
		for (int i = 0; i < kol_vo_W; i++){   
			W[i].hod();
			if(eat==2){
				Wolf volk;
				W.push_back(volk);
			}
		}
     	for (int i = 0; i < kol_vo_R; i++){   
			R[i].hod();
			sex_R = rand() % 4 + 1;
			if(sex_R == 2){
				Rabbit Zaya;
				R.push_back(Zaya);
			}

		}		
		Sleep(500);
		Field();
	}
	return 0;
}
                