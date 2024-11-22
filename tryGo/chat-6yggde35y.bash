###
 # @Author: LetMeFly
 # @Date: 2024-11-20 10:02:01
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2024-11-20 11:03:40
### 
你了解MinGW吗？

MinGW\x86_64-w64-mingw32\lib下有很多libxx.a，我添加一个libeasyx.a进去的话在编译的时候只需要加上个参数-leasyx就可以了。





如果我想把libeasyx.a放在MinGW\x86_64-w64-mingw32\lib\Let\这个字文件夹下，我应该如何编译





如果我把libeasyx.a放到MinGW\x86_64-w64-mingw32\lib\下的话，我只需要-leasyx就可以了
但是如果我把libeasyx.a放到MinGW\x86_64-w64-mingw32\lib\Let下的话，我就需要加上-L绝对路径才行`-LF:\OtherApps\Program\MinGW\x86_64-w64-mingw32\lib\Let`，而只加上`-LLet`就不行




链接库的问题解决了，可以编译运行demo了。
但编译另外一个文件时报错：
```
.\KongMingQi.cpp: In member function 'void PegSolitaire::drawBoard(int, int)':
.\KongMingQi.cpp:253:164: error: no matching function for call to 'settextstyle(int, int, const wchar_t [5], int, int, int, bool, bool, bool, int, int, int, int, int)'
     settextstyle(60, 0, L"微软alse, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
                                                                                                                                                                    ^
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note: candidate: 'void settextstyle(int, int, LPCTSTR)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note:   candidate expects 3 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note:   candidate expects 9 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool, BYTE, BYTE, BYTE, BYTE, BYTE)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note:   no known conversion for argument 3 from 'const wchar_t [5]' to 'LPCTSTR' {aka 'const char*'}
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note: candidate: 'void settextstyle(const LOGFONT*)'
 void settextstyle(const LOGFONT *font); // Set current text style
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note:   candidate expects 1 argument, 14 provided
.\KongMingQi.cpp: In function 'void DrawCircle(TCHAR*, int, int, int, double, int, int)':
.\KongMingQi.cpp:950:204: error: no matching function for call to 'settextstyle(int, int, const wchar_t [5], int, int, int, bool, bool, bool, int, int, int, int, int)'
   settextstyle(22, 0, L"微软ariable * 3600 / fors, variable * 3600 / fors, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
                                                                                                                                                                                                            ^
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note: candidate: 'void settextstyle(int, int, LPCTSTR)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note:   candidate expects 3 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note:   candidate expects 9 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool, BYTE, BYTE, BYTE, BYTE, BYTE)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note:   no known conversion for argument 3 from 'const wchar_t [5]' to 'LPCTSTR' {aka 'const char*'}
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note: candidate: 'void settextstyle(const LOGFONT*)'
 void settextstyle(const LOGFONT *font); // Set current text style
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note:   candidate expects 1 argument, 14 provided
.\KongMingQi.cpp: In function 'void MYCIRCLE(int, int)':
.\KongMingQi.cpp:1025:162: error: no matching function for call to 'settextstyle(int, int, const wchar_t [5], int, int, int, bool, bool, bool, int, int, int, int, int)'
   settextstyle(22, 0, L"微软alse, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
                                                                                                                                                                  ^
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note: candidate: 'void settextstyle(int, int, LPCTSTR)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:249:6: note:   candidate expects 3 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:250:6: note:   candidate expects 9 arguments, 14 provided
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note: candidate: 'void settextstyle(int, int, LPCTSTR, int, int, int, bool, bool, bool, BYTE, BYTE, BYTE, BYTE, BYTE)'
 void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:251:6: note:   no known conversion for argument 3 from 'const wchar_t [5]' to 'LPCTSTR' {aka 'const char*'}
In file included from F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/graphics.h:12,
                 from .\KongMingQi.cpp:10:
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note: candidate: 'void settextstyle(const LOGFONT*)'
 void settextstyle(const LOGFONT *font); // Set current text style
      ^~~~~~~~~~~~
F:/OtherApps/Program/MinGW/x86_64-w64-mingw32/include/Let/easyx.h:252:6: note:   candidate expects 1 argument, 14 provided
```





第1025行是`settextstyle(22, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);`
函数定义为`void settextstyle(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);`






我将所有的`L"微软雅黑"`修改为了`reinterpret_cast<LPCTSTR>("微软雅黑")`，编译运行成功了。
但是现实的中文会乱码，包括但不限于其他所有的中文。
我的cpp文件是以utf-8的格式保存的。