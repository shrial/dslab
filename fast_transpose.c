#include <stdio.h>

typedef struct
{
    int r, c, v;
} Element;

void fastTranspose(Element A[], Element B[], int rows, int cols)
{
    int nt = A[0].v;
    int tot[cols], index[cols];

    for (int i = 0; i < cols; i++)
    {
        tot[i] = 0;
    }

    for (int i = 1; i <= nt; i++)
    {
        tot[A[i].c]++;
    }

    index[0] = 1;
    for (int i = 1; i < cols; i++)
    {
        index[i] = index[i - 1] + tot[i - 1];
    }

    B[0].r = A[0].c;
    B[0].c = A[0].r;
    B[0].v = A[0].v;

    for (int i = 1; i <= nt; i++)
    {
        int j = index[A[i].c]++;
        B[j].r = A[i].c;
        B[j].c = A[i].r;
        B[j].v = A[i].v;
    }
}

int main()
{
    int rows, cols, nz;

    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter cols: ");
    scanf("%d", &cols);
    printf("Enter non-zero elements: ");
    scanf("%d", &nz);

    Element A[nz + 1];
    Element B[nz + 1];

    printf("Enter elements (row col value):\n");
    for (int i = 1; i <= nz; i++)
    {
        scanf("%d %d %d", &A[i].r, &A[i].c, &A[i].v);
    }

    A[0].r = rows;
    A[0].c = cols;
    A[0].v = nz;

    fastTranspose(A, B, rows, cols);

    printf("\nMatrix A:\n");
    for (int i = 0; i <= nz; i++)
    {
        printf("%d %d %d\n", A[i].r, A[i].c, A[i].v);
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i <= nz; i++)
    {
        printf("%d %d %d\n", B[i].r, B[i].c, B[i].v);
    }

    return 0;
}
