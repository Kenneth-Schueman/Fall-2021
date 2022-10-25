#ifndef shapes
#define shapes 

//Shapes

void triangle(int winX, int winY){
	int x, y;
	
	x = winX;
	y = winY; 
	
	//Triangle 
	mvaddstr(((y / 2) - 10), (x / 2), "^");
	mvaddstr(((y / 2) - 9), ((x / 2) - 1), "^^^");
	mvaddstr(((y / 2) - 8), ((x / 2) - 2), "^^^^^");
	mvaddstr(((y / 2) - 7), ((x / 2) - 3), "^^^^^^^");
	mvaddstr(((y / 2) - 6), ((x / 2) - 4), "^^^^^^^^^");
	mvaddstr(((y / 2) - 5), ((x / 2) - 5), "^^^^^^^^^^^");
	}
	
void square(int winX, int winY){
	int x, y;
	
	x = winX;
	y = winY;
	
	//Square
	for(int i =0; i < 8; i++){
		if (i <=0 || i >= 7){
			if (i == 0){
				mvaddstr(((y / 2) + 3), ((x / 2) - 20), "HHHHHHH");
			}
			else{
				mvaddstr(((y / 2) - 3), ((x / 2) - 20), "HHHHHHH");
			}
		}
		else{
			mvaddstr(((y / 2) + (3 - i)), ((x / 2) - 20), "H	 H");
		}
	}
}
	
void circle(int winX, int winY){
	int x, y;
	
	x = winX;
	y = winY;
	
	//Circle 
	mvaddstr(((y / 2) + 4), ((x / 2) + 15), "00");
	mvaddstr(((y / 2) + 3), ((x / 2) + 14), "0  0");
	mvaddstr(((y / 2) + 2), ((x / 2) + 13), "0    0");
	mvaddstr(((y / 2) + 1), ((x / 2) + 12), "0      0");
	mvaddstr((y / 2), ((x / 2) + 12), "0      0");
	mvaddstr(((y / 2) - 1), ((x / 2) + 13), "0    0");
	mvaddstr(((y / 2) - 2), ((x / 2) + 14), "0  0");
	mvaddstr(((y / 2) - 3), ((x / 2) + 15), "00");
	}
	
void cross(int winX, int winY){
	int x, y;
	
	x = winX;
	y = winY;
	
	//Cross
	mvaddstr(((y / 2) + 5),((x / 2) - 3), "X     X");
	mvaddstr(((y / 2) + 6), ((x / 2) - 2), "X   X");
	mvaddstr(((y / 2) + 7), ((x / 2) - 1), "X X");
	mvaddstr(((y / 2) + 8),  (x / 2), "X");
	mvaddstr(((y / 2) + 9), ((x / 2) - 1), "X X");
	mvaddstr(((y / 2) + 10), ((x / 2) - 2), "X   X");
	mvaddstr(((y / 2) + 11), ((x / 2) - 3), "X     X");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shape Selection

void standardPrint(int winX, int winY){
	int x, y;
	
	x = winX;
	y = winY;
	
	//Center O
	mvaddstr((y / 2), (x / 2), "o"); 
	
	triangle(winX, winY);
	square(winX, winY);
	circle(winX, winY); 
	cross(winX, winY);
	
	refresh();
}
	
void trianglePrint(int winX, int winY){
	int x, y, d;
	
	d = 9;
	x = winX;
	y = winY;
	
	//Center O
	mvaddstr((y / 2), (x / 2), "o"); 
	
	
	square(winX, winY);
	circle(winX, winY); 
	cross(winX, winY);
	
	//BOX
	mvaddstr(((y / 2) - 3), (x / 2)- d, "*******************");
	mvaddstr(((y / 2) - 4), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 5), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 6), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 7), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 8), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 9), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 10), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 11), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 12), (x / 2)- d, "*******************");
	
	triangle(winX, winY);
	
	refresh();
}

void squarePrint(int winX, int winY){
	int x, y, d;
	
	d = 26;
	x = winX;
	y = winY;
	
	//Center O
	mvaddstr((y / 2), (x / 2), "o"); 
	
	triangle(winX, winY);
	circle(winX, winY); 
	cross(winX, winY);
	
	//BOX
	mvaddstr(((y / 2) - 5), (x / 2)- d, "********************");
	mvaddstr(((y / 2) - 4), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 3), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 2), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) - 1), (x / 2)- d, "*			*");
	mvaddstr((y / 2), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 1), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 2), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 3), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 4), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 5), (x / 2)- d, "********************");
	
	square(winX, winY);
	
	refresh();
}

void circlePrint(int winX, int winY){
	int x, y, d;
	
	d = 6;
	x = winX;
	y = winY;
	
	//Center O
	mvaddstr((y / 2), (x / 2), "o"); 
	
	triangle(winX, winY);
	square(winX, winY); 
	cross(winX, winY);
	
	//BOX
	mvaddstr(((y / 2) - 5), (x / 2)+ d, "********************");
	mvaddstr(((y / 2) - 4), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) - 3), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) - 2), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) - 1), (x / 2)+ d, "*			*");
	mvaddstr((y / 2), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 1), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 2), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 3), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 4), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 5), (x / 2)+ d, "*			*");
	mvaddstr(((y / 2) + 6), (x / 2)+ d, "********************");
	
	circle(winX, winY);
	
	refresh();
}

void crossPrint(int winX, int winY){
	int x, y, d;
	
	d = 9;
	x = winX;
	y = winY;
	
	//Center O
	mvaddstr((y / 2), (x / 2), "o"); 
	
	triangle(winX, winY);
	square(winX, winY);
	circle(winX, winY); 
	
	mvaddstr(((y / 2) + 3), (x / 2)- d, "*******************");
	mvaddstr(((y / 2) + 4), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 5), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 6), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 7), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 8), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 9), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 10), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 11), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 12), (x / 2)- d, "*			*");
	mvaddstr(((y / 2) + 13), (x / 2)- d, "*******************");
	
	cross(winX, winY);
	
	refresh();
}

#endif