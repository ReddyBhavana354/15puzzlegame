#include<iostream>
using namespace std;
#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<Fl/Fl_Button.H>
char *int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;}
 class MyButton : public Fl_Button {
	int id[4][4];
	
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
 };

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	count =0;
}
int MyButton :: handle (int e) {
	if (e==FL_PUSH){
	count++;
	label(int2charstar(count));
	}
	return 1;
};
int main(int argc,char *argv[]){
int i;
int id[4][4];
  Fl_Window *window;
  Fl_Button *button[16];
  window = new Fl_Window(600,600,"DEMO");
  for(i=0;i<15;i++){
  button[i] = new Fl_Button(100+((i%4)*100),100+((i/4)*100),100,100,int2charstar((i+1)%16));
  id[i%4][i/4]=int2charstar((i+1)%16));
  }
  button[15]=new Fl_Button(400,400,100,100,"   ");
  id[4][4]=0;
  window->end();
  window->show();
  int s=Fl::run();
  cout<<"exiting...\n";
  return s;
  }
