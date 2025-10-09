/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testall.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:00:00 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/09 20:41:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fixed.hpp"
#include <iostream>

void testConstructors() {
    std::cout << "\n========== CONSTRUCTOR TESTS ==========" << std::endl;
    
    std::cout << "\n--- Default Constructor ---" << std::endl;
    Fixed a;
    std::cout << "Fixed a; -> " << a << std::endl;
    
    std::cout << "\n--- Int Constructor ---" << std::endl;
    Fixed b(42);
    std::cout << "Fixed b(42); -> " << b << std::endl;
    
    std::cout << "\n--- Float Constructor ---" << std::endl;
    Fixed c(3.14f);
    std::cout << "Fixed c(3.14f); -> " << c << std::endl;
    
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    Fixed d(b);
    std::cout << "Fixed d(b); -> " << d << std::endl;
    
    std::cout << "\n--- Assignment Operator ---" << std::endl;
    a = c;
    std::cout << "a = c; -> a = " << a << std::endl;
}

void testConversions() {
    std::cout << "\n========== CONVERSION TESTS ==========" << std::endl;
    
    Fixed a(42);
    Fixed b(3.75f);
    
    std::cout << "\n--- toInt() Tests ---" << std::endl;
    std::cout << "Fixed(42).toInt() = " << a.toInt() << " (expected: 42)" << std::endl;
    std::cout << "Fixed(3.75f).toInt() = " << b.toInt() << " (expected: 3)" << std::endl;
    
    std::cout << "\n--- toFloat() Tests ---" << std::endl;
    std::cout << "Fixed(42).toFloat() = " << a.toFloat() << " (expected: 42)" << std::endl;
    std::cout << "Fixed(3.75f).toFloat() = " << b.toFloat() << " (expected: 3.75)" << std::endl;
    
    std::cout << "\n--- getRawBits() Tests ---" << std::endl;
    std::cout << "Fixed(42).getRawBits() = " << a.getRawBits() << " (expected: " << (42 * 256) << ")" << std::endl;
    
    std::cout << "\n--- setRawBits() Test ---" << std::endl;
    Fixed c;
    c.setRawBits(1280); // Should represent 5.0 (1280 / 256)
    std::cout << "After setRawBits(1280): " << c << " (expected: 5)" << std::endl;
}

void testArithmetic() {
    std::cout << "\n========== ARITHMETIC TESTS ==========" << std::endl;
    
    Fixed a(10);
    Fixed b(3);
    Fixed c(2.5f);
    
    std::cout << "\n--- Addition Tests ---" << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << " (expected: 13)" << std::endl;
    std::cout << a << " + " << c << " = " << (a + c) << " (expected: 12.5)" << std::endl;
    
    std::cout << "\n--- Subtraction Tests ---" << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << " (expected: 7)" << std::endl;
    std::cout << a << " - " << c << " = " << (a - c) << " (expected: 7.5)" << std::endl;
    
    std::cout << "\n--- Multiplication Tests ---" << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << " (expected: 30)" << std::endl;
    std::cout << b << " * " << c << " = " << (b * c) << " (expected: 7.5)" << std::endl;
    std::cout << c << " * " << c << " = " << (c * c) << " (expected: 6.25)" << std::endl;
    
    std::cout << "\n--- Division Tests ---" << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << " (expected: 3.33333...)" << std::endl;
    std::cout << a << " / " << c << " = " << (a / c) << " (expected: 4)" << std::endl;
    std::cout << c << " / " << Fixed(2) << " = " << (c / Fixed(2)) << " (expected: 1.25)" << std::endl;
}

void testComparison() {
    std::cout << "\n========== COMPARISON TESTS ==========" << std::endl;
    
    Fixed a(5);
    Fixed b(3);
    Fixed c(5);
    
    std::cout << "\n--- Greater Than Tests ---" << std::endl;
    std::cout << a << " > " << b << " = " << (a > b) << " (expected: 1)" << std::endl;
    std::cout << b << " > " << a << " = " << (b > a) << " (expected: 0)" << std::endl;
    std::cout << a << " > " << c << " = " << (a > c) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Less Than Tests ---" << std::endl;
    std::cout << b << " < " << a << " = " << (b < a) << " (expected: 1)" << std::endl;
    std::cout << a << " < " << b << " = " << (a < b) << " (expected: 0)" << std::endl;
    std::cout << a << " < " << c << " = " << (a < c) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Greater or Equal Tests ---" << std::endl;
    std::cout << a << " >= " << b << " = " << (a >= b) << " (expected: 1)" << std::endl;
    std::cout << a << " >= " << c << " = " << (a >= c) << " (expected: 1)" << std::endl;
    std::cout << b << " >= " << a << " = " << (b >= a) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Less or Equal Tests ---" << std::endl;
    std::cout << b << " <= " << a << " = " << (b <= a) << " (expected: 1)" << std::endl;
    std::cout << a << " <= " << c << " = " << (a <= c) << " (expected: 1)" << std::endl;
    std::cout << a << " <= " << b << " = " << (a <= b) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Equality Tests ---" << std::endl;
    std::cout << a << " == " << c << " = " << (a == c) << " (expected: 1)" << std::endl;
    std::cout << a << " == " << b << " = " << (a == b) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Inequality Tests ---" << std::endl;
    std::cout << a << " != " << b << " = " << (a != b) << " (expected: 1)" << std::endl;
    std::cout << a << " != " << c << " = " << (a != c) << " (expected: 0)" << std::endl;
}

