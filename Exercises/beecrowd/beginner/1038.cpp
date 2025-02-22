/**
 * Problem: Simple product pricing based on product code and quantity.
 *
 * Description:
 * This program reads a product code and quantity, calculates the total
 * cost based on predefined prices for each product, and prints the value to be paid.
 *
 * Author: Kelvin Coelho
 * Date Created: 22/02/2025
 * Exercise Link: https://judge.beecrowd.com/en/problems/view/1038
 **/

#include <iostream>
#include <cstdio>

int main()
{
    int code;           /*< Product code */
    int quantity;       /*< Product quantity */
    double total = 0.0; /*< Total to be paid */

    std::cin >> code >> quantity;

    switch (code)
    {
        case 1:
            total = 4.00 * quantity;
            break;
        case 2:
            total = 4.50 * quantity;
            break;
        case 3:
            total = 5.00 * quantity;
            break;
        case 4:
            total = 2.00 * quantity;
            break;
        case 5:
            total = 1.50 * quantity;
            break;
    }
    std::printf("Total: R$ %.2f\n", total);
    // std::cout << "Total: R$ " << total << std::endl;

}