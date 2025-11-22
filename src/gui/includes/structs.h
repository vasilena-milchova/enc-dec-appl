#ifndef STRUCTS_H
#define STRUCTS_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Multiline_Output.H>

/**
 * @struct EncryptWidgets
 * @brief Holds pointers to all widgets used in the encryption UI.
 */
struct EncryptWidgets {
    Fl_Window* window;
    Fl_Choice* cipher_choice;
    Fl_Choice* input_type_choice;
    Fl_Input* input_data;
    Fl_Input* key_data;
    Fl_Input* shift_data;
    Fl_Input* output_file;
    Fl_Multiline_Output* output_display;
    Fl_Box* output_label;
    Fl_Button* encrypt_btn;
    Fl_Button* clear_btn;
    Fl_Button* browse_input_btn;
    Fl_Button* browse_key_btn;
    Fl_Button* browse_output_btn;
    Fl_Box* header_label;
    Fl_Box* key_label;
    Fl_Box* shift_label;
    bool is_text_mode;
    int cipher_type;
};

/**
 * @struct DecryptWidgets
 * @brief Holds pointers to all widgets used in the decryption UI.
 */
struct DecryptWidgets {
    Fl_Window* window;
    Fl_Choice* cipher_choice;
    Fl_Choice* input_type_choice;
    Fl_Input* input_data;
    Fl_Input* key_data;
    Fl_Input* shift_data;
    Fl_Input* output_file;
    Fl_Multiline_Output* output_display;
    Fl_Box* output_label;
    Fl_Button* decrypt_btn;
    Fl_Button* clear_btn;
    Fl_Button* browse_input_btn;
    Fl_Button* browse_key_btn;
    Fl_Button* browse_output_btn;
    Fl_Box* header_label;
    Fl_Box* key_label;
    Fl_Box* shift_label;
    bool is_text_mode;
    int cipher_type;
};

#endif
// STRUCTS_H