#include "SimonSays.h"

SimonSays::SimonSays()
{
	set_title("Simon Says");
	
	add(box);
	box.show();

	box.pack_start(row);
	for (int i = 0; i < 4; ++i)
	{
		row.pack_start(buttons[i]);
		row.show();
		buttons[i].set_label("b");
		buttons[i].show();
	}

	box.pack_start(start);
	start.set_label("start");
	start.show();

	
}

SimonSays::~SimonSays()
{

}