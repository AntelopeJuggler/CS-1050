/******************************************************************************
https://umsystem.instructure.com/courses/329816/files/37532060?module_item_id=10955584
*******************************************************************************/
#include <stdio.h>
#include "loyaltytracker.h"

int main(void) {
	for(int i = 0; i<=1; i++) { //does the following twice
		int amt = 0;
		printf("Enter purchase amount in cents: ");
		scanf("%d", &amt);
		record_purchase(amt);
		printf("Points earned: %d\n", compute_points(amt));
		printf("Total points: %d\n", get_total_points());
	}
	int choice = 0;
	printf("Redeem 10 points for a free drink? (1 for yes) ");
	scanf("%d", &choice);
	if(choice==1)
		redeem_reward(10);
	printf("Total points: %d\n", get_total_points());

	int mult = 0;
	printf("Bonus day! Multiplier = ");
	scanf("%d", &mult);
	bonus_points_day(mult);
	printf("Total points: %d\n", get_total_points());
}

