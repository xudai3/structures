/*
 * =====================================================================================
 *
 *       Filename:  poly.c
 *
 *    Description:  polyADT
 *
 *        Version:  1.0
 *        Created:  07/28/2015 02:55:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "fatal.h"

#define MaxDegree 100

static int Max(int A, int B)
{
    return A > B ? A : B;
}

typedef struct {
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} *Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
    int i;

    for (i = 0; i <= MaxDegree; i++) {
        Poly->CoeffArray[i] = 0;
    }
    Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
    int i;

    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

    for (i = PolySum->HighPower; i >= 0; i--) {
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
    }
}

void MultPolynomial(const Polynomial Poly1, 
        const Polynomial Poly2, Polynomial PolyProd)
{
    int i, j;

    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

    if (PolyProd->HighPower > MaxDegree) {
        Error("Exceeded array size");
    }else{
        for (i = 0; i <= Poly1->HighPower; i++) 
            for(j = 0; j <= Poly2->HighPower; j++)
                PolyProd->CoeffArray[i+j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
    }
}

void PrintPoly(const Polynomial Q)
{
    int i;

    for (i = Q->HighPower; i > 0; i--) {
        printf("%dx^%d + ", Q->CoeffArray[i], i);
    }
    printf("%d\n", Q->CoeffArray[0]);
}

int main()
{
    Polynomial P, Q;

    P = malloc(sizeof(*P));
    Q = malloc(sizeof(*Q));

    P->HighPower = 1;
    P->CoeffArray[0] = 2;
    P->CoeffArray[1] = 3;
    MultPolynomial(P, P, Q);
    PrintPoly(P);
    PrintPoly(Q);
    MultPolynomial(Q, Q, P);
    PrintPoly(P);
    PrintPoly(Q);
    AddPolynomial(P, P, Q);
    PrintPoly(P);
    PrintPoly(Q);

    return 0;
}
