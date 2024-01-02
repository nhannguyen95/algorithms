/**
 * KMP, 0-based index
 * Code was used to submit https://oj.vnoi.info/problem/substr
 */
public class Main {

    private static int[] computePrefixFunction(String P) {
        int m = P.length();
        int[] p = new int[m];
        p[0] = -1;
        int k = p[0];
        for(int q = 1; q < m; q++) {
            while(k >= 0 && P.charAt(k+1) != P.charAt(q)) {
                k = p[k];
            }
            if (P.charAt(k+1) == P.charAt(q)) {
                k++;
            }
            p[q] = k;
        }
        return p;
    }

    private static void kmp(String T, String P) {
        int n = T.length();
        int m = P.length();
        int[] p = computePrefixFunction(P);
        int q = -1;
        for(int i = 0; i < n; i++) {
            while(q >= 0 && P.charAt(q+1) != T.charAt(i)) {
                q = p[q];
            }
            if (P.charAt(q+1) == T.charAt(i)) {
                q++;
            }
            if (q == m - 1) {
                // P occurs in T at T[i - m + 1]
                q = p[q];
            }
        }
    }

    public static void main(String[] args) {

    }
}