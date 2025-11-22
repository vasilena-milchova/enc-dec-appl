#include <FL/Fl.H>
#include "gui.h"
#include "callbacks.h"

/**
 * Main entry point of the OtpXorKeyless application.
 *
 * @param argc Argument count from the command line.
 * @param argv Argument vector from the command line.
 * @return Exit status code (0 on normal exit).
 */
int main(int argc, char** argv) {
    createGUI(argc, argv);
    
    return Fl::run();
}
