#include <stdio.h>

int main() {
    
    const float price_apples = 5.99;
    const float price_carrots = 3.99;
    const float price_chips = 2.99;
    const float price_candy = 1.50;

    const float stock_apples = 7.2;
    const float stock_carrots = 4.1;
    const int stock_chips = 9;
    const int stock_candy = 3;

    
    float qty_apples, qty_carrots;
    int qty_chips, qty_candy;

    
    printf("Apples     (7.20  kg) : ");
    if (scanf("%f", &qty_apples) != 1 || qty_apples < 0 || qty_apples > stock_apples) return 1;

    printf("Carrots    (4.10  kg) : ");
    if (scanf("%f", &qty_carrots) != 1 || qty_carrots < 0 || qty_carrots > stock_carrots) return 1;

    printf("Chips      (9  units) : ");
    if (scanf("%d", &qty_chips) != 1 || qty_chips < 0 || qty_chips > stock_chips) return 1;

    printf("Candy      (3  units) : ");
    if (scanf("%d", &qty_candy) != 1 || qty_candy < 0 || qty_candy > stock_candy) return 1;

    
    if (qty_apples == 0 && qty_carrots == 0 && qty_chips == 0 && qty_candy == 0) {
        return 1;  
    }

    printf("\n");

    
    float cost_apples = qty_apples * price_apples;
    float cost_carrots = qty_carrots * price_carrots;
    float cost_chips = qty_chips * price_chips;
    float cost_candy = qty_candy * price_candy;

    
    float disc_candy = 0.0;
    int free_candies = (qty_chips / 2 < qty_candy ? qty_chips / 2 : qty_candy);
    disc_candy = free_candies * (price_candy * 0.5);

    float total_apples = cost_apples;
    float total_carrots = cost_carrots;
    float total_chips = cost_chips;
    float total_candy = cost_candy - disc_candy;

    
    float subtotal = total_apples + total_carrots + total_chips + total_candy;

    
    float promo_total_discount = 0.0;
    if (qty_apples >= 1.0 && qty_carrots >= 1.0 && qty_chips >= 1 && qty_candy >= 1) {
        promo_total_discount = subtotal * 0.10;
    }

    float subtotal_after_promo = subtotal - promo_total_discount;
    float tax = subtotal_after_promo * 0.05;
    float total = subtotal_after_promo + tax;

    
    printf("-------------------------------------------------------------------\n");
    printf("| Item     | Quantity     | Cost       | Discount    | Total      |\n");
    if (qty_apples > 0)
        printf("| Apples   | %4.2f      kg | $%9.2f | -$%9.2f | $%9.2f |\n",
               qty_apples, cost_apples, 0.0, total_apples);
    if (qty_carrots > 0)
        printf("| Carrots  | %4.2f      kg | $%9.2f | -$%9.2f | $%9.2f |\n",
               qty_carrots, cost_carrots, 0.0, total_carrots);
    if (qty_chips > 0)
        printf("| Chips    | %d            | $%9.2f | -$%9.2f | $%9.2f |\n",
               qty_chips, cost_chips, 0.0, total_chips);
    if (qty_candy > 0)
        printf("| Candy    | %d            | $%9.2f | -$%9.2f | $%9.2f |\n",
               qty_candy, cost_candy, disc_candy, total_candy);
    printf("-------------------------------------------------------------------\n\n");

    
    if (promo_total_discount > 0)
        printf("Subtotal        : $%.2f - $%.2f = $%.2f\n", subtotal, promo_total_discount, subtotal_after_promo);
    else
        printf("Subtotal        : $%.2f\n", subtotal);

    printf("Tax (5%%)        : $%.2f\n", tax);
    printf("----------------------------------------------------\n");
    printf("Total           : $%.2f\n", total);

    return 0;
}

