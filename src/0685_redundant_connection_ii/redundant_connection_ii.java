import java.util.ArrayList;

class Solution {

    private static final int N = 1010;  // 如题：二维数组大小的在3到1000范围内
    private int[] father;
    public Solution() {
        father = new int[N];

        // 并查集初始化
        for (int i = 0; i < N; ++i) {
            father[i] = i;
        }
    }

    // 并查集里寻根的过程
    private int find(int u) {
        if(u == father[u]) {
            return u;
        }
        father[u] = find(father[u]);
        return father[u];
    }

    // 将v->u 这条边加入并查集
    private void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }

    // 判断 u 和 v是否找到同一个根，本题用不上
    private Boolean same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    /**
     * 初始化并查集
     */
    private void initFather() {
        // 并查集初始化
        for (int i = 0; i < N; ++i) {
            father[i] = i;
        }
    }

    /**
     * 在有向图里找到删除的那条边，使其变成树
     * @param edges
     * @return 要删除的边
     */
    private int[] getRemoveEdge(int[][] edges) {
        initFather();
        for(int i = 0; i < edges.length; i++) {
            if(same(edges[i][0], edges[i][1])) { // 有向环
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return null;
    }

    /**
     * 删一条边之后判断是不是树
     * @param edges
     * @param deleteEdge 要删除的边
     * @return  true: 是树， false： 不是树
     */
    private Boolean isTreeAfterRemoveEdge(int[][] edges, int deleteEdge)
    {
        initFather();
        for(int i = 0; i < edges.length; i++)
        {
            if(i == deleteEdge) continue;
            if(same(edges[i][0], edges[i][1])) { // 有向环
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int[] inDegree = new int[N];
        for(int i = 0; i < edges.length; i++)
        {
            // 入度
            inDegree[ edges[i][1] ] += 1;
        }

        // 找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
        ArrayList<Integer> twoDegree = new ArrayList<Integer>();
        for(int i = edges.length - 1; i >= 0; i--)
        {
            if(inDegree[edges[i][1]] == 2) {
                twoDegree.add(i);
            }
        }

        // 处理图中情况1 和 情况2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if(!twoDegree.isEmpty())
        {
            if(isTreeAfterRemoveEdge(edges, twoDegree.get(0))) {
                return edges[ twoDegree.get(0)];
            }
            return edges[ twoDegree.get(1)];
        }

        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] result = solution.findRedundantDirectedConnection(new int[][]{{1,2}, {1,3}, {2,3}});
        for(int x : result) {
            System.out.printf("%d, ", x);
        }
        System.out.println();
    }
}