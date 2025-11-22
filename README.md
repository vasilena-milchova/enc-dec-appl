# 🔐 OtpXorKeyless - Encryption & Decryption Tool

C++ GUI application for file and text encryption/decryption using multiple cipher algorithms. Built with FLTK framework.
## Features

✨ **Three Encryption Algorithms:**
- **XOR Cipher** - Fast symmetric encryption with custom keys
- **One-Time Pad (OTP)** - Theoretically unbreakable encryption with auto-generated random keys
- **Caesar Cipher** - Classic shift cipher with customizable shift values

🎨 **GUI:**
- Green color scheme with intuitive interface
- Split-view design: Encryption on left, Decryption on right
- Real-time UI updates based on cipher and mode selection

📁 **Dual Input Modes:**
- **File Mode** - Encrypt/decrypt entire files with browse dialogs
- **Text Mode** - Quick encryption of text to hex

## System Requirements

- **OS:** Windows 10 or later
- **Compiler:** MinGW-w64 (g++ 14.2.0 or later)
- **Dependencies:** FLTK 1.4.4

## Installation

### 1. Install MinGW-w64

Download from: [https://www.msys2.org/](https://www.msys2.org/)

After installation, install required packages:
```bash
pacman -S mingw-w64-ucrt64-gcc
```

### 2. Install FLTK

Download FLTK 1.4.4 from: [https://www.fltk.org/](https://www.fltk.org/)

Extract to dir and build:
For example: `D:\fltk-1.4.4` 
```bash
cd D:\fltk-1.4.4
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

### 3. Clone/Download OtpXorKeyless

```bash
git clone https://github.com/vasilena-milchova/enc-dec-appl.git
cd OtpXorKeyless
```

## Building the Project

### Quick Build (Windows Command Prompt)

Simply run the batch script:
```bash
.\build.bat
```

This will:
1. Compile all source files
2. Link with FLTK libraries
3. Generate `OtpXorKeyless.exe` in the project directory
4. Display build status

The executable will be created as: `OtpXorKeyless.exe`

### Running the Application

```bash
OtpXorKeyless.exe
```

Or double-click `OtpXorKeyless.exe` in Windows Explorer.

### Troubleshooting Build Issues

**Issue**: Build fails with "g++ not found"
- **Solution**: Add MinGW to PATH
  - Open Environment Variables (Windows + X → System → Advanced system settings)
  - Click Environment Variables
  - Add: `C:\msys64\ucrt64\bin` to PATH
  - Restart command prompt and try again

**Issue**: "fltk/Fl.H: No such file or directory"
- **Solution**: Verify FLTK path
  - Check FLTK is installed at `D:\fltk-1.4.4`
  - If different location, edit build.bat line 4: `-I D:\your\fltk\path`
  - Save and run build.bat again

**Issue**: Linker errors about undefined references
- **Solution**: Verify FLTK build directory
  - Ensure `D:\fltk-1.4.4\build\lib` exists
  - Check it contains `libfltk.a`
  - If not, rebuild FLTK following Installation step 2

**Issue**: Build completes but no exe generated
- **Solution**: Check for compilation errors in output
  - Look for error messages (red text)
  - Most common: Missing header files or wrong includes
  - Verify all source files listed in build.bat exist

## Usage

### Starting the Application

Double-click `OtpXorKeyless.exe` or run from command prompt:
```bash
OtpXorKeyless.exe
```

### Encryption Workflow

#### File Mode
1. Select **Cipher**: XOR, One-Time Pad, or Caesar
2. Set **Input**: File (click Browse)
3. Set **Key/Shift**: 
   - XOR: Browse for key file
   - OTP: Automatically generated
   - Caesar: Enter shift value (default: 3)
4. Set **Output**: File location (click Browse)
5. Click **Encrypt**

#### Text Mode
1. Select **Cipher**: XOR, One-Time Pad, or Caesar
2. Switch to **Text** input mode
3. Paste/type input in the text field
4. Enter **Key/Shift** value
5. Click **Encrypt**
6. Result appears in output box (hex format for XOR/OTP)

### Decryption Workflow

Same as encryption but on the **right side** of the interface:

1. Select the same cipher and mode
2. Paste encrypted data
3. Provide the key/shift used for encryption
4. Click **Decrypt**
5. Result appears in output box

## File Format

### OTP Mode
When encrypting with OTP:
- **File Mode**: Generates `.key` file automatically (e.g., `output.key`)
- **Text Mode**: Shows key in output display 
- **Key Format**: Hexadecimal string

### Output Formats
- **XOR/OTP (Text Mode)**: Hexadecimal encoded
- **XOR/OTP (File Mode)**: Hexadecimal encoded
- **Caesar (Both Modes)**: Raw text output

## Project Structure

```
OtpXorKeyless/
├── build.bat                    # Windows build script
├── README.md                    # This file
|── LICENSE                      # License file
├── main.cpp                     # Application entry point
│
│
├── src/
│   ├── otp.h / otp.cpp         # One-Time Pad implementation
│   ├── xor_cipher.h / xor_cipher.cpp   # XOR cipher
│   ├── keyless_cipher.h / keyless_cipher.cpp   # Caesar cipher
│   ├── file_utils.h / file_utils.cpp   # File I/O utilities
│   │
│   └── gui/
│       ├── gui.cpp             # GUI window creation
│       ├── utils.cpp           # Hex conversion utilities
│       ├── callbacks.cpp       # Event callbacks
│       │
│       └── includes/
│           ├── gui.h           # GUI interface
│           ├── callbacks.h     # Callback declarations
│           ├── structs.h       # Widget structures
│           ├── colors.h        # Color scheme
│           └── utils.h         # Utility functions
│
└── OtpXorKeyless.exe           # Compiled executable (after build)
```

## Algorithm Details

### XOR Cipher
- **Type**: Symmetric encryption
- **Key**: Must be shorter than input (repeated if needed)
- **Security**: Moderate (vulnerable to frequency analysis)
- **Speed**: Very fast
- **Use Case**: Not for sensitive data

### One-Time Pad (OTP)
- **Type**: Symmetric encryption (theoretically unbreakable)
- **Key**: Auto-generated random bytes, same length as message
- **Security**: Perfect secrecy (if key is truly random and used once)
- **Speed**: Fast
- **Use Case**: Maximum security when key distribution is possible

### Caesar Cipher
- **Type**: Symmetric substitution cipher
- **Shift**: Integer value (default: 3)
- **Security**: Very weak (easily cracked)
- **Speed**: Very fast
- **Use Case**: Educational purposes only

## Example Workflows

### Encrypt a File with OTP

1. Open `OtpXorKeyless.exe`
2. Left side (Encryption):
   - Cipher: One-Time Pad
   - Input: File (browse to myfile.txt)
   - Output: myfile.encrypted
3. Click Encrypt
4. Result: myfile.encrypted + myfile.encrypted.key generated
5. Send encrypted file, securely share the .key file

### Decrypt with OTP

1. Right side (Decryption):
   - Cipher: One-Time Pad
   - Input: File (browse to myfile.encrypted)
   - Key: File (browse to myfile.encrypted.key)
   - Output: myfile.decrypted
2. Click Decrypt
3. Result: Original file recovered

### Quick Text Encryption with Caesar

1. Left side (Encryption):
   - Cipher: Caesar Cipher
   - Input: Text
   - Text: "Hello World"
   - Shift: 5
2. Click Encrypt
3. Result: "Mjqqt Btwqi" appears in output box

## Performance

| Cipher | Speed | Security | File Size |
|--------|-------|----------|-----------|
| XOR | Very Fast | Low | Same |
| OTP | Fast | Perfect | Same |
| Caesar | Very Fast | None | Same |

## Color Scheme

| Element | Color | Hex Code |
|---------|-------|----------|
| Primary | Green | `#4CAF50` |
| Dark Green | Dark | `#2E7D32` |
| Accent | Light Green | `#81C784` |
| Background | Very Light Green | `#F1F8E9` |
| Text | Dark Green | `#1B5E20` |
| Text Light | White | `#FFFFFF` |

## Keyboard Shortcuts

| Action | Shortcut |
|--------|----------|
| Encrypt | Click Encrypt button |
| Decrypt | Click Decrypt button |
| Clear Fields | Click Clear button |
| Browse File | Click Browse button |

## Known Limitations

- Maximum file size: Limited by system RAM
- XOR requires key to be shorter than plaintext
- OTP generates large key files (same size as plaintext)
- Caesar cipher only works with ASCII text

## Tips & Best Practices

### For Security:
1. **OTP is best** for maximum security
2. **Use long random keys** for XOR
3. **Never reuse OTP keys** - generate new ones each time
4. **Securely delete** key files after use
5. **Don't use Caesar** for sensitive data

### For Performance:
1. Use XOR for large files (fastest)
2. OTP generates keys on-the-fly (slower for large files)
3. Text mode is faster than file mode
4. Caesar is instant for any size

### For File Management:
1. Keep OTP `.key` files safe
2. Use descriptive filenames
3. Backup key files securely
4. Use different keys for different files

## Troubleshooting Runtime Issues

**Issue**: Application crashes on startup
- **Solution**: Verify FLTK libraries are present
  - Check `D:\fltk-1.4.4\build\lib\libfltk.a` exists
  - Ensure MinGW compiler matches FLTK build (both 64-bit)
  - Rebuild FLTK if needed

**Issue**: Encryption/Decryption fails
- **Solution**: Check input validation
  - Ensure file paths are correct
  - Verify file permissions
  - Check key format (hex for OTP)
  - Try with text mode first

**Issue**: Encrypted files can't be decrypted
- **Solution**: Verify matching cipher and key
  - Use same cipher for encrypt/decrypt
  - Double-check key file for OTP
  - Verify shift value for Caesar
  - Ensure file wasn't corrupted

**Issue**: Application window is too small
- **Solution**: Resize window or maximize
  - Drag window edges to resize
  - Double-click title bar to maximize
  - Adjust zoom if needed (Ctrl + Mouse Wheel)

## Contributing

Contributions are welcome! Please:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit changes (`git commit -m 'Add amazing feature'`)
4. Push to branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Disclaimer

⚠️ **Security Notice:**
- This tool is for **educational purposes**
- XOR and Caesar ciphers are **NOT secure** for sensitive data
- Use OTP with caution - key management is critical
- This software is provided AS-IS without warranty

## Changelog

### v1.0.0 (Current)
- ✨ Initial release
- 🎨 GUI with split-view design
- 📁 File and text mode support
- 🔐 Three encryption algorithms (XOR, OTP, Caesar)
- 🛠️ Batch build script for Windows
- 📦 Modular code structure with clear separation
- 🎯 Real-time UI updates
- 💾 Auto-generated key files for OTP

## Future Enhancements

- [ ] Support for additional ciphers (Vigenère, Blowfish, AES)
- [ ] Drag & drop file support
- [ ] File encryption progress bar
- [ ] Password-based key derivation (PBKDF2)
- [ ] Batch file processing
- [ ] Dark mode toggle
- [ ] Settings/preferences dialog
- [ ] Clipboard integration
- [ ] File hash verification
- [ ] Encryption history log

## Support

For issues, questions, or suggestions:

1. **Check existing issues** on GitHub
2. **Open a new issue** with:
   - Description of the problem
   - Steps to reproduce
   - Error messages (if any)
   - Your OS and compiler version
   - Relevant screenshots

3. **Documentation**: See README sections above

## FAQ

**Q: Can I encrypt large files?**
- A: Yes, but OTP generates keys the same size. XOR is fastest for large files.

**Q: Is OTP really unbreakable?**
- A: Theoretically yes, IF the key is truly random, used only once, and kept secret.

**Q: Can I use Caesar for real security?**
- A: No. Caesar cipher is trivial to crack. Use XOR or OTP instead.

**Q: Can I decrypt without the key?**
- A: XOR and OTP: No. Caesar: Yes, but it takes 25 attempts max.

**Q: What if I lose my OTP key?**
- A: Your encrypted file cannot be decrypted. Keep backups!

## Author

**Your Name**
- GitHub: [@Vasilena1](https://github.com/Vasilena1)
- Email: [vasilenamilchova@gmail.com](mailto:vasilenamilchova@example.com)

## Acknowledgments

- **FLTK Team** - Cross-platform GUI framework
- **MinGW-w64 Project** - Open-source compiler

## Additional Resources

- [Cryptography Basics](https://en.wikipedia.org/wiki/Cryptography)
- [One-Time Pad](https://en.wikipedia.org/wiki/One-time_pad)
- [XOR Cipher](https://en.wikipedia.org/wiki/XOR_cipher)
- [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher)
- [FLTK Documentation](https://www.fltk.org/doc-1.4/)

---

Last Updated: November 22, 2025

---

## Quick Reference Card

```
┌─────────────────────────────────────────────┐
│ OtpXorKeyless - Quick Reference             │
├─────────────────────────────────────────────┤
│ BUILD:     .\build.bat                      │
│ RUN:       OtpXorKeyless.exe                │
│                                             │
│ CIPHERS:   XOR | OTP | Caesar               │
│ MODES:     File | Text                      │
│                                             │
│ LEFT:      Encrypt                          │
│ RIGHT:     Decrypt                          │
│                                             │
│ OUTPUT: Hex (XOR/OTP) | Text (Caesar)       │
└─────────────────────────────────────────────┘
```

---

