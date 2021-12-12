#include <iostream>
#include <ncurses/ncurses.h> //ncurses window mvprint dll
#include <windows.h> //untuk fungsi sleep
using namespace std;

/* ANGGOTA KELOMPOK

Nama = Rivaldo
NPM  = 2117051054

Nama = Muhammad Iqbal Widiansyah
NPM  =  2117051011

Nama = Vidya Sinta Billkis
NPM  = 2117051029

*/
void end(int score){
	//fungsi jika menabrak tembok mati
	clear();
	mvprintw(4,15,"Kamu menabrak tembok dan mati !!!");
	mvprintw(6,15,"KAMU KALAh ");
	mvprintw(8,15,"Total Jalanmu = ");
	score-=1;
	mvprintw(8,31,"%d",score);
}
void map(WINDOW *win);
void menu(){
	//untuk menampilkan menu di awal
	initscr();//menampilkan layar
	int x=8,y=8;
	bool pilih=true;//untuk perulangan
	WINDOW *win = newwin(20, 40, 1, 1);//window 
    refresh();
    box(win, 0, 0);//batas window
    mvwprintw(win, 3, 13, " Main Menu");
    mvwprintw(win, 5, 10, " Simple Maze game");
    
    mvwprintw(win, 8, 11, " 1. Bermain");
    mvwprintw(win, 9, 11, " 2. Keluar");
    
    mvwprintw(win, 11, 5, "Tekan Tombol P untuk memilih");
    mvwprintw(win, 14, 9, "Tombol W untuk naik");
    mvwprintw(win, 15, 9, "Tombol S untuk turun");
    wmove(win, y, x);//posisi merubah
	wprintw(win, "=>");
    wrefresh(win);//merefresh window
    
    while(pilih){
    	char movem = wgetch(win);
    	 if (movem=='p'){//untuk memilih
    	 	if(y==8){// y=8 maka lanjut bermain
		pilih=false;}
		 if(y==9){
			exit (0);//jika y=2 / keluar maka exit
		}
	}
    if(movem=='w' ){
				if(y == 8){//untuk pembatas
					y = 8;
				}else{
					y--;//untuk naik
				}}
	else if(movem=='s' ){
				if(y == 9){//pembatas bawah
					y = 9;
				}else{
					y++;//untuk turun
				}}
	
	wclear(win);//membersihkan window
		box(win, 0, 0);
		mvwprintw(win, 3, 13, " Main Menu");
    mvwprintw(win, 5, 10, " Simple Maze game");
    
    mvwprintw(win, 8, 11, " 1. Bermain");
    mvwprintw(win, 9, 11, " 2. Keluar");
    
    mvwprintw(win, 11, 5, "Tekan Tombol P untuk memilih");
	wmove(win, y, x);
		wprintw(win, "=>");
		wrefresh(win);
		refresh();
}
//clear();
//getch();

}
void loading(){//fungsi loading
	initscr();
	int i=5,z=0;
	
	mvprintw(6,5, "-----------------");
	refresh();
	mvprintw(7,5, "|    LOADING    |");
	refresh();
	mvprintw(8,5, "-----------------");
	refresh();
	mvprintw(2,5,"SIMPLE GAME MAZE");
	refresh();
	
while(i<35){	
	mvprintw(11,i,"=");
	refresh();
	Sleep(30);	//fungsi sleep
	mvprintw(12,i++,"=");
	refresh();
	Sleep(30);
}
//clear();

mvprintw(15,5,"Game akan dimulai enjoyy ");
	refresh();
	Sleep(3000);
	
clear();//membersihkan layar
}
int main (){
	initscr();
	char nama[30];//untuk nama
	int x = 19, y = 1,i=0,o=0,score=0,name;
	char blok1[7]={7,11,13,14,15,21,26};
	char blok2[25]={0,1,2,3,5,7,9,11,15,17,18,19,21,22,23,24,26,28,29,30,32,33,35,36,37};//koordinat tembok untuk di search
	char blok3[11]={5,9,11,12,13,19,26,30,32,33,35};                                     // di bawah
	char blok4[18]={0,2,3,5,6,7,9,15,17,19,20,21,22,24,30,32,35,37};
	char blok5[24]={0,2,5,7,9,10,11,12,13,14,15,17,22,24,25,26,27,28,29,30,31,32,33,35};
	char blok6[17]={0,2,4,5,7,9,15,17,18,19,21,22,28,29,35,36,37};
	char blok7[20]={0,2,4,7,9,10,11,12,13,15,21,22,23,24,26,28,29,30,31,32};
	char blok8[18]={0,2,4,7,13,15,16,17,18,19,20,26,31,32,34,35,36,37};
	char blok9[24]={0,2,4,5,6,7,9,10,11,13,15,19,20,21,23,24,25,26,27,28,29,34,35,37};
	char blok10[19]={0,2,7,8,9,11,13,15,17,20,21,23,25,26,31,32,34,35,37};
	char blok11[21]={0,2,3,4,5,7,9,15,16,17,19,20,21,23,25,26,28,29,31,32,34};
	char blok12[21]={5,9,10,11,12,13,14,15,16,17,23,24,25,26,27,28,32,34,35,36,37};
	char blok13[18]={0,2,3,5,6,7,9,16,17,18,19,20,21,23,24,28,32,34};
	char blok14[18]={0,2,11,12,13,14,16,24,26,28,29,30,32,33,34,35,36,37};
	char blok15[21]={0,2,3,4,5,6,7,8,9,13,14,16,18,19,20,22,23,24,26,29,30};
	char blok16[15]={5,9,11,12,13,18,24,26,28,31,32,33,35,36,37};
	char blok17[19]={0,2,3,5,9,15,16,18,19,20,21,23,24,26,28,30,31,37};
	char blok18[14]={9,11,12,13,14,15,16,21,26,33,34,35,36,37};
	
   mvprintw(4,9, "-----------------------------");
   mvprintw(6,9, "-----------------------------");
   mvprintw(5,10,"Username = ");getstr(nama);//memasukan username
   
   clear();
    
	loading();//memasukan fungsi loading
	menu();//fungsi menu

	bool selesai = false;
	bool jalan=false;
	bool key=true;
	//initscr();
	mvprintw(3,53,"Jika menabrak tembok kamu akan mati");
	mvprintw(7,53,"Clue Lewati pojok kanan");
	mvprintw(9,53,"Tekan Tombol x untuk berhenti");
	mvprintw(10,53,"Capai F untuk Finish ");
	mvprintw(1,53,"USERNAME = ");
	mvprintw(1,65,nama);
		WINDOW * win = newwin(20, 40, 1, 1);//window
		refresh();
	box(win, 0, 0);
	map(win);    
	                   
		wmove(win, y, x);
	wprintw(win, "o");//karakter kita
	mvwprintw(win, 18, 38, "F");//tujuan =menang
	wrefresh(win);
		while(!selesai){
		char move = wgetch(win);
		
			if(move=='a' ){//jika ketik a 
				
				if(x == 1){//batas tembok agar tidak tembus
					x = 1;
				}else{
				x--;//maka ke kiri
				score=score+1;//menambah score= jalan 
				}}
			if(move=='d' ){
				if(x == 38){
					x = 38;
				}else{
					x++;//kanan
					score=score+1;
				}}
			if(move=='w' ){
				if(y == 1){
					y = 1;
				}else{
					y--;//atas
					score=score+1;
				}}
			if(move=='s' ){
				if(y == 18){
					y = 18;
				}else{
					y++;//bawah
					score=score+1;
				}}	
	 		if(move=='x'){//mengahiri program
                selesai = true;//mengentikan perulangan
                key=false;}//agar menonaktifkan getch dibawah
                
		mvprintw(16,53,"Total Jalanmu = ");
		mvprintw(16,69,"%d",score);//menampilkan score

		if(x==38&&y==18){//jika karakter di koordinat ini
			selesai=true;//maka selesai
			clear();
			mvprintw(5,15,"SELAMAT ANDA BERHASIL !!!");
		    mvprintw(8,15,"USERNAME    = ");
			mvprintw(9,15,"TOTAL JALAN = ");
			mvprintw(8,31,nama);
	     	mvprintw(9,31,"%d",score);
			
			
			mvprintw(14,15,"Terima kasih sudah bermain");
		}
		
		
		for(int o=0;o<=7;o++){if (x==blok1[o] && y==1){end(score)/* jika koordinat sesuai masuk fungsi end */;selesai = true;}}//searching koordinat tembok aray 
		for(int o=0;o<=25;o++){if (x==blok2[o] && y==2){end(score);selesai = true/* untuk menghentikan perulangan*/;}}		
		for(int o=0;o<=11;o++){if (x==blok3[o] && y==3){end(score);selesai = true;}}				
		for(int o=0;o<=18;o++){if (x==blok4[o] && y==4){end(score);selesai = true;}}
		for(int o=0;o<=24;o++){if (x==blok5[o] && y==5){end(score);selesai = true;}}
		for(int o=0;o<=17;o++){if (x==blok6[o] && y==6){end(score);selesai = true;}}
		for(int o=0;o<=20;o++){if (x==blok7[o] && y==7){end(score);selesai = true;}}
		for(int o=0;o<=18;o++){if (x==blok8[o] && y==8){end(score);selesai = true;}}
		for(int o=0;o<=24;o++){if (x==blok9[o] && y==9){end(score);selesai = true;}}
		for(int o=0;o<=19;o++){if (x==blok10[o] && y==10){end(score);selesai = true;}}
		for(int o=0;o<=21;o++){if (x==blok11[o] && y==11){end(score);selesai = true;}}
		for(int o=0;o<=21;o++){if (x==blok12[o] && y==12){end(score);selesai = true;}}
		for(int o=0;o<=18;o++){if (x==blok13[o] && y==13){end(score);selesai = true;}}
		for(int o=0;o<=19;o++){if (x==blok14[o] && y==14){end(score);selesai = true;}}
		for(int o=0;o<=21;o++){if (x==blok15[o] && y==15){end(score);selesai = true;}}
		for(int o=0;o<=15;o++){if (x==blok16[o] && y==16){end(score);selesai = true;}}
		for(int o=0;o<=19;o++){if (x==blok17[o] && y==17){end(score);selesai = true;}}
		for(int o=0;o<=14;o++){if (x==blok18[o] && y==18){end(score);selesai = true;}}
		

		wclear(win);
		box(win, 0, 0);
		map(win);
		if(x==38&&y==14){//jebakan iseng
			x = 35; y=7;	//karakter terlempar di koordinat ini
			mvwprintw(win, 14, 1," x        xxxx x       x x xxx xxxxxxx");
			mvprintw(14,53,"kamu Terjebak dan terlempar ");
		//	clear();
		}
		if(x==33&&y==15){
			x = 19; y=1;	// sama :)
			mvwprintw(win, 15, 1," xxxxxx x   xx x xxx xxx x  xx x      ");;
			mvprintw(15,53,"Back to home ");
		//	clear();
		}
		wmove(win, y, x);
		wprintw(win, "o");
		mvwprintw(win, 18, 38, "F");
		wrefresh(win);
		refresh();

	}	
	
	if(key){//menonaktifkan getch 
	
	getch(); }
	endwin();
}
                              
