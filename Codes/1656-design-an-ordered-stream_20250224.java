/*
 * @Author: LetMeFly
 * @Date: 2025-02-24 09:09:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-24 09:25:19
 */
import java.util.List;
import java.util.ArrayList;

class OrderedStream {
    private int n;
    private int ptr;
    private final String[] v;

    public OrderedStream(int n) {
        this.n = n;
        ptr = 1;
        v = new String[n + 1];
    }
    
    public List<String> insert(int idKey, String value) {
        v[idKey] = value;
        if (idKey != ptr) {
            return new ArrayList<>();
        }
        List<String> ans = new ArrayList<>();
        while (ptr <= n && v[ptr] != null) {
            ans.add(v[ptr]);
            ptr++;
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */