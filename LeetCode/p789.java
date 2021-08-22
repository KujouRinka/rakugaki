class Solution {
    private static int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int dist1 = dist(0, 0, target[0], target[1]);
        for (int[] g : ghosts)
            if (dist(g[0], g[1], target[0], target[1]) <= dist1)
                return false;
        return true;
    }
}
