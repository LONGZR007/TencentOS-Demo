#include "stm32f10x.h"
#include "bsp_usart.h"
#include "tos.h"


k_task_t task;

k_stack_t task_stack[1024];

void test_task(void *Parameter)
{
    while(1)
    {
        printf("hello world!\r\n");
        tos_task_delay(1000);
    }
}

/**
  * @brief  ������
  * @author �ܽ�
  * @retval ��
  */
int main(void)
{
    k_err_t err;
       
    /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
    USART_Config();

    printf("Welcome to TencentOS tiny\r\n");

    tos_knl_init(); // TOS Tiny kernel initialize
                                        
    err = tos_task_create(&task, 
                          "task1", 
                          test_task,
                          NULL, 
                          2, 
                          task_stack,
                          1024,
                          20);
    if(err != K_ERR_NONE)
        printf("TencentOS Create task fail! code : %d \r\n",err);
    
    tos_knl_start(); // Start TOS Tiny

}
