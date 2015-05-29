#include "SimonSays.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <gtkmm/main.h>
#include <glibmm.h>

SimonSays::SimonSays()
{
	srand(time(NULL));

	set_title("Simon Says");
	
	add(box);
	box.show();

	box.pack_start(row);
	for (int i = 0; i < 4; ++i)
	{
		row.pack_start(buttons[i]);
		row.show();
		buttons[i].def.set("Buttons_Green/Button_Unclicked.png");
		buttons[i].clk.set("Buttons_Green/Button_Clicked.png");
		buttons[i].set_image(buttons[i].clk);
	}

	box.pack_start(start);
	start.set_label("start");
	start.show();
	start.signal_clicked().connect( sigc::mem_fun(*this,
		&SimonSays::start_clicked) );



}

SimonSays::~SimonSays()
{

}

void SimonSays::start_clicked()
{
	for (int i = 0; i < 4; ++i)
	{
		buttons[i].show();
	}
	start.hide();

	startRound();
}

void SimonSays::simonSays()
{

	//iterate through every item in the list
	for (std::list<int>::iterator i = seq.begin(); i != seq.end(); ++i)
	{
		//print on terminal
		//std::cout << *i << " ";
		
		//set image to "clicked"
		buttons[*i].set_image(buttons[*i].clk);

		while( Gtk::Main::events_pending())
		{
			Gtk::Main::iteration();			
		}
		//wait for 5 seconds
		Glib::usleep(5000000);

		//set image to "unclicked/normal"
		buttons[*i].set_image(buttons[*i].def);

		
	}
}

void SimonSays::startRound()
{
	state = ROUNDSTATE;
	for (int i = 0; i < 4; ++i)
	{
		seq.push_back(i);
	}
	simonSays();
}