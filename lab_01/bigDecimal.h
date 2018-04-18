#ifndef __BIGDECIMAL_H__
#define __BIGDECIMAL_H__

#include <string>
#include <iostream>
#include <math.h>
#include <limits.h>
#include <gmp.h>

#define      BASE     10
#define  BASE_LEN     30
#define   POW_LEN      5
#define CHK(a,b) { if ((a).isNaN() || (b).isNaN()) return false; }

class BigDecimal{
	public:
		mpf_t base;

	public:
		// Constructors & destructor
		BigDecimal(){
			mpf_init(base);
		}

		BigDecimal(std::string str){
			mpf_init(base);
			mpf_set_str(base, str.c_str(), BASE);
		}

		~BigDecimal(){
			mpf_clear(base);
		}

		// Operators overloading
		BigDecimal operator+(const BigDecimal& other){
			BigDecimal result;
			mpf_add(result.base, this->base, other.base);
			return result;
		}
		

		BigDecimal operator-(const BigDecimal& other){
			BigDecimal result;
			mpf_sub(result.base, this->base, other.base);
			return result;
		}
		/*int operator>(const BigDecimal& other){
			return mpf_cmp_si (this->base, other.base);
		}*/
		
		BigDecimal operator*(const BigDecimal& other){
			BigDecimal result;
			mpf_mul(result.base, this->base, other.base);
			return result;
		}
		int operator==(const BigDecimal& other)  
		{
			
			return mpf_cmp(this->base, other.base);
			}
		
		/*char* operator>(expptr, const BigDecimal& num)  
		{
			;
			return mpf_get_str(NULL, expptr,10,0, num);
		}*/
			
		BigDecimal operator/(const BigDecimal& other)
		{
			BigDecimal result;
			mpf_div(result.base, this->base, other.base);
			return result;
		}

		BigDecimal& operator=(const BigDecimal& other){
			mpf_init_set(this->base, other.base);
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& out, const BigDecimal& number){
			mpf_out_str(stdout, BASE, BASE_LEN, number.base);
			out << std::endl;
			return out;
		}

		friend std::istream& operator>>(std::istream& in, BigDecimal& number){
			std::string strNum;
			in >> strNum;
			mpf_set_str(number.base, strNum.c_str(), BASE);
			return in;
		}
};

#endif // __BIGDECIMAL_H__