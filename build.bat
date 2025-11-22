g++ main.cpp src/otp.cpp src/xor_cipher.cpp src/keyless_cipher.cpp src/file_utils.cpp src/gui/gui.cpp src/gui/utils.cpp src/gui/callbacks.cpp -o OtpXorKeyless.exe ^
    -I D:\fltk-1.4.4 ^
    -I src\gui\includes ^
    -I src\ ^
    -L D:\fltk-1.4.4\build\lib ^
    -lfltk -lgdiplus -lws2_32 -lwinspool -lcomctl32 -lole32 -luuid -lcomdlg32 -loleaut32 -lgdi32
