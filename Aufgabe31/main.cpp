/*
a ist ein Zeiger auf einen konstanten float - Wert.
b ist ein konstanter Zeiger auf eine float - Variable.
c ist ein Zeiger auf einen konstanten Zeiger auf eine float - Variable.
d ist ein Array mit 3 Zeigern auf float - Variablen.
e ist ein Zeiger auf ein Array mit 3 Zeigern auf float - Variablen.
*/

int main() {
	float a1 = 4.3f;
	const float* a = &a1;
	float const* d = &a1;
	a++;
	d++;
	//*d = *d + *d;
	//*a = *a + *a;
	float * const b = &a1;
	//b++;
	*b = *b + *b;
	
	float * const * c = &b;

	**c = *b + *b;

}