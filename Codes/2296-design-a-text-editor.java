import java.lang.StringBuilder;

class TextEditor {
    private final StringBuilder left = new StringBuilder();
    private final StringBuilder right = new StringBuilder();

    private String text() {
        return left.substring(Math.max(0, left.length() - 10));
    }

    public TextEditor() {}
    
    public void addText(String text) {
        left.append(text);
    }
    
    public int deleteText(int k) {
        int ans = Math.min(left.length(), k);
        left.setLength(left.length() - ans);
        return ans;
    }
    
    public String cursorLeft(int k) {
        while (k-- > 0 && left.length() > 0) {
            right.append(left.charAt(left.length() - 1));
            left.setLength(left.length() - 1);
        }
        return text();
    }
    
    public String cursorRight(int k) {
        while (k-- > 0 && right.length() > 0) {
            left.append(right.charAt(right.length() - 1));
            right.setLength(right.length() - 1);
        }
        return text();
    }
}

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor obj = new TextEditor();
 * obj.addText(text);
 * int param_2 = obj.deleteText(k);
 * String param_3 = obj.cursorLeft(k);
 * String param_4 = obj.cursorRight(k);
 */