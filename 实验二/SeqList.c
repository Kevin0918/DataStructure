#include<stdio.h>
#define MAXSIZE 101

struct Seqlist {
    int data[MAXSIZE];
    int last;
};

typedef struct Seqlist *List;

List InitialL( List PtrL ) {
    
    PtrL->last = -1;
    memset( PtrL->data, 0,sizeof( PtrL->data ) );
    return PtrL;
}

List InputL ( List PtrL ) {
    
    int i, number;
    printf("请输入数组的大小：\n");
    scanf( "%d", &number );
    printf("请依次输入数组中的元素：\n");
    for ( i = 0; i < number; i++ ) {
        scanf("%d",& ( PtrL->data[i] ) );
        PtrL->last++;
    }
    return PtrL;
}

void OutputL ( List PtrL ) {
    
    int i;
    printf( "数组元素如下：\n" );
    for( i = 0; i <= PtrL->last; i++ ) {
        printf( "%d\n",PtrL->data[i] );
    }
}

List InsertL( List PtrL, int a ) {
    int i,j;
    for (i=0; i < PtrL->last; i++) {
        if ( PtrL->data[i] <= a && PtrL->data[i+1] >= a ) {
            break;
        }
    }
    for( j = PtrL->last; j > i; j-- )
        PtrL->data[j+1] = PtrL->data[j];
    PtrL->data[i+1] = a;
    PtrL->last ++;
    return PtrL;
}

List DeleteL ( List PtrL ) {
    for(int i=0; i<PtrL->last; i++)
    {
        if(PtrL->data[i] == PtrL->data[i+1])
        {
            PtrL->data[i]=PtrL->data[i+1];
            PtrL->last--;
        }
    }
    return PtrL;
}

int main() {
    int a;
    List PtrL;
    PtrL = ( List )malloc( sizeof( struct Seqlist ) );
    PtrL = InitialL( PtrL );
    PtrL = InputL( PtrL );
    printf( "请输入要插入的元素的值：\n" );
    scanf( "%d", &a );
    PtrL = InsertL( PtrL, a);
    PtrL = DeleteL( PtrL );
    OutputL( PtrL );
}