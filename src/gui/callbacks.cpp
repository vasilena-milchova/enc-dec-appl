#include "callbacks.h"
#include "utils.h"
#include "file_utils.h"
#include "xor_cipher.h"
#include "otp.h"
#include "keyless_cipher.h"
#include <FL/Fl_File_Chooser.H>

// ===== ENCRYPT CALLBACKS =====

/*
 * Opens a file chooser dialog to select the input file for encryption.
 * Updates the input file path in the EncryptWidgets structure.
 */
void browse_input_file_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::SINGLE, "Select Input File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->input_data->value(chooser.value());
    }
}

/*
 * Opens a file chooser dialog to select the key file for encryption.
 * Updates the key file path in the EncryptWidgets structure.
 */
void browse_key_file_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::SINGLE, "Select Key File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->key_data->value(chooser.value());
    }
}

/*
 * Opens a file chooser dialog to select or create the output file for encryption.
 * Updates the output file path in the EncryptWidgets structure.
 */
void browse_output_file_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::CREATE, "Save Output File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->output_file->value(chooser.value());
    }
}

void clear_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    w->input_data->value("");
    w->key_data->value("");
    w->shift_data->value("3");
    w->output_file->value("");
    w->output_display->value("");
}

void update_ui_enc(EncryptWidgets* w) {
    int cipher = w->cipher_choice->value();
    int input_type = w->input_type_choice->value();

    w->is_text_mode = (input_type == 1);
    w->cipher_type = cipher;

    const char* cipher_names[] = {"XOR Cipher", "One-Time Pad", "Caesar Cipher"};
    const char* input_mode = w->is_text_mode ? "text" : "file";

    std::string header = std::string("Using ") + cipher_names[cipher] + " on " + input_mode;
    w->header_label->label(strdup(header.c_str()));
    w->header_label->redraw();

    if (w->is_text_mode) {
        w->input_data->label("Input text:");
        w->browse_input_btn->hide();
        w->browse_output_btn->hide();
        w->output_display->show();
        w->output_label->show();
        w->output_file->hide();
    } else {
        w->input_data->label("Input file:");
        w->browse_input_btn->show();
        w->browse_output_btn->show();
        w->output_file->show();
        w->output_label->hide();
        w->output_display->hide();
    }

    if (cipher == 1) { // One-Time Pad
        w->key_label->hide();
        w->key_data->hide();
        w->browse_key_btn->hide();
        w->shift_label->hide();
        w->shift_data->hide();
    } else if (cipher == 2) { // Caesar Cipher
        w->key_label->hide();
        w->key_data->hide();
        w->browse_key_btn->hide();
        w->shift_label->show();
        w->shift_data->show();
    } else { // XOR Cipher
        w->key_label->show();
        w->key_data->show();

        if (w->is_text_mode) {
            w->key_label->label("Key text:");
            w->browse_key_btn->hide();
        } else {
            w->key_label->label("Key file:");
            w->browse_key_btn->show();
        }
    }

    w->window->redraw();
}

/*
 * Encryption cipher selection callback, triggers UI update.
 */
void cipher_choice_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    update_ui_enc(w);
}

/*
 * Encryption input type selection callback (text or file), triggers UI update.
 */
void input_type_choice_enc_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);
    update_ui_enc(w);
}

