# include "iGraphics.h"
# include "windows.h"
int Archer_y=200;
int Arrow_x=1025, Arrow_y=Archer_y+50;
int Arrow_x1=1025, Arrow_y1=Archer_y+50;
int Zubat_x=800, Zubat_y=0;
int Pelipper_x = 650, Pelipper_y = Zubat_y - 250;
int Woobat_x = 500 , Woobat_y =Zubat_y-128 ;
int page=1;
bool shoot=false;
int level = 1 ;
char lvl[20] ;
char sc[20];
int T,score;
char tm[50];

bool HitWoobat(void);
bool HitZubat(void);
bool HitPelipper(void);

void ResetWoobat(void);
void ResetZubat(void);
void ResetPelipper(void);

void ShowScore(void);
void ShowTime(void);
void ShowGameOver(void);
void ShowLevel(void);
int setTimer1,setTimer2,setTimer3,setTimer4,setTimer5,setTimer6;

void iDraw()
{
	iClear();
	if(page==1) iShowBMP(0,0,"MainMenu.bmp");
	else if(page==5) iShowBMP(0,0,"credits.bmp");
	else if(page==6) iShowBMP(0,0,"highscore.bmp");
	else if(page==4) iShowBMP(0,0,"Instructions.bmp");

	else if(page==2) {

	iShowBMP(0,0,"BackGround.bmp");
	if(shoot==true)iShowBMP(Arrow_x,Arrow_y,"Arrow.bmp");
	if(shoot==true)iShowBMP(Arrow_x1,Arrow_y1,"Arrow.bmp");
	iShowBMP(0,Archer_y,"Archer.bmp");
	ShowLevel();
	
	//zubat hit

	if(HitZubat()==false){
		iShowBMP(Zubat_x,Zubat_y,"Zubat.bmp");
	}
	else{ 
		iShowBMP(Zubat_x,Zubat_y,"Poof.bmp");
		ResetZubat();
	}
	
	//Woobat hit

	if(HitWoobat()==false){
		iShowBMP(Woobat_x,Woobat_y,"Woobat.bmp");
	}
	else{ 
		iShowBMP(Woobat_x,Woobat_y,"Poof.bmp");
		ResetWoobat();
	}

	// pelipper hit
	if(HitPelipper()==false){
		iShowBMP(Pelipper_x,Pelipper_y,"Pelipper.bmp");
	}
	else{ 
		iShowBMP(Pelipper_x,Pelipper_y,"Poof.bmp");
		ResetPelipper();
	}
	/*if(page==4) {
		iShowBMP();
	}*/


	}



	ShowScore();
	ShowTime();
	if(page==3){
		ShowGameOver();
		ShowScore();
	}

	

}
void iMouseMove(int mx, int my)
{
	
}
void iPassiveMouseMove(int mx, int my){
	if(my>382)
	Archer_y=382;
	else
    Archer_y=my;
	//if(shoot==false)Arrow_y=my+50;
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{   
		printf("x = %d y = %d\n", mx, my);
		if(mx>637 && mx<1024 && my>253 && my<308 && page==1){//Click on New Game in Main Menu
			page=2;
			T=60;
			score=0;
			iResumeTimer(setTimer1);
			iResumeTimer(setTimer2);
			iResumeTimer(setTimer3);
			iResumeTimer(setTimer4);
			iResumeTimer(setTimer5);
			iResumeTimer(setTimer6);
		}
		else if(mx>637 && mx <1024 && my > 60 && my <116 && page == 1)page=5;//Click on Credits in Main Menu
		else if(mx>10 && mx <128 && my>440 && my<492 && page==5)page=1;// Click on Back Button in Credits Screen
		else if(mx>637 && mx <1024 && my>123 && my<180 && page==1)page=6;// Click on in Highscore in Main Menu
		else if(mx>29 && mx <129 && my>430 && my<480 && page==6)page=1;// Click on Back Button in Highscore Screen
		else if(mx>637 && mx <1024 && my>186 && my<245 && page==1)page=4;// Click on Instructions in Main Menu
		else if(mx>850 && mx <1012 && my>5 && my<87 && page==4)page=1;// Click on Back Button in Instructions Screen

		else if(mx>850 && mx <990 && my>452 && my<504 && page==3){// Click on Replay in Game Over Screen
			page=2;
			T=120;
			score=0;
			iResumeTimer(setTimer1);
			iResumeTimer(setTimer2);
			iResumeTimer(setTimer3);
			iResumeTimer(setTimer4);
			iResumeTimer(setTimer5);
			iResumeTimer(setTimer6);
		}
		else if(page==2) {
			shoot=true;
		     if( my<=382) {
			
			    Arrow_x=0;
		        Arrow_y=my+50;
		    }
		     else if(my>=382){
                Arrow_x=0;
		        Arrow_y=432;
	        }
		}
	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{   
		
		shoot=true;
		if( my<=382){
			
			Arrow_x1=0;
		   Arrow_y1=my+50;
		}
		else if(my>=382)
		{
          Arrow_x1=0;
		  Arrow_y1=432;
	    }
	}


	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iKeyboard(unsigned char key)
{
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	
	//place your codes for other keys here
}

void ShowGameOver(void){
	//if(page==3){
		iShowBMP(0,0,"GameOver.bmp");
		sprintf(sc,"Your score is %d", score);
		iSetColor(255,0,0);
		iText(465,116, sc,GLUT_BITMAP_TIMES_ROMAN_24);
	//}
}
void Shoot(void){
	//if(shoot==true /*&& Arrow_x<1025*/)
		Arrow_x+=5;
		Arrow_x1+=5;
	//if(Arrow_x>1024)shoot=false;
}

//Move
void MoveZubat(void){
	if(score < 15)level = 1;
	if (score > 15 && score <=30) level = 2;
	if (score >30) level = 3;

	if(Zubat_y<470)Zubat_y+=level;
	else Zubat_y=0;
}


void MoveWoobat(){
	if(score < 15)level = 1;
	if (score > 15 && score <=30) level = 2;
	if (score >30) level = 3;

	if(Woobat_y<470)Woobat_y+=level;
	else Woobat_y=0;

}

void MovePelipper(void){
	if(score < 15)level = 1;
	if (score > 15 && score <=30) level = 2;
	if (score >30) level = 3;
	
	if(Pelipper_y<470)Pelipper_y+=level;
	else Pelipper_y=0;
}

//Hit

bool HitZubat(void){
	if((Arrow_x+128>=Zubat_x && Arrow_x<Zubat_x && Arrow_y>Zubat_y && Arrow_y+16 <=Zubat_y+128) || (Arrow_x1+128>=Zubat_x && Arrow_x1<Zubat_x && Arrow_y1>Zubat_y && Arrow_y1+16 <=Zubat_y+128)){
		score+=2;
		
		return true;
	}
	return false;
}

bool HitWoobat(void){
	if((Arrow_x+128>=Woobat_x && Arrow_x<Woobat_x && Arrow_y>Woobat_y && Arrow_y+16 <=Woobat_y+128) || (Arrow_x1+128>=Woobat_x && Arrow_x1<Woobat_x && Arrow_y1>Woobat_y && Arrow_y1+16 <=Woobat_y+128)){
		score+=3;
		
		return true;
	}
	 return false;
}

bool HitPelipper(void)  {
	if((Arrow_x+128>=Pelipper_x && Arrow_x<Pelipper_x && Arrow_y>Pelipper_y && Arrow_y+16 <=Pelipper_y+128) || (Arrow_x1+128>=Pelipper_x && Arrow_x1<Pelipper_x && Arrow_y1>Pelipper_y && Arrow_y1+16 <=Pelipper_y+128)){
		score++;
		
		return true;
	}
	return false;
}

//Reset

void ResetZubat(void){
	Zubat_y=0;
}

void ResetWoobat(void){
	Woobat_y=0;
}

void ResetPelipper(void){
	Pelipper_y=0;
}


void Timer(void){
	if(page==2){
	if(T>0)T--;
	if(T==0)page=3;
	}
}
void ShowScore(void){
	if(page==2) {
	sprintf(sc, "Score: %d", score);
	iSetColor(255,0,0);
	iText(500,500, sc); }
}
void ShowTime(void){
	if(page==2) {
	sprintf(tm, "Time Remaining %d s", T);
	iSetColor(255,0,0);
	iText(475,475,tm);}
}
void ShowLevel(void){

	sprintf(lvl, "Level : %d ", level);
	iSetColor(255,0,0);
	iText(500,450,lvl);
}

void Poof(){
		iShowBMP(Zubat_x,Zubat_y,"Poof.bmp");

}

int main()
{
	PlaySound("Sound.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
	setTimer1=iSetTimer(1000,Poof);
	setTimer2=iSetTimer(10,Shoot);
	setTimer3=iSetTimer(15,MoveZubat);
	setTimer4=iSetTimer(15,MoveWoobat);
	setTimer5=iSetTimer(15,MovePelipper);
	setTimer6=iSetTimer(1000,Timer);
	iInitialize(1024, 512, "Poke Shooter");
	return 0;
}	