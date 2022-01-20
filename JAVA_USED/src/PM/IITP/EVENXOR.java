package PM.IITP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class EVENXOR {

    public static int[] E = new int[1000];

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void calculate() {

        int index = 0;
        int N = 3, no1;
        while (index < 1000) {
            no1 = 0;
            String s = Integer.toBinaryString(N);
            //System.out.println(s);
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') {
                    no1++;
                }
            }
            if (no1 % 2 == 0) {
                E[index] = N;
                //System.out.println("Added " + N);
                index++;

            }
            N++;

        }
    }

    public static void main(String[] args) {
        FastReader keyboard = new FastReader();
        try {
            int t = keyboard.nextInt();
            calculate();
            while (t-- > 0) {
                int n = keyboard.nextInt();
                for (int i = 0; i < n; i++) {
                    System.out.print(E[i] + " ");
                }
                System.out.println();
            }
        }catch (Exception e){
            return;
        }
    }
}
