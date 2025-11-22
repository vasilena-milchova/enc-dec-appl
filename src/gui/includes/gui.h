#ifndef GUI_H
#define GUI_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

/**
 * @file gui.h
 * @brief Declares the function to create and initialize the main GUI window.
 *
 * This header provides the declaration for the createGUI function that sets up
 * the graphical user interface with the FLTK library.
 */

/**
 * Initializes and displays the GUI application window.
 * @param argc The argument count from the program entry point.
 * @param argv The argument vector from the program entry point.
 */
void createGUI(int argc, char** argv);

#endif // GUI_H
