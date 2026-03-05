import java.util.Arrays;

public class Main {

    static int memo[];

    public static int fibonachi(int num){

        if (num <= 1){
            return num;
        }

        if(memo[num] != -1){
            return memo[num];
        }

        memo[num] =  fibonachi(num-1) + fibonachi(num-2);
        return memo[num];
    }

    public static void main(String[] args) {
        memo = new int[10];
        Arrays.fill(memo, -1); 

        int num;

        for(int i=0; i<=5;i++){
            num = i;
            int result = fibonachi(num);
            System.out.println("Fibonaci ("+num+")"+": "+result);
        }
    }
}
