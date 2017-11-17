#include <stdio.h>  
#include <stdlib.h>  
#include <stddef.h>  
#include <stdarg.h>  
#include <string.h>  
#include <assert.h>  
#include <hiredis/hiredis.h> 


int main()
{
    redisContext *context = redisConnect("127.0.0.1", 6379);

    if(context->err)
    {
        redisFree(context);
        printf("Connect to redisServer faile\n");
        return -1;
    }

    printf("Connect to redisServer Success\n");

    const char* command1 = "set stest1 value1";  
    redisReply* r = (redisReply*)redisCommand(context, command1);  

    if( NULL == r)  
    {  
        printf("Execut command1 failure\n");  
        redisFree(context);  
        return -1;  
    }  

    if( !(r->type == REDIS_REPLY_STATUS && strcasecmp(r->str,"OK")==0))  
    {  
        printf("Failed to execute command[%s]\n",command1);  
        freeReplyObject(r);  
        redisFree(context);  
        return -1;  
    }

    freeReplyObject(r);

    printf("Succeed to execute command[%s]\n", command1);  

    return 0;
}

