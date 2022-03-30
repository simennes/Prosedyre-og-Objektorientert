#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines},
	stateFeedback{0, cellSize*height, cellSize*3, cellSize,""},
	minesFeedback{cellSize*5 + 10, cellSize*height, cellSize, cellSize,"Mines left:"},
	quit{cellSize*(width/2)-3*cellSize, cellSize*(height/2)-cellSize, cellSize*3, cellSize*2,"QUIT"},
	restart{cellSize*(width/2), cellSize*(height/2)-cellSize, cellSize*3, cellSize*2,"RESTART"}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->callback(cb_click, this);
			add(tiles.back().get()); 
		}
	}

	for(int i = 0; i < mines; i++){
		while(1){
			int ind = randint(0, tiles.size() - 1);
			if(!tiles[ind]->getMine()){
				tiles[ind]->setMine(true);
				break;
			}
		}
	}

	add(stateFeedback);
	add(minesFeedback);
	minesFeedback.value(to_string(mines).c_str());
	

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	shared_ptr<Tile> currTile = at(xy);
	currTile->open();
	if(!currTile->getMine()){
		vector<Point> neighbours = adjacentPoints(xy);
		int closeMines = countMines(neighbours);
		if(closeMines > 0){
			currTile->setAdjMines(closeMines);
		}
		else{
			for(Point p: neighbours){
				if(at(p)->getState() == Cell::closed){
					openTile(p);
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	shared_ptr<Tile> currTile = at(xy);
	currTile->flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}

	int minesLeft = mines - countFlagged();
	minesFeedback.value(to_string(minesLeft).c_str());
	if(isLost()) {setLost();}
	else if(isWon()) {setWon();}
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mines = 0;
	for(Point p: coords){
		shared_ptr<Tile> currTile = at(p);
		if(currTile->getMine()){
			mines++;
		}
	}
	return mines;
}

bool MinesweeperWindow::isWon(){
	int opened = 0;
	for(shared_ptr<Tile> tile: tiles){
		if(tile->getState() == Cell::open){
			opened++;
		}
	}
	if(width*height-opened == mines){
		return true;
	}
	else{
		return false;
	}
}

bool MinesweeperWindow::isLost(){
	for(shared_ptr<Tile> tile: tiles){
		if(tile->getState() == Cell::open && tile->getMine()){
			return true;
		}
	}
	return false;
}


void MinesweeperWindow::setWon(){
	markWonLost(true);
	stateFeedback.value("You won!");
}
void MinesweeperWindow::setLost(){
	markWonLost(false);
	stateFeedback.value("You lost");
}

int MinesweeperWindow::countFlagged(){
	int nFlagged = 0;
	for(shared_ptr<Tile> t: tiles){
		if(t->getState() == Cell::flagged){
			nFlagged++;
		}
	}
	return nFlagged;
}

void MinesweeperWindow::markWonLost(bool w){
	for(shared_ptr<Tile> t: tiles){
		t->wonLost(w);
	}
	add(quit);
	add(restart);
	quit.show();
	restart.show();
	quit.callback(cb_quit, this);
	restart.callback(cb_restart, this);	
}

void MinesweeperWindow::resetGame(){
	for(shared_ptr<Tile> tile: tiles){
		tile->value(0);
		tile->resetTile();
	}
	for(int i = 0; i < mines; i++){
		while(1){
			int ind = randint(0, tiles.size());
			if(!tiles[ind]->getMine()){
				tiles[ind]->setMine(true);
				break;
			}
		}
	}
}

void MinesweeperWindow::cb_quit(Fl_Widget*, void* pw){
    static_cast<MinesweeperWindow*>(pw)->hide();
}


void MinesweeperWindow::cb_restart(Fl_Widget*, void* pw){
	MinesweeperWindow* msw = static_cast<MinesweeperWindow*>(pw);
	msw->resetGame();
	msw->quit.hide();
	msw->restart.hide();
	msw->minesFeedback.value(to_string(msw->mines).c_str());
	msw->stateFeedback.value("");
}