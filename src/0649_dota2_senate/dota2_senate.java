
class Solution {
    public String predictPartyVictory(String senateStr) {
        // R = true表示本轮循环结束后，字符串里依然有R。D同理
        Boolean R = true, D = true;
        // 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
        int flag = 0;
        byte[] senate =  senateStr.getBytes();
        while (R && D) { // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
            R = false;
            D = false;
            for (int i = 0; i < senate.length; i++) {
                if (senate[i] == 'R') {
                    if (flag < 0) senate[i] = 0; // 消灭R，R此时为false
                    else R = true; // 如果没被消灭，本轮循环结束有R
                    flag++;
                }
                if (senate[i] == 'D') {
                    if (flag > 0) senate[i] = 0;
                    else D = true;
                    flag--;
                }
            }
        }
        // 循环结束之后，R和D只能有一个为true
        return R == true ? "Radiant" : "Dire";
    }

    public static void  main(String[] args) {
        Solution solution = new Solution();
        String result = solution.predictPartyVictory("DRRDRDRDRDDRDRDR");
        if(result.equals("Radiant")) {
            System.out.println("PASSED");
        }else {
            System.out.println("FAILED");
        }
    }
}
