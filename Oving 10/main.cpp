#include "MinesweeperWindow.h"
#include "OptionsWindow.h"

int main()
{
	Fl::background(200, 200, 200);

	Point startPoint{ 200,300 };
	OptionsWindow ow{startPoint.x, startPoint.y, 600, 400, "Options"};
	return gui_main();
}
