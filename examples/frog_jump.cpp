// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
    만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
       그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
       또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
    단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
    // freopen("input.txt", "r", stdin);

    setbuf(stdout, NULL);

    int TC;
    int test_case;

    scanf("%d", &TC);
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        int stone_num, k, start=0;
        int i,j,jump=0;

        scanf("%d",&stone_num);

        int arr[stone_num+1];
        arr[stone_num]=1000000000; //다음돌을 아예 엄청 큰 값을 잡아놔서 while문에 걸리지 않도록.

        //배열 입력받기.
        for(i=0;i<stone_num;i++)
            scanf("%d",&arr[i]);

        //배열 값의 개수
        scanf("%d",&k);
        i=0;//현재 노드를 가르키는 인덱스.

        //현재 값 == 배열의 마지막 값 일때까지.(도착할때까지)
        while(start!=arr[stone_num-1]){
            j=i;//j에 현재 값 인덱스를 저장. 다다음줄에서 쓴다.
            while (start + k >= arr[i]) i++;
            if(i==j) {// i 값에 변화가 없다 -> 불가능.
                jump = -1;
                break;
            }
            jump++;//변화가 있다 -> 가능 & jump!
            start = arr[i - 1]; //현재 위치를 수정.
        }


        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n", test_case);
        printf("%d\n",jump);

    }


    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}