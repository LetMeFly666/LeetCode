/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 23:28:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 23:31:40
 */
class MyType {
    enum Type1 {A, B, C}
    enum Type2 {H, W}

    Type1 type1;
    Type2 type2;

    public void print() {
        System.out.println(type1);
        System.out.println(type2);
    }
}

public class Main {
    public static void main(String args[]) {
        MyType myType = new MyType();
        myType.type1 = MyType.Type1.A;
        myType.type2 = MyType.Type2.W;    // 不能是myType必须是MyType
        myType.print();
    }
}