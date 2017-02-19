import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String S = scan.nextLine();
		int [] nums = new int[10]; // 0 ~ 9 인덱스;
		int ans = 0;

		for(int i = 0; i<S.length(); i++){
			nums[(S.charAt(i))-'0']++;
		}
		nums[9] = (int)Math.ceil((double)(nums[6]+nums[9])/2);
		nums[6] = nums[9];
		
		for(int i = 0; i<= 9; i++){
			ans = (ans>nums[i]? ans: nums[i]);
		}
		System.out.println(ans);
		scan.close();
	}
}
