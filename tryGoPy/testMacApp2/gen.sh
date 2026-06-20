###
 # @Author: LetMeFly
 # @Date: 2026-06-20 19:18:30
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-06-20 19:36:43
### 
mkdir -p Hello.app/Contents/MacOS

cat > main.cpp << 'EOF'
#include <cstdlib>

int main() {
    system("osascript -e 'tell application \"Terminal\" to activate'");
    system("osascript -e 'tell application \"Terminal\" to do script \"echo Hello from C++ App; read\"'");
    return 0;
}
EOF

clang++ main.cpp -o Hello.app/Contents/MacOS/Hello
chmod +x Hello.app/Contents/MacOS/Hello

cat > Hello.app/Contents/Info.plist << 'EOF'
<?xml version="1.0" encoding="UTF-8"?>
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>Hello</string>

    <key>CFBundleIdentifier</key>
    <string>xyz.letmefly.example.simpleapp.hello</string>

    <key>CFBundleName</key>
    <string>Let's Hello</string>
</dict>
</plist>
EOF