void encrypt_cb(Fl_Widget*, void* data) {
    EncryptWidgets* w = static_cast<EncryptWidgets*>(data);

    int choice = w->cipher_type;
    std::string input_data = w->input_data->value();
    std::string key_data = w->key_data->value();
    std::string shift_str = w->shift_data->value();
    std::string output_file = w->output_file->value();

    std::string plaintext;
    std::string key;

    if (w->is_text_mode) {
        plaintext = input_data;
        key = key_data;
    } else {
        if (!readFile(input_data, plaintext)) {
            show_message("Failed to read input file.");
            return;
        }
        if (choice == 0 && !readFile(key_data, key)) {
            show_message("Failed to read key file.");
            return;
        }
    }

    if (plaintext.empty()) {
        show_message("Please provide input data.");
        return;
    }

    // XOR cipher encryption
    if (choice == 0) {
        if (key.empty()) {
            show_message("Please provide a key.");
            return;
        }
        if (key.size() > plaintext.size()) {
            show_message("For XOR, key must be shorter than the input.");
            return;
        }
        std::string encrypted = xorCipher(plaintext, key);
        std::string hex_encrypted = bytesToHex(encrypted);

        if (w->is_text_mode) {
            w->output_display->value(hex_encrypted.c_str());
            show_message("XOR encryption done!");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file.");
                return;
            }
            if (!writeFile(output_file, hex_encrypted)) {
                show_message("Failed to write output file.");
                return;
            }
            show_message("XOR encryption done!");
        }

    // One-Time Pad encryption
    } else if (choice == 1) {
        std::string generated_key;
        std::string encrypted = otpEncrypt(plaintext, generated_key);
        std::string hex_encrypted = bytesToHex(encrypted);
        std::string hex_key = bytesToHex(generated_key);

        if (w->is_text_mode) {
            std::string result = std::string("=== ENCRYPTED TEXT ===\n") + hex_encrypted +
                                  std::string("\n\n=== GENERATED KEY (save this!) ===\n") + hex_key;
            w->output_display->value(result.c_str());
            show_message("OTP encryption done!\nKey generated and displayed.");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file for encrypted data.");
                return;
            }
            if (!writeFile(output_file, hex_encrypted)) {
                show_message("Failed to write output file.");
                return;
            }

            std::string key_file = output_file + ".key";
            if (!writeFile(key_file, hex_key)) {
                show_message("Encrypted file saved, but failed to save key file.");
                return;
            }

            std::string msg = std::string("OTP encryption done!\n") +
                              std::string("Encrypted: ") + output_file +
                              std::string("\nKey saved: ") + key_file;
            w->output_display->value(msg.c_str());
            show_message(msg.c_str());
        }

    // Caesar cipher encryption
    } else if (choice == 2) {
        int shift;
        try {
            shift = std::stoi(shift_str);
        } catch (...) {
            show_message("Invalid shift value. Please enter a number.");
            return;
        }

        std::string encrypted = caesarCipher(plaintext, shift);

        if (w->is_text_mode) {
            w->output_display->value(encrypted.c_str());
            show_message("Caesar Cipher encryption done!");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file.");
                return;
            }
            if (!writeFile(output_file, encrypted)) {
                show_message("Failed to write output file.");
                return;
            }
            std::string msg = std::string("Output written to:\n") + output_file;
            w->output_display->value(msg.c_str());
            show_message("Caesar Cipher encryption done!");
        }

    } else {
        show_message("Invalid cipher selection.");
    }
}

// ===== DECRYPT CALLBACKS =====

/*
 * Opens file chooser dialog to select input file for decryption.
 */
void browse_input_file_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::SINGLE, "Select Input File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->input_data->value(chooser.value());
    }
}

/*
 * Opens file chooser dialog to select key file for decryption.
 */
void browse_key_file_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::SINGLE, "Select Key File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->key_data->value(chooser.value());
    }
}

/*
 * Opens file chooser dialog to select or create output file for decryption.
 */
void browse_output_file_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    Fl_File_Chooser chooser(".", "All files (*)", Fl_File_Chooser::CREATE, "Save Output File");
    chooser.show();
    while (chooser.shown()) {
        Fl::wait();
    }
    if (chooser.value()) {
        w->output_file->value(chooser.value());
    }
}

void clear_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    w->input_data->value("");
    w->key_data->value("");
    w->shift_data->value("3");
    w->output_file->value("");
    w->output_display->value("");
}

