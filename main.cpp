#include <gtkmm/application.h>
#include <gtkmm/main.h>
#include "SimonSays.h"

int main(int argc, char *argv[])
{
	/*
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  	SimonSays game;

  	//Shows the window and returns when it is closed.
  	return app->run(game);
  	*/

  	Gtk::Main kit(argc, argv);

  	SimonSays game;

  	Gtk::Main::run(game);	

  	return 0;
}