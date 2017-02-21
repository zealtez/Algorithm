import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();

		Stack s = new Stack();
		int N = scan.nextInt(), start = 1;
		int[] nums = new int[100001];

		for (int i = 0; i < N; i++) {
			nums[i] = scan.nextInt();
		}
		// 입력정리

		for (int i = 0; i < N; i++) {
			if (s.top() > nums[i]) {
				System.out.println("NO");
				return;
			}

			while (s.top() < nums[i]) {
				sb.append("+\n");
				s.push(start);
				start++;
			}
			s.pop();
			sb.append("-\n");
		} // 성공됬을 때 알고리즘
		System.out.println(sb);
	}
}

class Stack {
	LinkedList<Integer> Stack = new LinkedList<>();

	void push(int x) {
		Stack.add(x);
	}

	void pop() {
		Stack.removeLast();
	}

	int top() {
		if (Stack.isEmpty()) {
			return -1;
		} else {
			return Stack.getLast();

		}
	}
}
