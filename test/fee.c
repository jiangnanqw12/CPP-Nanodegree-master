/*
北京市出租车打车计费规则如下：

1. 每公里单价计费2.3元

2. 起步价13元(包含3公里)

3. 晚上23点(含)至次日凌晨5点(不含)打车，每公里单价计费加收20%。

4. 每次乘车加收1元钱的燃油附加税。

小明每天上下班都要打车，公司和家的距离为12公里，上午上班时间为9点，下午下班时间为6点。

请编写一个小程序计算小明每天打车的总费用。


————————————————
版权声明：本文为CSDN博主「Ah-ray」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44626649/article/details/88072432
*/
#include <stdio.h>

int fare(int k,int t){
    float money;
    if(k <= 3)
    {   
        money = 14;
    }else
    {
        if(t >= 23 || t < 5)
        {
            money=(k - 3) * 2 * 1.2 + 14;
        }else
        {
            money=(k - 3) * 2 + 14;
        }
        return money;
    }
}
int main()
{

    int sumfare = fare(10,20) + fare(10,6);
    printf("总车费为%d",sumfare);
    return 0;
}
