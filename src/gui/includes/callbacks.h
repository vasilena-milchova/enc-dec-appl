#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <FL/Fl_Widget.H>
#include "structs.h"

/**
 * @file callbacks.h
 * @brief Declarations of GUI callback functions for encryption and decryption operations.
 *
 * This header declares the callback handlers for file browsing, clearing inputs,
 * UI updating, cipher selection, and performing encryption and decryption.
 * Callbacks are split into encryption and decryption sections for clarity.
 */

// Encryption callbacks
void browse_input_file_enc_cb(Fl_Widget*, void* data);
void browse_key_file_enc_cb(Fl_Widget*, void* data);
void browse_output_file_enc_cb(Fl_Widget*, void* data);
void clear_enc_cb(Fl_Widget*, void* data);
void update_ui_enc(EncryptWidgets* w);
void cipher_choice_enc_cb(Fl_Widget*, void* data);
void input_type_choice_enc_cb(Fl_Widget*, void* data);
void encrypt_cb(Fl_Widget*, void* data);

// Decryption callbacks
void browse_input_file_dec_cb(Fl_Widget*, void* data);
void browse_key_file_dec_cb(Fl_Widget*, void* data);
void browse_output_file_dec_cb(Fl_Widget*, void* data);
void clear_dec_cb(Fl_Widget*, void* data);
void update_ui_dec(DecryptWidgets* w);
void cipher_choice_dec_cb(Fl_Widget*, void* data);
void input_type_choice_dec_cb(Fl_Widget*, void* data);
void decrypt_cb(Fl_Widget*, void* data);

#endif
