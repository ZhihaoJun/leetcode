class Solution {
    public int divide(int dividend, int divisor) {
        int result = 0;
        while (dividend >= divisor && dividend > 0) {
            dividend -= divisor;
            result += 1;
        }
        return result;
    }
}

public class Test {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.divide(1, -1));
        System.out.println(s.divide(-1, -1));
        System.out.println(s.divide(-1, 1));
        System.out.println(s.divide(0, 0));
        System.out.println(s.divide(10, 2));
    }
}