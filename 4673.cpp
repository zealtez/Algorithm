
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		static int[] nums = new int[20001];
		Arrays.fill(nums, 0);
		for(int i = 1; i<=10000; i++){
			cnt(i);
		}
		for(int i = 1; i< 10001; i++){
			if(nums[i] == 0) 
			System.out.println(i);
		}
	}
	static void cnt(int num){
		if(num > 10000) return;
		int temp = num;
		int sum = num;
		while(temp>0){
			sum += (temp%10);
			temp /=10;
		}
		//System.out.println(sum);
		nums[sum]++;
		if(sum > 10000) return;
		cnt(sum);
		return;
	}
}