void map(WINDOW *win){        
	    mvwprintw(win, 1, 1, "      x   x xxx     x    x            ");//ini adalah map yg di pakai
		mvwprintw(win, 2, 1, "xxx x x x x   x xxx xxxx x xxx xx xxx ");
		mvwprintw(win, 3, 1, "    x   x xxx     x      x   x xx x   ");
		mvwprintw(win, 4, 1, " xx xxx x     x x xxxx x     x x  x x ");
		mvwprintw(win, 5, 1, " x  x x xxxxxxx x    x xxxxxxxxxx x   ");
		mvwprintw(win, 6, 1, " x xx x x     x xxx xx     xx     xxx ");
		mvwprintw(win, 7, 1, " x x  x xxxxx x     xxxx x xxxxx      ");
		mvwprintw(win, 8, 1, " x x  x     x xxxxxx     x    xx xxxx ");
		mvwprintw(win, 9, 1, " x xxxx xxx x x   xxx xxxxxxx    xx x ");
		mvwprintw(win, 10, 1," x    xxx x x x x  xx x xx    xx xx x ");
		mvwprintw(win, 11, 1," xxxx x x     xxx xxx x xx xx xx x    ");
		mvwprintw(win, 12, 1,"    x   xxxxxxxxx     xxxxxx   x xxxx ");
		mvwprintw(win, 13, 1," xx xxx x      xxxxxx xx   x   x x    ");
		mvwprintw(win, 14, 1," x        xxxx x       x x xxx xxxxxx ");
		mvwprintw(win, 15, 1," xxxxxxxx   xx x xxx xxx x  xx        ");
		mvwprintw(win, 16, 1,"    x   x xxx    x     x x x  xxx xxx ");
		mvwprintw(win, 17, 1," xx x   x     xx xxxx xx x x xx     x ");
		mvwprintw(win, 18, 1,"        x xxxxxx    x    x      xxxxx ");
}


