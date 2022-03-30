#pragma once
#include "GUI.h"


// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public Fl_Button
{
	Cell state = Cell::closed;
	bool isMine = false;
	
	void set_label(string s) { this->copy_label(s.c_str());}
	void set_label_color(Color c) {this->labelcolor(c.as_int());}
public:
	Tile(Point pos, int size) 
		 :Fl_Button(pos.x, pos.y, size, size, "") {};

	bool getMine() const { return isMine;};
	void setMine(bool mineState) {isMine = mineState;};
	void open();
	void flag();
	void setAdjMines(int n);
	void wonLost(bool w);
	void resetTile();

	Cell getState() const { return state; };

};
