#include<iostream>
#include<math.h>
using namespace std;
class Vector
{
	private:
		int i,j,k;// assuming only integer values are used

	public:

		Vector()
		{
			this->i = 0;
			this->j = 0;
			this->k = 0;
		}	
	
		Vector(int i, int j, int k)
		{
			this->i = i;
			this->j = j;
			this->k = k;
		}	
	
		Vector operator+(const Vector& operand)//vector addition 
		{
            return Vector(this->i + operand.i, this->j + operand.j, this->k + operand.k);
		}
	
		Vector operator-(const Vector& operand)//vector subtraction
		{
            return Vector(this->i - operand.i, this->j - operand.j, this->k - operand.k);
		}

		Vector operator*(const Vector& operand)//vector dot product
		{
            return Vector(this->i * operand.i, this->j * operand.j, this->k * operand.k);
		}

		Vector operator^(const Vector& operand)//vector cross product
		{

			int ci = this->j * operand.k - operand.j * this->k;
			int cj = this->k * operand.i - operand.k * this->i;
			int ck = this->i * operand.j - operand.i * this->j;
            return Vector(ci, cj, ck);
		}
		float magnitude()// vector magnitude
		{

			return sqrt(pow(this->i, 2) + pow(this->j, 2) + pow(this->k,2));
		}
		float operator>(const Vector& operand)//distance between 2 vectors
		{
            return sqrt(pow(this->i - operand.i, 2) + pow(this->j - operand.j, 2) + pow(this->k - operand.k, 2));
		}

		void showVector()//display vector
		{
			cout<<this->i<<"i +"<<this->j<<"j +"<<this->k<<"k"<<endl;

		}


};
int main()
{
	Vector a = Vector(1,2,3);
	Vector b = Vector(4,5,6);
	Vector c = Vector();
	c = a * b;
	c.showVector();
	float dist = a>b;
	cout<< dist;		
	return 0;
}
