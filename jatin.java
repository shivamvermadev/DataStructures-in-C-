import java.util.Scanner;
public class jatin {
    static void f1(int[][] a, int m,int n, int[][] b, int p, int q) {
    int v[][]  = new int[m][n];

    for(int i=0;i<m;++i) {
        for(int j=0;j<q;++j) {
            v[i][j] = 0;
        }
    }    

    for(int i=0;i<m;++i) {
        for(int j=0;j<q;++j) {
            for(int k=0;k<p;++k) {
                v[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i=0;i<m;++i) 
    {
        for(int j=0;j<q;++j) 
        {
            System.out.print(v[i][j] + " ");
        }
    }
}

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t, a,b, c, d;
        t = sc.nextInt();
        while(t > 0) {
            a = sc.nextInt();
            b = sc.nextInt();
            int[][] v1 = new int[a][b];
            for(int i=0;i<a;++i) {
                for(int j=0;j<b;++j) {
                    v1[i][j] = sc.nextInt();
                }
            }
            
            c = sc.nextInt();
            d = sc.nextInt();

            int v2[][] = new int[c][d];
            for(int i=0;i<c;++i) {
                for(int j=0;j<d;++j) {
                    v2[i][j] = sc.nextInt();
                }
            }
            if(b != c) {
                System.out.print("IMPOSSIBLE");
            }
            else {
                f1(v1, a, b, v2, c, d);            
            }
            System.out.println();
            t--;
        }
    }
}