void update_ui_dec(DecryptWidgets* w) {
    int cipher = w->cipher_choice->value();
    int input_type = w->input_type_choice->value();

    w->is_text_mode = (input_type == 1);
    w->cipher_type = cipher;

    const char* cipher_names[] = {"XOR Cipher", "One-Time Pad", "Caesar Cipher"};
    const char* input_mode = w->is_text_mode ? "text" : "file";

    std::string header = std::string("Using ") + cipher_names[cipher] + " on " + input_mode;
    w->header_label->label(strdup(header.c_str()));
    w->header_label->redraw();

    if (w->is_text_mode) {
        w->input_data->label("Input text:");
        w->browse_input_btn->hide();
        w->browse_output_btn->hide();
        w->output_display->show();
        w->output_label->show();
        w->output_file->hide();
    } else {
        w->input_data->label("Input file:");
        w->browse_input_btn->show();
        w->browse_output_btn->show();
        w->output_file->show();
        w->output_label->hide();
        w->output_display->hide();
    }

    
    if (cipher == 1) { // One-Time Pad
        w->key_label->hide();
        w->key_data->hide();
        w->browse_key_btn->hide();
        w->shift_label->hide();
        w->shift_data->hide();
    } else if (cipher == 2) { // Caesar Cipher
        w->key_label->hide();
        w->key_data->hide();
        w->browse_key_btn->hide();
        w->shift_label->show();
        w->shift_data->show();
    } else { // XOR Cipher
        w->key_label->show();
        w->key_data->show();

        if (w->is_text_mode) {
            w->key_label->label("Key text:");
            w->browse_key_btn->hide();
        } else {
            w->key_label->label("Key file:");
            w->browse_key_btn->show();
        }
    }

    w->window->redraw();
}

/*
 * Decryption cipher selection callback, triggers UI update.
 */
void cipher_choice_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    update_ui_dec(w);
}

/*
 * Decryption input type selection callback (text or file), triggers UI update.
 */
void input_type_choice_dec_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);
    update_ui_dec(w);
}

void decrypt_cb(Fl_Widget*, void* data) {
    DecryptWidgets* w = static_cast<DecryptWidgets*>(data);

    int choice = w->cipher_type;
    std::string input_data = w->input_data->value();
    std::string key_data = w->key_data->value();
    std::string shift_str = w->shift_data->value();
    std::string output_file = w->output_file->value();

    std::string ciphertext;
    std::string key;

    if (w->is_text_mode) {
        ciphertext = input_data;
        key = key_data;
    } else {
        if (!readFile(input_data, ciphertext)) {
            show_message("Failed to read input file.");
            return;
        }
        if (choice == 0 && !readFile(key_data, key)) {
            show_message("Failed to read key file.");
            return;
        }
    }

    if (ciphertext.empty()) {
        show_message("Please provide input data.");
        return;
    }

    // XOR cipher decryption
    if (choice == 0) {
        if (key.empty()) {
            show_message("Please provide a key.");
            return;
        }
        std::string ct = w->is_text_mode ? hexToBytes(ciphertext) : ciphertext;
        std::string decrypted = xorCipher(ct, key);

        if (w->is_text_mode) {
            w->output_display->value(decrypted.c_str());
            show_message("XOR decryption done!");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file.");
                return;
            }
            if (!writeFile(output_file, decrypted)) {
                show_message("Failed to write output file.");
                return;
            }
            show_message("XOR decryption done!");
        }

    // One-Time Pad decryption
    } else if (choice == 1) {
        if (key.empty()) {
            show_message("Please provide a key.");
            return;
        }
        std::string ct = w->is_text_mode ? hexToBytes(ciphertext) : ciphertext;
        std::string k = w->is_text_mode ? hexToBytes(key) : key;
        std::string decrypted = otpDecrypt(ct, k);

        if (w->is_text_mode) {
            w->output_display->value(decrypted.c_str());
            show_message("OTP decryption done!");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file.");
                return;
            }
            if (!writeFile(output_file, decrypted)) {
                show_message("Failed to write output file.");
                return;
            }
            std::string msg = std::string("Output written to:\n") + output_file;
            w->output_display->value(msg.c_str());
            show_message("OTP decryption done!");
        }

    // Caesar cipher decryption
    } else if (choice == 2) {
        int shift;
        try {
            shift = std::stoi(shift_str);
        } catch (...) {
            show_message("Invalid shift value. Please enter a number.");
            return;
        }

        std::string decrypted = caesarDecipher(ciphertext, shift);

        if (w->is_text_mode) {
            w->output_display->value(decrypted.c_str());
            show_message("Caesar Cipher decryption done!");
        } else {
            if (output_file.empty()) {
                show_message("Please specify an output file.");
                return;
            }
            if (!writeFile(output_file, decrypted)) {
                show_message("Failed to write output file.");
                return;
            }
            std::string msg = std::string("Output written to:\n") + output_file;
            w->output_display->value(msg.c_str());
            show_message("Caesar Cipher decryption done!");
        }

    } else {
        show_message("Invalid cipher selection.");
    }
}