void testIncrement() {
    std::cout << "\n========== INCREMENT/DECREMENT TESTS ==========" << std::endl;
    
    Fixed a(5);
    
    std::cout << "\n--- Pre-increment Tests ---" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << " (a should now be ~5.004)" << std::endl;
    std::cout << "a = " << a << std::endl;
    
    std::cout << "\n--- Post-increment Tests ---" << std::endl;
    std::cout << "a++ = " << a++ << " (should show previous value)" << std::endl;
    std::cout << "a = " << a << " (should now be ~5.008)" << std::endl;
    
    std::cout << "\n--- Pre-decrement Tests ---" << std::endl;
    std::cout << "--a = " << --a << " (should now be ~5.004)" << std::endl;
    std::cout << "a = " << a << std::endl;
    
    std::cout << "\n--- Post-decrement Tests ---" << std::endl;
    std::cout << "a-- = " << a-- << " (should show previous value)" << std::endl;
    std::cout << "a = " << a << " (should now be 5)" << std::endl;
}

void testMinMax() {
    std::cout << "\n========== MIN/MAX TESTS ==========" << std::endl;
    
    Fixed a(10);
    Fixed b(5);
    Fixed c(7.5f);
    
    std::cout << "\n--- Non-const min/max Tests ---" << std::endl;
    std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << " (expected: 5)" << std::endl;
    std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << " (expected: 10)" << std::endl;
    std::cout << "min(" << b << ", " << c << ") = " << Fixed::min(b, c) << " (expected: 5)" << std::endl;
    std::cout << "max(" << b << ", " << c << ") = " << Fixed::max(b, c) << " (expected: 7.5)" << std::endl;
    
    std::cout << "\n--- Const min/max Tests ---" << std::endl;
    const Fixed d(15);
    const Fixed e(12);
    std::cout << "min(const " << d << ", const " << e << ") = " << Fixed::min(d, e) << " (expected: 12)" << std::endl;
    std::cout << "max(const " << d << ", const " << e << ") = " << Fixed::max(d, e) << " (expected: 15)" << std::endl;
}

void testEdgeCases() {
    std::cout << "\n========== EDGE CASE TESTS ==========" << std::endl;
    
    std::cout << "\n--- Zero Tests ---" << std::endl;
    Fixed zero;
    Fixed five(5);
    std::cout << "0 + 5 = " << (zero + five) << " (expected: 5)" << std::endl;
    std::cout << "5 - 5 = " << (five - five) << " (expected: 0)" << std::endl;
    std::cout << "0 * 5 = " << (zero * five) << " (expected: 0)" << std::endl;
    
    std::cout << "\n--- Negative Number Tests ---" << std::endl;
    Fixed neg(-3);
    std::cout << "Fixed(-3) = " << neg << " (expected: -3)" << std::endl;
    std::cout << "5 + (-3) = " << (five + neg) << " (expected: 2)" << std::endl;
    std::cout << "(-3) * 2 = " << (neg * Fixed(2)) << " (expected: -6)" << std::endl;
    
    std::cout << "\n--- Small Fractional Tests ---" << std::endl;
    Fixed small(0.25f);
    std::cout << "Fixed(0.25f) = " << small << " (expected: 0.25)" << std::endl;
    std::cout << "0.25 * 4 = " << (small * Fixed(4)) << " (expected: 1)" << std::endl;
    std::cout << "1 / 4 = " << (Fixed(1) / Fixed(4)) << " (expected: 0.25)" << std::endl;
    
    std::cout << "\n--- Chain Operations ---" << std::endl;
    Fixed result = Fixed(2) + Fixed(3) * Fixed(4);
    std::cout << "2 + 3 * 4 = " << result << " (expected: 14)" << std::endl;
    
    result = (Fixed(10) - Fixed(4)) / Fixed(2);
    std::cout << "(10 - 4) / 2 = " << result << " (expected: 3)" << std::endl;
}

void testPrecision() {
    std::cout << "\n========== PRECISION TESTS ==========" << std::endl;
    
    std::cout << "\n--- Fixed-Point Precision Limits ---" << std::endl;
    Fixed a(1.0f / 3.0f);
    Fixed b(2.0f / 3.0f);
    Fixed sum = a + b;
    std::cout << "1/3 + 2/3 = " << sum << " (should be close to 1)" << std::endl;
    
    std::cout << "\n--- Repeated Operations ---" << std::endl;
    Fixed accumulator(0);
    for (int i = 0; i < 10; i++) {
        accumulator = accumulator + Fixed(0.1f);
    }
    std::cout << "Sum of 0.1 ten times = " << accumulator << " (should be close to 1)" << std::endl;
    
    std::cout << "\n--- Very Small Numbers ---" << std::endl;
    Fixed tiny(1.0f / 256.0f);  // Smallest representable positive number
    std::cout << "Smallest positive: " << tiny << " (expected: ~0.00390625)" << std::endl;
    std::cout << "Smallest + Smallest = " << (tiny + tiny) << std::endl;
}

int main(void) {
    std::cout << "===============================================" << std::endl;
    std::cout << "      COMPREHENSIVE FIXED CLASS TESTS        " << std::endl;
    std::cout << "===============================================" << std::endl;
    
    testConstructors();
    testConversions();
    testArithmetic();
    testComparison();
    testIncrement();
    testMinMax();
    testEdgeCases();
    testPrecision();
    
    std::cout << "\n===============================================" << std::endl;
    std::cout << "            ALL TESTS COMPLETED               " << std::endl;
    std::cout << "===============================================" << std::endl;
    
    return 0;
}
