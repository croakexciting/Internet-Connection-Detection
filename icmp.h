typedef struct  _IPHeader
{
    u_char vile;           // 版本和首部长度
    u_char ser;            // 服务类型
    u_short totalLen;      // 总长度
    u_short id;            // 标示符
    u_short flag;          // 标记+分片偏移
    u_char ttl;            // 存活时间
    u_char protocol;       // 协议
    u_short checkSum;      // 首部校验和
    in_addr srcIP;         // 源IP地址
    in_addr destIP;        // 目的IP地址
}IPHeader, *PIPHDR;

typedef struct _ICMPHeader
{
    u_char type;            // 类型
    u_char code;            // 代码
    u_short checkSum;       // 校验和
    u_short id;             // 标示符
    u_short seq;            // 序列号
}ICMPHeader, *PICMPHDR;

//ICMP时间戳请求报文
typedef struct _ECHOREQUEST
{
    ICMPHeader icmpHeader;       //ICMP头部
    int time;                    //记录ping时间  
    char data[32];               //数据
}ECHOREQUEST, *pechorequest;

//ICMP时间戳应答报文
typedef struct _ECHORESPONSE
{
    IPHeader ipHeader;
    ECHOREQUEST echoRequest;
    char fill[255];            //接收其他多余的应答数据
}ECHORESPONSE, *PECHORESPONSE;
