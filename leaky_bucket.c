#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define noOfPackets 5

int random(int a){        
        int rn = (rand() % 10) % a;
        return rn == 0 ? 1 : rn;
}

int main(){
        int packets[noOfPackets], i, rate, bucketSize, pSizeRem = 0, pTime = 0, op;
        for(i = 0; i < noOfPackets; i++)
                packets[i] = random(6) % 10;
        for(i = 0;i < noOfPackets; i++)
                printf("Packet[%d] : %d bytes\n",i, packets[i]);
        printf("Enter output rate: ");
        scanf("%d", &rate);
        printf("Enter bucket size: ");
        scanf("%d", &bucketSize);
        for(i = 0;i < noOfPackets; i++){
                if((packets[i] + pSizeRem) > bucketSize){
                        if(packets[i] > bucketSize)
                                printf("Incoming packet size (%d bytes) is greater than bucket size (%d bytes) - PACKET REJECTED\n", packets[i], bucketSize);
                        else
                                printf("Bucket capacity exceeded - PACKETS REJECTED \n");
                }

                else{
                        pSizeRem += packets[i];
                        printf("\nIncoming packet size : %d-----", packets[i]);
                        printf("Bytes remaining to transmit : %d\n", pSizeRem);
                        pTime = random(4) * 10;
                        printf("Time left for transmission : %d units\n", pTime);
                        for(int c = 10; c <= pTime; c += 10){
                                sleep(1);
                                if(pSizeRem){
                                        if(pSizeRem <= rate)
                                                op = pSizeRem , pSizeRem = 0;
                                        else
                                                op = rate, pSizeRem -= rate;
                                        printf("Packet of size %d transmitted-----", op);
                                        printf("Bytes remaining to transmit : %d\n", pSizeRem);
                                }
                                else{
                                        printf("Time left for transmission: %d units\n", pTime-c);
                                        printf("No packets to transmit!\n");
                                }
                        }
                }
        }
        return 0;
}


