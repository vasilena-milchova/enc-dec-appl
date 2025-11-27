#include "gui.h"
#include "callbacks.h"
#include "structs.h"
#include "colors.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Output.H>

/**
 * Creates and shows the main GUI window.
 *
 * @param argc Argument count from main.
 * @param argv Argument vector from main.
 */

void createGUI(int argc, char** argv) {
    Fl_Window* window = new Fl_Window(1500, 560, "OtpXorKeyless - Encrypt & Decrypt");
    window->color(COLOR_BG);

    // ===== TOP HEADER =====
    Fl_Box* main_header = new Fl_Box(0, 0, 1500, 50, "🔐 OtpXorKeyless - Encryption & Decryption Tool");
    main_header->color(COLOR_PRIMARY_DARK);
    main_header->labelcolor(COLOR_PRIMARY_DARK);
    main_header->labelfont(FL_BOLD);
    main_header->labelsize(20);

    // ===== LEFT SIDE - ENCRYPTION =====
    
    // Section background
    Fl_Box* enc_bg = new Fl_Box(5, 55, 740, 495, "");
    enc_bg->color(FL_WHITE);
    enc_bg->box(FL_BORDER_BOX);

    // Title
    Fl_Box* title_enc = new Fl_Box(15, 65, 720, 35, "ENCRYPTION");
    title_enc->labelfont(FL_BOLD);
    title_enc->labelsize(18);
    title_enc->labelcolor(COLOR_PRIMARY);

    // Cipher choice
    Fl_Choice* cipher_choice_enc = new Fl_Choice(200, 110, 280, 30, "Cipher:");
    cipher_choice_enc->add("XOR Cipher|One-Time Pad|Caesar Cipher");
    cipher_choice_enc->value(0);
    cipher_choice_enc->labelsize(13);
    cipher_choice_enc->textsize(13);
    cipher_choice_enc->box(FL_FLAT_BOX);
    cipher_choice_enc->color(COLOR_BG);
    cipher_choice_enc->selection_color(COLOR_ACCENT);

    // Input type choice
    Fl_Choice* input_type_choice_enc = new Fl_Choice(200, 155, 280, 30, "Input:");
    input_type_choice_enc->add("File|Text");
    input_type_choice_enc->value(0);
    input_type_choice_enc->labelsize(13);
    input_type_choice_enc->textsize(13);
    input_type_choice_enc->box(FL_FLAT_BOX);
    input_type_choice_enc->color(COLOR_BG);
    input_type_choice_enc->selection_color(COLOR_ACCENT);

    // Header label
    Fl_Box* header_label_enc = new Fl_Box(15, 200, 720, 25, "Using XOR Cipher on file");
    header_label_enc->labelfont(FL_ITALIC);
    header_label_enc->labelsize(14);
    header_label_enc->labelcolor(0x666666FF);
    header_label_enc->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Input data field
    Fl_Input* input_data_enc = new Fl_Input(200, 240, 260, 32, "Input file:");
    input_data_enc->labelsize(13);
    input_data_enc->textsize(13);
    input_data_enc->box(FL_FLAT_BOX);
    input_data_enc->color(COLOR_BG);

    // Browse input button
    Fl_Button* browse_input_btn_enc = new Fl_Button(470, 240, 70, 32, "Browse");
    browse_input_btn_enc->labelsize(12);
    browse_input_btn_enc->color(COLOR_ACCENT);
    browse_input_btn_enc->labelcolor(COLOR_TEXT_LIGHT);

    // Key label
    Fl_Box* key_label_enc = new Fl_Box(140, 290, 60, 32, "Key file:");
    key_label_enc->labelsize(13);
    key_label_enc->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Key data field
    Fl_Input* key_data_enc = new Fl_Input(200, 290, 260, 32, "");
    key_data_enc->labelsize(13);
    key_data_enc->textsize(13);
    key_data_enc->box(FL_FLAT_BOX);
    key_data_enc->color(COLOR_BG);

    // Browse key button
    Fl_Button* browse_key_btn_enc = new Fl_Button(470, 290, 70, 32, "Browse");
    browse_key_btn_enc->labelsize(12);
    browse_key_btn_enc->color(COLOR_ACCENT);
    browse_key_btn_enc->labelcolor(COLOR_TEXT_LIGHT);

    // Shift label
    Fl_Box* shift_label_enc = new Fl_Box(140, 290, 60, 32, "Shift:");
    shift_label_enc->labelsize(13);
    shift_label_enc->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    shift_label_enc->hide();

    // Shift data field
    Fl_Input* shift_data_enc = new Fl_Input(200, 290, 260, 32, "");
    shift_data_enc->labelsize(13);
    shift_data_enc->textsize(13);
    shift_data_enc->box(FL_FLAT_BOX);
    shift_data_enc->color(COLOR_BG);
    shift_data_enc->value("3");
    shift_data_enc->hide();

    // Output file field
    Fl_Input* output_file_enc = new Fl_Input(200, 340, 260, 32, "Output file:");
    output_file_enc->labelsize(13);
    output_file_enc->textsize(13);
    output_file_enc->box(FL_FLAT_BOX);
    output_file_enc->color(COLOR_BG);

    // Browse output button
    Fl_Button* browse_output_btn_enc = new Fl_Button(470, 340, 70, 32, "Browse");
    browse_output_btn_enc->labelsize(12);
    browse_output_btn_enc->color(COLOR_ACCENT);
    browse_output_btn_enc->labelcolor(COLOR_TEXT_LIGHT);

    // Output label
    Fl_Box* output_label_enc = new Fl_Box(140, 340, 60, 32, "Output:");
    output_label_enc->labelsize(13);
    output_label_enc->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Output display
    Fl_Multiline_Output* output_display_enc = new Fl_Multiline_Output(200, 340, 340, 110, "");
    output_display_enc->labelsize(13);
    output_display_enc->textsize(11);
    output_display_enc->box(FL_FLAT_BOX);
    output_display_enc->color(COLOR_BG);
    output_display_enc->wrap();

    // Encrypt button
    Fl_Button* encrypt_btn = new Fl_Button(200, 465, 120, 40, "Encrypt");
    encrypt_btn->labelsize(14);
    encrypt_btn->labelfont(FL_BOLD);
    encrypt_btn->color(COLOR_PRIMARY);
    encrypt_btn->labelcolor(COLOR_TEXT_LIGHT);
    encrypt_btn->box(FL_FLAT_BOX);

    // Clear button (encryption)
    Fl_Button* clear_enc_btn = new Fl_Button(330, 465, 100, 40, "Clear");
    clear_enc_btn->labelsize(14);
    clear_enc_btn->labelfont(FL_BOLD);
    clear_enc_btn->color(0x9E9E9EFF);
    clear_enc_btn->labelcolor(COLOR_TEXT_LIGHT);
    clear_enc_btn->box(FL_FLAT_BOX);

    // Bundle encryption widgets
    EncryptWidgets* enc_widgets = new EncryptWidgets{
        window, cipher_choice_enc, input_type_choice_enc, 
        input_data_enc, key_data_enc, shift_data_enc, output_file_enc, 
        output_display_enc, output_label_enc,
        encrypt_btn, clear_enc_btn, browse_input_btn_enc, browse_key_btn_enc, browse_output_btn_enc,
        header_label_enc, key_label_enc, shift_label_enc, false, 0
    };

    cipher_choice_enc->callback(cipher_choice_enc_cb, enc_widgets);
    input_type_choice_enc->callback(input_type_choice_enc_cb, enc_widgets);
    encrypt_btn->callback(encrypt_cb, enc_widgets);
    clear_enc_btn->callback(clear_enc_cb, enc_widgets);
    browse_input_btn_enc->callback(browse_input_file_enc_cb, enc_widgets);
    browse_key_btn_enc->callback(browse_key_file_enc_cb, enc_widgets);
    browse_output_btn_enc->callback(browse_output_file_enc_cb, enc_widgets);

    // ===== RIGHT SIDE - DECRYPTION =====
    
    int offset = 755;

    // Section background
    Fl_Box* dec_bg = new Fl_Box(5 + offset, 55, 740, 495, "");
    dec_bg->color(FL_WHITE);
    dec_bg->box(FL_BORDER_BOX);

    // Title
    Fl_Box* title_dec = new Fl_Box(15 + offset, 65, 720, 35, "DECRYPTION");
    title_dec->labelfont(FL_BOLD);
    title_dec->labelsize(18);
    title_dec->labelcolor(COLOR_PRIMARY);

    // Cipher choice
    Fl_Choice* cipher_choice_dec = new Fl_Choice(200 + offset, 110, 280, 30, "Cipher:");
    cipher_choice_dec->add("XOR Cipher|One-Time Pad|Caesar Cipher");
    cipher_choice_dec->value(0);
    cipher_choice_dec->labelsize(13);
    cipher_choice_dec->textsize(13);
    cipher_choice_dec->box(FL_FLAT_BOX);
    cipher_choice_dec->selection_color(COLOR_ACCENT);

    // Input type choice
    Fl_Choice* input_type_choice_dec = new Fl_Choice(200 + offset, 155, 280, 30, "Input:");
    input_type_choice_dec->add("File|Text");
    input_type_choice_dec->value(0);
    input_type_choice_dec->labelsize(13);
    input_type_choice_dec->textsize(13);
    input_type_choice_dec->box(FL_FLAT_BOX);
    input_type_choice_dec->selection_color(COLOR_ACCENT);

    // Header label
    Fl_Box* header_label_dec = new Fl_Box(15 + offset, 200, 720, 25, "Using XOR Cipher on file");
    header_label_dec->labelfont(FL_ITALIC);
    header_label_dec->labelsize(14);
    header_label_dec->labelcolor(0x666666FF);
    header_label_dec->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Input data field
    Fl_Input* input_data_dec = new Fl_Input(200 + offset, 240, 260, 32, "Input file:");
    input_data_dec->labelsize(13);
    input_data_dec->textsize(13);
    input_data_dec->box(FL_FLAT_BOX);
    input_data_dec->color(COLOR_BG);

    // Browse input button
    Fl_Button* browse_input_btn_dec = new Fl_Button(470 + offset, 240, 70, 32, "Browse");
    browse_input_btn_dec->labelsize(12);
    browse_input_btn_dec->color(COLOR_ACCENT);
    browse_input_btn_dec->labelcolor(COLOR_TEXT_LIGHT);

    // Key label
    Fl_Box* key_label_dec = new Fl_Box(140 + offset, 290, 60, 32, "Key file:");
    key_label_dec->labelsize(13);
    key_label_dec->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Key data field
    Fl_Input* key_data_dec = new Fl_Input(200 + offset, 290, 260, 32, "");
    key_data_dec->labelsize(13);
    key_data_dec->textsize(13);
    key_data_dec->box(FL_FLAT_BOX);
    key_data_dec->color(COLOR_BG);

    // Browse key button
    Fl_Button* browse_key_btn_dec = new Fl_Button(470 + offset, 290, 70, 32, "Browse");
    browse_key_btn_dec->labelsize(12);
    browse_key_btn_dec->color(COLOR_ACCENT);
    browse_key_btn_dec->labelcolor(COLOR_TEXT_LIGHT);

    // Shift label
    Fl_Box* shift_label_dec = new Fl_Box(140 + offset, 290, 60, 32, "Shift:");
    shift_label_dec->labelsize(13);
    shift_label_dec->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    shift_label_dec->hide();

    // Shift data field
    Fl_Input* shift_data_dec = new Fl_Input(200 + offset, 290, 260, 32, "");
    shift_data_dec->labelsize(13);
    shift_data_dec->textsize(13);
    shift_data_dec->box(FL_FLAT_BOX);
    shift_data_dec->color(COLOR_BG);
    shift_data_dec->value("3");
    shift_data_dec->hide();

    // Output file field
    Fl_Input* output_file_dec = new Fl_Input(200 + offset, 340, 260, 32, "Output file:");
    output_file_dec->labelsize(13);
    output_file_dec->textsize(13);
    output_file_dec->box(FL_FLAT_BOX);
    output_file_dec->color(COLOR_BG);

    // Browse output button
    Fl_Button* browse_output_btn_dec = new Fl_Button(470 + offset, 340, 70, 32, "Browse");
    browse_output_btn_dec->labelsize(12);
    browse_output_btn_dec->color(COLOR_ACCENT);
    browse_output_btn_dec->labelcolor(COLOR_TEXT_LIGHT);

    // Output label
    Fl_Box* output_label_dec = new Fl_Box(140 + offset, 340, 60, 32, "Output:");
    output_label_dec->labelsize(13);
    output_label_dec->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    // Output display
    Fl_Multiline_Output* output_display_dec = new Fl_Multiline_Output(200 + offset, 340, 340, 110, "");
    output_display_dec->labelsize(13);
    output_display_dec->textsize(11);
    output_display_dec->box(FL_FLAT_BOX);
    output_display_dec->color(COLOR_BG);
    output_display_dec->wrap();

    // Decrypt button
    Fl_Button* decrypt_btn = new Fl_Button(200 + offset, 465, 120, 40, "Decrypt");
    decrypt_btn->labelsize(14);
    decrypt_btn->labelfont(FL_BOLD);
    decrypt_btn->color(COLOR_PRIMARY);
    decrypt_btn->labelcolor(COLOR_TEXT_LIGHT);
    decrypt_btn->box(FL_FLAT_BOX);

    // Clear button (decryption)
    Fl_Button* clear_dec_btn = new Fl_Button(330 + offset, 465, 100, 40, "Clear");
    clear_dec_btn->labelsize(14);
    clear_dec_btn->labelfont(FL_BOLD);
    clear_dec_btn->color(0x9E9E9EFF);
    clear_dec_btn->labelcolor(COLOR_TEXT_LIGHT);
    clear_dec_btn->box(FL_FLAT_BOX);

    // Bundle decryption widgets
    DecryptWidgets* dec_widgets = new DecryptWidgets{
        window, cipher_choice_dec, input_type_choice_dec, 
        input_data_dec, key_data_dec, shift_data_dec, output_file_dec, 
        output_display_dec, output_label_dec,
        decrypt_btn, clear_dec_btn, browse_input_btn_dec, browse_key_btn_dec, browse_output_btn_dec,
        header_label_dec, key_label_dec, shift_label_dec, false, 0
    };

    cipher_choice_dec->callback(cipher_choice_dec_cb, dec_widgets);
    input_type_choice_dec->callback(input_type_choice_dec_cb, dec_widgets);
    decrypt_btn->callback(decrypt_cb, dec_widgets);
    clear_dec_btn->callback(clear_dec_cb, dec_widgets);
    browse_input_btn_dec->callback(browse_input_file_dec_cb, dec_widgets);
    browse_key_btn_dec->callback(browse_key_file_dec_cb, dec_widgets);
    browse_output_btn_dec->callback(browse_output_file_dec_cb, dec_widgets);

    window->end();
    window->show(argc, argv);
    
    // Initialize UI elements based on default settings
    update_ui_enc(enc_widgets);
    update_ui_dec(dec_widgets);
}
