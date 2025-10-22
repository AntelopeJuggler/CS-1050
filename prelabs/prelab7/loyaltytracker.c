#include "loyaltytracker.h"

static int total(int pts, int purchase) { //if both neg 1, reset. If one neg 1, return that one. Else, add numbers to total
    static int total_points = 0;
    static int purchase_total = 0;
    int ret = 0;
    if(pts==-1 && purchase == -1) {
        total_points = 0;
        purchase_total = 0;
        ret = 1;
    }
    else if (pts == -1) 
        ret = total_points;
    else if (purchase == -1) 
        ret = purchase_total;
    else {
        total_points+=pts;
        purchase_total+=purchase;
    }
    
    return ret;
}

int reset_day(void) {
    return total(-1,-1);
}

int record_purchase(int cents) {
    int ret = 1;
    if(cents>=0) 
        total(0, cents);
    else ret=-1;
    return ret;
}

int compute_points(int cents) {
    int points = cents/100;
    total(points, 0);
    return points;
}

int get_total_points(void) {
    return total(-1, 0);
}

int redeem_reward(int points_needed) {
    int ret = 1;
    if(total(-1, 0)>=points_needed)
        total(-points_needed, 0);
    else ret = 0;
    return ret;
}

int bonus_points_day(int multiplier) {
    int points = total(-1,0);
    int new_points = points * multiplier;
    total(new_points-points, 0);
    return new_points;
}