import java.util.List;
import java.util.ArrayList;

class Solution {

    private void dfs(int key, List<List<Integer>>  rooms, List<Boolean> visited) {
        if (visited.get(key)) {
            return;
        }

        visited.set(key, true);
        for (int k : rooms.get(key)) {
            // 深度优先搜索遍历
            dfs(k, rooms, visited);
        }
    }


    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        List<Boolean> visited = new ArrayList<Boolean>(){{
            for(int i = 0 ; i < rooms.size(); i++){
                add(false);
            }
        }};

        dfs(0, rooms, visited);
        //检查是否都访问到了
        for (boolean flag : visited) {
            if (!flag) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        // int[][] data = new int[][]{{1},{2},{3},{}};
        List<List<Integer>> rooms = new ArrayList<>();
        rooms.add(new ArrayList<Integer>(){ {add(1);} });
        rooms.add(new ArrayList<Integer>(){ {add(2);} });
        rooms.add(new ArrayList<Integer>(){ {add(3);} });
        rooms.add(new ArrayList<Integer>(){ {} });
        // System.out.println(rooms.size() );
        System.out.println( solution.canVisitAllRooms(rooms) );
    }
}