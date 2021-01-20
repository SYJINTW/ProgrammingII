#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n, box;                                       	// n: number of reels, box: box size
int a[1000];                                      	// Reel levels
bool vis[1000];                                   	// Vis array, record used reels

bool dfs(int step, int sum) {                       // step: used reel number, sum: current box height
	if (step == n) return true;                  	// All reels used, find a solution, return true

	for (int i = 0; i < n; i++) {               	// Pick a reel starting from pos
		if (vis[i]) continue;                     	// The reel has been used, skip it

		vis[i] = true;                           	// Pick one, set to used

		if (sum + a[i] < box) {                   	// After picking the reel, the box is not full
			if (dfs(step + 1, sum + a[i])) 			// Continue with the current box, return true if find a solution
				return true;                      	
		} else if (sum + a[i] == box) {           	// After picking the reel, the box is full
			if (dfs(step + 1, 0))         	     	// Start with a new box (sum = 0), return true if find a solution
				return true;						
		}                                         	// Else: The reel leads to overflow

		vis[i] = false;                           	// Reset the used state
	}

	return false;                                 	// We can't find a solution, return false
}

int main() {
	int T, sum, ans;                                // T: testcases, sum: sum of reels, ans: box number

	scanf("%d", &T);                              	// Read testcase number
	while (T--) {                                	// Read testcases
		scanf("%d", &n);                          	// Number of reels
		sum = 0; 									// The sum of reels
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]); 					// Level of every reel
			sum += a[i]; 							// Increase sum
		}
		for (ans = n; ans > 1; ans--) { 			// Determine box number
			box = sum / ans; 						// Calculate box size
			if (sum % ans == 0) { 					// Skip non-integer box sizes
				memset(vis, false, sizeof vis); 	// Reset vis array
				if (dfs(0, 0)) break; 				// Try to fill the boxes recursively
			}
		}
		printf("%d\n", ans); 						// Print the maximum box number
	}

	return 0;
}
