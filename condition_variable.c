 #include<stdio.h>
 #include<pthread.h>
 #include<unistd.h>
 pthread_mutex_t l;
 pthread_cond_t cond;
 int amount=0;
 void* deposit(void* arg)
 {
    
     while(1)
     {
        pthread_mutex_lock(&l);
        amount=amount+20;
        printf("20 rs reposited, final value of amount is %d\n",amount);
        if(amount>50){
        pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&l);
        sleep(1);
    }
    return NULL;
 }
 void* withdrawl()
 {
   while(1){
    pthread_mutex_lock(&l);
    while(amount<50)
    {
       
        pthread_cond_wait(&cond,&l);

    } 
    
    amount-=50;
    printf("Amount withdrawn is rs50 ,left is :%d\n",amount);
    pthread_mutex_unlock(&l);
    
}
    
    return NULL;
 }
 int main()
 {
    pthread_t t1,t2;
    pthread_mutex_init(&l,NULL);
    pthread_create(&t1,NULL,&deposit,NULL);
    pthread_create(&t2,NULL,&withdrawl,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&l);
    pthread_cond_destroy(&cond);
    printf("End of deposit and withdrawl\n");
    return 0;
 }