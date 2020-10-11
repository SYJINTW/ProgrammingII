//Prefix Sum

#include <stdio.h>

int main()
{
	long long int n, q;
	long long int a, b, sum;
	long long int m_a, m_b, m_sum;
	long long int tmp;
	
	//end untill EOF
	while(scanf("%lld %lld", &n, &q) != EOF){
		
		long long int prefix[2000001] = {0}; //prefix sum list

		//initial max value
		m_sum = 0;
		m_a = 0;
		m_b = 0;
		
		//initial prefix sum
		for(int i = 1; i <= n; i++){
			scanf("%lld", &tmp);
			prefix[i] = prefix[i-1] + tmp;
		}

		//calculate the sum of range[a,b]
		for(int i = 0; i < q; i++){
			scanf("%lld %lld", &a, &b);
			if(a <= b){
				sum = prefix[b] - prefix[a-1];
			}
			else{
				sum = prefix[n] - prefix[a-1] + prefix[b];
			}

			if(sum > m_sum){
				m_sum = sum;
				m_a = a;
				m_b = b;
			}
		}
		
		printf("Max_range: (%lld,%lld); Value: %lld\n", m_a, m_b, m_sum);
	}

	return 0;
}