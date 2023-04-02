
public class MyClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        String ans = "";
        for(int i = 0; i < n; i++) {
            String line = sc.nextLine();
            ans = ans.concat(line.substring(0,1));
        }

        System.out.println(ans);
    }
}